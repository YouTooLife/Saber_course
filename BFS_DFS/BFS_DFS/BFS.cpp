//
//  BFS.cpp
//  BFS_DFS
//
//  Created by YouTooLife on 03/12/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#include <queue>


#include "BFS.hpp"


void BFS::BFS_FIND(Graph& G, Vertex& s)
{
    for (Vertex& u:G.V())
    {
        u.color = WHITE;
        u.d = 0;
        u.prev = nullptr;
    }
    
    s.color = GRAY;
    s.d = 0;
    s.prev = nullptr;
    
    queue<Vertex*> Q;
    Q.push(&s);
    
    
    cout << "\nBFS: from " << s.getName() <<"\n";
    
    while (!Q.empty()) {
        
        Vertex* u = Q.front();
        Q.pop();
        for (Vertex* v: G.getAdj(*u))
        {
            if (v->color == WHITE) {
                v->color = GRAY;
                v->d = u->d + 1;
                v->prev = u;
                Q.push(v);
            }
        }
        u->color = BLACK;
        u->print();
    }
    cout << "\n---------\n\n";
}
