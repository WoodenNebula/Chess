#include "Chess.hpp"

/// <summary>
/// Initializes member variables
/// </summary>
Chess::Piece::Piece() 
{}

void Chess::Piece::Move() {}


Chess::Pawn::Pawn(PIECE_COLOR color, unsigned int Position) 
{
	m_color = color;
	m_position = Position;
}

Chess::Rook::Rook(PIECE_COLOR color, unsigned int Position)
{
	m_color = color;
	m_position = Position;
}

Chess::Knight::Knight(PIECE_COLOR color, unsigned int Position)
{
	m_color = color;
	m_position = Position;
}

Chess::Bishop::Bishop(PIECE_COLOR color, unsigned int Position)
{
	m_color = color;
	m_position = Position;
}

Chess::Queen::Queen(PIECE_COLOR color, unsigned int Position)
{
	m_color = color;
	m_position = Position;
}

Chess::King::King(PIECE_COLOR color, unsigned int Position)
{
	m_color = color;
	m_position = Position;
}