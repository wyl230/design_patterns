#!/bin/bash
cp ../SimpleFactory/mine . -r
cd mine/
rm *.cpp
rm *.h
cp ../*.cpp .
cp ../*.h .
rm build -rf
./run.sh
