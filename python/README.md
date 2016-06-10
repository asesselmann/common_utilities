## reduce dae meshes
The reduceMeshesInDirectory.py is a helper script for reducing meshes of file type .dae

## Dependencies
python3
blender (Ubuntu14 repo version does not work, use the newest [version](https://www.blender.org/download/) )
### Ubuntu14 
Example: 
```
#!/bin/bash
tar xf /path/to/blender-2.77a-linux-glibc211-x86_64.tar.bz2
sudo mv blender-2.77a-linux-glibc211-x86_64/ /opt/blender
sudo ln -s /opt/blender/blender /usr/local/bin/blender
```
## Usage
Example directory:
```
#!/bin/bash
python3 reduceMeshesInDirectory.py /home/letrend/workspace/poseestimator/models/roboy/dae/ /home/letrend/workspace/poseestimator/models/roboy_simplified/dae/ 0.1
```
The first two parameters define paths to input/output directories, the last parameters defines the ratio of mesh reduction (c.f. [decimate modifier](https://www.blender.org/manual/modeling/modifiers/generate/decimate.html)). The script search through the input directory and transforms every .dae file to a .dae file with the same name into the output directory. NOTE: mind the additional '/' in the input/output paths.

Example single file:
```
#!/bin/bash
python3 reduceMeshSingleFile.py ~/workspace/poseestimator/models/roboy/dae/p-oberschenkel-v02.dae ~/workspace/poseestimator/models/roboy_simplified/dae/p-oberschenkel-v02.dae 0.05
```
The first two parameters define paths to input/output .dae file, while the thir parameter defines the ratio of mesh reduction.

## Note
There are no sanity checks regarding your original files. They will be overwritten, if you set the output directory to your input directory!
Also reducing the mesh faces below some value will degenerate your mesh. To avoid this you can try different values first in blender.
