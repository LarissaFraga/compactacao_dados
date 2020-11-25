#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "GerenciadorDeArquivo.cpp"
using namespace std;

int main(int argc, char *argv[])
{

    string documentoString = GerenciadorDeArquivo::convertTXTtoString(argv[1]);
  
    cout << documentoString << "\n";

    cout << "Esse texto possui: "<< documentoString.size() <<" caracteres"<< "\n";

}