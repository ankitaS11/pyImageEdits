cmake_minimum_required(VERSION 3.11)

project(pybind_check)
add_subdirectory(pybind11)
pybind11_add_module(pyImageEdits pymain.cpp src/ImgEdit.cpp)