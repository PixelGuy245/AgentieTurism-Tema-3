cmake_minimum_required(VERSION 3.10)

project(AgentieTurism)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(AgentieTurism 
    main.cpp
    Turist.cpp
    Serviciu.cpp
    Cazare.cpp
    Excursie.cpp
    Zbor.cpp
    Tranzactie.cpp
)