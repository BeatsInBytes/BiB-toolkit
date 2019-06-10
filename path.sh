#!/bin/bash

pathChecker() {
    num=$(echo $PATH | tr ':' '\n' | grep 'bib-toolkit' | wc -l)
    if [ $num -ge '1' ]; then
        echo "Path modification successful"
    else
        echo "Path modification failed"
    fi
}


echo "Adding bins to path..."


numbib=$(echo $PATH | tr ':' '\n' | grep 'bib-toolkit/bin' | wc -l)

if [ $numbib -eq 0 ]; then 

    sleep .4

    dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
    bin="${dir}/bin"
    newPath="${PATH}:${bin}"

    export PATH=$newPath
    pathChecker
else
    echo "Bin directory already exists in path"
fi