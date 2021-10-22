#!/bin/bash

SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

for file in $SCRIPT_DIR/*.txt
do
    $SCRIPT_DIR/../geopulse -f "$file"
done