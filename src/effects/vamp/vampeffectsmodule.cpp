/*
 * Audacity: A Digital Audio Editor
 */
#include "vampeffectsmodule.h"

#include <vamp-hostsdk/PluginLoader.h>

#include "framework/audioplugins/iaudiopluginsscannerregister.h"
#include "framework/audioplugins/iaudiopluginmetareaderregister.h"

#include "effects/effects_base/ieffectloadersregister.h"
#include "effects/effects_base/ieffectviewlaunchregister.h"
#include "effects/effects_base/iparameterextractorregistry.h"
#include "effects/effects_base/effectstypes.h"

// Forward declarations for internal components
// These will be implemented in subsequent files
namespace au::effects {
class VampEffectLoader;
class VampPluginsScanner;
class VampPluginsMetaReader;
}

using namespace au::effects;

static const std::string mname("effects_vamp");

static void vamp_init_qrc()
{
    Q_INIT_RESOURCE(vamp);
}

VampEffectsModule::VampEffectsModule()
    : m_metaReader{std::make_shared<VampPluginsMetaReader>()},
      m_effectLoader{std::make_shared<VampEffectLoader>()},
      m_pluginsScanner{std::make_shared<VampPluginsScanner>()}
{
}

std::string VampEffectsModule::moduleName() const
{
    return mname;
}

void VampEffectsModule::registerExports()
{
    // VAMP does not export global services like LV2 or Builtin effects
    // All registration happens via resolveImports pattern
}

void VampEffectsModule::resolveImports()
{
    // Register scanner for plugin discovery
    auto scannerRegister = globalIoc()->resolve<muse::audioplugins::IAudioPluginsScannerRegister>(mname);
    if (scannerRegister) {
        scannerRegister->registerScanner(m_pluginsScanner);
    }

    // Register metadata reader for plugin information
    auto metaReaderRegister = globalIoc()->resolve<muse::audioplugins::IAudioPluginMetaReaderRegister>(mname);
    if (metaReaderRegister) {
        metaReaderRegister->registerReader(m_metaReader);
    }

    // Register effect loader
    auto loadersRegister = globalIoc()->resolve<IEffectLoadersRegister>(mname);
    if (loadersRegister) {
        loadersRegister->registerLoader(m_effectLoader);
    }

    // Register parameter extractor for auto-generated UI
    auto paramExtractorRegistry = globalIoc()->resolve<IParameterExtractorRegistry>(mname);
    if (paramExtractorRegistry) {
        // TODO: Register VampParameterExtractor when implemented
        // paramExtractorRegistry->registerExtractor(std::make_shared<VampParameterExtractor>());
    }
}

void VampEffectsModule::registerResources()
{
    vamp_init_qrc();
}

void VampEffectsModule::registerUiTypes()
{
    // Register QML types if needed
    // TODO: Register Vamp-specific QML types when UI implementation is ready
}

void VampEffectsModule::onInit(const muse::IApplication::RunMode& mode)
{
    if (m_metaReader) {
        m_metaReader->init();
    }
    
    if (m_effectLoader) {
        m_effectLoader->init();
    }
    
    if (m_pluginsScanner) {
        m_pluginsScanner->init(mode);
    }
}

void VampEffectsModule::onDeinit()
{
    if (m_effectLoader) {
        m_effectLoader->deinit();
    }
    
    if (m_pluginsScanner) {
        m_pluginsScanner->deinit();
    }
    
    if (m_metaReader) {
        m_metaReader->deinit();
    }
}

muse::modularity::IContextSetup* VampEffectsModule::newContext(const muse::modularity::ContextPtr& ctx) const
{
    return new VampEffectsContext(ctx);
}

// =====================================================
// VampEffectsContext
// =====================================================

void VampEffectsContext::resolveImports()
{
    // Register view launcher for effect UI
    auto lr = ioc()->resolve<IEffectViewLaunchRegister>(mname);
    if (lr) {
        // TODO: Register VampViewLauncher when UI implementation is ready
        // For now, VAMP effects use Extension or Analyzer family
        // lr->regLauncher(EffectFamily::Extension, std::make_shared<VampViewLauncher>(iocContext()));
    }
}

void VampEffectsContext::onDeinit()
{
    // Cleanup context-specific resources
}
