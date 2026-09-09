#include "colors.h"

const Color darkGrey = {26, 31, 40, 255};  // 0: Cella vuota (Sfondo griglia)
const    Color green = {47, 230, 23, 255};    // 1: S-Piece
const    Color red = {232, 18, 18, 255};      // 2: Z-Piece
const    Color orange = {226, 116, 17, 255};  // 3: L-Piece
const    Color yellow = {237, 234, 4, 255};   // 4: O-Piece
const    Color purple = {166, 0, 247, 255};  // 5: T-Piece
const    Color cyan = {21, 204, 209, 255};    // 6: I-Piece
const    Color blue = {13, 64, 216, 255}; 

std::vector<Color> GetCellColors(){
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}