#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>

using namespace std;

class ImageEdits {
private:
    string image_path = "", type = "", width = "", height = "", RGB = "";
    string red = "", green = "", blue = "";
    ifstream image;
public:
    ImageEdits(string image_path) {
        this->image_path = image_path;
    }
    
    void read_image();
    bool is_image_path_valid();

    string get_image_path() {
        return this->image_path;
    }

    void set_image_path(string new_path) {
        this -> image_path = new_path;
    }
    
    void apply_nofilterimg();
    void apply_bluefilterimg();
    void apply_greenfilterimg();
    void apply_redfilterimg();
    void apply_grayscaleimg();
    void adjust_brightness();
    void increase_brightness(int amount);
    void decrease_brightness(int amount);
};

#endif