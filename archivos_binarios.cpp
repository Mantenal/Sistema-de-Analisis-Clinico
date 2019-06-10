#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;

void entradas();
void salidas();
void eliminar();
void modificar();

struct estudiantes
{
char nombre[20];
char apellido[20];
int edad;       
}estu;


 main()
  {
    char dec;
    
    do
    {
    system("cls");  
    cout<<"A. registrar"<<endl;
    cout<<"B. mostrar"<<endl;
    cout<<"C. modificar"<<endl;
    cout<<"D. eliminar"<<endl;
    cout<<"E. salir"<<endl;       
           
       do
       {
       dec=toupper(getch());
       }while(!isalpha(dec));       
    
        switch(dec)
        {
          case 'A':
            entradas();   
          break;     
          
          case 'B':
            salidas();   
          break;
          
          case 'C':
           modificar();   
          break; 
          
          case 'D':
           eliminar();    
          break;
          
            
        }      
           
    } while(dec!='E');   
        
        
        
  }


void entradas()
{
     ofstream entrada;
  entrada.open("archivo.dat",ios::out|ios::app|ios::binary);
  
  if(entrada.fail())
  {
            cout<<"error al crear archivo";
            getch();      
  }   
  
  else 
  {
  cout<<"nombre :"<<endl;
  cin>>estu.nombre;
  cout<<"Apellido: "<<endl;
  cin>>estu.apellido;
  cout<<"edad: "<<endl;
  cin>>estu.edad;
  
  entrada.write((char *)&estu,sizeof(estudiantes));
  entrada.close();
  }   
      
}


void salidas()
{
     ifstream salida;
     salida.open("archivo.dat",ios::in|ios::binary);
     
     if (salida.fail())
     {
     cout<<"error al abrir el archivo"<<endl;
     getch();                  
     }
     else       
     {
     int nreg;
     
     salida.seekg(0,ios::end);
     nreg=salida.tellg()/sizeof(estudiantes);
     salida.seekg(0);  
     
       for(int x=0;x<nreg;x++)
              {
              salida.read((char *)&estu,sizeof(estudiantes));
              
            // if(strcmp(nom,estu.nombre)==0) 
              cout<<"nombre : "<<estu.nombre<<endl;
              cout<<"apellido : "<<estu.apellido<<endl;
              cout<<"edad : "<<estu.edad<<endl<<endl<<endl;
              
              }
     salida.close();
     getch();
       
     }
            
}


void eliminar()
{
      ofstream entrada;
      entrada.open("temp.dat",ios::out|ios::binary);
      ifstream salida;
     salida.open("archivo.dat",ios::in|ios::binary);
     
     if (salida.fail()||entrada.fail())
     {
     cout<<"error al abrir el archivo"<<endl;
     getch();                  
     }
     else
     {
     int nreg;
     char ntem[20];
     cout<<"introduce nombre del alumno a eliminar"<<endl;
     cin>>ntem;
     
     salida.seekg(0,ios::end);
     nreg=salida.tellg()/sizeof(estudiantes);
     salida.seekg(0);  
     
       for(int x=0;x<nreg;x++)
              {
              salida.read((char *)&estu,sizeof(estudiantes));
                   if(strcmp(estu.nombre,ntem)==0)
                     {
                     cout<<"registro borrado"<<endl;                             
                     }
                     
                     else
                     {
                     entrada.write((char *)&estu,sizeof(estudiantes));    
                     }
                    
              }
     salida.close();
     entrada.close();
     remove("archivo.dat");
     rename("temp.dat","archivo.dat");
     
     getch();   
     
     }
}

void modificar()
{
     
           ofstream entrada;
      entrada.open("temp.dat",ios::out|ios::binary);
      
      
      ifstream salida;
     salida.open("archivo.dat",ios::in|ios::binary);
     
     if (salida.fail()||entrada.fail())
     {
     cout<<"error al abrir el archivo"<<endl;
     getch();                  
     }
     else
     {
     int nreg;
     char ntem[20];
     
     cout<<"introduce nombre del alumno a modificar"<<endl;
     cin>>ntem;
     
     
     salida.seekg(0,ios::end);
     nreg=salida.tellg()/sizeof(estudiantes);
     salida.seekg(0);  
     
       for(int x=0;x<nreg;x++)
              {
              salida.read((char *)&estu,sizeof(estudiantes));
                   if(strcmp(estu.nombre,ntem)==0)
                     {
                     cout<<"introdusca nuevo nombre"<<endl;
                     cin>>estu.nombre;
                     
                     cout<<"introdusca nuevo apellido"<<endl;
                     cin>>estu.apellido;
                     
                     cout<<"introdusca nueva edad"<<endl;
                     cin>>estu.edad;
                     cout<<"registro modificado"<<endl;                             
                     }
                     
                     entrada.write((char *)&estu,sizeof(estudiantes));    
              }
     salida.close();
     entrada.close();
     remove("archivo.dat");
     rename("temp.dat","archivo.dat");
     
    // remove("hola.docx");
     getch();   
     
     }
     
     
}



