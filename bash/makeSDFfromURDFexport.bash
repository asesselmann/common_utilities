#!/bin/bash
if [ "$#" -ne 1 ]; then
    echo "USAGE:     ./makeSDFfromUREDFexport.bash path/to/directory"
else
    currentworkingdirectory=$(pwd)
    cd $1
    projectname=$(ls robots|sed -e "s/.URDF//")
    mkdir $projectname
    cd $projectname
    mkdir dae cad
    cp ../meshes/* cad
    python $currentworkingdirectory/../python/step-stl-dae/stl-to-dae.py cad/ dae/
    gz sdf -p ../robots/$projectname.URDF > model.sdf
    grep -rl "STL" model.sdf | xargs sed -i "s/STL/dae/g"
    grep -rl "meshes" model.sdf | xargs sed -i "s/meshes/dae/g"
    cp $currentworkingdirectory/model.config .
    grep -rl "PROJECTNAME" model.config | xargs sed -i "s/PROJECTNAME/$projectname/g"
    cd $currentworkingdirectory 
fi 
