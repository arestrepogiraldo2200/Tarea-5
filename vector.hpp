
//Alejandro Restrepo Giraldo CC: 1001389709

//Librerías
#include<iostream>
#include <sstream>
using std::cout;
using std::endl;



namespace myvec{

  class Vector{
  
    public:
      
//-----Constructor con parametro de número de entradas del vector
      Vector (int Len){
      
        cout << "Objeto Vector creado"<< endl;
        Longitud = Len;
        

        //Vector de longitud Len y entradas 0 por defecto
        V = new int [Longitud] {0};

        }
                
              
//-----Función de impresión
       void PrintVec(void){ 
       
         cout << "[ " ;         
         for(int i = 0; i < Longitud; i++) {
           cout<< *(V+i) <<" ";
         }
         cout << "]" << endl;
         
       }
       
//-----Función de inicialización de valores
       void SetPos(int entry, int value){ 
         
         if (entry > Longitud - 1)
            cout<< "!! Entrada fuera del rango"<< endl;
         else
           *(V+entry) = value;
       }
   
      
//-----Función de obtención de entrada
       int GetPos(int entry){ 
         
         if (entry > Longitud - 1){
           cout<< "!! Entrada fuera del rango"<< endl;
           return 0;
         }
         else
            return *(V+entry);
       }
   
   
//-----Función de obtención de longitud
       int GetSize(void){ 
         return Longitud; 
       }
       
//-----Función de sobrecarga del operador =
       void operator = (Vector V_1){

         if (V_1.GetSize() != Longitud){
           cout<< "Los vectores son de tamaños diferentes. No se puede realizar la operación requerida." << endl;
           
         }
         else {
           for(int i = 0; i < Longitud; i++)  
             *(V + i) = V_1.GetPos(i);           
         }
         
         
       } 
   


//-----Función de sobrecarga del operador +
       Vector operator + (Vector V_1){

         if (V_1.GetSize() != Longitud){
          cout<< "Los vectores son de tamaños diferentes. No se puede realizar la operación requerida." << endl;

           
         }
         else {
           Vector VSum(Longitud);
           for(int i = 0; i < Longitud; i++)  
             VSum.SetPos(i, V_1.GetPos(i) + *(V+i));
           return VSum;

         }
       } 

   
   
//-----Función de sobrecarga del operador -
       Vector operator - (Vector V_1){

         if (V_1.GetSize() != Longitud){
          cout<< "Los vectores son de tamaños diferentes. No se puede realizar la operación requerida." << endl;

           
         }
         else {
           Vector VSum(Longitud);
           for(int i = 0; i < Longitud; i++)  
             VSum.SetPos(i, V_1.GetPos(i) - *(V+i));
           return VSum;

         }
       } 
       
       
      
//-----Función de sobrecarga del operador []
       int& operator [] (int i){
         if (i < Longitud){
           return *(V+i);
         }
         else{
           cout << "Índice fuera del rango." << endl;
         }
       }
  
   
//Atributos privados
    private:
      int Longitud;
      int *V;
  
  };
}


