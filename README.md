# pyImageEdits

```pyImageEdits``` allows you to play with `.ppm` images of type `P3` by providing the following features-
1. ```read_image('imagepath.ppm')```: Reads image from the path given as an argument.
2. `resize(width, height)`: Resizes the image as per width and height provided in the argument.
3. `horizontal_flip()`: Flips the image horizontally.
4. `vertical_flip()`: Flips the image vertically.
5. `applyfilter_red()`: Applies red filter to the image.
6. `applyfilter_blue()`: Applies blue filter to the image.
7. `applyfilter_green()`: Applies green filter to the image.
8. `applyfilter_grayscale()`: Applies grayscale to the image.
9. `adjust_brightness(amt)`: Adjusts brightness as per amt ( to decrease brightness amt < 0 ).
10. `write_image('name.ppm')`: Save the image with the same name provided in the argument.

### Usage 
``` 
git clone https://github.com/ankitaS11/pyImageEdits.git
cd PyImageEdits
git clone https://github.com/pybind/pybind11.git
mkdir build && cd build
cmake ..
make
```
Insert `.ppm` image of type "P3" [(Some `.ppm` images can be found here)](https://github.com/ferrabacus/p3images) in the build directory to use the `pyImageEdits` library.
Open python shell in the same directory and import `pyImageEdits`:
```
python3
>>> import pyImageEdits
>>> x = pyImageEdits.ImageEdits("monument.ppm")
>>> x.read_image("provide_image_path_to_read")     # To read the image
>>> x.resize(provide_width, provide_height)        # To resize the image
>>> x.horizontal_flip()                            # To flip image horizontally
>>> x.vertical_flip()                              # To flip image vertically
>>> x.applyfilter_red()                            # To apply red filter
>>> x.applyfilter_green()                          # To apply green filter
>>> x.applyfilter_blue()                           # To apply blue filter
>>> x.applyfilter_grayscale()                      # To apply grayscale filter
>>> x.set_image_path()                             # To change the image path
>>> x.apply_bluefilterimg()                        # To apply blue filter
>>> x.apply_redfilterimg()                         # To apply red filter
>>> x.apply_greenfilterimg()                       # To apply green filter
>>> x.apply_nofilterimg()                          # To get an image without applying filter
>>> x.apply_grayscaleimg()                         # To get a grayscale image
>>> x.adjust_brightness()                          # To adjust brightness of an image
>>> x.write_image("filename_to_write the image")   # To save the image with the name given in the argument
```
### Structure
```
|-- include
  |-- ImgEdit.hpp
|-- src
  |-- ImgEdit.cpp
|-- pymain.cpp
|-- CMakeLists.txt
|-- sample_output_images
|-- README.md
|-- a.out
```
### Sample Output Images 
<p align = "center">
<img align="center" src="https://github.com/ankitaS11/pyImageEdits/blob/main/sample_output_images/0001.jpg">
</p>
<p align = "center">
<img align="center" src="https://github.com/ankitaS11/pyImageEdits/blob/main/sample_output_images/0002.jpg">
</p>
