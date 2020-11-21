#include "Node.h";

class Busca_Digital
{
private:
    char* x;
    Node *pt;
    int l;
    bool a;

public:
    //construtor
    Busca_Digital();

    //método de busca
    bool busca(char*, Node*, int, bool);
};