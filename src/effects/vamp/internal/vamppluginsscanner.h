/*
 * Audacity: A Digital Audio Editor
 */

#pragma once

#include <memory>
#include "framework/audioplugins/iaudiopluginscanner.h"

namespace muse::audioplugins {
class IRegisterAudioPluginsScenario;
}

namespace au::effects {

/**
 * @brief VampPluginsScanner - Discovers available VAMP plugins
 * 
 * Responsible for:
 * - Enumerating available VAMP plugins from system paths
 * - Building metadata for each discovered plugin
 * - Handling plugin state (validated, missing, error)
 */
class VampPluginsScanner : public muse::audioplugins::IAudioPluginsScanner
{
public:
    VampPluginsScanner();
    ~VampPluginsScanner();

    void init(const muse::IApplication::RunMode& mode) override;
    void deinit() override;

    // TODO: Implement scan() to discover VAMP plugins
    // muse::Ret scan(const muse::audioplugins::AudioPluginsScannerParams& params) override;

private:
    // TODO: Add member variables for scanner state
};

}
