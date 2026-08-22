/*APRENDIZAJE DE PUNTEROS, PASAJES
  FUNCIÓN TÍPICA DE INTRODUCCIÓN 
  PASAJE POR REFERENCIA (NUEVO)
  PASAJE POR VALOR (NUEVO)
  */


#include <iostream>
using namespace std;

/*PASAJE POR VALOR  - copia el valor de la variable*/
void Mayor(int a, int b, int c){
  if (a>b){
  c= a;      
  }else {
    c=b;
  }
  // `c` se destruye al salir de la función
  cout<< c<< endl;
}

void MayorPuntero(int a, int b, int *c){ //PASAJE POR PUNTEROS, a diff de pasaje por valor simple acá puedo usar la variable C fuera de la función
if (a>b){
  *c= a;      
  }else {
    *c=b;
  }  
}

void MayorRef(int a, int b, int &c){ //PASAJE POR REFERENCIA, reinvención del pasaje por punteros
if (a>b){
  c= a;      
  }else {
    c=b;
  }}


int main() {
  int num=2;
  int num2 = 3;
  int num3;
  Mayor(num,num2,num3); //c es una copia de num3, modificar c no afecta a num3. Si imprimo num3 sigue siendo 0
  //MayorRef(num,num2,num3); // c es un alias, otro nombre para la variable num3, ocupan misma dirección de memoria
  //MayorPuntero(num,num2, &num3);
  //cout<< num3<< endl;
  return 0;
} 

/*  int main(){
  double x=5.5; //x empieza con 5.5
  double y = 10.2; 
  double z;
  double *px = &x; //px apunta a x
  double& ry=y; //ry es alias de y
  *px = 3.14; //cambia valor de x
  z=ry;
  double &r =*px; //r es alias de px
  r=99.4; //como alias y x ocupan misma dirección también se reescribe x. Valor final.
  px=&z; // px apunta a z
  ry=*px; // ry adquiere valor de px, o sea de z por línea 14

  cout<< x<<endl; // 99.4
  cout<< y<<endl; // 10.2
  cout<< z<<endl; // 10.2
  return 0;
}
*/