#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{


    //delete _chatBot;       //Deleted for task 0


}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}


//void GraphNode::MoveChatbotHere(ChatBot *chatbot)   //task 5
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    /*   task 5
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
    */

    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    //_chatBot = nullptr; // invalidate pointer at source //deleted for task 5
}


GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{


    //return _childEdges[index];     //deleted for task 4
    return _childEdges[index].get();


}
