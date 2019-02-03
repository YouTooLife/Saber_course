//
//  Graph.hpp
//  BFS_DFS
//
//  Created by YouTooLife on 03/12/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <vector>
#include <list>

#include "Vertex.hpp"

using namespace std;

class Graph {
    
private:
    vector<Vertex> vertices;

public:
    void add(Vertex& u);
    void addAll(vector<Vertex>& v);
    void addEdge(Vertex& u, Vertex* v);
    bool isEmpty() const;
    vector<Vertex>& V();
    list<Vertex*>& getAdj(Vertex& u);
    
    void print() const;
};

#endif /* Graph_hpp */
