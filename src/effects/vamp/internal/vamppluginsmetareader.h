/*
 * Audacity: A Digital Audio Editor
 */

#pragma once

#include <memory>
#include "framework/audioplugins/iaudiopluginmetareader.h"

namespace muse::audioplugins {
struct AudioPluginMetaInfo;
}

namespace au::effects {

/**
 * @brief VampPluginsMetaReader - Reads VAMP plugin metadata
 * 
 * Responsible for:
 * - Reading plugin name, description, version
 * - Extracting parameter information
 * - Determining plugin type and capabilities
 */
class VampPluginsMetaReader : public muse::audioplugins::IAudioPluginMetaReader
{
public:
    VampPluginsMetaReader();
    ~VampPluginsMetaReader();

    void init() override;
    void deinit() override;

    // TODO: Implement readMetaInfo() to extract plugin information
    // muse::Ret readMetaInfo(const muse::io::path_t& pluginPath,
    //                        muse::audioplugins::AudioPluginMetaInfo& metaInfo) const override;

private:
    // TODO: Add member variables for metadata extraction
};

}
