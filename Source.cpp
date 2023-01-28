#include <iostream>
using namespace std;


Node *start = nullptr;
Node *curr = nullptr;
Node *last = nullptr;

class Node
{
public:
	Node* right;
	Node* left;
	char c;
	Node() { right = left = nullptr; c = ' '; }
	Node(int v) { right = left = nullptr; c = v; }
};

void Insert(char val)
{
	if (start == nullptr) // first node
	{
		start = new Node(val);
		curr = start;
		last = start;
	}
	else if (curr == last) // insert at end
	{
		Node *p = new Node(val);
		curr->right = p;
		p->left = curr;
		curr = p;
		last = p;
	}
	else // curr is in the middle, so insert in middle
	{
		Node* p = new Node(val);
		Node *t = curr->right;
		curr->right = p;
		p->left = curr;
		t->left = p;
		p->right = t;
		curr = curr->right;
	}
}

void main()
{
	start = curr = last = nullptr;
	Insert('A');
	Insert('B');
	Insert('C');
	Insert('D');
	Insert('E');
	curr = curr->left;
	curr = curr->left;
	curr = curr->left;
	curr = curr->left;
	Insert('1');
	Insert('2');
}