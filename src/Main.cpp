#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "GerenciadorDeArquivo.cpp"
#include "Huffman.cpp"

using namespace std;

int main(int argc, char *argv[])
{

    string documentoString = GerenciadorDeArquivo::convertTXTtoString(argv[1]);

    // cout << documentoString << "\n";

    // cout << "Esse texto possui: "<< documentoString.size() <<" caracteres"<< "\n";

    string str = documentoString;

    string compactadaString, descompactadaString;

    calculaFreq(str, str.length());

    codigoHuffman(str.length());

    cout << "Caracteres e suas frequências:\n";

    for (auto v = codes.begin(); v != codes.end(); v++)
        cout << v->first << ' ' << v->second << endl;

    for (auto i : str)
        compactadaString += codes[i];

    cout << "\nDados codificados Huffman:\n"
         << compactadaString << endl;

    GerenciadorDeArquivo::convertStringtoArqFreq(compactadaString);

    descompactadaString = decodifica(minHeap.top(), compactadaString);

    cout << "\nDados decodificados do Huffman:\n"
         << descompactadaString << endl;

    GerenciadorDeArquivo::convertStringtoArqDefreq(descompactadaString);

    return 0;
}
