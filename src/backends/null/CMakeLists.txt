
include(ECMQtDeclareLoggingCategory)

set( NullBackend_SRCS 
 nullbackend.cpp  
 nulldocumentsettings.cpp
 nullgenerator.cpp
)

ecm_qt_declare_logging_category(NullBackend_SRCS
                                HEADER cirkuitnullbackend_debug.h
                                IDENTIFIER CIRKUIT_DEBUG
                                CATEGORY_NAME org.kde.cirkuitnullbackend)

add_library(cirkuit_nullbackend MODULE ${NullBackend_SRCS} )
kcoreaddons_desktop_to_json( cirkuit_nullbackend nullbackend.desktop
                             SERVICE_TYPES cirkuit_backend.desktop
)
target_link_libraries( cirkuit_nullbackend  cirkuitlibs)

install(TARGETS cirkuit_nullbackend DESTINATION ${PLUGIN_INSTALL_DIR})
