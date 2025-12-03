#include "Graph.h"
#include <iostream>

Graph::Graph(int numVertices, int numEdges){
    this->numVertices = numVertices;
    this->numEdges = numEdges;

    this->vertices = new Vertex[numVertices];

    this->adjMatrix = new int*[numVertices];
    for(int i = 0; i < numVertices; i++){
        this->adjMatrix[i] = new int[numVertices];
    }

    for (int i = 0; i < numVertices; i++){
        Vertex v = Vertex();
        v.setIndex(i);
        v.setDegree(0);
        this->vertices[i] = v;
    }
}

Graph::~Graph(){
    delete[] this->vertices;

    for(int i = 0; i < this->numVertices; i++){
        delete[] this->adjMatrix[i];
    }
    
    delete[] this->adjMatrix;
}

void Graph::addEdge(Edge* edge){
    int start = edge->getStartVert();
    int end = edge->getEndVert();
    int weight = edge->getWeight();

    this->vertices[start].setDegree(this->vertices[start].getDegree() + 1);
    this->vertices[end].setDegree(this->vertices[end].getDegree() + 1);
    
    this->adjMatrix[start][end] = weight;
    this->adjMatrix[end][start] = weight;
}

void Graph::printAdjMatrix(){
    std::cout << "The adjacency matrix of G is: " << std::endl;
    for(int i = 0; i < this->numVertices; i++){
        for(int j = 0; j < this->numVertices; j++){
            std::cout << this->adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Graph::printOddDegree(){
    std::cout << "The nodes with odd degrees in G are: " << std::endl;

    std::cout << "O = { "
    for(int i = 0; i < this->numVertices; i++){
        if(this->vertices[i].getDegree() % 2 != 0){
            std::cout << this->vertices[i].getIndex() << " ";
        }
    }
    
    std::cout << "}" << std::endl;
}

void Graph::printDijkstra(){
    
}