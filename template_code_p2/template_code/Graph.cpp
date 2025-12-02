include "Graph.h"

Graph::Graph(int numVertices, int numEdges){
    this->numVertices = numVertices;
    this->numEdges = numEdges;

    this->vertices = new Vertex[numVertices];
    this->edges = new Edge[numEdges];

    this->adjMatrix = new int[numVertices][numVertices];
}

Graph::~Graph(){
    delete[] this->vertices;
    delete[] this->edges;

    for(int i = 0; i < this->numVertices; i++){
        delete[] this->adjMatrix[i];
    }
    
    delete[] this->adjMatrix;
}