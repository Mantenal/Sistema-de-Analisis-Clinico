#include "stdafx.h"
#include <string>
#include<fstream>
#include "windows.h"
#include<conio.h>

#include <iostream>


using namespace std;


void entradas();

void eliminar();
void modificar();


class Nodo {
	int Info;
	string Nombre;
	int Dia;
	int Mes;
	int Anio;
	Nodo *ant, *sig;


public:
	Nodo(int info, string nombre, int dia, int mes, int anio) {
		Info = info;
		Nombre = nombre;
		Dia = dia;
		Mes = mes;
		Anio = anio;
	};

	
	friend class ListaGenerica;
}leer(0, "0", 0, 0, 0);


class ListaGenerica {
	Nodo *raiz;
public:
	ListaGenerica() { raiz = NULL; };
	~ListaGenerica();
	void insertarPrimero(int info, string nombre, int dia, int mes, int anio);
	void imprimir();
	void salidas();
};



void ListaGenerica::salidas()
{
	ifstream salida;
	salida.open("archivo.dat", ios::in | ios::binary);

	if (salida.fail())
	{
		cout << "error al abrir el archivo" << endl;
		getch();
	}
	else
	{
		int nreg;

		salida.seekg(0, ios::end);
		nreg = salida.tellg() / sizeof(Nodo);
		salida.seekg(0);

		for (int x = 0;x < nreg;x++)
		{
			salida.read((char *)&leer, sizeof(Nodo));

			// if(strcmp(nom,estu.nombre)==0) 
			
			
			cout << "nombre : " << leer.Nombre << endl;
			cout << "Info : " << leer.Info << endl;
			cout << "Edad : " << leer.Anio << endl << endl << endl;

		}
		salida.close();
		getch();

	}
}







ListaGenerica::~ListaGenerica()
{
	Nodo *reco = raiz;
	Nodo *bor;
	while (reco != NULL)
	{
		bor = reco;
		reco = reco->sig;
		delete bor;
	}
}








void ListaGenerica::insertarPrimero(int info, string nombre, int dia, int mes, int anio)
{
	Nodo *nuevo = new  Nodo(info, nombre, dia, mes, anio);
	nuevo->ant = NULL;
	if (raiz == NULL)
	{
		nuevo->sig = NULL;
		raiz = nuevo;
	}
	else
	{
		nuevo->sig = raiz;
		raiz->ant = raiz;
		raiz = nuevo;
	}
	



	ofstream entrada;
	entrada.open("archivo.dat", ios::out | ios::app | ios::binary);

	if (entrada.fail())
	{
		cout << "error al crear archivo";
		system("pause");
	}
	else
	{
		entrada.write((char *)&nuevo, sizeof(Nodo));
		entrada.close();

	}

}















void ListaGenerica::imprimir()
{
	Nodo *reco = raiz;
	while (reco != NULL)
	{
		cout << reco->Info << "-";

		cout << reco->Nombre << "-";
		cout << reco->Dia << "-";
		cout << reco->Mes << "-";
		cout << reco->Anio << endl;

		reco = reco->sig;
	}
	cout << "\n";



}


void main()
{
	ListaGenerica *lista1 = new ListaGenerica();
	lista1->insertarPrimero(10, "hola", 4, 3, 1999);
	lista1->insertarPrimero(20, "adios", 1, 9, 1997);
	lista1->insertarPrimero(5, "geby", 5, 6, 1998);
	lista1->imprimir();
	lista1->salidas()
	delete lista1;
	cin.get();
}