/*
 * Audacity: A Digital Audio Editor
 */

#pragma once

#include <memory>
#include "effects/effects_base/ieffectviewlauncher.h"

namespace muse::modularity {
class IContextSetup;
using ContextPtr = std::shared_ptr<IContextSetup>;
}

namespace au::effects {

/**
 * @brief VampViewLauncher - Manages VAMP effect UI views
 * 
 * Responsible for:
 * - Launching effect editor dialogs
 * - Managing effect state and presets
 * - Handling real-time effect monitoring
 */
class VampViewLauncher : public IEffectViewLauncher
{
public:
    explicit VampViewLauncher(const muse::modularity::ContextPtr& ctx);
    ~VampViewLauncher();

    // TODO: Implement launch() to show effect UI
    // void launch(const EffectInstanceId& id, const EffectId& effectId) override;

private:
    muse::modularity::ContextPtr m_context;
};

}
