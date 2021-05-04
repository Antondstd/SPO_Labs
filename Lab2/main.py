import sys
from shlex import split
from ctypes import *
# so_file = "/home/user/SPO/OMG/lab1libtest.so"
so_file = "/home/user/SPO/Lab1Final/lab1lib.so"
lab1 = CDLL(so_file)

def fsbrowse(fspath):
    hfs = c_void_p(lab1.getHFSPlus(fspath))
    if (hfs.value == None):
        print("This is not a HFSPlus system")
        sys.exit(-1)
    exit = False
    while(exit == False):
        inp = raw_input("$:")
        print(inp)
        if (inp == None or inp == ""):
            continue
        command = split(inp)
        # print(command)
        # print(len(command))
        if (command == None):
            continue
        if (command[0] == "exit"):
            exit = True
        elif (command[0] == "ls"):
            if (len(command) < 2):
                ls = c_char_p(lab1.ls(hfs, None))
            else:
                ls = c_char_p(lab1.ls(hfs, command[1]))
            print(ls.value)
        elif (command[0] == "cd" and len(command) == 2):
            cd = (c_char_p(lab1.cd(hfs, command[1])).value)
            if (cd != None):
                print(cd)
        elif (command[0] == "pwd"):
            pwd = c_char_p(lab1.f_pwd(hfs))
            print(pwd.value)
        elif (command[0] == "cp" and len(command) == 3):
            print(c_char_p(lab1.cp(hfs,command[1],command[2])).value)
        else:
            print("Command not found")


if (len(sys.argv) == 3 and sys.argv[1] == "fsfind" and (sys.argv[2] == "0" or sys.argv[2] == "1") ):
    print((c_char_p(lab1.getDisksPartitions(sys.argv[2])).value).decode("utf-8"))
    sys.exit(0)
if (len(sys.argv) == 3 and sys.argv[1] == "fsbrowse"):
    fsbrowse(sys.argv[2])
    sys.exit(0)
print("Bad arguments")

