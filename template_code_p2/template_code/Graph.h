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
        void addEdge(int, int, int);
        void removeEdge(int, int);
        bool isEdge(int, int);
        int getWeight(int, int);
        void printAdjMatrix();
        void printOddDegree();
        void printDijkstra();
};

#endif