cmake_minimum_required(VERSION 4.0)
project(OMImageWriter 
                  VERSION 2.7.0 
                  LANGUAGES CXX
                  DESCRIPTION "Tool for creating bootable Linux installation USB flash drives"                  
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
                  Core
                  Widgets
                  Svg
                  Linguist
)

qt_standard_project_setup(I18N_TRANSLATED_LANGUAGES ast bg ca cs de
                                    de_DE es es_AR fi fr fr_FR hi_IN
                                    hr_HR hu id_ID it ja nl_NL pl pt_BR
                                    pt_PT ro_RO ru ru_RU tr_TR
                                    
)

add_subdirectory(src)

