#include "Edge.h"
#include "Node.h"

Edge::Edge(Node *source, Node *dest)
{
	this->source = source;
	this->dest = dest;
}

Node* Edge::getSource()
{
	return this->source;
}

Node* Edge::getDest()
{
	return this->dest;
}

int Edge::getUpSpeed()
{
	return this->source->getUpSpeed() + this->dest->getDownSpeed();
}

int Edge::getDownSpeed()
{
	return this->source->getDownSpeed() + this->dest->getUpSpeed();
}

std::string Edge::toDot()
{
	std::string result = "	" + std::to_string(source->getId()) + " -> " + std::to_string(dest->getId());
	result += " [";
	result += "label=\"" + std::to_string(this->getUpSpeed()) + "/" + std::to_string(this->getDownSpeed()) + "\"";
	result += "];\n";
	return result;
}
