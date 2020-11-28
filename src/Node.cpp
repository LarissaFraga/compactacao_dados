#include "Node.h"

Node::Node()
{
    prox = 0;
}

Node::Node(int c, Node *p = 0)
{
    chave = c;
    prox = p;
}

//setters
void Node::setChave(int chave)
{
    this->chave = chave;
}

void Node::setProx(Node *p)
{
    this->prox = p;
}

//getters
int Node::getChave()
{
    return chave;
}

Node *Node::getProx()
{
    return prox;
}