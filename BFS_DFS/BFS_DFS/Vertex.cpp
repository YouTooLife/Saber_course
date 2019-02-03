//
//  Vertex.cpp
//  BFS_DFS
//
//  Created by YouTooLife on 03/12/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#include "Vertex.hpp"


void Vertex::addEdge(Vertex* vertex)
{
    this->edges.push_back(vertex);
}

void Vertex::print() const
{
    cout << this->name << ") ";
    cout << " d = " << this->d << "; prev = " << (this->prev? this->prev->getName(): "nil") <<"\n";
}

void Vertex::printDFS() const
{
    print();
    cout << "    t = " << this->t << "\n";
}

list<Vertex*>& Vertex::getEdges()
{
    return this->edges;
}

const list<Vertex*>& Vertex::getEdges() const
{
    return this->edges;
}
