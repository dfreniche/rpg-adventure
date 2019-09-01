#!/bin/bash

IDSK=$CPCT_PATH/tools/iDSK-0.13/bin/iDSK
SOURCE1=rpg.bas
SOURCE2=main.bas
DESTINATION1=rpg-c.bas
DESTINATION2=main-c.bas
TARGET=rpg.dsk
PRESENTATION_FILE=present.txt

# Close any open RVM2 instance
./close-rvw.sh


# REMOVE COMMENTS FROM BASIC FILE
grep -v "'" $SOURCE1 > $DESTINATION1
grep -v "'" $SOURCE2 > $DESTINATION2

# CREATE DSK
$IDSK $TARGET -n

# Convert to MSDOS CR+LF LINE FORMAT
# This needs unix2dos util 
# brew install unix2dos
unix2dos $SOURCE1
unix2dos $SOURCE2
unix2dos $DESTINATION1
unix2dos $DESTINATION2
unix2dos $PRESENTATION_FILE

# ADD TO DSK
$IDSK $TARGET -i $SOURCE1 -t 0
$IDSK $TARGET -i $SOURCE2 -t 0
$IDSK $TARGET -i $DESTINATION1 -t 0
$IDSK $TARGET -i $DESTINATION2 -t 0
$IDSK $TARGET -i $PRESENTATION_FILE -t 0

# ONCE MINIMIFIED FILE IS IN DSK, DELETE IT
rm $DESTINATION1
rm $DESTINATION2

echo "Success 🎉, let's launch RVM 🚀"

# LAUNCH RVM
cpct_rvm $TARGET

# BRING RVM TO FRONT
./bring-rvm-front.sh