#include <stdio.h>

class Node
{

private:
    int chave;
    Node *prox;
    char info[50];

public:
    //Construtores
    Node();

    Node(int chave, Node *prox);

    //setters
    void setChave(int chava);
    void setProx(Node *prox);

    //getters
    int getChave();
    Node *getProx();
};