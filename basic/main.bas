10 ' *******************************
20 '  
30 ' RPG GAME
40 ' by @dfreniche
50 ' July 2019
60 '
70 ' *******************************


100 ' *******************************
110 ' INITIALIZE
120 ' *******************************
120 energy=100:attack=30:defense=15
130 energyen=90:attacken=20:defenseen=10:a$=""

200 ' PRESENTATION


300 ' PRINT GAME STATUS
310 WHILE 1 
320 LOCATE 1,1: PRINT CHR$(251);" PLAYER ["energy"](a"attack")(d"defense")  "
330 LOCATE 1,2: PRINT CHR$(250);" ENEMY  ["energyen"](a"attacken")(d"defenseen")"

400 ' PLAYER ACTIONS
410 LOCATE 1,5: INPUT"ACTION (A/D)";a$: a$=UPPER$(a$)
420 IF a$="A" THEN GOSUB 490:GOTO 510
430 IF a$="D" THEN LOCATE 1,4: ?"Player defends!  ":energy=energy+defense:GOTO 510
440 GOTO 410

480 ' PLAYER ATTACKS
490 energyen=energyen-attack
495 LOCATE 1,4: ?"Player attacks!  "
496 RETURN

500 ' ENEMY ACTIONS
510 IF RND>0.25 THEN LOCATE 1,4: ?"Enemy attacks!  ":energy=energy-attacken:GOTO 900
520 LOCATE 1,4: ?"Enemy defends!  ":energyen=energyen+defenseen


900 WEND


10000 ' LEAVE THIS EMPTY LINE AT THE END FOR UNIX2DOS
