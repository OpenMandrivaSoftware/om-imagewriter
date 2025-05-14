set(OMI_HEADERS common.h
                externalprogressbar.h
                imagewriter.h
                mainapplication.h
                maindialog.h
                physicaldevice.h
                platform.h
                usbdevice.h
                usbdevicemonitor.h
)

set(OMI_SOURCES common.cpp
                imagewriter.cpp
                main.cpp
                mainapplication.cpp
                maindialog.cpp
                physicaldevice.cpp
                maindialog.ui
)

qt_add_resources(qt_resources OMImageWriter.qrc)

if(WIN32)
  set(OMI_HEADERS ${OMI_HEADERS}
                  win32/usbdevicemonitor_win_p.h
  )

  set(OMI_SOURCES ${OMI_SOURCES}
                  win32/externalprogressbar_win.cpp
                  win32/platform_win.cpp
                  win32/usbdevicemonitor_win.cpp
  )

  qt_add_resources(qt_resources_win 
      PREFIX "win32/"
      FILES OMImageWriter.manifest
            OMImageWriter.rc
            icon-open.ico
            icon-refresh.ico
            icon-om.ico
  )

  add_compile_options(-Zc:strictStrings)
endif()

if(APPLE)
  set(OMI_HEADERS ${OMI_HEADERS}
                  usbdevicemonitor_mac_p.h
  )
  
  set(OMI_SOURCES ${OMI_SOURCES}
                  macOSX/externalprogressbar_mac.mm
                  macOSX/platform_mac.mm
                  macOSX/usbdevicemonitor_mac.mm
  )

  qt_add_resources(qt_resources_macOSX
      PREFIX "macOSX/"
      FILES icon-om.icns
            Info.plist
  )
endif()

if(UNIX AND NOT APPLE)
  set(OMI_HEADERS ${OMI_HEADERS}
                  linux/platform_lin_suprogram.h
                  linux/usbdevicemonitor_lin_p.h
  )

  set(OMI_SOURCES ${OMI_SOURCES}
                  linux/externalprogressbar_lin.cpp
                  linux/platform_lin.cpp
                  linux/platform_lin_suprogram.cpp
                  linux/usbdevicemonitor_lin.cpp
  )
  
  install(FILES ${CMAKE_SOURCE_DIR}/doc/DEPLOY.html
                ${CMAKE_SOURCE_DIR}/doc/README.html
          DESTINATION
            share/doc/om-imagewriter/
  )

  install(FILES ${CMAKE_SOURCE_DIR}/doc/LICENSE.html
          DESTINATION
            share/licenses/om-imagewriter/
  )

  install(FILES linux/org.openmandriva.pkexec.om-imagewriter.policy
          DESTINATION
            share/polkit-1/actions/
  )

  install(FILES ${CMAKE_SOURCE_DIR}/img/icon-om.svg
        DESTINATION 
          share/icons/hicolor/scalable/apps
        RENAME
          om-imagewriter.svg
  )
endif()

qt_add_executable(om-imagewriter 
                  ${OMI_SOURCES}
                  ${OMI_HEADERS}
                  ${qt_resources}
                  ${qt_resources_win}
                  ${qt_resources_macOSX}
)

target_link_libraries(om-imagewriter PUBLIC 
                        Qt6::Core
                        Qt6::Widgets
                        Qt6::Svg
                        Qt6::Linguist
)

set_target_properties(om-imagewriter PROPERTIES
                        WIN32_EXECUTABLE ON
                        MACOSX_BUNDLE ON
)

qt_add_translations(om-imagewriter
                      TS_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lang
)

install(TARGETS om-imagewriter DESTINATION bin)

