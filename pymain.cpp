#include<iostream>

#include <pybind11/pybind11.h>
#include "img.cpp"
#include "main.hpp"

namespace py = pybind11;
using namespace std;

int main() {
    
        int choice;
        //  Image Path is provided here
        ImageEdits imged ("monument.ppm");
}

PYBIND11_MODULE(pyImageEdits, m) {
    m.doc() = "A sample add function";

    py::class_<ImageEdits>(m, "ImageEdits")
        .def(py::init<std::string>())
        .def("read_image", &ImageEdits::read_image)
        .def("apply_nofilterimg", &ImageEdits::apply_nofilterimg)
        .def("apply_bluefilterimg", &ImageEdits::apply_bluefilterimg)
        .def("apply_greenfilterimg", &ImageEdits::apply_greenfilterimg)
        .def("apply_redfilterimg", &ImageEdits::apply_redfilterimg);
