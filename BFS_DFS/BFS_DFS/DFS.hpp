//
//  DFS.hpp
//  BFS_DFS
//
//  Created by YouTooLife on 03/12/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#ifndef DFS_hpp
#define DFS_hpp

#include "Graph.hpp"
#include "Vertex.hpp"

#include <iostream>
#include <queue>

class DFS
{
    
private:
    static void DFS_Visit(Graph& G, Vertex& u);
    
public:
    static size_t g_time;
    static queue<Vertex*> q_dfs;
    static void DFS_RUN(Graph& G);
};

#endif /* DFS_hpp */
