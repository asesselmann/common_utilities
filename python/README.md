## reduce dae meshes
The reduceMeshesInDirectory.py is a helper script for reducing meshes of file type .dae

## Dependencies
blender
python3

## Usage
Example:
```
#!/bin/bash
python reduceMeshesInDirectory.py /home/letrend/workspace/poseestimator/models/roboy/dae/ /home/letrend/workspace/poseestimator/models/roboy_simplified/dae/ 0.1
```
The first two parameters define paths to input/output directories, the last parameters defines the ratio of mesh reduction (c.f. [decimate modifier](https://www.blender.org/manual/modeling/modifiers/generate/decimate.html)). The script search through the input directory and transforms every .dae file to a .dae file with the same name into the output directory. NOTE: mind the additional '/' in the input/output paths.
