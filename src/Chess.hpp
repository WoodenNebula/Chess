#pragma once

#include "Piece.hpp"

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>


namespace Chess {

enum VALID_POS
{
	a8 = 91, b8, c8, d8, e8, f8, g8, h8 = 98,
	a7 = 81, b7, c7, d7, e7, f7, g7, h7 = 88,
	a6 = 71, b6, c6, d6, e6, f6, g6, h6 = 78,
	a5 = 61, b5, c5, d5, e5, f5, g5, h5 = 68,
	a4 = 51, b4, c4, d4, e4, f4, g4, h4 = 58,
	a3 = 41, b3, c3, d3, e3, f3, g3, h3 = 48,
	a2 = 31, b2, c2, d2, e2, f2, g2, h2 = 38,
	a1 = 21, b1, c1, d1, e1, f1, g1, h1 = 28
};


struct Square 
{
	//PIECE_COLOR squareColor = PIECE_COLOR::NONE;
	unsigned int index = NULL;
	std::unique_ptr<Piece> piece;
};

class ChessBoard
{

public:
	ChessBoard();

	~ChessBoard();

	void PrintBoard();

	/// <summary>
	/// Generates all the pieces of both players and fills the empty chess board with the starting position pieces
	/// </summary>
	void GenerateAndFill();

	/// <summary>
	/// moves the given piece to next position
	/// </summary>
	void UpdatePiece(Piece& piece);

protected:
	std::array<Square, 120> m_board;

};


}	//namespace Chess