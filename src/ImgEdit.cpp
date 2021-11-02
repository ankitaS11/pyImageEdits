#include<iostream>
#include<fstream>
#include<sstream>
#include "../include/ImgEdit.hpp"

using namespace std;

bool ImageEdits::is_image_path_valid() {
    return (!this->image ? false : true); 
}

void ImageEdits::read_image() {
    /* This loads image only once */
    this->image.open(this->image_path);
    this->image >> this->type;
    this->image >> this->width;
    this->image >> this->height;
    this->image >> this->RGB;
    /* This checks if an image path is valid or not */
    if (ImageEdits::is_image_path_valid() == false)
        cout << "Image not read properly! \n";
}

void ImageEdits::apply_nofilterimg() {
    if (ImageEdits::is_image_path_valid() == true) {
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
            nofilter_image << r << " " << g << " " << b << endl;
        }
        nofilter_image.close();
    }
    else {
    cout << "Image not read properly! \n";
    }
}
    
void ImageEdits::apply_bluefilterimg() {
    if (ImageEdits::is_image_path_valid() == true) {
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
            b = (b+50)>255 ? b=255 : b+=50;
            // Saving the applied filter in bluefilter image 
            bluefilter_image << r << " " << g << " " << b << endl;
        }
        bluefilter_image.close();
    }
    else {
        cout << "Input Image not read properly! \n";
    }
}

void ImageEdits::apply_greenfilterimg() {
    if (ImageEdits::is_image_path_valid() == true) {
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
            // Increasing the intensity of green pixels
            g = (g+50)>255 ? g=255 : g+=50;
            // Saving the applied filter in greenfilter image 
            greenfilter_image << r << " " << g << " " << b << endl;
        }
        greenfilter_image.close();
    }
    else {
        cout << "Image not read properly! \n";
    }
}

void ImageEdits::apply_redfilterimg() {
    if (ImageEdits::is_image_path_valid() == true) {
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
            // Increasing the intensity of red pixels
            r = (r+50)>255 ? r=255 : r+=50;
            // Saving the applied filter in redfilter image 
            redfilter_image << r << " " << g << " " << b <<endl;
        }
        redfilter_image.close();
    }
    else {
        cout << "Image not read properly! \n";
    }
}

void ImageEdits::apply_grayscaleimg() {
    if (ImageEdits::is_image_path_valid() == true) {
        ofstream grayscale_image;
        grayscale_image.open("grayscale_image.ppm");
        grayscale_image << type << endl;
        grayscale_image << width << " " << height << endl;
        grayscale_image << RGB << endl;
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
            // Converting to grayscale image
            int x = (r + g + b)/3;
            r = g = b = x;   
            // Saving the image in new file named grayscale_image.
            grayscale_image << r << " " << g << " " << b << endl;
        }
        grayscale_image.close();
    }
    else {
        cout << "Image not read properly! \n";
    }
}

void ImageEdits::increase_brightness(int amount) {
    if (ImageEdits::is_image_path_valid() == true) {
        ofstream brightened_image;
        brightened_image.open("brightened_image.ppm");
        brightened_image << type << endl;
        brightened_image << width << " " << height << endl;
        brightened_image << RGB << endl;
        // cout<< type << width << height << RGB <<endl;
        string image_path = "", type = "", width = "", height = "", RGB = "";
        string red = "", green = "", blue = "";
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
            // Increasing the brightness by increasing the value of pixels
            r = (r + r*(amount/100))<255 ? r+(r*(amount/100)) : 255;
            g = (g + g*(amount/100))<255 ? g+(g*(amount/100)) : 255;
            b = (b + b*(amount/100))<255 ? b+(b*(amount/100)) : 255;
            // Saving the image in a new file named brightened_image 
            brightened_image << r << " " << g << " " << b << endl;
        }
        brightened_image.close();
    }
    else {
        cout << "Image not read properly! \n";
    }
}

void ImageEdits::decrease_brightness(int amount) {
    if (ImageEdits::is_image_path_valid() == true) {
        ofstream darkened_image;
        darkened_image.open("darkned_image.ppm");
        darkened_image << type << endl;
        darkened_image << width << " " << height << endl;
        darkened_image << RGB << endl;
        // cout<< type << width << height << RGB <<endl;
        string image_path = "", type = "", width = "", height = "", RGB = "";
        string red = "", green = "", blue = "";
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
            // Decreasing the brightness by reducing the value of pixels
            r = (r - amount)>0 ? r-amount : 0;
            g = (g - amount)>0 ? g-amount : 0;
            b = (b - amount)>0 ? b-amount : 0;
            // Saving the image in a new file named darkened_image
            darkened_image << r << " " << g << " " << b << endl;
        }
        darkened_image.close();
    } 
    else {
        cout << "Image not read properly! \n";
    }
}

void ImageEdits::adjust_brightness() {
    int amount;
    cout << "Enter the amount by which brightness needs to be increased(+ve)/decreased(-ve) >> ";
    cin >> amount;
    if (amount < 0) {
        this->ImageEdits::decrease_brightness(-1 * amount);
    }
    else {
        this->ImageEdits::increase_brightness(amount);
    }
}



