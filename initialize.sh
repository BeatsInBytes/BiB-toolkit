#!/bin/bash

if [ "$0" = "$BASH_SOURCE" ]; then
    dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
    echo "Error: Script must be sourced. 
Instead, run: 
    source $dir/initialize.sh"
else
    dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
    source $dir/path.sh
fi

