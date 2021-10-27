#include<iostream>
#include<fstream>
#include<sstream>

#include "../include/ImgEdit.hpp"

using namespace std;
    
void ImageEdits::read_image() {
    /* This loads image only once */
    this->image.open(this->image_path);
    this->image >> this->type;
    this->image >> this->width;
    this->image >> this->height;
    this->image >> this->RGB;

    // You can use this: check_if_image_empty();
}

// bool check_if_image_empty() {
//     if (this->width == 0 || this->height == 0) return true;
//     return false;
// }

// void ImageEdits::change_contrast(int amount) {
//     if (amount < 0) {
//         this->decrease_contrast(-1 * amount);
//     } else {
//         this->increase_contrast(amount);
//     }
// }

void ImageEdits::apply_nofilterimg() {
    ofstream nofilter_image;
    nofilter_image.open("nofilter_image.ppm");
    nofilter_image << type << endl;
    nofilter_image << width << " " << height << endl;
    nofilter_image << RGB << endl;
    // cout<< type << width << height << RGB <<endl;
    while(!image.eof()) {
        image >> red;
        image >> green;
        image >> blue;
        // Converting string to int type
        int r = 0, g = 0, b = 0;
        stringstream redstream(red);
        stringstream greenstream(green);
        stringstream bluestream(blue);
        redstream >> r;
        greenstream >> g;
        bluestream >> b;
        // Saving the original image i.e. without filter  
        nofilter_image<< r <<" " << g <<" "<< b <<endl;
    }
    nofilter_image.close();
}
    
void ImageEdits::apply_bluefilterimg() {
        ofstream bluefilter_image;
        bluefilter_image.open("bluefilter_image.ppm");
        bluefilter_image << type << endl;
        bluefilter_image << width << " " << height << endl;
        bluefilter_image << RGB << endl;
        // cout<< type << width << height << RGB <<endl;
        while(!image.eof()) {
            image >> red;
            image >> green;
            image >> blue;
            // Converting string to int type
            int r = 0, g = 0, b = 0;
            stringstream redstream(red);
            stringstream greenstream(green);
            stringstream bluestream(blue);
            redstream >> r;
            greenstream >> g;
            bluestream >> b;
            // Increasing the intensity of blue Pixels
            if(b + 50 > 255 ) {
                b = 255;
            }
            else {
                b += 50;
            }
            // Saving the applied filter in bluefilter image 
            bluefilter_image<< r <<" " << g <<" "<< b <<endl;
        }
        bluefilter_image.close();
    }

void ImageEdits::apply_greenfilterimg() {
    ofstream greenfilter_image;
    greenfilter_image.open("greenfilter_image.ppm");
    greenfilter_image << type << endl;
    greenfilter_image << width << " " << height << endl;
    greenfilter_image << RGB << endl;
    // cout<< type << width << height << RGB <<endl;
    while(!image.eof()) {
        image >> red;
        image >> green;
        image >> blue;
        // Converting string to int type
        int r = 0, g = 0, b = 0;
        stringstream redstream(red);
        stringstream greenstream(green);
        stringstream bluestream(blue);
        redstream >> r;
        greenstream >> g;
        bluestream >> b;
        // Increasing the intensity of blue Pixels
        if(g + 50 > 255 ) {
            g = 255;
        }
        else {
            g += 50;
        }
        // Saving the applied filter in bluefilter image 
        greenfilter_image<< r <<" " << g <<" "<< b <<endl;
    }
    greenfilter_image.close();
}

void ImageEdits::apply_redfilterimg() {
    ofstream redfilter_image;
    redfilter_image.open("redfilter_image.ppm");
    redfilter_image << type << endl;
    redfilter_image << width << " " << height << endl;
    redfilter_image << RGB << endl;
    // cout<< type << width << height << RGB <<endl;
    while(!image.eof()) {
        image >> red;
        image >> green;
        image >> blue;
        // Converting string to int type
        int r = 0, g = 0, b = 0;
        stringstream redstream(red);
        stringstream greenstream(green);
        stringstream bluestream(blue);
        redstream >> r;
        greenstream >> g;
        bluestream >> b;
        // Increasing the intensity of blue Pixels
        if(r + 50 > 255 ) {
            r = 255;
        }
        else {
            r += 50;
        }
        // Saving the applied filter in bluefilter image 
        redfilter_image<< r <<" " << g <<" "<< b <<endl;
    }
    redfilter_image.close();
}