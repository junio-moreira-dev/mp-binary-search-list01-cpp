cmake_minimum_required(VERSION 4.2)
project(mp_binary_search_list01_cpp)

set(CMAKE_CXX_STANDARD 20)

#add_executable(mp_binary_search_list01_cpp main.cpp
#        src/Exer01_HelpMadruga.cpp
#        src/Exer02_SolarPanelsTransport.cpp)

# Declara o primeiro exercício como um executável independente
add_executable(Exer01_HelpMadruga src/Exer01_HelpMadruga.cpp)

# Declara o segundo exercício como um executável independente
add_executable(Exer02_SolarPanelsTransport src/Exer02_SolarPanelsTransport.cpp)


# Se ainda mantiver um main.cpp na raiz, declare-o aqui:
add_executable(Main main.cpp)
