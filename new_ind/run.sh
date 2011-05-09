#!/bin/sh

arg=$*

make gen_define.exe
./gen_define.exe $arg > defines.h
rm -f read64_independent.o read64_independent.exe
make 
./read64_independent.exe
