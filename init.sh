#!/bin/bash

SCRIPT_DIR="$(dirname "$0")"
SCRIPT_DIR="$(realpath $SCRIPT_DIR)"
cd $SCRIPT_DIR # Make sure working directory is directory of this script.

sudo apt update
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi

mkdir build
cd build

git clone https://github.com/raspberrypi/pico-sdk
cd pico-sdk
git submodule update --init
cd ..

git clone https://github.com/kripton/RF24
cd RF24
git switch kripton-rp2xxx
cd ..

cp pico-sdk/external/pico_sdk_import.cmake ..

cmake .. -DPICO_SDK_PATH=./pico-sdk
make