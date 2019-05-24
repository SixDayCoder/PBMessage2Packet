.\windows-tool\protoc.exe --cpp_out=packets PBMessage.proto
echo "Create PBMessage.h and PBMessage.cc Finish"
.\gen-pbmessage.py 
echo "Create CXX Packet Finish"
echo "Finish"
pause