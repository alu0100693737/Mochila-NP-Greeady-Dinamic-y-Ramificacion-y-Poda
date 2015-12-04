#include "mochila_ramificada.h"
#include <fstream>
using namespace std;
#include <stdlib.h>
#include<time.h> 
#include <math.h>  

#include <vector> //vector dinamico tam  0 < i <= 2^n con poda

mochila_Ramificada::mochila_Ramificada(istream &is){
  
      tamMochila =0;
      numElementos = 0;
      pesoItems=NULL;
      //matriz=NULL;
      valorItems=NULL;
      vectorOrdenado = NULL;
      mochila_Ramificada::read(is);
}

mochila_Ramificada::mochila_Ramificada(int a, int b, int i)
{	tamMochila =0;
      numElementos = 0;
      pesoItems=NULL;
      //matriz=NULL;
      valorItems=NULL;
      vectorOrdenado = NULL;
      if (i ==-1)//estudio case 6
	mochila_Ramificada::estudiogreedy(a,b,3);
      else
	mochila_Ramificada::automatico(a, b, i);
}
  

mochila_Ramificada::~mochila_Ramificada(){
      tamMochila=0; 
      numElementos = 0;
      delete [] pesoItems;
      delete [] valorItems;
      delete [] vectorOrdenado;
      pesoItems=NULL;
      valorItems=NULL;
      vectorOrdenado = NULL;
}

void mochila_Ramificada::automatico(int a, int b, int i=2){//numElementos y tamMochila
  numElementos=a;
  tamMochila=b;
  pesoItems = new int[numElementos+1];
  valorItems = new int[numElementos+1];
  vectorOrdenado =new double[numElementos+1];
	              
  //incluimos posicion inicial (0,0)
  pesoItems[0]=0;
  valorItems[0]=0;
  
  srand(time(NULL));
  int k =i;
  for (int i=1; i<=numElementos; i++){
    pesoItems[i]=fabs((rand()*k)%15);  
    valorItems[i]=fabs((rand()*k)%15); 
    k = k+20;
  }
  
  cout <<endl<<"\tCAPACIDAD:" <<tamMochila<<endl;   
  cout <<endl<<" \tNUM OBJETOS:" << numElementos <<endl;           

  cout<<"Tabla de pesos: [";
  for (int i=0;i<=numElementos;i++){
          cout<<pesoItems[i]<<", ";
  }
  cout<< "]" << endl;
    
  cout<<"Tabla de valores: [";
  for (int i=0;i<=numElementos;i++){
          cout<<valorItems[i]<<", ";
  }
  cout<< "]" << endl;
     
  double c = 0.0;
     cout << "\nInicialización tabla vectorOrdenado" << endl;
	//cout.flush();
	set_vectorOrdenado(c,0);
	for (int i= 1; i<=numElementos; i++)
	{
	    c = (double)get_pesoItem(i)/get_valorItem(i);
	    set_vectorOrdenado(c,i);
	}
	
	double aux= -1; //valor mayor
	double* pepe = new double[numElementos+1];
	int* marcados = new int[numElementos+1];
	int indice = -1;
	
	
	for (int j=0; j<=numElementos; j++){
	  for (int k=0; k<=numElementos; k++)
	    if (get_vectorOrdenado(k) > aux){
	      aux = get_vectorOrdenado(k);
	      indice = k;
	    }
	  pepe[j] = aux;
	  set_vectorOrdenado(0, indice);
	  aux = -1;
	}
	cout << "[";
	//metiendo valores en vector original
	for (int j=0; j<=numElementos; j++){
	  set_vectorOrdenado(pepe[j], j);
	
	  cout << get_vectorOrdenado(j)<<  ", ";
	  
	}cout << "]" << endl << endl;
}

void mochila_Ramificada::estudiogreedy(int a, int b, int i=2){
  numElementos=a;
  tamMochila=b;
  pesoItems = new int[numElementos+1];
  valorItems = new int[numElementos+1];
  vectorOrdenado =new double[numElementos+1];
	              
  //incluimos posicion inicial (0,0)
  pesoItems[0]=0;
  valorItems[0]=0;
  
  srand(time(NULL));
  int k =i;
  for (int i=1; i<=numElementos; i++){
    pesoItems[i]=fabs((rand()*k)%15);  
    valorItems[i]=fabs((rand()*k)%15); 
    k = k+20;
  }
  
  /*cout <<endl<<"\tCAPACIDAD:" <<tamMochila<<endl;   
  cout <<endl<<" \tNUM OBJETOS:" << numElementos <<endl;           

  cout<<"Tabla de pesos: [";
  for (int i=0;i<=numElementos;i++){
          cout<<pesoItems[i]<<", ";
  }
  cout<< "]" << endl;
    
  cout<<"Tabla de valores: [";
  for (int i=0;i<=numElementos;i++){
          cout<<valorItems[i]<<", ";
  }
  cout<< "]" << endl;
     */
  double c = 0.0;
     //cout << "\nInicialización tabla vectorOrdenado" << endl;
	//cout.flush();
	set_vectorOrdenado(c,0);
	for (int i= 1; i<=numElementos; i++)
	{
	    c = (double)get_pesoItem(i)/get_valorItem(i);
	    set_vectorOrdenado(c,i);
	}
	
	double aux= -1; //valor mayor
	double* pepe = new double[numElementos+1];
	int* marcados = new int[numElementos+1];
	int indice = -1;
	
	
	for (int j=0; j<=numElementos; j++){
	  for (int k=0; k<=numElementos; k++)
	    if (get_vectorOrdenado(k) > aux){
	      aux = get_vectorOrdenado(k);
	      indice = k;
	    }
	  pepe[j] = aux;
	  set_vectorOrdenado(0, indice);
	  aux = -1;
	}
	//cout << "[";
	//metiendo valores en vector original
	for (int j=0; j<=numElementos; j++){
	  set_vectorOrdenado(pepe[j], j);
	
	 // cout << get_vectorOrdenado(j)<<  ", ";
	  
	}//cout << "]" << endl << endl;
}
  
void mochila_Ramificada::read(istream &is){ //Leemos fichero y cargamos datos
     
     char fich[255];
     is >> fich;
     cout << "\nCargando el fichero: " << fich << endl;
     ifstream fe(fich);
     if(!fe){
             cout << "\nNo se  pudo abrir el fichero indicado" << endl;
     }else{
           //Obtenemos la capacidad de la mochila y el numero de objetos
           fe >> numElementos;
           fe >> tamMochila;  
           
           cout <<endl<<"\tCAPACIDAD:" <<tamMochila<<endl;   
           cout <<"\tNUM OBJETOS:" << numElementos <<endl;           
           cout <<endl<< "OBJETOS: (PESO  VALOR)"<<endl;

           pesoItems = new int[numElementos+1];
           valorItems = new int[numElementos+1];
	   vectorOrdenado =new double[numElementos+1];
           
	   //incluimos posicion inicial (0,0)
           pesoItems[0]=0;
           valorItems[0]=0;
           

           for (int i=1;i<=numElementos;i++){
               fe >> pesoItems[i];     
               cout << "\t" << pesoItems[i];
               if (pesoItems[i]<10){
                    cout << "  ";
               }else{
                   cout << " ";
               }
               fe >> valorItems[i];  
               cout << "\t" << valorItems[i]<<endl;
           }
     }
     fe.close();
     
     cout<<endl;
     cout<<"\nTabla de pesos:  [";
     for (int i=0;i<=numElementos;i++){
          cout<<pesoItems[i]<<", ";
     }
     cout<< "]" << endl;
     
     cout<<"\nTabla de valores:  [";
     for (int i=0;i<=numElementos;i++){
          cout<<valorItems[i]<<", ";
     }
     cout<< "]" << endl;
     
    
     double a = 0.0;
     cout << "\nInicialización tabla vectorOrdenado" << endl;
	//cout.flush();
	set_vectorOrdenado(a,0);
	for (int i= 1; i<=numElementos; i++)
	{
	    a = (double)get_pesoItem(i)/get_valorItem(i);
	    set_vectorOrdenado(a,i);
	}
	
	double aux= -1; //valor mayor
	double* pepe = new double[numElementos+1];
	int* marcados = new int[numElementos+1];
	int indice = -1;
	
	
	for (int j=0; j<=numElementos; j++){
	  for (int k=0; k<=numElementos; k++)
	    if (get_vectorOrdenado(k) > aux){
	      aux = get_vectorOrdenado(k);
	      indice = k;
	    }
	  pepe[j] = aux;
	  set_vectorOrdenado(0, indice);
	  aux = -1;
	}
	
	//metiendo valores en vector original
	cout << "[";
	for (int j=0; j<=numElementos; j++){
	  set_vectorOrdenado(pepe[j], j);
	
	  cout << get_vectorOrdenado(j)<<  ", ";
	  
	}cout << "]\n";
}

int mochila_Ramificada::get_tamMochila(){
  return tamMochila;
}

int mochila_Ramificada::get_numElementos(){
  return numElementos;
}

void mochila_Ramificada::set_numElementos(int a){
  numElementos =a ;
}
int mochila_Ramificada::get_pesoItem(int pos){
  return pesoItems[pos];
}

int mochila_Ramificada::get_valorItem(int pos){
  return valorItems[pos];
}

void mochila_Ramificada::set_vectorOrdenado(double valor, int pos){
  vectorOrdenado[pos] = valor;
}
  
double mochila_Ramificada::get_vectorOrdenado(int pos){
  return vectorOrdenado[pos];
}

double mochila_Ramificada::mochila(int size, int conta)
{ 
  int contador = conta;
   int tamanyo =size;
   double resultado = 0.0;
   /*for (int i=0; i<numElementos; i++)
     resultado[i] =0.0;
   //cout << contador << tamanyo << endl;*/
   
   cout << "\n ******************RESULTADO******************" << endl;
     
     
     
    while ((contador< numElementos) && (tamanyo>0))
    {
	  if (get_vectorOrdenado(contador) <= tamanyo)
	  {	cout << "\tSe eligio el peso : " << get_vectorOrdenado(contador) << endl;
	       tamanyo = tamanyo - get_vectorOrdenado(contador);
		resultado += get_vectorOrdenado(contador);
		contador++;
		//mochila(tamanyo, contador);
	  }else{
	    
	      contador++; 
	      //mochila(tamanyo, contador);
	  }
    }
    
    
      cout << "\nPodremos meter en la mochila: " << resultado << " kg \n";
      return resultado;
}

double mochila_Ramificada::estudiomochila(int size, int conta, int c)
{  
   int contador = conta;
   int tamanyo =size;
   double resultado = 0.0;

    while ((contador< numElementos) && (tamanyo>0))
    {
	  if (get_vectorOrdenado(contador) <= tamanyo)
	  {	//cout << "\tSe eligio el peso : " << get_vectorOrdenado(contador) << endl;
	       tamanyo = tamanyo - get_vectorOrdenado(contador);
		resultado += get_vectorOrdenado(contador);
		contador++;

	  }else{
	    
	      contador++; 

	  }
    }
    
      return resultado;
}



double mochila_Ramificada::mochilaram()
{
  //vector dinamico de tam 0 < v.size <= 2^n
  vector<double> v;
  
  double aux = 0.0;
  double aux2 = 0.0;
  int a= 0;
  
  for (int i= 0; i<numElementos; i++)
  {

    for (int k= 0; k<=1; k++)
    {
      if (k==1)
	if (v.size() == 0){
	  if (get_vectorOrdenado(i) <= get_tamMochila())
	  {	v.push_back(get_vectorOrdenado(i));
		
	  }
	}else{
	  a = v.size();
	  for (int l= 0; l< a; l++)
	  {
	    aux = get_vectorOrdenado(i) + v[l];
	    if(aux<= get_tamMochila())
	      v.push_back(aux);
 	    
	  }
	}
    }
  }
  for (int i=0; i< v.size(); i++)
    if ((v[i] > aux2) && (v[i] <= get_tamMochila()))
      aux2 = v[i]; 
  return aux2;
  
}
	     