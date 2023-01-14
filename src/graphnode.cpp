
#include "graphedge.h"
#include "graphnode.h"

#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    /* 
        My comment - TASK 0:
        GraphNode destructor is wrongly deleting _chatbot variable,
        ChatLogic destructor is already deleting this variable which 
        is first created by ChatLogic constructor.
    */
    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(/*GraphEdge *edge*/std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
/*
    My comment: Task 5: This function in parameter cannot be a pointer anymore.
*/
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    /*
        My comment: Task 5: Remove _chatBot = nullptr; because _chatBot is not a pointer anymore.
    */
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////
    /*
        My comment - Task 4: Add .get because function returns a raw pointer.
    */
    return (_childEdges[index]).get();

    ////
    //// EOF STUDENT CODE
}