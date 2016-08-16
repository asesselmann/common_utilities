#!/bin/bash
if [ "$#" -ne 1 ]; then
    echo "USAGE:     ./publish2ppa.bash path/to/src/directory"
else
    currentDir=$(pwd)
    cd $1
    find . ! -path . -maxdepth 1 -type d|column -c 100
    echo "-------"
    echo "WARNING: the above packages will be published to ppa"
    echo "-------"
    read -r -p "Proceed? [y/n] " response
    response=${response,,}    # tolower
    if [[ $response =~ ^(yes|y)$ ]]; then
	mkdir -p tmp
        find . ! -path . -maxdepth 1 -type d| while read FILE ; do
	    packagename=${FILE/*\//}
	    packagename=ros-indigo-$(echo ${packagename}|tr '_' '-') 
	    echo "###############     processing ${packagename} in directory: ${FILE}    ################"
	    bloom-generate rosdebian ${FILE} --os-name ubuntu --os-version trusty --ros-distro indigo          
	    mkdir -p tmp/${packagename}/src && cp ${FILE}/* tmp/${packagename}/src -r
	    mv debian tmp/${packagename}
	    rm tmp/${packagename}/debian/rules && cp ${currentDir}/rules tmp/${packagename}/debian
	    grep -rl "PACKAGENAME" tmp/${packagename}/debian/rules | xargs sed -i "s/PACKAGENAME/${packagename}/g"
	    rm tmp/${packagename}/debian/changelog && cp ${currentDir}/changelog tmp/${packagename}/debian
	    grep -rl "PACKAGENAME" tmp/${packagename}/debian/changelog | xargs sed -i "s/PACKAGENAME/${packagename}/g"
	    sed -i '/Maintainer/c\Maintainer: Simon Trendel <simon.trendel@tum.de>' tmp/${packagename}/debian/control
	    sed -i '/Standards-Version/c\Standards-Version: 3.9.5' tmp/${packagename}/debian/control
	    versionnumber=$(grep -Po '(?<=\()\d.\d.\d' tmp/${packagename}/debian/changelog)
	    cd tmp/
	    tar -acf ${packagename}_${versionnumber}.orig.tar.gz ${packagename}
	    cd ${packagename}
	    debuild -S
	    cd ..
	    dput -f ppa:letrend/${packagename} ${packagename}_${versionnumber}-1_source.changes
	    cd ..
	done
    else
        echo "ABORT"
    fi
    cd ${currenDir}
fi

