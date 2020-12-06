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

    string encodedString, decodedString; 
    
    calcFreq(str, str.length()); 
    
    HuffmanCodes(str.length()); 
    
    cout << "Caracteres e suas frequencias:\n"; 
    
    for (auto v=codes.begin(); v!=codes.end(); v++) 
        cout << v->first <<' ' << v->second << endl; 
  
    for (auto i: str) 
        encodedString+=codes[i]; 
  
    cout << "\nDados codificados Huffman:\n" << encodedString << endl; 

    GerenciadorDeArquivo::convertStringtoArqFreq(encodedString);
  
    decodedString = decode_file(minHeap.top(), encodedString); 
    
    cout << "\nDados decodificados do Huffman:\n" << decodedString << endl; 
    
    GerenciadorDeArquivo::convertStringtoArqDefreq(decodedString);

    return 0; 

}