#include <iostream>
#include <bitset>

class Board {
    public:
        uint32_t blackMan;
        uint32_t blackKing;
        uint32_t whiteMan;
        uint32_t whiteKing;
        /*
        I am using a 32 bit unsigned binary sequence for each piece type called a bitboard to represent each state.
        The board will be numbered from top to bottom on the dark pieces from 32 to 1, where 1 is on the black side.
        */
        Board() {
            blackMan = 0x000000FF;
            blackKing = 0x00000000;
            whiteMan = 0xFF000000;
            whiteKing = 0x00000000;
        }
};