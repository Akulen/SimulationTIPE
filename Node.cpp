#include "Node.h"

Node::Node(int nbBits, int id, int bucketSize, bool connected, int upSpeed, int downSpeed)
{
	this->nbBits = nbBits;
	this->id = id;
	this->bucketSize = bucketSize;
	this->buckets.resize(nbBits);
	this->connected = connected;
	this->upSpeed = upSpeed;
	this->downSpeed = downSpeed;
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
	std::string result = "	" + std::to_string(this->id) + "[color=" + (this->connected ? "green" : "red") + "; style=filled];\n";
	for(std::vector<std::vector<Edge> >::iterator bucketIt = this->buckets.begin(); bucketIt != this->buckets.end(); ++bucketIt)
		for(std::vector<Edge>::iterator edgeIt = bucketIt->begin(); edgeIt != bucketIt->end(); ++edgeIt)
			result += (*edgeIt).toDot();
	return result;
}

bool Node::isConnected()
{
	return this->connected;
}

void Node::toggleConnected()
{
	this->connected = !this->connected;
}

void Node::addEdge(Edge toAdd)
{
	this->buckets[0].push_back(toAdd);
}

int Node::getUpSpeed()
{
	return this->upSpeed;
}

void Node::setUpSpeed(int speed)
{
	this->upSpeed = speed;
}

int Node::getDownSpeed()
{
	return this->downSpeed;
}

void Node::setDownSpeed(int speed)
{
	this->downSpeed = speed;
}
