#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

class ImageEdits {

public:
    ~ImageEdits();
    ImageEdits() {}
    struct RGB 
    {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    };

    void set_width(int width) {
        this->width = width;
    }
    
    void set_height(int height) {
        this->height = height;
    }
    void read_image(string file_name);
    void write_image(string file_name);
    void delete_image();
    void horizontal_flip();
    void vertical_flip();
    void resize(int height, int weight);
    void applyfilter_red();
    void applyfilter_green();
    void applyfilter_blue();
    void applyfilter_grayscale();
    void adjust_brightness(int amount);
    RGB **image = nullptr;

private:
    int width = 0;
    int height = 0;
    int color = 0;
    string type = "P3";
};

#endif