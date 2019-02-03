//
//  DFS.cpp
//  BFS_DFS
//
//  Created by YouTooLife on 03/12/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#include "DFS.hpp"

size_t DFS::g_time;
queue<Vertex*> DFS::q_dfs;

void DFS::DFS_Visit(Graph& G, Vertex& u)
{
    DFS::g_time++;
    u.d = DFS::g_time;
    u.color = GRAY;
    
    cout << " (" << u.getName() << "";
    
    for (Vertex* v: G.getAdj(u))
    {
        if (v->color == WHITE) {
            v->prev = &u;
            DFS_Visit(G, *v);
        }
    }
    cout << ")";
    u.color = BLACK;
    DFS::g_time++;
    u.t = DFS::g_time;
    DFS::q_dfs.push(&u);
}


void DFS::DFS_RUN(Graph& G)
{
    for (Vertex& u: G.V())
    {
        u.color = WHITE;
        u.prev = nullptr;
    }
    
    DFS::g_time = 0;
    DFS::q_dfs = {};
    
    cout << "\nDFS: \n";
    
    for (Vertex& u: G.V())
    {
        if (u.color == WHITE) {
            DFS_Visit(G, u);
        }
    }
    
    cout << "\n-------\n\n";
    
    while (!DFS::q_dfs.empty()) {
        Vertex* u = DFS::q_dfs.front();
        DFS::q_dfs.pop();
        u->printDFS();
    }
    
    cout << "\n-------\n\n";
}
