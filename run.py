import platform
import os

generate_windows_cmd = ""
generate_linux_cmd = ["protoc --cpp_out=packets PBMessage.proto", "python gen-pbmessage.py"]


def main():
    if platform.system() == "Windows":
        print ("aaa")
    elif platform.system() == "Linux":
        for cmd_str in generate_linux_cmd:
            os.system(cmd_str)


main()
