# VAMP Effects Migration to Audacity 4

## Progress Status

### ✅ Phase 1: Module Structure (COMPLETED)
- [x] Create `vampeffectsmodule.h` header
- [x] Create `vampeffectsmodule.cpp` implementation
- [x] Create `vamp.qrc` resource file
- [x] Create `CMakeLists.txt` build configuration
- [x] Create directory structure placeholders

### ⏳ Phase 2: Core Components (IN PROGRESS)
- [ ] Implement `VampEffectLoader`
- [ ] Implement `VampPluginsScanner`
- [ ] Implement `VampPluginsMetaReader`
- [ ] Implement `VampParameterExtractor`
- [ ] Implement `VampViewLauncher`

### 📋 Phase 3: Legacy Code Adaptation (PENDING)
- [ ] Adapt `VampEffect.h` to new architecture
- [ ] Adapt `VampEffect.cpp` to new architecture
- [ ] Remove/refactor `LoadVamp.h/cpp`
- [ ] Update all includes and imports

### 🧪 Phase 4: Integration & Testing (PENDING)
- [ ] Register module in main CMakeLists.txt
- [ ] Add resources to build configuration
- [ ] Compile with `USE_VAMP=ON`
- [ ] Test plugin discovery
- [ ] Test parameter extraction
- [ ] Test audio processing

## Architecture Overview

```
VampEffectsModule (IModuleSetup)
├── VampEffectLoader (IEffectLoader)
├── VampPluginsScanner (IAudioPluginsScanner)
├── VampPluginsMetaReader (IAudioPluginMetaReader)
└── VampParameterExtractor (IParameterExtractor)

VampEffectsContext (IContextSetup)
└── VampViewLauncher (IEffectViewLauncher)
```

## Key Design Decisions

1. **Module Pattern**: Using Muse Framework's `IModuleSetup` instead of old `PluginProvider`
2. **Dependency Injection**: All components registered via IoC container
3. **Separation of Concerns**: 
   - Scanner: discovers plugins
   - MetaReader: reads metadata
   - Loader: instantiates effects
   - ParameterExtractor: extracts UI parameters
4. **UI Separation**: View launcher deferred to Phase 3

## API Mappings: Au3 → Audacity 4

| Au3 | Audacity 4 | Status |
|-----|-----------|--------|
| `PluginProvider` | `IModuleSetup` | ✅ Implemented |
| `StatefulEffect` | `Effect` (via loader) | ⏳ Pending |
| `StatefulEffectUIServices` | `IEffectViewLauncher` | ⏳ Pending |
| `EffectUIServices::DoMessageBox` | Modern dialogs | ⏳ Pending |
| `inputTracks()` | `EffectSettingsAccess` | ⏳ Pending |
| `mProjectRate` | `EffectSettings` | ⏳ Pending |
| `mPlugin->getParameter()` | `ParameterInfo` | ⏳ Pending |

## Testing Checklist

- [ ] Compilation without errors (USE_VAMP=ON)
- [ ] Module loads in Audacity startup
- [ ] Plugin discovery works
- [ ] Plugin metadata extracted correctly
- [ ] Parameters detected and formatted
- [ ] Effect processes audio (legacy VampEffect still works)
- [ ] UI displays parameters
- [ ] Presets save/load
- [ ] Real-time effect capability (if applicable)

## Known Issues & TODOs

1. **Forward Declarations**: Internal classes need implementation
2. **Parameter Extraction**: Need to map VAMP parameters to ParameterInfo
3. **Audio Processing**: Need to adapt legacy audio handling
4. **UI Generation**: Need QML components for effect UI
5. **Error Handling**: Add proper error messages and logging

## Next Steps

1. Create `VampEffectLoader` - foundational for plugin loading
2. Create `VampPluginsScanner` - discovers available plugins
3. Create `VampPluginsMetaReader` - reads plugin information
4. Integrate with Audacity build system
5. Test compilation and plugin discovery
