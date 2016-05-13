#ifndef DEF_KADEMLIA
#define DEF_KADEMLIA

#include <string>
#include <vector>

#include "Node.h"

class Kademlia
{
	public:

	Kademlia(int nbBits, int bucketSize = 20);
	int getNbBits();
	int getNbNodes();
	int getBucketSize();
	Node* getNode(int idNode);
	void writeToFile(std::string name);
	std::string toDot();

	private:

	int nbBits;
	int nbNodes;
	int bucketSize;
	std::vector<Node> graph;
};

#endif
