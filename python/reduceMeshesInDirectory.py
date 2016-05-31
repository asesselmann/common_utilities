from subprocess import call
import sys
from os import listdir
from os.path import isfile, join

argv = sys.argv

print(argv)

if len(argv)!=4:
    print('USAGE: path/to/dae/directory/ outputpath/directory/ ration[0-1]')
else:
    files = [f for f in listdir(argv[1]) ]
    print('Converting '+ str(len(files)) +' files')
    for file in files:
        if file.endswith('.dae'):
            call(["blender", "--background", "--python", "reduceMesh.py", "--", join(argv[1],file), join(argv[2],file), argv[3] ])
