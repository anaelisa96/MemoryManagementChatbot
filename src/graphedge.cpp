#include "graphnode.h"
#include "graphedge.h"

#include <iostream>

GraphEdge::GraphEdge(int id)
{
    std::cout << " GraphEdge Constructor\n";
    _id = id;
}

// TO REMOVE
GraphEdge::~GraphEdge()
{
    std::cout << "---> Graph Edge Destructor\n";
}

void GraphEdge::SetChildNode(GraphNode *childNode)
{
    _childNode = childNode;
}

void GraphEdge::SetParentNode(GraphNode *parentNode)
{
    _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token)
{
    _keywords.push_back(token);
}