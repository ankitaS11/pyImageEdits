#include<iostream>
#include <pybind11/pybind11.h>
#include "include/ImgEdit.hpp"

namespace py = pybind11;
using namespace std;

PYBIND11_MODULE(pyImageEdits, m) {
    m.doc() = "A sample add function";

    py::class_<ImageEdits>(m, "pyImageEdits")
        .def(py::init<std::string>())
        .def("read_image", &ImageEdits::read_image)
        .def("get_image_path", &ImageEdits::get_image_path)
        .def("set_image_path", &ImageEdits::set_image_path)
        .def("apply_nofilterimg", &ImageEdits::apply_nofilterimg)
        .def("apply_bluefilterimg", &ImageEdits::apply_bluefilterimg)
        .def("apply_greenfilterimg", &ImageEdits::apply_greenfilterimg)
        .def("apply_redfilterimg", &ImageEdits::apply_redfilterimg)
        .def("apply_grayscaleimg", &ImageEdits::apply_grayscaleimg)
        .def("adjust_brightness", &ImageEdits::adjust_brightness);
}