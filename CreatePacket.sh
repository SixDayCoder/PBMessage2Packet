#!/bin/sh
protoc --cpp_out=packets PBMessage.proto
echo "Create PBMessage.h and PBMessage.cc Finish"

python gen-pbmessage.py 
echo "Create CXX Packet Finish"
echo "Finish"