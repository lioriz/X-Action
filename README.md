# X-Action
Convert 3D color RGB pics to 2D black & white pics

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