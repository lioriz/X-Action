# X-Action
Manipulate images

# Build instructions
## prebuild
sudo apt update
sudo apt --fix-broken install
sudo apt install libgtk2.0-dev pkg-config
sudo apt install libcanberra-gtk-module libcanberra-gtk3-module
sudo apt install g++-8

## Opencv
Follow the instructions: https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html

Go to your 3rd party lib dir
* wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip
* unzip opencv.zip
* mkdir -p build && cd build
* cmake  ../opencv-master
* make (it's a long build, add -j if you can)
* sudo make install