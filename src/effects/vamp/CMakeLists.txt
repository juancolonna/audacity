# Audacity VAMP Effects Module

set(VAMP_MODULE_SOURCES
    vampeffectsmodule.cpp
)

set(VAMP_MODULE_HEADERS
    vampeffectsmodule.h
)

if(USE_VAMP)
    add_library(effects_vamp OBJECT
        ${VAMP_MODULE_SOURCES}
        ${VAMP_MODULE_HEADERS}
        vamp.qrc
    )

    target_include_directories(effects_vamp PRIVATE
        ${VAMP_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}
    )

    target_link_libraries(effects_vamp PRIVATE
        vamp-hostsdk
        effects_base
        framework
    )

    set_target_properties(effects_vamp PROPERTIES
        FOLDER "effects"
        AUTOMOC ON
    )
    
    # Link to main Audacity target
    target_link_libraries(audacity PRIVATE effects_vamp)
endif()
