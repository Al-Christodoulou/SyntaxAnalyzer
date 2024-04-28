// Necessary imports
#include <iostream>
#include "Process.h"
#include "SyntaxTree.h"

/*
 * Checks if the given string, is
 * | not syntactically correct &
 * shows the corresponding syntax tree
 */
void Process::MsyntaxParse( const std::list<Symbols>& listToCheck )
{

	std::list<Symbols> generatedList { Symbols::G };
	std::list<TreeNode*> levelPointerList {};

	std::list<Symbols>::const_iterator listToCheckIterator { listToCheck.begin() };
	std::list<Symbols>::iterator generatedListIterator { generatedList.begin() };
	// Initialize an iterator for the list of TreeNode pointers
	std::list<TreeNode*>::iterator genNodePtr_iterator { levelPointerList.begin() };

	unsigned generationStep { 0 };
	bool isSymbolStringValid { true };

	bool startsWithOpenBrackets = (*listToCheckIterator == Symbols::Open);
	bool endsWithClosedBrackets = (*(--listToCheck.end()) == Symbols::Close);
	if ( !startsWithOpenBrackets || !endsWithClosedBrackets )
		isSymbolStringValid = false;

	SyntaxTree syntaxTree { Symbols::G };
	genNodePtr_iterator = levelPointerList.insert( levelPointerList.begin(), syntaxTree.MgetRoot() );

	while ( listToCheckIterator != listToCheck.end() && isSymbolStringValid )
	{

		/*
		 * Continue the parsing process, while the
		 * Symbol that is checked, hasn't been generated.
		 */
		while ( generatedListIterator != generatedList.end() && listToCheckIterator != listToCheck.end() &&
				*generatedListIterator != *listToCheckIterator && isSymbolStringValid )
		{
			std::vector<Symbols> children {};
			const TreeNode* const currentParent { *genNodePtr_iterator };
			bool terminalSymbolFound { false };

			if ( *generatedListIterator == Symbols::G )
			{

				*generatedListIterator = Symbols::Close;
				generatedListIterator = generatedList.insert( generatedListIterator, Symbols::M );
				generatedListIterator = generatedList.insert( generatedListIterator, Symbols::Open );

				children.clear();
				children.push_back( Symbols::Open );
				children.push_back( Symbols::M );
				children.push_back( Symbols::Close );

				syntaxTree.MpushChildren( &(*genNodePtr_iterator), children );
				*genNodePtr_iterator = (*genNodePtr_iterator)->MgetChildren().at( 2 );
				for ( int k { 1 }; k >= 0; k-- )
					genNodePtr_iterator = levelPointerList.insert( genNodePtr_iterator, currentParent->MgetChildren().at( k ) );

				++genNodePtr_iterator;
				++generatedListIterator;
				++listToCheckIterator;
			}
			else if ( *generatedListIterator == Symbols::M )
			{

				*generatedListIterator = Symbols::Z;
				generatedListIterator = generatedList.insert( generatedListIterator, Symbols::Y );

				children.clear();
				children.push_back( Symbols::Y );
				children.push_back( Symbols::Z );

				syntaxTree.MpushChildren( &(*genNodePtr_iterator), children );
				*genNodePtr_iterator = (*genNodePtr_iterator)->MgetChildren().at( 1 );
				genNodePtr_iterator = levelPointerList.insert( genNodePtr_iterator, currentParent->MgetChildren().at( 0 ) );

			}
			else if ( *generatedListIterator == Symbols::Y )
			{

				/*
				 * Declare replacement Symbol, based
				 * on the value of listToCheckIterator.
				 */
				switch ( *listToCheckIterator )
				{
					case Symbols::a:

						*generatedListIterator = Symbols::a;

						children.clear();
						children.push_back( Symbols::a );

						terminalSymbolFound = true;

						syntaxTree.MpushChildren( &(*genNodePtr_iterator), children );
						*genNodePtr_iterator = (*genNodePtr_iterator)->MgetChildren().at( 0 );
						break;
					case Symbols::b:

						*generatedListIterator = Symbols::b;

						children.clear();
						children.push_back( Symbols::b );

						terminalSymbolFound = true;

						syntaxTree.MpushChildren( &(*genNodePtr_iterator), children );
						*genNodePtr_iterator = (*genNodePtr_iterator)->MgetChildren().at( 0 );
						break;
					case Symbols::Open:

						*generatedListIterator = Symbols::G;

						children.clear();
						children.push_back( Symbols::G );

						syntaxTree.MpushChildren( &(*genNodePtr_iterator), children );
						*genNodePtr_iterator = (*genNodePtr_iterator)->MgetChildren().at( 0 );
						break;
					default:

						isSymbolStringValid = false;
						break;
				}

			}
			else if ( *generatedListIterator == Symbols::Z )
			{

				/*
				 * Declare replacement Symbol, based
				 * on the value of listToCheckIterator.
				 */
				switch ( *listToCheckIterator )
				{
					case Symbols::Multiply:

						*generatedListIterator = Symbols::M;
						generatedListIterator = generatedList.insert( generatedListIterator, Symbols::Multiply );

						children.clear();
						children.push_back( Symbols::Multiply );
						children.push_back( Symbols::M );

						terminalSymbolFound = true;

						syntaxTree.MpushChildren( &(*genNodePtr_iterator), children );
						*genNodePtr_iterator = (*genNodePtr_iterator)->MgetChildren().at( 1 );
						genNodePtr_iterator = levelPointerList.insert( genNodePtr_iterator, currentParent->MgetChildren().at( 0 ) );

						break;
					case Symbols::Minus:

						*generatedListIterator = Symbols::M;
						generatedListIterator = generatedList.insert( generatedListIterator, Symbols::Minus );

						children.clear();
						children.push_back( Symbols::Minus );
						children.push_back( Symbols::M );

						terminalSymbolFound = true;

						syntaxTree.MpushChildren( &(*genNodePtr_iterator), children );
						*genNodePtr_iterator = (*genNodePtr_iterator)->MgetChildren().at( 1 );
						genNodePtr_iterator = levelPointerList.insert( genNodePtr_iterator, currentParent->MgetChildren().at( 0 ) );
						break;
					case Symbols::Plus:

						/*
						 * Update generated list's iterators, so
						 * that they point -> M, +.
						 */
						*generatedListIterator = Symbols::M;
						generatedListIterator = generatedList.insert( generatedListIterator, Symbols::Plus );

						children.clear();
						children.push_back( Symbols::Plus );
						children.push_back( Symbols::M );

						terminalSymbolFound = true;

						syntaxTree.MpushChildren( &(*genNodePtr_iterator), children );
						*genNodePtr_iterator = (*genNodePtr_iterator)->MgetChildren().at( 1 );
						genNodePtr_iterator = levelPointerList.insert( genNodePtr_iterator, currentParent->MgetChildren().at( 0 ) );
						break;
					default:

						// Assign current iterator -> erased element's previous item.
						generatedListIterator = generatedList.erase( generatedListIterator );

						genNodePtr_iterator = levelPointerList.erase( genNodePtr_iterator );
						if ( listToCheckIterator != (--listToCheck.end()) ) { listToCheckIterator++; }
						genNodePtr_iterator++;
						generatedListIterator++;
						break;
				}

			}
			else if ( generatedListIterator != generatedList.end() )
			{
				generatedListIterator++;
				genNodePtr_iterator++;
				continue;
			}

			std::cout << "\n(Generation step): " << generationStep << "\n-> ";
			Mprint( generatedList );
			std::cout << "\n";

			++generationStep;

			if ( terminalSymbolFound )
			{
				generatedListIterator++;
				genNodePtr_iterator++;
				listToCheckIterator++;
			}

		}

		if ( listToCheckIterator != listToCheck.end() )
		{
			listToCheckIterator++;
		}

	}

	// Inform about string's validation
	if ( !isSymbolStringValid || listToCheck.size() != generatedList.size() )
	{
		std::cout << "\n*** Invalid string inserted ***\n";
		return;
	}

	std::cout << "\n\nString ";
	Mprint( listToCheck );
	std::cout << " is valid!";

	std::cout << "\n\nSyntax tree:\n";
	syntaxTree.Mshow();
}

// Starts program's main process.
void Process::Mbegin()
{
	std::string sampleString( "(b*b-a)" );
	std::list<Symbols> symbolList = Mmatch( sampleString );
	
	MsyntaxParse( symbolList );
};