import sys
import os
import xml.etree.ElementTree as ET

# path
input_path = r".\PBMessage.proto"
output_dir = r".\packets"
output_packet_base_packet_file_name = "Packet.h"
output_packet_define_file_name = "PacketDefine.h"
output_packet_factory_header_file_name = "PacketFactory.h"
output_packet_factory_impl_file_name = "PacketFactory.cpp"

# template path
template_pbmessage_define_path = r".\PacketDefine.xml"
template_pbmessage_packet_base_path = r".\PacketBaseHeader.xml"
template_pbmessage_packet_path = r".\PacketHeader.xml"
template_pbmessage_packet_factory_header = r".\PacketFactoryHeader.xml"
template_pbmessage_packet_factory_impl = r".\PacketFactoryImpl.xml"


# xml tag
xml_comment_tag = "comment"
xml_include_header_tag = "includeheader"
xml_class_name_tag = "classname"
xml_packet_base_tag = "packetbaseheader"
xml_packet_header_tag = "packetheader"
xml_factory_impl_tag = "factoryimpl"
xml_factory_header_tag = "factoryheader"

# xml repalce variable
xml_packet_name_enum = "${PacketNameEnum}"
xml_packet_name = "${PacketName}"
xml_packet_pak_name = "${PacketPakName}"
xml_pakcet_pak_macro_define = "${PacketMacroDefine}"
xml_include_packet_header = "${IncludePacketHeader}"
xml_case_create_packet = "${CaseCreatePacket}"


# startwith
packet_start_with = ["CS", "SC"]


def get_packet_name_enum(packet_name, id, is_add_end_line):
    prefix = "PACKET_ID_"
    surfix = ""
    if is_add_end_line:
        surfix = " = " + str(id) + ",\n\t\t    "
    else:
        surfix = " = " + str(id) + ","
    return prefix + str.upper(packet_name) + surfix


def parse_pbmessage_name_list(input_file):
    packet_name_list = []
    for line in input_file:
        if str.startswith(line, "message"):
            packet_name = line[line.find("message") + len("message") + 1:]
            packet_name = str.upper(packet_name).strip()
            for start_str in packet_start_with:
                if str.startswith(packet_name, start_str):
                    packet_name_list.append(packet_name)
    return packet_name_list


def parse_pbmessage_define(packet_name_list):
    tree = ET.parse(template_pbmessage_define_path)
    root = tree.getroot()
    output = ""
    for idx in range(0, len(packet_name_list)):
        packet_name = packet_name_list[idx]
        if idx != len(packet_name_list) - 1:
            packet_name_enum = get_packet_name_enum(packet_name, idx + 1, True)
        else:
            packet_name_enum = get_packet_name_enum(packet_name, idx + 1, False)
        output += packet_name_enum
    node = root.find(xml_include_header_tag)
    text = node.text.replace(xml_packet_name_enum, output)
    # write content to file
    output_file_path = os.path.join(output_dir, output_packet_define_file_name)
    output_file = open(output_file_path, "wb+")
    output_file.writelines(text)


def parse_pbmessage_packet_base():
    tree = ET.parse(template_pbmessage_packet_base_path)
    root = tree.getroot()
    node = root.find(xml_packet_base_tag)
    # write to files
    output_file_path = os.path.join(output_dir, output_packet_base_packet_file_name)
    output_file = open(output_file_path, "wb+")
    output_file.writelines(node.text)


def parse_pbmessage_packet(packet_name):
    tree = ET.parse(template_pbmessage_packet_path)
    root = tree.getroot()
    node = root.find(xml_packet_header_tag)

    packet_pak_name = packet_name + "_PAK"
    text = node.text.replace(xml_packet_name, packet_name)
    text = text.replace(xml_packet_pak_name, packet_pak_name)

    packet_macro_define = packet_pak_name + "_H_"
    text = text.replace(xml_pakcet_pak_macro_define, packet_macro_define)

    packet_file_name = packet_pak_name + ".h"
    packet_name_enum = "PACKET_ID_" + packet_name
    text = text.replace(xml_packet_name_enum, packet_name_enum)

    # wirte to files
    output_file_path = os.path.join(output_dir, packet_file_name)
    output_file = open(output_file_path, "wb+")
    output_file.writelines(text)


def get_packet_include_header_name(packet_name):
    prefix = r'#include "'
    surfix = r'"' + "\n\t"
    return prefix + packet_name + "_PAK.h" + surfix


def get_case_create_packet(packet_name):
    prefix = r"case PACKET_ID::"
    surfix = "m_PacketIdList[nPacketId]++; return std::make_shared<{0}>();\n\t\t    "
    packet_enum_name = "PACKET_ID_" + packet_name + " : "
    packet_pak_name = packet_name + "_PAK"
    return prefix + packet_enum_name + surfix.replace("{0}", packet_pak_name)


def parse_pbmessage_packet_factory_header():
    tree = ET.parse(template_pbmessage_packet_factory_header)
    root = tree.getroot()
    node = root.find(xml_factory_header_tag)
    # write to files
    output_file_path = os.path.join(output_dir, output_packet_factory_header_file_name)
    output_file = open(output_file_path, "wb+")
    output_file.writelines(node.text)


def parse_pbmessage_packet_factory_impl(packet_name_list):
    tree = ET.parse(template_pbmessage_packet_factory_impl)
    root = tree.getroot()
    node = root.find(xml_factory_impl_tag)

    # parse include packet header
    include_packet_header = ""
    for idx in range(0, len(packet_name_list)):
        include_packet_header_record = get_packet_include_header_name(packet_name_list[idx])
        include_packet_header += include_packet_header_record
    text = node.text.replace(xml_include_packet_header, include_packet_header)

    # parse create packet
    case_create_packet = ""
    for idx in range(0, len(packet_name_list)):
        case_create_packet_record = get_case_create_packet(packet_name_list[idx])
        case_create_packet += case_create_packet_record
    text = text.replace(xml_case_create_packet, case_create_packet)

    # write to files
    output_file_path = os.path.join(output_dir, output_packet_factory_impl_file_name)
    output_file = open(output_file_path, "wb+")
    output_file.writelines(text)


def main():
    # create ouput dir
    if not os.path.exists(output_dir):
        os.mkdir(output_dir)
    input_file = open(input_path, "rb")
    packet_name_list = parse_pbmessage_name_list(input_file)

    # parse packet define
    parse_pbmessage_define(packet_name_list)
    # parse packet base header
    parse_pbmessage_packet_base()
    # parse packet header
    for i in range(0, len(packet_name_list)):
        parse_pbmessage_packet(packet_name_list[i])
    # parse packet factory
    parse_pbmessage_packet_factory_header()
    parse_pbmessage_packet_factory_impl(packet_name_list)


main()
