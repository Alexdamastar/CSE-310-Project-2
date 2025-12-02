#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "Edge.h"

class Graph {
    private:
        int numVertices;
        int numEdges;
        Vertex* vertices;
        Edge* edges;
        int** adjMatrix;
    public:
        Graph(int, int);
        ~Graph();
        void addEdge(Edge*);
        void addVertex(Vertex*);
        void printAdjMatrix();
        void printOddDegree();
        void printDijkstra();
};

#endif