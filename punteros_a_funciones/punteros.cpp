//===================================
//Ejercicios puntuales de lev-Guia Práctica Punteros
//===================================
/*
#include <iostream>
using namespace std;

void buscarMayor(int arr[], int n, int *mayor, int *posicion){
    *mayor=*arr;

    for(int i=0; i<n-1; i++){
        if(*(arr+i+1)>*(arr+i) && *(arr+i+1)>*mayor){
            *mayor=*(arr+i+1);
            *posicion=i+1;
        }

    }

    cout<<"Mayor: "<< *mayor<<endl;
    cout<<"Posicion: "<<*posicion<<endl;
}




int main()
{
    // Defina la función buscarMayor y complete el programa.
    int n=5;
    int arr[n];
    int max=0;
    int pos=0;
    for(int i=0; i<n;i++){
        cout<<"Ingrese el elemento "<<i<<":"<<endl;
        cin>>*(arr+i);
    }
    buscarMayor(arr, n, &max, &pos);

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

void invertir(int *ptr, int n) {
    cout<<"Invertido: ";
  for(int i=n-1; i>=0; i--){
    cout<<*(ptr +i)<<" ";
  }
}

int main() {
  // Defina la función invertir sin utilizar otro arreglo.
  int n = 5;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cout << "Ingrese el elemento " << i << ":" << endl;
    cin >> *(arr + i);
  }

  int *ptr = arr;
  invertir(ptr, n);

  return 0;
}
  */

  /*
#include <iostream>
using namespace std;

int main()
{
    // Complete el programa usando new y delete.
    int* x = new int;
    cout<<"Ingrese un numero entero:"<<endl;
    cin>>*x;
    *x = *x**x;
    
    cout<<"Cuadrado: "<<*x;
    delete x;

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main()
{
    // Complete el programa usando dos arreglos dinámicos.
    
    int n;
    cout<<"Ingrese la cantidad de elementos: "<<endl;
    cin>>n;
    int* arr=new int[n];
    for(int i=0; i<n;i++){
        cout<<"Ingrese el elemento "<<i<<":"<<endl;
        cin>>*(arr+i);
    }
    
    int* arrHeap= new int [n];
    //f. invierte
    for(int i=0; i<n; i++){
        *(arrHeap +n-1-i)=*(arr+i);     
    }
    
    //muestra invertido
    cout<<"Copia invertida: ";
    for(int i=0; i<n; i++){
           cout<<*(arrHeap+i)<<" ";
    }
    
    
    delete[] arrHeap;
    delete[] arr;
    return 0;
}

*/


// #include <iostream>
// using namespace std;
// int main()
// {
//     // Complete el programa reservando los tres arreglos dinámicos.
//     int A;
//     int B;
//     cout<<"Ingrese la cantidad del primer arreglo:"<<endl;
//     cin>>A;
//     cout<<"Ingrese la cantidad del segundo arreglo:"<<endl;
//     cin>>B;
//     int* arrA =new int[A];
//     int* arrB= new int[B];
//     int* arrRes = new int[A + B];
// //ingresa primeros elementos  
//     for(int i=0; i<A;i++){
//         cout<<"Ingrese A["<<i<<"]:"<<endl;
//         cin>>*(arrA+i);
//     }
// //ingresa siguientes elementos
//     for(int i=0; i<B; i++){
//         cout<<"Ingrese B["<<i<<"]:"<<endl;
//         cin>>*(arrB + i);
//     }
    
//     cout<<"Arreglo unido: ";
//    for(int i=0; i<A;i++){
//       *(arrRes +i)=*(arrA+i);
//    }
//    for(int i=0; i<B; i++){
//       *(arrRes +A+i)=*(arrB +i);
//    }
    
//    for(int i=0; i<A+B;i++){
//       cout<<*(arrRes+i)<<" ";
//    }
    
//     delete[] arrA;
//     delete[] arrB;
//     delete[] arrRes;
//     return 0;
// }

#include <iostream>
using namespace std;

int* filtrarPositivos(int arr[], int n, int* res){
    
//cuenta el tamaño del array nuevo    
    int contador=0;
    for(int i=0; i<n;i++){
        if(*(arr+i)>0){
            contador++;
        }
    }
//puntero a la cantidad resultante    
    *res=contador;
    

    if(contador==0){
      *res=0;
      return nullptr;
    }

//nuevo array
    int* arrP = new int [contador];
    int j=0;
    for(int i =0; i<n;i++){
      if(*(arr+i)>0){
          *(arrP +j)=*(arr+i);
          j++;
      }
    }
    return arrP; 
}

int main()
{
    // Defina filtrarPositivos. Quien recibe el arreglo devuelto debe liberarlo.
    int n;
    cout<<"Ingrese la cantidad de elementos:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Ingrese el elemento "<<i<<":"<<endl;
        cin>>*(arr+i);
    }
    
    int cantidadPositivos=0;
    int* ptr;
    ptr=filtrarPositivos(arr, n, &cantidadPositivos);
    
    if(cantidadPositivos==0){
      cout<<"Sin positivos";
    }else{
      cout<<"Positivos: ";
      for(int i=0; i<cantidadPositivos;i++){
        cout<<*(ptr+i)<<" ";
      }
      delete[] ptr;
    }
    return 0;
}