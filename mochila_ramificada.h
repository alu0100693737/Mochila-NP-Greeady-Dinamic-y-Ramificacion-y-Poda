#ifndef _MOCHILA_ENTRADA2_H
#define _MOCHILA_ENTRAD3_H

#include <iostream>
#include <fstream>
//#include <stdio.h>
 
using namespace std;

class mochila_Ramificada{

	private:
	  int tamMochila;
	  int numElementos;
	  int *pesoItems;
	  int *valorItems;
	  
	  double *vectorOrdenado;

	  void recurrencia(int j,int c);
	
	  void queItemsHay();
				
	public:

	  mochila_Ramificada(istream &is);
	  mochila_Ramificada(int a, int b, int i);
	  ~mochila_Ramificada();
	  int get_tamMochila();
	  int get_numElementos();
	  void set_numElementos(int a);
	  int get_pesoItem(int pos);
	  int get_valorItem(int pos);
	  void set_vectorOrdenado(double valor, int pos);
	  double get_vectorOrdenado(int pos);
	  void read(istream &is); //tiene el vector ya ordenado v/w
	  void automatico(int a, int b, int i);
	  void estudiogreedy(int a, int b,int c);//igual que automatico pero sin cout
	  double estudiomochila(int a, int b, int c);
	  double mochila(int size, int numElem);//unico metodo publico

	  //metodos mochila ramificada

	  double mochilaram();
	  
	  
};
#endif