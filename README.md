# pyImageEdits

```pyImageEdits``` allows you to play with `.ppm` images by providing the following features:
1. ```read_image```: Reads Image path.
2. ```apply_bluefilterimg```: Applies blue filter to the given image path.
3. `apply_greenfilterimg`: Applies green filter to  the given image path.
4. ```apply_redfilterimg```: Applies red filter to the given image path.
5. `apply_nofilterimg`: Get an image without applying filter
### Usage 
``` 
git clone https://github.com/ankitaS11/pyImageEdits.git
mkdir build && cd build
cmake ..
make
```
Insert `.ppm` image [(Some `.ppm` images can be found here)](https://github.com/ferrabacus/p3images) in the build directory to use the `pyImageEdits` library.
Open python shell in the same directory and import `pyImageEdits`:
```
python3
>>> import pyImageEdits
>>> x = pyImageEdits.ImageEdits("monument.ppm")
>>> x.read_image()           # To read the image
>>> x.apply_bluefilterimg()  # To apply blue filter
>>> x.apply_redfilterimg()   # To apply red filter
>>> x.apply_greenfilterimg() # To apply green filter
>>> x.apply_nofilterimg()    # To get an image without applying filter
```
### Structure
```
|-- include
  |-- ImgEdit.hpp
|-- src
  |-- ImgEdit.cpp
|-- pymain.cpp
|-- pybind11
|-- CMakeLists.txt
|-- sample_output_images
  |-- bluefilter_image.jpg
  |-- nofilter_image.bmp
  |-- sampletest_image.bmp
  |-- greenfilter_image.bmp
  |-- redfilter_image.bmp
|-- README.md
|-- a.out
```
### Sample Output Images 
<p align = "center">
<img align="left" width="350" height="300" src="https://raw.githubusercontent.com/ankitaS11/pyImageEdits/main/sample_output_images/sampletest_image.bmp?token=AQKDYACJPWVYUJZYOLJECJDBPE4KG">
<img align="left" width="350" height="300" src="https://github.com/ankitaS11/pyImageEdits/blob/main/sample_output_images/bluefilter_image.jpg">
<img align="left" width="350" height="300" src="https://raw.githubusercontent.com/ankitaS11/pyImageEdits/main/sample_output_images/redfilter_image.bmp">
<img align="left" width="350" height="300" src="https://raw.githubusercontent.com/ankitaS11/pyImageEdits/main/sample_output_images/greenfilter_image.bmp">
</p>
