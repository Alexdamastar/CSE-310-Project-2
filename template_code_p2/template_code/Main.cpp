#include "Edge.h"
#include "Graph.h"
#include "Vertex.h"
#include <iostream>

int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices;
    int numOfEdges;

    if(!std::cin.eof()){
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    }
    else{
        std::cout<<"Input not found!"<<std::endl;
        return -1;
    }

    Graph graph = Graph(numOfVertices, numOfEdges);


    while(!std::cin.eof()){
        int startVertice;
        int endVertice;
        int weight;
        std::cin >> startVertice;
        std::cin >> endVertice;
        std::cin >> weight;
        
        Edge* newEdge = new Edge(startVertice, endVertice);
        newEdge->setWeight(weight);

        graph.addEdge(newEdge);
    }

    graph.printAdjMatrix();

    return 0;
}