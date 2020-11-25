#include <iostream>
#include <string>		// Necessário para usar strings
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class GerenciadorDeArquivo{
	public:
	
	static string convertTXTtoString(char *endereco){
		FILE *fl;
		int c;
		string resultado = "";

		if((fl = fopen(endereco, "r")) == NULL)
		{
			perror("Erro: fopen");
		}

		while((c = fgetc(fl)) != EOF){
			resultado += c;
		}

		if((c == EOF) && (feof(fl) == 0) && (ferror(fl) != 0))
			perror("Erro: fgetc");
		
		fclose(fl);
		return resultado;
	}
};
