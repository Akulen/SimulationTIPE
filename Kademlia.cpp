#include "Kademlia.h"

Kademlia::Kademlia(int nbBits, int bucketSize)
{
	this->nbBits = nbBits;
	this->nbNodes = 1 << nbBits;
	this->bucketSize = bucketSize;
	for(int iNode = 0; iNode < this->nbNodes; ++iNode)
		this->graph.push_back(Node(nbBits, iNode, bucketSize));
}

int Kademlia::getNbBits()
{
	return this->nbBits;
}

int Kademlia::getNbNodes()
{
	return this->nbNodes;
}

int Kademlia::getBucketSize()
{
	return this->bucketSize;
}

Node* Kademlia::getNode(int idNode)
{
	if(idNode < 0 && idNode >= this->nbNodes)
		idNode = 0;
	return &this->graph[idNode];
}

std::string Kademlia::toDot()
{
	std::string result = "digraph {\n";
	for(std::vector<Node>::iterator nodeIt = this->graph.begin(); nodeIt != this->graph.end(); ++nodeIt)
		result += nodeIt->toDot();
	result += "}\n";
	return result;
}

int Kademlia::closestFather(int iNode, int jNode)
{
	int difference = iNode xor jNode;
	int distance = this->nbBits;
	while(distance > 0 && !(difference & (1 << (distance - 1))))
		--distance;
	return distance;
}
