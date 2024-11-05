import os
import re
import time


# Compile the .cpp code
def ccpp(): #compile cpp
    prog = "emc"
    os.system(f'g++ -o {prog} {prog}.cpp')
    return 0

# move the binary release to the respective directory version
def mvbin(): # move binary
    prog = "emc"
    #prog_version = str(input("Enter the release directory to build: "))
    for i in range(len(os.listdir())):
        d = re.search("^emc.*amd64$", os.listdir()[i])
        if d:
            os.system(f'mv {prog} {d[0]}/usr/bin/')
            break
    return 0

def rm_n_bdeb(): # remove and build deb
    for i in range(len(os.listdir())):
        d = re.search("^emc.*amd64$", os.listdir()[i])
        if d:
            for j in range(len(os.listdir())):
                pkg = re.search("^emc.*deb$", os.listdir()[j])
                if pkg:
                    print("Package .deb exists! Removing existent .deb and build an new")
                    os.system(f"rm -rf {pkg[0]}")
                    time.sleep(1)
                    os.system(f"dpkg-deb --build {d[0]}")
                    return 0
            break
    return 1

def bdeb(): # build .deb
    for i in range(len(os.listdir())):
        d = re.search("^emc.*amd64$", os.listdir()[i])
        if d:
            for j in range(len(os.listdir())):
                pkg = re.search("^emc.*deb$", os.listdir()[j])
                if not pkg:
                    print("Building .deb...")
                    time.sleep(1)
                    os.system(f"dpkg-deb --build {d[0]}")
                    break
            break
    return 0

if __name__ == '__main__':
    ccpp()
    mvbin()
    if rm_n_bdeb() == 0:
        print("Package builded")
    else:
        bdeb()
        print("Package builded")
