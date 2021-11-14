# X-Action
Convert 3D color RGB pics to 2D black&white pics

## Build instructions
### prebuild
sudo apt update
sudo apt --fix-broken install
sudo apt install libgtk2.0-dev pkg-config
sudo apt install libcanberra-gtk-module libcanberra-gtk3-module
sudo apt install g++-8

### Opencv
Follow the instructions: https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html

Go to your 3rd party lib dir in your machine
* wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip
* unzip opencv.zip
* mkdir -p build && cd build
* cmake  ../opencv-master
* make (it's a long build... add -j<num> if you can)
* sudo make install

### Build project
* mkdir -p build && cd build
* cmake -DCMAKE_CXX_COMPILER=<g++-8 path> .. (example: cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++-8 ..)
* build projects
  * make PythonConversion (for first assignment)
  * make X-Action (for x action assignment)
  * make (to build all)
  
## Run instructions
### Run PythonConversion
Go to build/bin
run ./PythonConversion
It will gow over the images in the images directory and show them in black&white

### Run X-Action
Go to build/bin
run ./X-Action <num of threads> 
num of threads should be from 1 to 10, any other number will result sungle thread run.
the converted black&white images will be saved in images_out directory.

## Docker
Unfortuenetly I had some issues with the docker in my machine so I didn't have the time to build it completely, the project build, the X-Action is working but the PythonConversion causing segmentation fault.

You can find the dockerfile in docker directory.
I uploaded the image to docker-hub use "docker pull lioriz/image-converter:latest" to download the image.

 * run the image with terminal. "docker run -it lioriz/image-converter:latest"
 * go to X-Action. "cd imageConverter/X-Action/"
 * run the exe files in build/bin.
