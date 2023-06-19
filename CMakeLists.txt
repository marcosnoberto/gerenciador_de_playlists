cmake_minimum_required(VERSION 3.5)

# set( CMAKE_CXX_COMPILER "/pathto/g++" )
# set( CMAKE_C_COMPILER "/pathto/gcc" )

# Nome do seu projeto
project(MeuProjeto)

# flags de compilação, vc pode colocar aqui
# o addres sanitizer por exemplo
# set ( CMAKE_CXX_FLAGS "-Wall" )

include_directories( include )

# Adiciona a flag de depuração "-g" ao compilar com o GCC ou Clang
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
endif()

# Adiciona a flag de depuração "/DEBUG" ao compilar com o MSVC
if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /DEBUG")
endif()

# Adiciona os arquivos fonte ao executável
add_executable(MeuProjeto src/main.cpp
                          src/Musica.cpp
                          src/Playlist.cpp)

# Configuração do Doxygen
# find_package(Doxygen)
# if (DOXYGEN_FOUND)
#     set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
#     set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doc/html/)
#     configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#     message("Doxygen build started")
# else()
#     message("Doxygen need to be installed to generate the documentation")
# endif()

# # Alvo para gerar documentação com o Doxygen
# if (DOXYGEN_FOUND)
#     add_custom_target(doc_doxygen ALL
#         COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#         COMMENT "Generating API documentation with Doxygen"
#         VERBATIM
#     )
# endif()

# # # Configurando o Doxygen
# find_package(Doxygen REQUIRED)

# set(DOXYGEN_INPUT_DIR ${CMAKE_SOURCE_DIR})
# set(DOXYGEN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/doc/)

# # set(DOXYGEN_PROJECT_NAME "MeuProjeto")
# # set(DOXYGEN_PROJECT_VERSION "1.0")

# # Lista de arquivos a serem documentados
# set(DOXYGEN_INPUT_LIST
#     ${CMAKE_SOURCE_DIR}/src/main.cpp
#     ${CMAKE_SOURCE_DIR}/src/Musica.cpp 
#     ${CMAKE_SOURCE_DIR}/src/Playlist.cpp)


# set(DOXYGEN_EXAMPLE_PATH ${CMAKE_SOURCE_DIR}/examples)
# set(DOXYGEN_IMAGE_PATH ${CMAKE_SOURCE_DIR}/docs/images)

# # Configurações do Doxygen
# # set(DOXYGEN_GENERATE_HTML YES)
# # set(DOXYGEN_GENERATE_MAN NO)
# # set(DOXYGEN_EXTRACT_PRIVATE YES)
# # set(DOXYGEN_EXTRACT_STATIC YES)
# # set(DOXYGEN_HIDE_FRIEND_COMPOUNDS YES)
# # set(DOXYGEN_HTML_DYNAMIC_SECTIONS YES)
# # set(DOXYGEN_GENERATE_TREEVIEW YES)
# # set(DOXYGEN_TREEVIEW_WIDTH 250)

# # Gerando documentação com Doxygen
# doxygen_add_docs(docs ${DOXYGEN_INPUT_LIST}
#                  COMMENT "Gerando documentação doxygen")

