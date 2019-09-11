#!/bin/bash

IDSK=$CPCT_PATH/tools/iDSK-0.13/bin/iDSK
TARGET=rpg.dsk
PRESENTATION_FILE=src/present.txt

# Make will create DSK with the binary
make

# Check make went OK, if not print message and exit
if [ $? -ne 0 ]; then
    echo "..."
    echo "💥 Error compiling / linking / check above message"
    exit
fi

# ADD TO DSK
$IDSK $TARGET -i $PRESENTATION_FILE -t 0

echo "Success 🎉, let's launch RVM 🚀"

# LAUNCH RVM
/mnt/c/Users/dfren/bin/rvm/RetroVirtualMachine.exe -w -insert $TARGET  --boot=cpc6128@es -command="run\"rpg\"\n"
