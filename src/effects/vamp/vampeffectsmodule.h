/*
 * Audacity: A Digital Audio Editor
 */

#pragma once

#include <memory>

#include "modularity/imodulesetup.h"

namespace au::effects {

class VampEffectLoader;
class VampPluginsScanner;
class VampPluginsMetaReader;

class VampEffectsModule : public muse::modularity::IModuleSetup
{
public:
    VampEffectsModule();

    std::string moduleName() const override;
    void registerExports() override;
    void resolveImports() override;
    void registerResources() override;
    void registerUiTypes() override;
    void onInit(const muse::IApplication::RunMode& mode) override;
    void onDeinit() override;

    muse::modularity::IContextSetup* newContext(const muse::modularity::ContextPtr& ctx) const override;

private:
    const std::shared_ptr<VampPluginsMetaReader> m_metaReader;
    const std::shared_ptr<VampEffectLoader> m_effectLoader;
    const std::shared_ptr<VampPluginsScanner> m_pluginsScanner;
};

class VampEffectsContext : public muse::modularity::IContextSetup
{
public:
    VampEffectsContext(const muse::modularity::ContextPtr& ctx)
        : muse::modularity::IContextSetup(ctx) {}

    void resolveImports() override;
    void onDeinit() override;
};

}
