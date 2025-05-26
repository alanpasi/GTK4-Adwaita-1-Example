cmake_minimum_required(VERSION 3.31)

project(Adwaita VERSION 1.0 LANGUAGES C) # Nome do projeto

# Define o nome do executável explicitamente
set(EXECUTABLE_NAME "adwaita-test") # Nome do executável

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

# Define um nome de saída diferente para todos os executáveis do projeto
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Encontra o pacote ADWAITA
find_package(PkgConfig REQUIRED)
pkg_check_modules(ADWAITA REQUIRED libadwaita-1)

# Adiciona a biblioteca math (m)
find_library(MATH_LIB m)
if(NOT MATH_LIB)
    message(FATAL_ERROR "Biblioteca math não encontrada!")
endif()

# Adiciona o executável usando o nome customizado
add_executable(${EXECUTABLE_NAME} adwaita-test.c)

# Linka as bibliotecas e inclui diretórios para o TARGET específico
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${ADWAITA_INCLUDE_DIRS})
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${ADWAITA_LIBRARIES} ${MATH_LIB})

# Opcional: Regras de instalação (se estiver usando)
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
