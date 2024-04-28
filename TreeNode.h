#pragma region Definition Of Class TreeNode

#ifndef TREENODE_H
#define TREENODE_H

// Necessary imports
#include <iostream>
#include <vector>
#include "Symbols.h"

class TreeNode
{
	/*
	 * Make SyntaxTree class a friend, so
	 * that it can access the private members
	 * of TreeNode.
	 */
	friend class SyntaxTree;

	// Mutate TreeNode's output.
	friend std::ostream& operator<<( std::ostream& output, const TreeNode& node )
	{
		output << MapToChar.at( node.MgetData() ) << " ";
		return output;
	}
public:

	// Define constructor.
	explicit TreeNode( Symbols symbol )
		: pr_data( symbol )
	{
	};

	Symbols MgetData() const { return this->pr_data; }
	const std::vector<TreeNode*>& MgetChildren() const { return this->pr_children; }
private:

	std::vector<TreeNode*> pr_children {};
	Symbols pr_data {};
};

#endif

#pragma endregion