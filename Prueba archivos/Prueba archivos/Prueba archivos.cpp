#include "stdafx.h"
#include <string>
#include <iostream>


using namespace std;

class Nodo {
	int Info;
	string Nombre;
	int Dia;
	int Mes;
	int A?o;
	Nodo *ant, *sig;
public:
	Nodo(int info, string nombre, int dia, int mes, int a?o) {
		Info = info;
		Nombre = nombre;
		Dia = dia;
		Mes = mes;
		A?o = a?o;
	};
	friend class ListaGenerica;
};


class ListaGenerica {
	Nodo *raiz;
public:
	ListaGenerica() { raiz = NULL; };
	~ListaGenerica();
	void insertarPrimero(int info, string nombre, int dia, int mes, int a?o);
	void imprimir();
};






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








void ListaGenerica::insertarPrimero(int info, string nombre, int dia, int mes, int a?o)
{
	Nodo *nuevo = new Nodo(info, nombre, dia, mes, a?o);
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
		cout << reco->A?o << endl;

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
	delete lista1;
	cin.get();
}