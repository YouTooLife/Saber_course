//
//  Vertex.hpp
//  BFS_DFS
//
//  Created by YouTooLife on 03/12/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <list>
#include <iostream>
#include <string>

using namespace std;


enum Color {
    WHITE = 0, GRAY, BLACK
};

class Vertex {

private:
    string name;
    list<Vertex*> edges;
    
public:
    size_t d;
    size_t t;
    Vertex* prev;
    Color color;
    
    Vertex(size_t d = -1, Color color = WHITE, size_t t = 0, Vertex* prev = nullptr):
    d(d), color(color), t(t), prev(prev) {
    };

    void addEdge(Vertex* vertex);
    list<Vertex*>& getEdges();
    const list<Vertex*>& getEdges() const;
    void print() const;
    void printDFS() const;
    
    void setName(const string& name) { this->name = name; }
    const string& getName() const { return name; }
};

#endif /* Vertex_hpp */
