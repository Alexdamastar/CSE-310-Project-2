include "Graph.h"

Graph::Graph(int numVertices, int numEdges){
    this->numVertices = numVertices;
    this->numEdges = numEdges;

    this->vertices = new Vertex[numVertices];

    this->adjMatrix = new int[numVertices][numVertices];

    for (int i = 0; i < numVertices; i++){
        Vertex v = Vertex();
        v.setIndex(i);
        v.setDegree(0);
        this->vertices[i] = v;
    }
}

Graph::~Graph(){
    for(int i = 0; i < this->numVertices; i++){
        delete this->vertices[i];
    }
    
    delete[] this->vertices;

    for(int i = 0; i < this->numVertices; i++){
        delete[] this->adjMatrix[i];
    }
    
    delete[] this->adjMatrix;
}

Graph::addEdge(Edge* edge){
    int start = edge->getStartVert();
    int end = edge->getEndVert();
    int weight = edge->getWeight();

    this->vertices[start].setDegree(this->vertices[start].getDegree() + 1);
    this->vertices[end].setDegree(this->vertices[end].getDegree() + 1);
    
    this->adjMatrix[start][end] = weight;
    this->adjMatrix[end][start] = weight;
}

Graph::printAdjMatrix(){
    std::cout << "The adjacency matrix of G is: " << std::endl;
    for(int i = 0; i < this->numVertices; i++){
        for(int j = 0; j < this->numVertices; j++){
            std::cout << this->adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Graph::printOddDegree(){

}

Graph::printDijkstra(){
    
}