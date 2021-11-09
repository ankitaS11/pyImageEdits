#include<iostream>
#include<fstream>
#include<sstream>
#include "../include/ImgEdit.hpp"

using namespace std;

ImageEdits::~ImageEdits() {
    delete_image();
}

void ImageEdits::read_image(string file_name) {
    ifstream input(file_name, ios::binary);
    if (input) {
        input >> type >> width >> height >> color;
        if (type == "P3") {
            image = new RGB*[height];
            for (int i=0; i<height; i++) {
                image[i] = new RGB[width];
                for (int j=0; j<width; j++) {
                    int r, g, b;
                    input >> r >> g >> b;
                    image[i][j].red = r;
                    image[i][j].green = g;
                    image[i][j].blue = b;
                }
            }
            input.close();
        }
    }
    else
        raise_warning_message();
}

void ImageEdits::write_image(string file_name) {
    if (image != nullptr) {
        ofstream output(file_name, ios::binary);
        if (output.is_open()) {
            output << type << endl;
            output << width << " " << height << endl;
            output << 255 << endl;

            if (type == "P3") {
                for (int i=0; i<height; i++) {
                    for (int j=0; j<width; j++) {
                        output << (int) image[i][j].red << " ";
                        output << (int) image[i][j].green << " ";
                        output << (int) image[i][j].blue << " ";
                    }
                }
            }
            output.close();
        }
    }
    else
        raise_warning_message();
}

void ImageEdits::horizontal_flip() {
    if (image != nullptr) {
        for (int i=0; i<height; i++)
            for(int j=0; j<width/2; j++)
                swap(image[i][j], image[i][width-1-j]);
    }
    else
        raise_warning_message();
}

void ImageEdits::vertical_flip() {
    if (image != nullptr) {
        for (int i=0; i<height/2; i++)
            for (int j=0; j<width; j++) 
                swap(image[i][j], image[height-1-i][j]);
    }
    else
        raise_warning_message();
}

void ImageEdits::resize(int height, int width) {
    if (image != nullptr) {
        RGB **image_resized = new RGB*[height];
        for (int i=0; i<height; i++) {
            image_resized[i] = new RGB[width];
            for (int j=0; j<width; j++) {
                image_resized[i][j].red = 255;
                image_resized[i][j].green = 255;
                image_resized[i][j].blue = 255;
            }
        }

        for (int i = 0; i < height; i++) 
            for (int j=0; j<width; j++)
                image_resized[i][j] = image[i*this->height/height][j*this->width/width];
        delete_image();
        image = image_resized;
        this -> height = height;
        this -> width = width;
    }
    else
        raise_warning_message();
}

void ImageEdits::delete_image() {
    if(image != nullptr) {
        for (int i=0; i< height; i++)
            delete image[i];

        delete image;
    }
}

void ImageEdits::applyfilter_red() {
    if (image != nullptr) {
        for (int i=0; i<height; i++) 
            for (int j=0; j<width; j++)
                image[i][j].red = (image[i][j].red+50)>255 ? 255 : image[i][j].red+=50;
    }  
    else
        raise_warning_message();
}

void ImageEdits::applyfilter_green() {
    if (image != nullptr) {
        for (int i=0; i<height; i++)
            for (int j=0; j<width; j++)
                image[i][j].green = (image[i][j].green+50)>255 ? 255 : image[i][j].green+=50;
    }
    else
        raise_warning_message();
}

void ImageEdits::applyfilter_blue() {
    if (image != nullptr) {
        for (int i=0; i<height; i++) 
            for (int j=0; j<width; j++)
                image[i][j].blue = (image[i][j].blue+50)>255 ? 255 : image[i][j].blue+=50;
    } 
    else
        raise_warning_message();
}

void ImageEdits::applyfilter_grayscale() {
    if (image != nullptr) {
        const float r = 0.299f;
        const float g = 0.587f;
        const float b = 0.114f;
        float grayscaleValue;

        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                grayscaleValue = image[i][j].red*r + image[i][j].green*g + image[i][j].blue*b;
                image[i][j].red = grayscaleValue;
                image[i][j].green = grayscaleValue;
                image[i][j].blue = grayscaleValue;
            }
        }
    }
    else
        raise_warning_message();
}

void ImageEdits::adjust_brightness(int amount) {
    if (image != nullptr) {
        if (amount > 0) {
            for (int i=0; i<height; i++) {
                for (int j=0; j<width; j++) {
                    image[i][j].red = (image[i][j].red+image[i][j].red*(amount/100))<255 ? image[i][j].red+image[i][j].red*(amount/100) : 255;
                    image[i][j].green = (image[i][j].green+image[i][j].green*(amount/100))<255 ? image[i][j].green+image[i][j].green*(amount/100) : 255;
                    image[i][j].blue = (image[i][j].blue+image[i][j].blue*(amount/100))<255 ? image[i][j].blue+image[i][j].blue*(amount/100) : 255;
                }
            }   
        }
        else 
        {
            for (int i=0; i<height; i++) {
                for (int j=0; j<width; j++) {
                    image[i][j].red = (image[i][j].red+amount)>0 ? image[i][j].red+amount : 0;
                    image[i][j].green = (image[i][j].green+amount)>0 ? image[i][j].green+amount : 0;
                    image[i][j].blue = (image[i][j].blue+amount)>0 ? image[i][j].blue+amount : 0;

                }
            }   
        }
    }
    else
        raise_warning_message();
}

void raise_warning_message() {
    cout << "Image not read properly \n";
}

