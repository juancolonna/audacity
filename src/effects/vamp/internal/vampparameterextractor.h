/*
 * Audacity: A Digital Audio Editor
 */

#pragma once

#include <memory>
#include "effects/effects_base/ieffectparametersprovider.h"

namespace au::effects {

class Effect;
struct ParameterInfo;

/**
 * @brief VampParameterExtractor - Extracts parameter information for auto-generated UI
 * 
 * Responsible for:
 * - Converting VAMP plugin parameters to ParameterInfo format
 * - Handling parameter ranges, types, and units
 * - Supporting auto-generated effect UIs
 */
class VampParameterExtractor : public IParameterExtractor
{
public:
    VampParameterExtractor();
    ~VampParameterExtractor();

    // TODO: Implement extractParameters() to convert VAMP parameters
    // ParameterInfoList extractParameters(Effect* effect) const override;

private:
    // TODO: Add helper methods for parameter conversion
};

}
