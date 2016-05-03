#include "Node.h"
#include "Edge.h"

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
	for(std::vector<std::vector<Edge*> >::iterator bucketIt = this->buckets.begin(); bucketIt != this->buckets.end(); ++bucketIt)
		for(std::vector<Edge*>::iterator edgeIt = bucketIt->begin(); edgeIt != bucketIt->end(); ++edgeIt)
			result += std::to_string((*edgeIt)->getDest()->getId()) + " ";
	result += "};\n";
	return result;
}
