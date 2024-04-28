#pragma region Definition Of Class SyntaxTree

#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

// Necessary imports
#include "TreeNode.h"
#include <list>

class SyntaxTree
{
public:

	// Define constructor.
	SyntaxTree( const Symbols& symbol )
		: pr_root_ptr( MnewNode( symbol ) )
	{
	};

	// Define destructor.
	~SyntaxTree()
	{
		MErase( &pr_root_ptr );
		std::cout << "\n\nThe tree is destroyed...";
	}
public:

	// Returns a pointer, pointing at the root.
	TreeNode* MgetRoot() const { return this->pr_root_ptr; }

	void MpushChildren( TreeNode**, const std::vector<Symbols>& );
	void Mshow() const { Mprint( pr_root_ptr ); }
private:

	TreeNode* pr_root_ptr;
private:

	TreeNode* MnewNode( const Symbols& symbol ) { return new TreeNode( symbol ); }
	void Mprint( const TreeNode* ) const;
	void MErase( TreeNode** );
};

#endif

#pragma endregion