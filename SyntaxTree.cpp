// Necessary imports
#include <iostream>
#include "SyntaxTree.h"

// Adds a new child(leaf) to the SyntaxTree.
void SyntaxTree::MpushChildren( TreeNode** parent_ptr, const std::vector<Symbols>& data )
{
	bool rootExists = ((*parent_ptr) != nullptr);
	if ( !rootExists )
	{
		if ( !data.empty() ) { *parent_ptr = MnewNode( data.at( 0 ) ); }
		return;
	}

	for ( const Symbols& symbol : data )
		(*parent_ptr)->pr_children.push_back( MnewNode( symbol ) );
}

// Prints the SyntaxTree.
void SyntaxTree::Mprint( const TreeNode* parent_ptr ) const
{
	bool parentExists = (parent_ptr != nullptr);
	if ( parentExists )
	{
		std::cout << *parent_ptr;
		for ( const TreeNode* child : parent_ptr->pr_children )
			Mprint( child );
	}
}

// Erases SyntaxTree's nodes.
void SyntaxTree::MErase( TreeNode** parent_ptr )
{
	bool rootExists = ((*parent_ptr) != nullptr);
	if ( !rootExists ) { return; }

	for ( TreeNode* child : (*parent_ptr)->pr_children )
		MErase( &child );

	/*
	 * Erase reference to the parent,
	 * to save memory space.
	 */
	delete* parent_ptr;
}