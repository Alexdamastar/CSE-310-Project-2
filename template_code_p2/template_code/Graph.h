#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "Edge.h"

class Graph {
    private:
        int numVertices;
        int numEdges;
        Vertex* vertices;
        int** adjMatrix;
    public:
        Graph(int, int);
        ~Graph();
        void addEdge(Edge*);
        void printAdjMatrix();
        void printOddDegree();
        void printDijkstra();
        void printDijkstra(int);
};

#endif