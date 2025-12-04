#include "Graph.h"
#include <iostream>

Graph::Graph(int numVertices, int numEdges){
    this->numVertices = numVertices;
    this->numEdges = numEdges;
    this->vertices = new Vertex[numVertices + 1];

    this->adjMatrix = new int*[numVertices + 1];
    for(int i = 0; i <= numVertices; i++){
        this->adjMatrix[i] = new int[numVertices + 1];
        for(int j = 0; j <= numVertices; j++){
            this->adjMatrix[i][j] = 0;
        }
    }

    for (int i = 1; i <= numVertices; i++){
        Vertex v = Vertex();
        v.setIndex(i);
        v.setDegree(0);
        this->vertices[i] = v;
    }
}

Graph::~Graph(){
    delete[] this->vertices;

    for(int i = 0; i <= this->numVertices; i++){
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
    for(int i = 1; i <= this->numVertices; i++){
        for(int j = 1; j <= this->numVertices; j++){
            std::cout << this->adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Graph::printOddDegree(){
    std::cout << "The nodes with odd degrees in G are: " << std::endl;
    std::cout << "O = { ";

    for(int i = 1; i <= this->numVertices; i++){
        if(this->vertices[i].getDegree() % 2 != 0){
            std::cout << this->vertices[i].getIndex() << " ";
        }
    }

    std::cout << "}" << std::endl;
}

void Graph::printDijkstra(){
    for(int i = 1; i <= this->numVertices; i++){
        if(this->vertices[i].getDegree() % 2 != 0){
            printDijkstra(i);
        }
    }
}

void Graph::printDijkstra(int vertex){
    const int INF = 1000000000;

    int numVertices = this->numVertices;
    int* dist = new int[numVertices + 1];
    bool* visited = new bool[numVertices + 1];

    for(int i = 1; i <= numVertices; i++){
        dist[i] = INF;
        visited[i] = false;
    }

    dist[vertex] = 0;

    for(int iter = 1; iter <= numVertices; iter++){
        int u = -1;
        int best = INF;
        for(int i = 1; i <= numVertices; i++){
            if(!visited[i] && dist[i] < best){
                best = dist[i];
                u = i;
            }
        }

        if(u == -1) break;
        visited[u] = true;

        for(int v = 1; v <= numVertices; v++){
            if(visited[v]) continue;
            int w = this->adjMatrix[u][v];
            if(w <= 0) continue;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    std::cout << std::endl;
    std::cout << "The shortest path lengths from Node " << vertex << " to all other nodes are: " << std::endl;

    for(int i = 1; i <= numVertices; i++){
        if(dist[i] >= INF) std::cout << "  " << i << ": INF" << std::endl;
        else std::cout << "  " << i << ": " << dist[i] << std::endl;
    }

    delete[] dist;
    delete[] visited;
}