cmake_minimum_required(VERSION 3.19)
project(knapsack)

set(CMAKE_CXX_STANDARD 14)

add_executable(knapsack
    main.cpp
    src/Bag.cpp
    src/Item.cpp
    src/Knapsack.cpp
        src/csv.cpp)
