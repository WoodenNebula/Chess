#pragma once

#include <iostream>
#include <string>

namespace Chess {

static class ChessBoard
{
public:
	ChessBoard();

	ChessBoard(const char* msg);
	~ChessBoard();

	/// <summary>
	/// Initilize required stuff
	/// </summary>
	void Init();
};

class Pieces : protected ChessBoard 
{
	Pieces();
	~Pieces();

	void Create();
};

}	//namespace Chess

