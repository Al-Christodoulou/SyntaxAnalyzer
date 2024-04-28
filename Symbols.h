#pragma region Definition Of Class Symbols

#ifndef SYMBOLS_H
#define SYMBOLS_H

// Necessary imports
#include <map>

enum class Symbols
{
	G,
	M,
	Y,
	Z,
	a,
	b,
	Multiply,
	Minus,
	Plus,
	Close,
	Open
};

const std::map<const Symbols, const char> MapToChar
{
	std::pair<Symbols, char>{ Symbols::G, 'G' },
	std::pair<Symbols, char>{ Symbols::M, 'M' },
	std::pair<Symbols, char>{ Symbols::Y, 'Y' },
	std::pair<Symbols, char>{ Symbols::Z, 'Z' },
	std::pair<Symbols, char>{ Symbols::a, 'a' },
	std::pair<Symbols, char>{ Symbols::b, 'b' },
	std::pair<Symbols, char>{ Symbols::Multiply, '*' },
	std::pair<Symbols, char>{ Symbols::Minus, '-' },
	std::pair<Symbols, char>{ Symbols::Plus, '+' },
	std::pair<Symbols, char>{ Symbols::Close, ')' },
	std::pair<Symbols, char>{ Symbols::Open, '(' }
};

const std::map<const char, const Symbols> MapToSymb
{
	std::pair<char, Symbols>{ 'G', Symbols::G },
	std::pair<char, Symbols>{ 'M', Symbols::M },
	std::pair<char, Symbols>{ 'Y', Symbols::Y },
	std::pair<char, Symbols>{ 'Z', Symbols::Z },
	std::pair<char, Symbols>{ 'a', Symbols::a },
	std::pair<char, Symbols>{ 'b', Symbols::b },
	std::pair<char, Symbols>{ '*', Symbols::Multiply },
	std::pair<char, Symbols>{ '-', Symbols::Minus },
	std::pair<char, Symbols>{ '+', Symbols::Plus },
	std::pair<char, Symbols>{ ')', Symbols::Close },
	std::pair<char, Symbols>{ '(', Symbols::Open }
};

#endif

#pragma endregion