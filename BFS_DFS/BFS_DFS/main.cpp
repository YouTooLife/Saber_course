//
//  main.cpp
//  BFS_DFS
//
//  Created by YouTooLife on 03/12/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#include <iostream>
#include <vector>

#include "Graph.hpp"
#include "Vertex.hpp"
#include "BFS.hpp"
#include "DFS.hpp"

int main(int argc, const char * argv[]) {
    
    Graph G;
    vector<Vertex> vertices(8);
    
    G.addAll(vertices);
    
    G.addEdge(G.V()[7], &G.V()[3]);
    G.addEdge(G.V()[6], &G.V()[5]);
    G.addEdge(G.V()[6], &G.V()[2]);
    G.addEdge(G.V()[6], &G.V()[7]);
    G.addEdge(G.V()[6], &G.V()[3]);
    G.addEdge(G.V()[5], &G.V()[1]);
    G.addEdge(G.V()[5], &G.V()[2]);
    G.addEdge(G.V()[0], &G.V()[1]);
    G.addEdge(G.V()[1], &G.V()[0]);
    G.addEdge(G.V()[4], &G.V()[0]);
    G.addEdge(G.V()[0], &G.V()[4]);
    G.addEdge(G.V()[1], &G.V()[5]);
    G.addEdge(G.V()[2], &G.V()[6]);
    G.addEdge(G.V()[2], &G.V()[5]);
    G.addEdge(G.V()[2], &G.V()[3]);
    G.addEdge(G.V()[3], &G.V()[2]);
    G.addEdge(G.V()[3], &G.V()[6]);
    G.addEdge(G.V()[3], &G.V()[7]);
    G.addEdge(G.V()[6], &G.V()[7]);
    G.addEdge(G.V()[7], &G.V()[6]);
    G.addEdge(G.V()[5], &G.V()[6]);
    G.addEdge(G.V()[6], &G.V()[5]);
    
    G.print();
    
    BFS::BFS_FIND(G, G.V()[1]);
    
    
    G.V().clear();
    vertices.pop_back();
    vertices.pop_back();
    G.addAll(vertices);
    
    G.addEdge(G.V()[0], &G.V()[1]);
    //G.addEdge(G.V()[0], &G.V()[4]);
    G.addEdge(G.V()[0], &G.V()[3]);
    
    //G.addEdge(G.V()[1], &G.V()[0]);
    //G.addEdge(G.V()[1], &G.V()[5]);
    G.addEdge(G.V()[1], &G.V()[4]);
    //G.addEdge(G.V()[1], &G.V()[2]);
    
    //G.addEdge(G.V()[2], &G.V()[1]);
    G.addEdge(G.V()[2], &G.V()[4]);
    G.addEdge(G.V()[2], &G.V()[5]);

    //G.addEdge(G.V()[3], &G.V()[6]);
    //G.addEdge(G.V()[3], &G.V()[7]);
    G.addEdge(G.V()[3], &G.V()[1]);
    
    //G.addEdge(G.V()[4], &G.V()[0]);
    //G.addEdge(G.V()[4], &G.V()[1]);
    G.addEdge(G.V()[4], &G.V()[3]);
    
    //G.addEdge(G.V()[5], &G.V()[4]);
    //G.addEdge(G.V()[5], &G.V()[1]);
    G.addEdge(G.V()[5], &G.V()[5]);
    
    /*
    G.addEdge(G.V()[6], &G.V()[2]);
    G.addEdge(G.V()[6], &G.V()[5]);
    G.addEdge(G.V()[6], &G.V()[3]);
    
    G.addEdge(G.V()[7], &G.V()[3]);
    G.addEdge(G.V()[7], &G.V()[6]);
     */
    
    G.print();
    
    DFS::DFS_RUN(G);
    
    return 0;
}
