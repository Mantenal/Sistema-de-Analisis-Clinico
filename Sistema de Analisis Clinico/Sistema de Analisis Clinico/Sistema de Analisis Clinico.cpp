// Sistema de Analisis Clinico.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Windows.h"
#include <iostream>
#include <string>
#include <algorithm>
#include<fstream>
#include<string.h>

using namespace std;
bool primera = true;




/***********************************************************************************************************************************/

//Recursos Materiales

class R_Materiales {
private:
	int Codigo;
	int Tipo;
	string Nombre;
	int Existencia;
	float Precio;
public:

	void alta();
	void modificar();
	/*void R_analgesicos();
	void R_antivioticos();
	void R_preventivos();*/


	void buscar(bool buscar, int dato);//1,1 buscar,     0,1 analgesicos,  0,2antivioticos,   0,3preventivos
}materiales;



class Nodo_Materiales {
	int Codigo;
	int Tipo;
	string Nombre;
	int Existencia;
	float Precio;
	Nodo_Materiales *ant, *sig;
public:
	Nodo_Materiales(int codigo, int tipo, string nombre, int existencia, float precio) {
		Codigo = codigo;
		Tipo = tipo;
		Nombre = nombre;
		Existencia = existencia;
		Precio = precio;
	};
	friend class ListaMateriales;
};



class ListaMateriales {
	Nodo_Materiales *raiz;
public:
	ListaMateriales() { raiz = NULL; };
	~ListaMateriales() {
		Nodo_Materiales *reco = raiz;
		Nodo_Materiales *bor;
		while (reco != NULL)
		{
			bor = reco;
			reco = reco->sig;
			delete bor;
		}
	};
	void insertarPrimero(int codigo, int tipo, string nombre, int existencia, float precio);
	void imprimir();
};



/***********************************************************************************************************************************/






class C_Personal : public R_Materiales {
private:
	string nombre;
	int edad;
	int ine;
	int codigo;
	int tipo;
	float sueldo;
public:
	void agregar();
	void reporte();
	void buscar();
	void Modificar();
	void eliminar();
	//funcion de agregar heredada de R_materiales

};
class M_Clientes {
protected:
	string nombre;
	int edad;
	int telefono;
	int codigo;
public:
	void agregar();
	void buscar();
	void modificar();
	void eliminar();

};

class Cita : public M_Clientes {
private:
	int dia;
	int mes;
	int hora;
	int minuto;
	int t_cita;
public:
	void nueva();
	void lista();
	void reporte_sangre();
	void reporte_azucar();
	void reporte_orina();
};



int main()
{
	char opc, opc2;
	
	do
	{
		system("cls");
		cout << "LABORATORIO DE ANALISIS CLINICO" << endl << endl;
		cout << "1-Recursos Materiales" << endl;
		cout << "2-Control de Personal" << endl;
		cout << "3-Manejo de Clientes" << endl;
		cout << "4-Salir del Sistema" << endl << endl;
		cin >> opc;
		system("cls");

		switch (opc)
		{
		case '1':
			cout << "RECURSOS MATERIALES" << endl << endl;
			cout << "1-Dar de Alta Producto" << endl;
			cout << "2-Buscar un Producto" << endl;
			cout << "3-Modificar Precio de Producto" << endl;
			cout << "4-Reporte de Analgesicos" << endl;
			cout << "5-Reporte de Antibioticos" << endl;
			cout << "6-Reporte de Preventivo" << endl << endl;
			cin >> opc2;
			switch (opc2)
			{
			case'1':
				// alta producto
				materiales.alta();

				break;
			case'2':
				//buscar producto
				materiales.buscar(true, 1);
				break;
			case'3':
				//modificar precio 
				materiales.modificar();

				break;
			case'4':
				//reporte de analgesicos
				materiales.buscar(false, 1);
				break;
			case '5':
				//reporte de antibiote 
				materiales.buscar(false, 2);
				break;
			case '6':
				// reporte preventivo 
				materiales.buscar(false, 3);
				break;
			default:
				//falla
				break;
			}

			break;
		case '2':
			cout << "CONTROL DE PERSONAL" << endl << endl;
			cout << "1-Agregar un Empleado" << endl;
			cout << "2-Reporte de Empleados" << endl;
			cout << "3-Buscar un Empleado" << endl;
			cout << "4-Modificar Datos de un Empleado" << endl;
			cout << "5-Eliminar un Empleado" << endl;
			cout << "6-Agregar un Producto" << endl << endl;
			cin >> opc2;
			switch (opc2)
			{
			case'1':
				// agregar empleado
				break;
			case'2':
				//reporte de empleado
				break;
			case'3':
				//Busca un empleado
				break;
			case'4':
				//modificar datos 
				break;
			case '5':
				//eliminar un empleado
				break;
			case '6':
				// agregar producto

				break;
			default:
				break;
			}
			break;
		case '3':
			cout << "MANEJO DE CLIENTES" << endl << endl;
			cout << "1-Agregar un Cliente" << endl;
			cout << "2-Buscar un Cliente" << endl;
			cout << "3-Modificar Datos de un Cliente" << endl;
			cout << "4-Eliminar un Cliente" << endl;
			cout << "5-Establecer una Cita" << endl;
			cout << "6-Lista de Citas" << endl;
			cout << "7-Reporte de Clientes que Solicitaron Examen de Sangre" << endl;
			cout << "8-Reporte de Clientes que Solicitaron Examen de Nivel de Azucar" << endl;
			cout << "9-Reporte de Clientes que Solicitaron Examen de Orina" << endl << endl;
			cin >> opc2;

			switch (opc2)
			{
			case'1':
				// agregar Cliente
				break;
			case'2':
				//buscar clientes
				break;
			case'3':
				//modificar datos de cliente
				break;
			case'4':
				//Eliminar cliente
				break;
			case '5':
				//Establecer cita
				break;
			case '6':
				// Listas de citas
				break;
			case '7':
				//sangre
				break;
			case '8':
				//azucar
				break;
			case '9':
				//orina
				break;
			default:
				break;
			}

			break;

		default:
			cout << "Opcion no Valida" << endl;
			break;
		}
	} while (opc != 4);
	return 0;
}


void R_Materiales::alta() {

	system("cls");
	ofstream entrada;
	entrada.open("Materiales.dat", ios::out | ios::app | ios::binary);

	if (entrada.fail())
	{
		cout << "error al crear archivo";
		system("pause");
	}

	else
	{
		cout << "Ingresar Codigo:" << endl;
		cin >> materiales.Codigo;

		do
		{
			cout << "ingresa el tipo:" << endl;
			cout << "1-Analgesico" << endl;
			cout << "2-Antiviotico" << endl;
			cout << "3-Preventivo" << endl;
			cin >> materiales.Tipo;
		} while (materiales.Tipo < 0 && materiales.Tipo>4);
		cout << "Ingresa el Nombre:" << endl;//revisar aqui el tipo de dato string puede dar problemas
		getline(cin, materiales.Nombre);
		getline(cin, materiales.Nombre);
		cout << "Ingresa la Cantidad:" << endl;
		cin >> materiales.Existencia;
		cout << "Ingresa el Precio:" << endl;
		cin >> materiales.Precio;
		entrada.write((char *)&materiales, sizeof(R_Materiales));
		entrada.close();
	}

}


void R_Materiales::buscar(bool buscar, int dato)
{

	ListaMateriales *lista1 = new ListaMateriales();

	int nreg;
	string nombre,nombre2;

	ifstream salida;
	salida.open("Materiales.dat", ios::in | ios::binary);

	if (salida.fail())
	{
		cout << "error al abrir el archivo" << endl;
		system("pause");
	}
	else
	{
		salida.seekg(0, ios::end);
		nreg = salida.tellg() / sizeof(R_Materiales);
		salida.seekg(0);

		if (buscar == false) {//buscar antivioticos,analgesicos,preventivos

			for (int x = 0;x < nreg;x++)
			{
				salida.read((char *)&materiales, sizeof(R_Materiales));

				if (materiales.Tipo == dato) {
					lista1->insertarPrimero(materiales.Codigo, materiales.Tipo, materiales.Nombre, materiales.Existencia, materiales.Precio);

				}

			}
			
		}




		else
		{
			if (dato==1)
			{
				cout << "Ingresa el Nombre del Producto a Buscar" << endl;
				getline(cin, nombre);
				getline(cin, nombre);

		
				std::transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);
			

				for (int x = 0;x < nreg;x++)
				{
					salida.read((char *)&materiales, sizeof(R_Materiales));

					nombre2 = materiales.Nombre;
					std::transform(nombre2.begin(), nombre2.end(), nombre2.begin(), ::toupper);

					if (nombre == nombre2) {
						lista1->insertarPrimero(materiales.Codigo, materiales.Tipo, materiales.Nombre, materiales.Existencia, materiales.Precio);

					}

				}


			}
		}




		salida.close();
		lista1->imprimir();
		system("pause");

	}
	delete lista1;
}



void ListaMateriales::imprimir()
{
	Nodo_Materiales *reco = raiz;
	while (reco != NULL)
	{
		cout << reco->Codigo << "-";

		cout << reco->Nombre << "-";
		cout << reco->Existencia << "-";
		cout << reco->Precio << endl;

		reco = reco->sig;
	}
	cout << "\n";
}

void ListaMateriales::insertarPrimero(int codigo, int tipo, string nombre, int existencia, float precio)
{
	Nodo_Materiales *nuevo = new Nodo_Materiales(codigo, tipo, nombre, existencia, precio);
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



void R_Materiales::modificar()
{

	ofstream entrada;
	entrada.open("temp.dat", ios::out | ios::binary);


	ifstream salida;
	salida.open("Materiales.dat", ios::in | ios::binary);

	if (salida.fail() || entrada.fail())
	{
		cout << "error al abrir el archivo" << endl;
		system("pause");
	}
	else
	{
		int nreg;
		int ntem;
		bool encontrar = false;

		cout << "Introduce el codigo del producto a cambiar" << endl;
		cin >> ntem;


		salida.seekg(0, ios::end);
		nreg = salida.tellg() / sizeof(R_Materiales);
		salida.seekg(0);

		for (int x = 0;x < nreg;x++)
		{
			salida.read((char *)&materiales, sizeof(R_Materiales));
			if (materiales.Codigo == ntem)
			{
				cout << "Introduzca nuevo precio" << endl;
				cin >> materiales.Precio;
				encontrar = true;
			}

			entrada.write((char *)&materiales, sizeof(R_Materiales));
		}

		if (encontrar == false)
		{
			cout << "No se encontro Registro" << endl;
		}
		salida.close();
		entrada.close();
		remove("Materiales.dat");
		rename("temp.dat", "Materiales.dat");

		// remove("hola.docx");
		system("pause");

	}
}
