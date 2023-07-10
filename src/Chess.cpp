#include "Chess.hpp"

Chess::ChessBoard::ChessBoard()
{
}

Chess::ChessBoard::ChessBoard(const char* msg)
{
	std::cout << msg << std::endl;
	std::cin.get();
	//TODO: initialize all the objects required like pieces and rendering
}

Chess::ChessBoard::~ChessBoard()
{
	//TODO: cleanup tasks
}

void Chess::ChessBoard::Init()
{

}


Chess::Pieces::Pieces()
{

}

Chess::Pieces::~Pieces()
{

}

void Chess::Pieces::Create()
{

}
