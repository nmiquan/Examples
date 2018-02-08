CC=gcc

GraphClient: AdjacencyList.o GraphClient.c Graph.h
	$(CC) -Werror -Wall AdjacencyList.o GraphClient.c Graph.h -o graph

AdjacencyList: AdjacencyList.c Graph.h
	$(CC) -Werror -Wall AdjacencyList.c Graph.h -o AdjacencyList.o
