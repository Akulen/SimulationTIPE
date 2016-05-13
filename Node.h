#ifndef DEF_NODE
#define DEF_NODE

#include <string>
#include <vector>

#include "Edge.h"

class Node
{
	public:

	Node(int nbBits, int id, int bucketSize = 20, bool connected = false, int upSpeed = 50, int downSpeed = 10);
	int getNbBits();
	int getId();
	int getBucketSize();
	std::string toDot();
	bool isConnected();
	void toggleConnected();
	void addEdge(Edge toAdd);
	int getUpSpeed();
	void setUpSpeed(int speed);
	int getDownSpeed();
	void setDownSpeed(int speed);

	private:

	int nbBits;
	int id;
	int bucketSize;
	std::vector<std::vector<Edge> > buckets;

	bool connected;
	int upSpeed;
	int downSpeed;
};

#endif
