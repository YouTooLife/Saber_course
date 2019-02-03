//
//  Graph.cpp
//  BFS_DFS
//
//  Created by YouTooLife on 03/12/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#include "Graph.hpp"
#include <string>


void Graph::add(Vertex& u)
{
    uint8_t range = 'Z'-'A'+1;
    size_t n = this->vertices.size();
    
    string name = "";
    do
    {
        uint8_t mod = n % range;
        name = (char)('A'+mod) + name;
    } while ((n = n / range));
    u.setName(name);
    
    this->vertices.push_back(u);
}

void Graph::addAll(vector<Vertex>& v)
{
    for (Vertex& u: v)
    {
        this->add(u);
    }
}
vector<Vertex>& Graph::V()
{
    return vertices;
}

void Graph::addEdge(Vertex& u, Vertex* v)
{
    u.addEdge(v);
}

bool Graph::isEmpty() const
{
    return vertices.empty();
}
list<Vertex*>& Graph::getAdj(Vertex& u)
{
    return u.getEdges();
}


void Graph::print() const
{
    cout << "\nGraph: \n";
    for (const Vertex& u: this->vertices)
    {
        cout << u.getName() << ")  ";
        for (const Vertex* v: u.getEdges())
            cout << "-" << v->getName();
        cout << "\n";
    }
    cout << "---------\n\n";
}
