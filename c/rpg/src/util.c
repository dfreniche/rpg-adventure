#include "util.h"
#include <stdio.h>

/****************************************************************************
 * Special ASCII codes
 ***************************************************************************/
#define US  0x1f        // LOCATE
#define FS  0x1c        // INK
#define GS  0x1d        // BORDER
#define EM  0x19        // SYMBOL
#define SO  0x0e        // PAPER
#define SI  0x0f        // PEN
#define FF  0x0c        // CLS

// wait_for_enter_key: waits reading the keyboard until we read Key_Return
void wait_for_enter_key() {
    // Is enter pressed?

   while (!cpct_isKeyPressed(Key_Return) && !cpct_isKeyPressed(Key_Enter)) {
      cpct_scanKeyboard();
   }
}

// CLS: firmware clear screen
// using FIRMWARE
void cls() {
    putchar(FF);
}

// locate: moves cursor to x,y location on screen
// x starts in 1, y starts in 1
// using FIRMWARE
void locate(u8 x, u8 y) {
    // we check for absurd x, y values
    if (x > 80 || y > 25) {
        return;
    }

    putchar(31); // 31 is control code for firmware locate
    putchar(x);
    putchar(y);
}

// ink: set foreground and background colors for ink
// using FIRMWARE
void ink(u8 myInk, u8 color1, u8 color2) {
   putchar (FS);
   putchar (myInk); putchar (color1); putchar (color2);
}

// border: sets border color
// using FIRMWARE
void border(u8 color1, u8 color2) {
   putchar (GS);
   putchar (color1); putchar (color2);
}

// paper: sets paper color
// using FIRMWARE
void paper(u8 color1) {
   putchar (SO);
   putchar (color1);
}

// pen
// using FIRMWARE
void pen (u8 myInk) {
   putchar (SI);
   putchar (myInk);
}

// repeat_print: prints s times times :-)
void repeat_print(char *s, u8 times) {
    for (int i=0; i<times; i++) {
        printf(s);
    }
}

// repeat_print_char: prints character times times :-)
void repeat_print_char(char c, u8 times) {
    for (int i=0; i<times; i++) {
        putchar(c);
    }
}

u8 generate_random_number(u8 limit) {
    return (cpct_rand() % limit) + 1;
}

/*  Works like the SYMBOL AFTER sentence in BASIC
 * v1.1 Firmware version
 * c: 1st character we're going to redefine. SYMBOL AFTER 250, c == 250
 * matrix_address: pointer to the memory address where 
 */
void symbol_after_11(u8 c, u16 matrix_address) {
    // note: we're putting c in the address 0xB734. That's why we tell the compiler this is a u8 pointer
    // but then we derefence the pointer telling the compiler c is a value, not a memory address
    // here instead of a pointer variable we're using an inmediate with a memory address
    // we're putting c in the memory address 0xB734
    *((u8 *)0xB734)  = c;               // 1st character we're going to redefine
    *((u8 *)0xB735)  = 0xFF;            // have to be set to indicate a matrix is following
    *((u16 *)0xB736) = matrix_address;  // this is a memory address. Memory addresses are 16 bit long
}

// symbol: redefines character at position `charNumber` using 8 bytes
// using FIRMWARE
void symbol(u8 charNumber, u8 b0, u8 b1, u8 b2, u8 b3, u8 b4, u8 b5, u8 b6, u8 b7) {
    putchar(EM);
    putchar(charNumber);
    putchar(b0);
    putchar(b1);
    putchar(b2);
    putchar(b3);
    putchar(b4);
    putchar(b5);
    putchar(b6);
    putchar(b7);
}