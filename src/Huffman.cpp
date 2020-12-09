#include <iostream>
#include <map>
#include <queue>
#include "MinNoHeap.cpp"

#define MAX_TREE_HT 256
using namespace std;

map<char, string> codes;

map<char, int> freq;

struct compare
{
    bool operator()(MinNoHeap *l, MinNoHeap *r)
    {
        return (l->freq > r->freq);
    }
};

void imprime(struct MinNoHeap *pt, string str)
{
    if (!pt)
        return;
    if (pt->data != '$')
        cout << pt->data << ": " << str << "\n";
    imprime(pt->left, str + "0");
    imprime(pt->right, str + "1");
}
void armazenaCodigo(struct MinNoHeap *pt, string str)
{
    if (pt == NULL)
        return;
    if (pt->data != '$')
        codes[pt->data] = str;
    armazenaCodigo(pt->left, str + "0");
    armazenaCodigo(pt->right, str + "1");
}

priority_queue<MinNoHeap *, vector<MinNoHeap *>, compare> minHeap;

void codigoHuffman(int size)
{
    struct MinNoHeap *left, *right, *top;
    for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
        minHeap.push(new MinNoHeap(v->first, v->second));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinNoHeap('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    armazenaCodigo(minHeap.top(), "");
}

void calculaFreq(string str, int n)
{
    for (int i = 0; i < str.size(); i++)
        freq[str[i]]++;
}

string decodifica(struct MinNoHeap *pt, string s)
{
    string ans = "";
    struct MinNoHeap *atual = pt;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            atual = atual->left;
        else
            atual = atual->right;

        if (atual->left == NULL && atual->right == NULL)
        {
            ans += atual->data;
            atual = pt;
        }
    }
    return ans + '\0';
}