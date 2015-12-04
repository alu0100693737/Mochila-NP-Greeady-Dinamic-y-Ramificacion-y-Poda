#include <iostream>
#include <fstream>
#include "mochila_greedy.h"

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "mochilaD.h"
#include "mochila_ramificada.h"
#include <cstdlib>
#include <stdlib.h>
#include <cmath>

//#include <cstdlib>
using namespace std;

void delay(int secs) {
	  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
      }
      
int main()
{  
  system ("color 6" );
  
  int pepe= 2;
   

  do{
    //usar hola2 en greedy y hola en dinamico
    int eleccion= 0;
    cout << "\n*********************************************************************************";
    cout << "\nBienvenido al programa que estudia la complejidad de algoritmos de la Mochila.\n";
    cout << "*********************************************************************************\n";
    cout << "\n+\t1-Algoritmo Greedy con entrada desde fichero \n" << endl;
    cout << "+\t2-Algoritmo Greedy con entrada automatica. Uso de rand() \n" << endl;
    cout << "+\t3-Algoritmo Dinamico con entrada desde fichero \n" << endl;
    cout << "+\t4-Algoritmo Dinamico con entrada automatica. Uso de rand() \n" << endl;
    cout << "+\t5-Algoritmo Ramificacion y Poda con entrada desde fichero \n" << endl;
    cout << "+\t6-Algoritmo Ramificacion y Poda con entrada automatica. Uso de rand() \n" << endl;
    cout << "+\t7-Comparacion de resultados, misma entrada, distintos algoritmos \n" << endl;
    cout << "+\t8-Estudio de complejidades segun tiempo de ejecucion \n" << endl;
    
    cout << "+\t0-SALIR \n" << endl;
    cin>>pepe;

    if (pepe == 1){
         cout << "Introduzca a continuacion el fichero\n\n";
	 mochilaGreedy A(cin);
	 A.mochila(A.get_tamMochila(), 0);
	 A.~mochilaGreedy();
    }
    if (pepe == 2){
    
	  mochilaGreedy B(12, 8, 3);
	  B.mochila(8,0);
	  B.~mochilaGreedy();
    }
    if (pepe == 3){ 
	  cout << "Introduzca el fichero para cargar la mochila: \n";
	  mochilaD C(cin);
	  C.resolver();
	  C.~mochilaD();
    }
	  
    if (pepe == 4){
	  int prueba1 = 10;
	  double* vectordina = new double [prueba1];
	  int a = 0;
	  //for (int i = 0; i< prueba1; i++)
	  //{
	    mochilaD D(20,12, 3);
	    a = D.resolver();
	    cout << "dina " << a << endl;
	    //D.~mochilaD();
	   //  delay(1);
	  //}
    }
    if (pepe==5){
      double a = 0.0;
      cout << "Introduzca a continuacion el fichero\n\n";
	 mochila_Ramificada A(cin);
	 a= A.mochilaram();
	 cout << "El valor maximo que puede tener la mochila es: " << a << endl;
	 //A.mochila(A.get_tamMochila(), 0);
	 A.~mochila_Ramificada();
    }
    
    if (pepe==6){
      double a = 0.0;
      mochila_Ramificada B(12, 12, 2);
      a = B.mochilaram();
      cout << "El valor maximo que puede tener la mochila es: " << a << endl;
      B.~mochila_Ramificada();
      
    }
    
    if(pepe == 7){
      int prueba1 = 20;
      double* vectorgreedy = new double [prueba1];
      double* vectorpoda = new double [prueba1];
      int numeroElementos;
      int peso;
      
      cout << "\nIntroduzca el numero de elementos con el que quiere hacer el estudio\n";
      cin >> numeroElementos;
      cout << "\nIndique ahora el peso maximo de la mochila\n";
      cin >> peso;
      
      for (int i = 0; i<prueba1; i++)
      {
	  double a= 0;
	  
	  mochilaGreedy B(numeroElementos, peso, -1);
	  vectorgreedy[i] = B.estudiomochila(B.get_tamMochila(),0,0);
	  B.~mochilaGreedy();
	  mochila_Ramificada C(numeroElementos, peso, -1);
	  vectorpoda[i] = C.mochilaram();
	  C.~mochila_Ramificada();
	  delay(1);
      }
      
      cout << "\t[Greedy\t--\tPoda y Ramificacion]\n\n";
//       cout << "-----------------------------------------";
      double* diferencia = new double [prueba1];
      double aux;
      for (int i = 0; i<prueba1; i++)
      {
	
	cout << "\t" <<vectorgreedy[i] << "\t--\t" << vectorpoda[i] << endl;
	diferencia[i] = fabs(vectorgreedy[i]-vectorpoda[i]);
      }
      aux = 0.0;
      for (int i=0; i<prueba1; i++)
	aux += diferencia[i];
      aux = aux/prueba1;
      cout << "\nLa diferencia media entre los dos algoritmos es de: " << aux << endl;
      //cout << "
      
    }//case 7
    
    if (pepe == 8){
	  int prueba1 = 10;
	  double* vectorgre = new double [prueba1];
	  double* vectordina = new double [prueba1];
	  double* vectorpoda = new double [prueba1];
	  double media1 = 0.0;
	  double media2 = 0.0;
	  double media3 = 0.0;
	  int numeroElementos =12;
	  int peso = 12;
	  for (int i = 0; i<prueba1; i++)
	  {
	      timespec ts;
	      clock_gettime(CLOCK_REALTIME, &ts);
	      
	      mochilaD D(12,12, -1);
	      D.resolverestudio();
	      D.~mochilaD();
	      
	      timespec b;
	      clock_gettime(CLOCK_REALTIME, &b);
	      vectordina[i] = (b.tv_nsec-ts.tv_nsec);
	      cout << "Dina " << vectordina[i] << endl;
	  
	      timespec h;
	      clock_gettime(CLOCK_REALTIME, &h);
	      
	      mochilaGreedy B(12, 12, -1);
	      B.estudiomochila(B.get_tamMochila(),0, 0);
	      B.~mochilaGreedy();
	      
	      timespec j;
	      clock_gettime(CLOCK_REALTIME, &j);
	      vectorgre[i] = (j.tv_nsec-h.tv_nsec);
	      cout << "Greedy " << vectorgre[i] << endl;
	      
	      timespec z;
	      clock_gettime(CLOCK_REALTIME, &z);
	      
	       mochila_Ramificada G(12, 12, -1);
		G.mochilaram();
		G.~mochila_Ramificada();
		
		timespec p;
	       clock_gettime(CLOCK_REALTIME, &p);
	       vectorpoda[i] = (p.tv_nsec-z.tv_nsec);
	       cout << "Poda " << vectorpoda[i] << endl;
	       
	       delay(2);
	      
	      
	      
	  }
	  
	  for (int i=0; i< prueba1; i++)
	  {
	    media1 +=vectorgre[i];	    
	    media2 +=vectordina[i];
	    media3 +=vectorpoda[i];
	  }
  	    media1 = media1/prueba1;
	    media2 = media2/prueba1;
	    media3 = media3/prueba1;
	    cout << "El algoritmo Greedy tarda de media: " << media1 << " nanosegundos\n\n";
	    cout << "El algoritmo Dinamico tarda de media: " << media2 << " nanosegundos\n\n";
	    cout << "El algoritmo Poda y Ramificacion tarda de media: " << media3 << " nanosegundos\n\n";
	  
    }//case 8
    
      
     // mochila_Ramificada B(12, 12, 1);
      //double a = B.mochilaram();
    
      //cout << "hola que aseeee. " << endl;

  }while((pepe >= 1) && (pepe<=8));

  cout << "\nHa salido con exito \n\n";
}
      