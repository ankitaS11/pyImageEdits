#include<iostream>
#include <pybind11/pybind11.h>
#include "include/ImgEdit.hpp"

namespace py = pybind11;
using namespace std;

PYBIND11_MODULE(pyImageEdits, m) {
    m.doc() = "A sample add function";

    py::class_<ImageEdits>(m, "ImageEdits")
        .def(py::init())
        .def("read_image", &ImageEdits::read_image)
        .def("write_image", &ImageEdits::write_image)
        .def("horizontal_flip", &ImageEdits::horizontal_flip)
        .def("vertical_flip", &ImageEdits::vertical_flip)
        .def("resize", &ImageEdits::resize)
        .def("set_width", &ImageEdits::set_width)
        .def("set_height", &ImageEdits::set_height)
        .def("applyfilter_red", &ImageEdits::applyfilter_red)
        .def("applyfilter_green", &ImageEdits::applyfilter_green)
        .def("applyfilter_blue", &ImageEdits::applyfilter_blue)
        .def("applyfilter_grayscale", &ImageEdits::applyfilter_grayscale)
        .def("adjust_brightness", &ImageEdits::adjust_brightness);
        
}