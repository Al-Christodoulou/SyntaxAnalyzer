#pragma region Definition Of Class Process

#ifndef PROCESS_H
#define PROCESS_H

// Necessary imports
#include <iostream>
#include <list>
#include "Symbols.h"

class Process
{
public:

	void Mbegin();
private:

	void MsyntaxParse( const std::list<Symbols>& );

	/*
	 * Returns a list, after mapping each
	 * list[k], { foreach k < list.size() } with
	 * it's corresponding Symbol.
	 */
	std::list<Symbols> Mmatch( const std::string& list )
	{
		std::list<Symbols> listToCheck { };
		for ( unsigned k { 0 }; k < list.size(); k++ )
			listToCheck.push_back( MapToSymb.at( list.at( k ) ) );

		return listToCheck;
	}

	// Shows the given list of Symbols.
	void Mprint( const std::list<Symbols>& list ) const
	{
		for ( const Symbols& symbol : list )
			std::cout << MapToChar.at( symbol );
	};
};

#endif

#pragma endregion