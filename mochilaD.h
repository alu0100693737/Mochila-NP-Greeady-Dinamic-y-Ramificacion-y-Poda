#ifndef _MOCHILA_ENTRADA1_H
#define _MOCHILA_ENTRADA1_H

#include <iostream>
#include <fstream>
#include <stdio.h>
 
using namespace std;

class mochilaD{

	private:
	  int tamMochila;
	  int numElementos;
	  int *pesoItems;
	  int *valorItems;
	  
	  double *vectorOrdenado;
	  
	  int **matriz;
	  int totalItems;
	  int filas;
	  int columnas;
  
	  void read(istream &is);

	  void mostrarMatriz();
		
	  void construirMatriz();
		
	  void recurrencia(int j,int c);
	
	  int queItemsHay();
	  void automatico(int a, int b, int i);
	  void estudiodinamico(int a, int b, int c);
				
	public:

	  mochilaD(istream &is);
	  mochilaD(int a, int b, int i);
	  ~mochilaD();
	  double resolver();//unico metodo publico
	  double resolverestudio(); //metodo case 6

};
#endif
