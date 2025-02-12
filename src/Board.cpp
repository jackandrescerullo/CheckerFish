#include <iostream>
#include <bitset>
#include <string>

class Board {
    public:
        uint32_t blackMan;
        uint32_t blackKing;
        uint32_t whiteMan;
        uint32_t whiteKing;
        bool blackTurn;
        /*
        I am using a 32 bit unsigned binary sequence for each piece type called a bitboard to represent each state.
        The board will be numbered from top to bottom on the dark pieces from 32 to 1, where 1 is on the black side.
        */
        Board() {
            blackMan = 0x000000FF;
            blackKing = 0x00000000;
            whiteMan = 0xFF000000;
            whiteKing = 0x00000000;
            blackTurn = true;
        }
        /*
        My logic is to use the or operator to add a piece at a 
        given position by shifting positoion 1 and returning 1 or the other.
        I also modify the bitboard in place by passing a reference.
        */
        void addPiece(int position, uint32_t& bitboard) {
            bitboard |= (0x00000001 << (position-1));
        }
        /*
        This works the same way, but by using an and and a not operator.
        */
        void removePiece(int position, uint32_t& bitboard) {
            bitboard &= ~(0x00000001 << (position-1));
        }
        // this is just to swicth whose turn it is
        void nextTurn() {
            blackTurn = !blackTurn;
        }
        // this returns a boolean for a piece at a given position
        bool pieceAt(int position, uint32_t& bitboard) {
            return (bitboard & (0x00000001 << (position-1))) != 0;
        }

        
        // this is for debugging the methods
        void printBitboards() {
            std::cout << "Black Men: " << std::bitset<32>(blackMan) << std::endl;
            std::cout << "Black Kings: " << std::bitset<32>(blackKing) << std::endl;
            std::cout << "White Men: " << std::bitset<32>(whiteMan) << std::endl;
            std::cout << "White Kings: " << std::bitset<32>(whiteKing) << std::endl;
        }


};