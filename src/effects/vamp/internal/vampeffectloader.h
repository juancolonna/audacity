/*
 * Audacity: A Digital Audio Editor
 */

#pragma once

#include <memory>
#include "framework/audioplugins/ieffectplugin.h"

namespace muse::audioplugins {
class AudioPluginMetaInfo;
}

namespace au::effects {

class IEffectLoader;

/**
 * @brief VampEffectLoader - Loads individual VAMP effect plugins
 * 
 * Responsible for:
 * - Instantiating VAMP plugins from plugin keys
 * - Wrapping VAMP plugins to IEffectPlugin interface
 * - Managing plugin lifecycle (init, deinit)
 */
class VampEffectLoader
{
public:
    VampEffectLoader();
    ~VampEffectLoader();

    void init();
    void deinit();

    // TODO: Implement load() to return IEffectPlugin wrapper
    // std::shared_ptr<IEffectPlugin> load(const muse::audioplugins::AudioPluginMetaInfo& metaInfo);

private:
    // TODO: Add member variables for plugin cache, etc.
};

}
