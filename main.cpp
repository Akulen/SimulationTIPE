#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>

#include "Kademlia.h"

void dotToFile(std::string name, std::string dot)
{
	FILE *file = fopen((std::string("Dot/") + name + std::string(".dot")).c_str(), "w");
    fprintf(file, "%s", dot.c_str());
	fclose(file);
}

int main()
{
	srand(time(0));
	Kademlia reseau(4);
	printf("%d\n", reseau.getNbNodes());
	for(int iNode = 0; iNode < reseau.getNbNodes(); ++iNode)
		if(rand() % 2)
			reseau.getNode(iNode)->toggleConnected();
	for(int iNode = 0; iNode < reseau.getNbNodes(); ++iNode)
	{
		reseau.getNode(iNode)->setUpSpeed((rand() % 81) + 20);
		reseau.getNode(iNode)->setDownSpeed((rand() % 41) + 10);
		if(reseau.getNode(iNode)->isConnected())
			for(int jNode = 0; jNode < reseau.getNbNodes(); ++jNode)
				if(iNode != jNode && reseau.getNode(jNode)->isConnected())
					if(rand() % 5 == 0)
						reseau.getNode(iNode)->addEdge(Edge(reseau.getNode(iNode), reseau.getNode(jNode)));
	}
	dotToFile("plop", reseau.toDot());
	return 0;
}
