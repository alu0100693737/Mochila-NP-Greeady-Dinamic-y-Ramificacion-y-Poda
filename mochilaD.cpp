#include "mochilaD.h"
#include <stdlib.h>
#include<time.h> 
#include <math.h>  

//CONSTRUCTOR
mochilaD::mochilaD(istream &is){
     //Le pasamos por el cin el nombre del fichero que queremos abrir
     //Inicializamos los valores
	    tamMochila = 0;
	    numElementos = 0;
	    pesoItems=NULL;
	    matriz=NULL;
	    valorItems=NULL;
	    totalItems=0;
	    filas = 0;
	    columnas = 0;
	
	    //Leemos de fichero
	    mochilaD::read(is);    
}

mochilaD::mochilaD(int a, int b, int i)
{	tamMochila = 0;
	    numElementos = 0;
	    pesoItems=NULL;
	    matriz=NULL;
	    valorItems=NULL;
	    totalItems=0;
	    filas = 0;
	    columnas = 0;
	    if (i==-1)
	      mochilaD::estudiodinamico(a,b,i);
	    else
	      mochilaD::automatico(a, b, 3);
}

//DESTRUCTOR
mochilaD::~mochilaD(){
     //Quitamos los punteros
	    if(pesoItems!=NULL){
		        delete [] pesoItems;
          pesoItems=NULL;
	    }
	    if(valorItems!=NULL){
		       delete [] valorItems;
		       valorItems=NULL;
	    }
	    if(matriz!=NULL){
        delete [] matriz;
		      matriz=NULL;
	    }
}      

void mochilaD::automatico(int a, int b, int i = 2){//numElementos y tamMochila
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
    valorItems[i]=fabs((rand()*k)%5);
    k= k+20;
  }
  cout <<endl<<"CAPACIDAD:" <<tamMochila<<endl;   
  cout <<endl<<"NUM OBJETOS:" << numElementos <<endl;           
  cout <<endl<< "OBJETOS: (PESO  VALOR)"<<endl;

  cout<<"Tabla de pesos: ";
  for (int i=0;i<=numElementos;i++){
          cout<<pesoItems[i]<<" ";
  }
  cout<<endl;
    
  cout<<"Tabla de valores: ";
  for (int i=0;i<=numElementos;i++){
          cout<<valorItems[i]<<" ";
  }
  cout<<endl;
  
  //creacion de la matriz
    filas = numElementos;
    //añadimos posicion inicial
    columnas = tamMochila+1;
     
    matriz = new int*[filas];
    for (int i=0;i<filas;i++){
        matriz[i]=new int[columnas];    
    }
    
    //Inicializamos todo a 0, la primera fila y columna NECESARIAS a 0
    for (int i = 0; i < filas;i++){
        for (int j = 0; j < columnas;j++){
            matriz[i][j]=0;
        }     
    }
}

void mochilaD::estudiodinamico(int a, int b, int i=2)
{
  numElementos=a;
  tamMochila=b;
  pesoItems = new int[numElementos+1];
  valorItems = new int[numElementos+1];
  vectorOrdenado =new double[numElementos+1];
	              
  //incluimos posicion inicial (0,0)
  pesoItems[0]=0;
  valorItems[0]=0;
  
  srand(time(NULL));
  //int k =i;
  for (int i=1; i<=numElementos; i++){
    
    pesoItems[i]=fabs((rand()*i)%12); 
    valorItems[i]=fabs((rand()*i)%12);
    //k= k+20;
  }
  /*cout <<endl<<"CAPACIDAD:" <<tamMochila<<endl;   
  cout <<endl<<"NUM OBJETOS:" << numElementos <<endl;           
  cout <<endl<< "OBJETOS: (PESO  VALOR)"<<endl;

  cout<<"Tabla de pesos: ";
  for (int i=0;i<=numElementos;i++){
          cout<<pesoItems[i]<<" ";
  }
  cout<<endl;
    
  cout<<"Tabla de valores: ";
  for (int i=0;i<=numElementos;i++){
          cout<<valorItems[i]<<" ";
  }
  cout<<endl;
  */
  //creacion de la matriz
    filas = numElementos;
    //añadimos posicion inicial
    columnas = tamMochila+1;
     
    matriz = new int*[filas];
    for (int i=0;i<filas;i++){
        matriz[i]=new int[columnas];    
    }
    
    //Inicializamos todo a 0, la primera fila y columna NECESARIAS a 0
    for (int i = 0; i < filas;i++){
        for (int j = 0; j < columnas;j++){
            matriz[i][j]=0;
        }     
    }
}

  
  
  
  
  
void mochilaD::read(istream &is){//Leemos de fichero y cargamos datos
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
           
	   //incluimos posicion inicial (0,0)
           pesoItems[0]=0;
           valorItems[0]=0;
           
	   
           for (int i=1;i<=numElementos;i++){
               fe >> pesoItems[i];
	       //cout << "\t[";     
               //cout << pesoItems[i];
               if (pesoItems[i]<10){
                 //   cout << ",  ";
               }else{
                   //cout << ", ";
               }
               fe >> valorItems[i];  
               //cout << valorItems[i] << "]\n";
           }
     }
     fe.close();
     
     cout<<endl;
     cout<<"Tabla de pesos: [";
     for (int i=0;i<=numElementos;i++){
          cout<<pesoItems[i]<<", ";
     }
     cout<< "]" << endl;
     
     cout<<"Tabla de valores: [";
     for (int i=0;i<=numElementos;i++){
          cout<<valorItems[i]<<", ";
     }
     cout<<"]" << endl<<endl;

    //creacion de la matriz
    filas = numElementos;
    //añadimos posicion inicial
    columnas = tamMochila+1;
     
    matriz = new int*[filas];
    for (int i=0;i<filas;i++){
        matriz[i]=new int[columnas];    
    }
    
    //Inicializamos todo a 0, la primera fila y columna NECESARIAS a 0
    for (int i = 0; i < filas;i++){
        for (int j = 0; j < columnas;j++){
            matriz[i][j]=0;
        }     
    }
}

void mochilaD::mostrarMatriz(){
    for (int i = 0; i < filas;i++){
        for (int j = 0; j < columnas;j++){
            if(matriz[i][j]<10){
                 cout << matriz[i][j]<<"  ";                   
            }else{
                 cout << matriz[i][j]<<" ";
            }
        }     
        cout<<endl;
    }
}


void mochilaD::construirMatriz(){

//La primera columna y fila ya están a 0  
//formula planteada para cada objeto. el objeto justo de encima o el anterior menos 
    //cout << filas << columnas << endl;
    for (int f=0; f< filas; f++)
    {  	matriz[0][f] = 0;
	matriz[f][0] = 0;
    }
    
    for(int f=1; f < filas; f++){
         for(int c=1 ; c < columnas; c++){
                   if(c < pesoItems[f]){//si la columna es menor al peso del objeto en la posicion de la fila
                        matriz[f][c] = matriz[f-1][c];//Colocamos el de arriba
                   }else{
                        if(matriz[f-1][c] >= (matriz[f-1][c-pesoItems[f]] + valorItems[f])){//Si el valor de arriba es mayor o igual al de la fila de arriba en la columna c-pesoItems[f]+valorItems[f]
                             matriz[f][c] = matriz[f-1][c];//Colocamos el de arriba
                        }else{
                             matriz[f][c] = matriz[f-1][c-pesoItems[f]]+ valorItems[f];
                        }          
                   }         
         }

    }    

}


void mochilaD::recurrencia(int a, int b){//En la llamada b equivale a tamMochila- a numElementos
    if(a>0){
         if(b<pesoItems[a]){ //El tamaño es menor que la capacidad, llamamos a un peso menor.
              recurrencia(a-1,b);
         }else{
              if((matriz[a-1][b-pesoItems[a]]+ valorItems[a]) > matriz[a-1][b])
              { 
                   recurrencia(a-1,b-pesoItems[a]);
                   //cout << "Objeto de peso = " << pesoItems[a] << " con valor = " << valorItems[a] << endl;  
                   totalItems++;
              }
              else 
                  recurrencia(a-1,b);
        }
    }
}

int  mochilaD::queItemsHay()
{
    recurrencia(numElementos, tamMochila);
    return totalItems;
}

double mochilaD::resolverestudio(){
  construirMatriz();
  return matriz[filas-1][columnas-1];
}
double mochilaD::resolver(){
     construirMatriz();
     cout<<"////////////MATRIZ////////////"<<endl<<endl;
     mostrarMatriz();
     cout<<endl;
    
     cout<<"Total de objetos:";
     cout << queItemsHay() <<endl<<endl; 
     cout<<"El valor maximo de la mochila sera: "<<matriz[filas-1][columnas-1]<<endl;
     return matriz[filas-1][columnas-1];
}
