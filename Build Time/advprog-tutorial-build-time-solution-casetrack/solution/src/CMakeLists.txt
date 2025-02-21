cmake_minimum_required(VERSION 3.8)
project(caseTrack VERSION 0.3.0 LANGUAGES CXX)
add_executable(caseTrack caseTrack.cpp helper.cpp)
target_compile_features(caseTrack PUBLIC cxx_std_17)
