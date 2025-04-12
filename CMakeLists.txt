cmake_minimum_required(VERSION 3.29)
project(M2OEP_sgorgees_tbayliss)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(M2OEP_sgorgees_tbayliss
    Bouquet.cpp
    Bouquet.h
    Flower.cpp
    Flower.h
    main.cpp
    Tulip.cpp
    Tulip.h)

#add_executable(M2OEP_sgorgees_tbayliss
#        Bouquet.cpp
#        Bouquet.h
#        Flower.cpp
#        Flower.h
#        Tulip.cpp
#        Tulip.h
#        testing.cpp)
