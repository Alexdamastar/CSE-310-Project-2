#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    private:
        int numVertices;
        int** adjMatrix;
    public:
        Graph(int);
        ~Graph();
        void addEdge(int, int, int);
        void removeEdge(int, int);
        bool isEdge(int, int);
        int getWeight(int, int);
        void printAdjMatrix();
        void printOddDegree();
        void printDijkstra(int);
};

#endif