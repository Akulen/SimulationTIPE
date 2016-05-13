#ifndef DEF_EDGE
#define DEF_EDGE

#include <string>

class Node;

class Edge
{
	public:

	Edge(Node *source, Node *dest);
	Node* getSource();
	Node* getDest();
	int getUpSpeed();
	int getDownSpeed();
	std::string toDot();

	private:

	Node *source;
	Node *dest;
};

#endif
