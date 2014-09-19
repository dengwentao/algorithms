//
//  CloneGraph.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/18/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include <assert.h>
#include "CloneGraph.h"

struct Node
{
    vector<Node*> neighbors;
    int value;
    bool visited;
    
    Node(int v){value=v; visited=false;};
    void AddNeighbor(Node* p){neighbors.push_back(p);};

    void Print()
    {
        if(visited)
            return;
        else
            visited = true;
        cout << value << ' ';
        for(vector<Node*>::const_iterator it=neighbors.begin(); it!=neighbors.end(); ++it)
            (*it)->Print();
    }
};

class Graph
{
public:
    vector<Node*> nodes;
    Graph(){};
    ~Graph(){};
    void Init();
    void Clear();
    void Print();
    Graph* Clone();
};

// set up a connected directional graph
void Graph::Init()
{
    Node* n0 = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n0->AddNeighbor(n1);
    n0->AddNeighbor(n2);
    n0->AddNeighbor(n3);
    n1->AddNeighbor(n2);
    n1->AddNeighbor(n3);
    n2->AddNeighbor(n0);
    n2->AddNeighbor(n1);
    n3->AddNeighbor(n4);
    nodes.push_back(n0);
    nodes.push_back(n1);
    nodes.push_back(n2);
    nodes.push_back(n3);
    nodes.push_back(n4);
}

void Graph::Clear()
{
    for(vector<Node*>::const_iterator it=nodes.begin(); it!=nodes.end(); ++it)
        (*it)->visited = false;
}

void Graph::Print()
{
    Clear();
    for(vector<Node*>::const_iterator it=nodes.begin(); it!=nodes.end(); ++it)
        (*it)->Print();
    cout << endl;
}

Graph* Graph::Clone()
{
    map<Node*, Node*> m;
    Graph* g = new Graph();
    //create nodes vector for new graph and keep a mapping between old and new.
    for(vector<Node*>::const_iterator it=nodes.begin(); it!=nodes.end(); ++it)
    {
        Node* n = new Node((*it)->value);
        g->nodes.push_back(n);
        m[*it] = n; // map old Node* to new Node*
    }
    //for each old node, update mapped new node for their neighbors.
    for(vector<Node*>::const_iterator it=nodes.begin(); it!=nodes.end(); ++it)
    {
        for(vector<Node*>::const_iterator cit=(*it)->neighbors.begin(); cit!=(*it)->neighbors.end(); ++cit)
            m[*it]->neighbors.push_back(m[*cit]);
    }
    return g;
}

int main()
{
    Graph* g = new Graph();
    g->Init();
    g->Print();
    Graph* g2 = g->Clone();
    g2->Print();
    return 0;
}
