#include "Node.h"

Node::Node(int nbBits, int id, int bucketSize)
{
	this->nbBits = nbBits;
	this->id = id;
	this->bucketSize = bucketSize;
	this->buckets.resize(nbBits);
}

int Node::getNbBits()
{
	return this->nbBits;
}

int Node::getId()
{
	return this->id;
}

int Node::getBucketSize()
{
	return this->bucketSize;
}

std::string Node::toDot()
{
	std::string result = "	" + std::to_string(this->id) + " -- { ";
	for(std::vector<std::vector<Node> >::iterator bucketIt = this->buckets.begin(); bucketIt != this->buckets.end(); ++bucketIt)
		for(std::vector<Node>::iterator nodeIt = bucketIt->begin(); nodeIt != bucketIt->end(); ++nodeIt)
			result += std::to_string(nodeIt->getId()) + " ";
	result += "};\n";
	return result;
}
