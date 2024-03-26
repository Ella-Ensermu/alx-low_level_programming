#!/bin/bash
wget -P /tmp https://github.com/Zebib0/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libfunction2.so
export LD_PRELOAD=/tem/libfunction2.so
