# Syntax Analyzer
A basic C++ syntax analyzer based on a simple grammar.

Date of creation: January 2023

The grammar is shown below. Lowercase letters indicate terminal symbols.
```
Z → (K)
K → GM
G → ν | Z
M → -K | +K | e
```
where e is a null character.

The program prints the syntax analyzation process and its corresponding binary tree form in a preorder traversal format.

Example screenshots:

<p float="left">
	<img src="https://i.imgur.com/HrdJ7Ui.png" width="30%" />
	<img src="https://i.imgur.com/Xx4gphQ.png" width="32%" />
	<img src="https://i.imgur.com/Lw9ImxE.png" width="30%" />
</p>
