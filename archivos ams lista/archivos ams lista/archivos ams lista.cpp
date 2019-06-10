#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include <string>

using namespace std;

void entradas();
void salidas();
void eliminar();
void modificar();
bool primera = true;

struct estudiantes
{
	int Info;
	string Nombre;
	int Dia;
	int Mes;
	int Anio;

}estu;



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
};



class ListaGenerica {
	Nodo *raiz;
public:
	ListaGenerica() { raiz = NULL; };
	~ListaGenerica();
	void insertarPrimero(int info, string nombre, int dia, int mes, int anio);
	void imprimir();
};

void ListaGenerica::insertarPrimero(int info, string nombre, int dia, int mes, int anio)
{
	Nodo *nuevo = new Nodo(info, nombre, dia, mes, anio);
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
		cout << reco->Anio << endl;

		reco = reco->sig;
	}
	cout << "\n";
}



int main()
{
	char dec;

	do
	{
		system("cls");
		cout << "A. registrar" << endl;
		cout << "B. mostrar" << endl;
		cout << "C. modificar" << endl;
		cout << "D. eliminar" << endl;
		cout << "E. salir" << endl;

		do
		{
			dec = toupper(_getch());
		} while (!isalpha(dec));

		switch (dec)
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

	} while (dec != 'E');



}


void entradas()
{
	ofstream entrada;
	entrada.open("archivo.dat", ios::out | ios::app | ios::binary);

	if (entrada.fail())
	{
		cout << "error al crear archivo";
		_getch();
	}

	else
	{
		cout << "nombre :" << endl;//revisar aqui el tipo de dato string puede dar problemas

		if (primera == true) {
			getline(cin, estu.Nombre);
			primera = false;

		}
		else
		{
			getline(cin, estu.Nombre);
			getline(cin, estu.Nombre);

		}

		

		cout << "Anios: " << endl;
		cin >> estu.Anio;
		cout << "Mes: " << endl;
		cin >> estu.Mes;
		cout << "Dia: " << endl;
		cin >> estu.Dia;
		cout << "Info: " << endl;
		cin >> estu.Info;
		

		entrada.write((char *)&estu, sizeof(estudiantes));
		entrada.close();
	}

}




void salidas()
{

	ListaGenerica *lista1 = new ListaGenerica();

	ifstream salida;
	salida.open("archivo.dat", ios::in | ios::binary);

	if (salida.fail())
	{
		cout << "error al abrir el archivo" << endl;
		_getch();
	}
	else
	{
		int nreg;

		salida.seekg(0, ios::end);
		nreg = salida.tellg() / sizeof(estudiantes);
		salida.seekg(0);

		for (int x = 0;x<nreg;x++)
		{
			salida.read((char *)&estu, sizeof(estudiantes));

			// if(strcmp(nom,estu.nombre)==0) 
			cout << "nombre :" <<estu.Nombre<< endl;//revisar aqui el tipo de dato string puede dar problemas
			
			cout << "Anios: " <<estu.Anio << endl;
			
			cout << "Mes: " <<estu.Mes<< endl;

			cout << "Dia: " <<estu.Dia<< endl;
			
			cout << "Info: " <<estu.Info<< endl;
			cout << endl << endl;

			lista1->insertarPrimero(estu.Info, estu.Nombre, estu.Dia, estu.Mes, estu.Anio);

		

		}
		salida.close();
		lista1->imprimir();

		_getch();

	}

}








void eliminar()
{
	ofstream entrada;
	entrada.open("temp.dat", ios::out | ios::binary);
	ifstream salida;
	salida.open("archivo.dat", ios::in | ios::binary);

	if (salida.fail() || entrada.fail())
	{
		cout << "error al abrir el archivo" << endl;
		_getch();
	}
	else
	{
		int nreg;
		int ntem;
		cout << "introduce nombre del alumno a eliminar" << endl;
		cin >> ntem;

		salida.seekg(0, ios::end);
		nreg = salida.tellg() / sizeof(estudiantes);
		salida.seekg(0);

		for (int x = 0;x<nreg;x++)
		{
			salida.read((char *)&estu, sizeof(estudiantes));
			if (estu.Info == ntem)
			{
				cout << "registro borrado" << endl;
			}

			else
			{
				entrada.write((char *)&estu, sizeof(estudiantes));
			}

		}
		salida.close();
		entrada.close();
		remove("archivo.dat");
		rename("temp.dat", "archivo.dat");

		_getch();

	}
}






void modificar()
{

	ofstream entrada;
	entrada.open("temp.dat", ios::out | ios::binary);


	ifstream salida;
	salida.open("archivo.dat", ios::in | ios::binary);

	if (salida.fail() || entrada.fail())
	{
		cout << "error al abrir el archivo" << endl;
		_getch();
	}
	else
	{
		int nreg;
		int ntem;

		cout << "introduce nombre del alumno a modificar" << endl;
		cin >> ntem;


		salida.seekg(0, ios::end);
		nreg = salida.tellg() / sizeof(estudiantes);
		salida.seekg(0);

		for (int x = 0;x<nreg;x++)
		{
			salida.read((char *)&estu, sizeof(estudiantes));
			if (estu.Info == ntem)
			{
				cout << "introdusca nuevo nombre" << endl;
				cin >> estu.Nombre;

				cout << "introdusca nuevo Info" << endl;
				cin >> estu.Info;

				cout << "introdusca nuevO Anio" << endl;
				cin >> estu.Anio;
				cout << "registro modificado" << endl;
			}

			entrada.write((char *)&estu, sizeof(estudiantes));
		}
		salida.close();
		entrada.close();
		remove("archivo.dat");
		rename("temp.dat", "archivo.dat");

		// remove("hola.docx");
		_getch();

	}


}



