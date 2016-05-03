#ifndef DEF_NODE
#define DEF_NODE

#include <string>
#include <vector>

class Node
{
	public:

	Node(int nbBits, int id, int bucketSize = 20);
	int getNbBits();
	int getId();
	int getBucketSize();
	std::string toDot();

	private:

	int nbBits;
	int id;
	int bucketSize;
	std::vector<std::vector<Node> > buckets;
};

#endif
