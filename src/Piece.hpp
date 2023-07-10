#pragma once
#include <iostream>
#include <memory>

namespace Chess
{


enum class PIECE_TYPE
{
	NONE = -1, KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN
};

enum class PIECE_COLOR
{
	NONE = -1, WHITE = 0, BLACK = 1
};

class Piece
{
public:
	Piece();

	virtual void Move();
	PIECE_TYPE m_type = PIECE_TYPE::NONE;

protected:
	PIECE_COLOR m_color = PIECE_COLOR::NONE;
	unsigned int m_position = NULL;
	bool m_highlighted = false;
	bool m_isPinned = false;
	bool m_isAlive = true;
};



class Pawn : public Piece
{
public:
	Pawn(PIECE_COLOR color, unsigned int Position);
};



class Rook : public Piece
{
public:
	Rook(PIECE_COLOR color, unsigned int Position);
};



class Knight : public Piece
{
public:
	Knight(PIECE_COLOR color, unsigned int Position);
};



class Bishop : public Piece
{
public:
	Bishop(PIECE_COLOR color, unsigned int Position);
};



class King : public Piece
{
public:
	King(PIECE_COLOR color, unsigned int Position);
};



class Queen : public Piece
{
public:
	Queen(PIECE_COLOR color, unsigned int Position);
};



}	//namespace Chess

