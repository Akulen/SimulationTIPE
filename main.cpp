#include <cstdio>
#include <string>

#include "Kademlia.h"

void dotToFile(std::string name, std::string dot)
{
	FILE *file = fopen((std::string("Dot/") + name + std::string(".dot")).c_str(), "w");
    fprintf(file, "%s", dot.c_str());
	fclose(file);
}

int main()
{
	Kademlia reseau(4);
	printf("%d\n", reseau.getNbNodes());
	dotToFile("plop", reseau.toDot());
	return 0;
}
