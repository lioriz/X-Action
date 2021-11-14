FROM ubuntu:18.04

MAINTAINER Lior Izrael <lioriz888@gmail.com>

RUN apt-get update -y
RUN apt --fix-broken install
RUN apt install -y g++-8
RUN apt install -y libgtk2.0-dev pkg-config
RUN apt install -y libcanberra-gtk-module libcanberra-gtk3-module
RUN apt install -y cmake wget unzip git

RUN mkdir opencv && cd opencv && \
    wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip && \
    unzip opencv.zip && \
    mkdir build && cd build && \
    cmake  ../opencv-master && make && \
    make install

RUN LD_LIBRARY_PATH=/usr/local/lib && \
    export LD_LIBRARY_PATH

RUN mkdir imageConverter && cd imageConverter && \
    git clone https://github.com/lioriz/X-Action.git && \
    cd X-Action && \
    git checkout master && \
    mkdir build && cd build && \
    cmake cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++-8 .. && \
    make
