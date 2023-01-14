
#include "graphedge.h"
#include "graphnode.h"

#include <iostream>

GraphNode::GraphNode(int id)
{
    std::cout << "----> GraphNode Constructor with _chatBot address " << &_chatBot << "\n";
    _id = id;
}

GraphNode::~GraphNode()
{
    std::cout << "---> GraphNode Destructor with _chatBot address: " << &_chatBot << "  ";
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
void GraphNode::MoveChatbotHere(ChatBot /***/chatbot)
{
    //std::cout << "Address of _chatBot in MoveChatbotHere: " << &_chatBot << "\n";
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    //std::cout << "Address of _chatBot in MoveChatbotToNewNode: " << &_chatBot << "\n";
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////
    return (_childEdges[index]).get();

    ////
    //// EOF STUDENT CODE
}