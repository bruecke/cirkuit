add_subdirectory (templates)

include(ECMQtDeclareLoggingCategory)

ecm_qt_declare_logging_category(TikzBackend_SRCS
                                HEADER cirkuit_tikzbackend_debug.h
                                IDENTIFIER CIRKUIT_DEBUG
                                CATEGORY_NAME org.kde.cirkuit_tikzbackend)
                                
kconfig_add_kcfg_files(TikzBackend_SRCS GENERATE_MOC settings.kcfgc)
install(FILES tikzbackend.kcfg DESTINATION ${KCFG_INSTALL_DIR})

ki18n_wrap_ui(TikzBackend_SRCS settings.ui)

add_library(cirkuit_tikzbackend
 MODULE 
 ${TikzBackend_SRCS}
 tikzbackend.cpp
 tikzdocumentsettings.cpp
 tikzgenerator.cpp)
kcoreaddons_desktop_to_json( cirkuit_tikzbackend tikzbackend.desktop
                             SERVICE_TYPES cirkuit_backend.desktop
)
target_link_libraries( cirkuit_tikzbackend  KF5::KIOCore cirkuitlibs)

install(TARGETS cirkuit_tikzbackend DESTINATION ${PLUGIN_INSTALL_DIR})
