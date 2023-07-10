#include "Chess.hpp"

Chess::ChessBoard::ChessBoard()
{
	GenerateAndFill();
	
	

	//m_board;
	///*110, 111, 112, 113, 114, 115, 116, 117, 118, 119,*/
	///*100, 101, 102, 103, 104, 105, 106, 107, 108, 109,*/
	///*90,   91,  92,  93,  94,  95,  96,  97,  98,  99,*/
	///*80,   81,  82,  83,  84,  85,  86,  87,  88,  89,*/
	///*70,   71,  72,  73,  74,  75,  76,  77,  78,  79,*/
	///*60,   61,  62,  63,  64,  65,  66,  67,  68,  69,*/
	///*50,   51,  52,  53,  54,  55,  56,  57,  58,  59,*/
	///*40,   41,  42,  43,  44,  45,  46,  47,  48,  49,*/
	///*30,   31,  32,  33,  34,  35,  36,  37,  38,  39,*/
	///*20,   21,  22,  23,  24,  25,  26,  27,  28,  29,*/
	///*10,   11,  12,  13,  14,  15,  16,  17,  18,  19,*/
	///*0,     1,	  2,   3,   4,   5,	  6,   7,	8,   9 */

	//// Reserving 16 piece size for both players
	//players.at(0).reserve(16);
	//players.at(1).reserve(16);



	


	//const unsigned int INVALID_POS[56] = {
	//	110, 111, 112, 113,	114, 115, 116, 117,	118, 119,
	//	100, 101, 102, 103,	104, 105, 106, 107,	108, 109,
	//	90, /*91,  92,	93,	 94,  95,  96   97, 98*/  99,
	//	80, /*81,  82,	83,	 84,  85,  86,  87, 88*/  89,
	//	70, /*71,  72,	73,	 74,  75,  76,  77, 78*/  79,
	//	60, /*61,  62,	63,	 64,  65,  66,  67, 68*/  69,
	//	50, /*51,  52,	53,	 54,  55,  56,  57, 58*/  59,
	//	40, /*41,  42,	43,	 44,  45,  46,  47, 48*/  49,
	//	30, /*31,  32,	33,	 34,  35,  36,  37, 38*/  39,
	//	20, /*21,  22,	23,	 24,  25,  26,  27, 28*/  29,
	//	10,  11,  12,	13,	 14,  15,  16,  17,  18,  19,
	//	 0,	   1,	2,	 3,	  4,   5,	6,	 7,	  8,   9
	//};

	
}


Chess::ChessBoard::~ChessBoard()
{
	
}

std::string ePieceToString(Chess::PIECE_TYPE type)
{
	using namespace Chess;
	switch (type)
	{
	case PIECE_TYPE::NONE:
		return std::string("0");
	case PIECE_TYPE::KING:
		return std::string("KING");
	case PIECE_TYPE::QUEEN:
		return std::string("QUEEN");
	case PIECE_TYPE::BISHOP:
		return std::string("BISHOP");
	case PIECE_TYPE::KNIGHT:
		return std::string("KNIGHT");
	case PIECE_TYPE::ROOK:
		return std::string("ROOK");
	case PIECE_TYPE::PAWN:
		return std::string("PAWN");
	}

}

void Chess::ChessBoard::PrintBoard()
{
	int i = 1;
	std::cout << "[GAME] : WELCOME TO CHESS!!!\nThe Current Board state is as below:" << std::endl;
	for (auto itr = m_board.begin(); itr != m_board.end(); itr++)
	{
		std::cout << itr->index << "[" << ePieceToString(itr->piece->m_type) << "]\t";
		std::cin.get();
		/*if (i < 10)
		{
			std::cout << std::endl;
		}*/
		++i;
	}
}

/// <summary>
/// Generates all the pieces of both players and fills the empty chess board with the starting position pieces
/// </summary>
void Chess::ChessBoard::GenerateAndFill()
{
	PIECE_COLOR temp = PIECE_COLOR::NONE;

	for (unsigned int pos = 0; pos < m_board.size(); ++pos)
	{
		//Update index of every square
		m_board[pos].index = pos;

		//Fill in white's side with corresponding pieces
		if (pos >= VALID_POS::a1 && pos <= VALID_POS::h1)
		{
			switch (pos)
			{
			case a1:
				(m_board.at(pos)).piece = std::make_unique<Rook>(PIECE_COLOR::WHITE, pos);
				break;

			case b1:
				(m_board.at(pos)).piece = std::make_unique<Knight>(PIECE_COLOR::WHITE, pos);
				break;

			case c1:
				(m_board.at(pos)).piece = std::make_unique<Bishop>(PIECE_COLOR::WHITE, pos);
				break;

			case d1:
				(m_board.at(pos)).piece = std::make_unique<Queen>(PIECE_COLOR::WHITE, pos);
				break;

			case e1:
				(m_board.at(pos)).piece = std::make_unique<King>(PIECE_COLOR::WHITE, pos);
				break;

			case f1:
				(m_board.at(pos)).piece = std::make_unique<Bishop>(PIECE_COLOR::WHITE, pos);
				break;

			case g1:
				(m_board.at(pos)).piece = std::make_unique<Knight>(PIECE_COLOR::WHITE, pos);
				break;

			case h1:
				(m_board.at(pos)).piece = std::make_unique<Rook>(PIECE_COLOR::WHITE, pos);
				break;

			default:
				break;
			}
		}
		//Fill in White's PAWN ROW
		else if (pos >= VALID_POS::a2 && pos <= VALID_POS::h2)
		{
			(m_board.at(pos)).piece = std::make_unique<Pawn>(PIECE_COLOR::WHITE, pos);
		}

		//Fill in Black's PAWN ROW
		else if (pos >= VALID_POS::a7 && pos <= VALID_POS::h7)
		{
			(m_board.at(pos)).piece = std::make_unique<Pawn>(PIECE_COLOR::BLACK, pos);
		}
		//Fill in Black's side with corresponding pieces
		else if (pos >= VALID_POS::a8 && pos <= VALID_POS::h8)
		{
			switch (pos)
			{
			case a8:
				(m_board.at(pos)).piece = std::make_unique<Rook>(PIECE_COLOR::BLACK, pos);
				break;

			case b8:
				(m_board.at(pos)).piece = std::make_unique<Knight>(PIECE_COLOR::BLACK, pos);
				break;

			case c8:
				(m_board.at(pos)).piece = std::make_unique<Bishop>(PIECE_COLOR::BLACK, pos);
				break;

			case d8:
				(m_board.at(pos)).piece = std::make_unique<Queen>(PIECE_COLOR::BLACK, pos);
				break;

			case e8:
				(m_board.at(pos)).piece = std::make_unique<King>(PIECE_COLOR::BLACK, pos);
				break;

			case f8:
				(m_board.at(pos)).piece = std::make_unique<Bishop>(PIECE_COLOR::BLACK, pos);
				break;

			case g8:
				(m_board.at(pos)).piece = std::make_unique<Knight>(PIECE_COLOR::BLACK, pos);
				break;

			case h1:
				(m_board.at(pos)).piece = std::make_unique<Rook>(PIECE_COLOR::BLACK, pos);
				break;

			default:
				break;
			}
		}
	}

}

void Chess::ChessBoard::UpdatePiece(Piece& piece)
{

}
