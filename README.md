# PBMessage2Packet
<br>Parse PBMessage.proto and get Packet files in CXX</br>

# Directory
## packets
<br>packets dir contains the generated files </br>
<br>files in packets are what we needed, copy all files in packets into your cxx project</br> 
## template
<br>xml files used in generating files </br>
<br>PacketBaseHeader.xml -> packets/Packet.h</br>
<br>PacketDefine.xml -> packets/PacketDefine.h</br>
<br>PacketFactoryHeader.xml -> packets/PacketFactory.h</br>
<br>PacketFactoryImpl.xml -> packets/PacketFactory.cpp</br>
<br>PacketHeader.xml -> packet/XXXXXX_PAK.h</br>
## windows-tool
<br>tools for windows to generate PBMessage.pb.h and PBMessage.pb.cc</br>

# How To Use
<br>1.add your packet into your PBMessage.proto</br>
<br>Notice:the packet form client to server should startwith "CG" and the packet from server to client should startwith "GC"</br>
<br>also you can change the name style by modified </br>
```
gen-pbmessage.py
line:39
# startwith
packet_start_with = ["CG", "GC"]
```
<br>2.Winodws -> execute CreatePacket.bat</br>
<br>3.Linux-> execute CreatePacket.sh</br>
