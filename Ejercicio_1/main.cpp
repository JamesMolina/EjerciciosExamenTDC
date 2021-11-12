#include <iostream>
#include <vector>
#include "Arista.hpp"
#include "Vertice.hpp"
#include "Grafo.hpp"
#include "Seq.hpp"
#include "Set.hpp"
#include <iostream>
#include <fstream>
#include "SuperClaseVE.hpp"

using namespace std;
Grafo *G = new Grafo();

int valido(int num, int size){
	if(size < 1)
		return -1;
	while(true){
		if(num >= 0 && num < size)
			return num;
		cout << "Ingrese un tamano valido: ";
		cin >> num;
	}
}

bool EsUnNumero(string cadena){
  for(int i = 0 ; i < cadena.size(); i++ )
    if( !isdigit(cadena[i]) )
      return false;
  return true;
}

int inputValido(){
	string leer;
	while(true){
		cin >> leer;
		if(EsUnNumero(leer))
			return stoi(leer);
		else
			cout << "Ingrese una entrada valida!!: ";
	}
}

int* obtenerArista(string cadena){
	int index = 0;
	int *dosVertices = new int[2];
	string acum = "";
	for(int i = 1; i < cadena.size()-1; i++){
		if(cadena[i] == ','){
			dosVertices[0] = stoi(acum);
			acum = "";
		}else
			acum += cadena[i];
	}
	dosVertices[1] = stoi(acum);
	return dosVertices;
}

void grafoMatriz(){
	cout << endl << endl;
	cout << "Grafo a Matriz:" << endl;
	int tamano = G->getSecuencia()->getConjuntos()[0]->getVE().size()+1;
	SuperClaseVE *matriz[tamano][tamano];
	for(int i = 0; i < tamano; i++){
		for(int j = 0; j < tamano; j++){
			matriz[i][j] = new Vertice(0);
		}
	}
	for(int i = 1; i < tamano; i++){
		matriz[0][i] = G->getSecuencia()->getConjuntos()[0]->getVE()[i-1];
		matriz[i][0] = matriz[0][i];
	}
	
	vector<SuperClaseVE*> VE = G->getSecuencia()->getConjuntos()[1]->getVE();
	for(int i = 0; i < VE.size(); i++){
		int *arista = obtenerArista(  ((Arista *)VE[i])->toString() );
		int fila, columna;
		for(int j = 0; j < tamano; j++)
			if( ((Vertice *)matriz[j][0])->getValor()== arista[0])
				for(int k = 0; k < tamano; k++ )
					if( ((Vertice *)matriz[0][k])->getValor() == arista[1]){
						matriz[j][k] = new Vertice(1);
						matriz[k][j] = new Vertice(1);
					}
	}
	
	for(int i = 0; i < tamano; i++){
		for(int j = 0; j < tamano; j++){
			if(matriz[i][j])
				cout << "[" << matriz[i][j]->toString() << "]";
			else 
				cout << "[ ]";
		}
		cout << endl;
	}
	cout << endl << endl;
	
}

void imprimirGrafo(){
	cout << endl << endl << G->toString() << endl << endl;
}

void grafoMenu(){
	int opciones;
	cout << endl;
	cout << "1. Imprimir Grafo" << endl;
	cout << "2. Grafo a Matriz" << endl;
	cout << "Ingrese una opcion: ";
	opciones = inputValido();
	cout << endl;
	if(opciones == 1)
		imprimirGrafo();
	if(opciones == 2)
		grafoMatriz();
}

void cargarArchivoArista(){
	ifstream f( "ElementosE.txt" );
	string lineas;
	vector<int> elementosVertices;
 	if ( f.is_open() ) {
 		getline( f, lineas );
 		Set *nuevoSet = new Set();
 		while( !f.eof() ) {
 			int *aristas = obtenerArista(lineas);
 			Vertice *vx = new Vertice(aristas[0]);
 			Vertice *vy = new Vertice(aristas[1]);
 			SeqV *sv = new SeqV(vx, vy);
 			Arista *A = new Arista(sv);
 			nuevoSet->setVE(A);
 			getline( f, lineas );
 			elementosVertices.push_back(aristas[0]);
 			elementosVertices.push_back(aristas[1]);
 		}
 		Set *s = new Set();
		for(int i = 0; i < elementosVertices.size(); i++){
 			Vertice *v = new Vertice(elementosVertices[i]);
 			s->setVE(v);
		}
 		G->getSecuencia()->setConjuntoV(s);
 		G->getSecuencia()->setConjuntoE(nuevoSet);
	}
 	else
 		cerr << "Error al abrir el archivo." << endl; 
}

bool existeArista(Vertice *x, Vertice *y){
	vector<SuperClaseVE*> listaArista = G->getSecuencia()->getConjuntos()[1]->getVE();
	int x_1 = x->getValor();
	int y_1 = y->getValor();
	for(int i = 0; i < listaArista.size(); i++){
		int x_2 = ((Vertice*) ((Arista *) listaArista[i] )->getSecuencia()->getX())->getValor();
		int y_2 = ((Vertice*)((Arista *) listaArista[i] )->getSecuencia()->getY())->getValor();
		if( (x_2 == x_1 && y_2 == y_1 ) || (x_2 == y_1 && y_2 == x_1) )
			return true;
	}
	return false;
}

void anadirArista(){
	int opcion;
	do{
		int tamano = G->getSecuencia()->getConjuntos()[0]->getVE().size();
		if(tamano > 0){
			cout << endl;
			cout << G->toString() << endl;
			int x, y;
			cout << "Ingrese la posicion del primer vertice: ";
			x = inputValido();
			valido(x, tamano);
			cout << "Ingrese la posicion del segundo vertice: ";
			y = inputValido();
			valido(y, tamano);
			SeqV *s = new SeqV();
			s->setX(new Arista());
			s->setY(new Arista());
			Vertice *Ax = (Vertice*)(G->getSecuencia()->getConjuntos()[0]->getUnVE(x));
			Vertice *Ay = (Vertice*)(G->getSecuencia()->getConjuntos()[0]->getUnVE(y));
			if(!existeArista(Ax,Ay)){
				s->setX((Arista*)(G->getSecuencia()->getConjuntos()[0]->getUnVE(x)));
				s->setY((Arista*)(G->getSecuencia()->getConjuntos()[0]->getUnVE(y)));
				G->getSecuencia()->getConjuntos()[1]->setVE(new Arista(s));	
			}
			cout << "Desea seguir anadiendo [No = 0]: ";
			opcion = inputValido();
			cout << endl;
		}else{
			cout << "No existen vertices" << endl;
			opcion = 0;
		}
	}while(opcion != 0);
}

void aristasMenu(){
	cout << endl;
	int opcion;
	cout << "1. Anadir Arista" << endl;
	cout << "2. Cargar Archivo txt" << endl;
	cout << "Ingrese la opcion: ";
	opcion = inputValido();
	if(opcion == 1)
		anadirArista();
	if(opcion == 2)
		cargarArchivoArista();
}


void anadirVertice(){
	cout << endl;
	int opcion, valor;
	do{
		cout << "Ingrese el valor del vertice: ";
		valor = inputValido();
		G->getSecuencia()->getConjuntos()[0]->setVE(new Vertice(valor));
		cout << "Desea seguir anadiendo [No = 0]: ";
		opcion = inputValido();
		cout << endl;
	}while(opcion != 0);
}

int verticeNum(string cadena){
	string acum = "";
	for(int i = 0; i < cadena.size(); i++){
		if(cadena[i] == '|')
			return stoi(acum);
		else
			acum += cadena[i];
	}	
}

string etiqueta(string cadena){
	string acum = "";
	for(int i = 0; i < cadena.size(); i++){
		if(cadena[i] == '|')
			acum = "";
		else
			acum += cadena[i];
	}	
	return acum;
}

void cargarArchivoVertice(){
	ifstream f( "ElementosV.txt" );
	string lineas;
 	if ( f.is_open() ) {
 		getline( f, lineas );
 		Set *nuevoSet = new Set();
 		while( !f.eof() ) {
 			Vertice *v = new Vertice();
			v->setValor(verticeNum(lineas));
			v->setEtiqueta(etiqueta(lineas));
 			nuevoSet->setVE(v);
			getline( f, lineas );
 		}
 		G->getSecuencia()->setConjuntoV(nuevoSet);
 		G->getSecuencia()->setConjuntoE(new Set());
	}
 	else
 		cerr << "Error al abrir el archivo." << endl; 
}

void etiquetarVertice(){
	imprimirGrafo();
	int pos;
	cout << "Ingrese la posicion del vertice a etiquetar: ";
	pos = inputValido();
	if( G->getSecuencia()->getConjuntos()[0]->getVE().size() > 0){
		valido(pos, G->getSecuencia()->getConjuntos()[0]->getVE().size());
		string etiqueta;
		cout << "Ingrese la etiqueta: ";
		cin >> etiqueta;
		((Vertice*)(G->getSecuencia()->getConjuntos()[0]->getUnVE(pos)))->setEtiqueta(etiqueta);
	}else{
		cout << "La lista de vertices esta vacia" << endl;
	}
}

void verticeConEtiqueta(){
	cout << endl << endl << "Vertices = { ";
	int tamano = G->getSecuencia()->getConjuntos()[0]->getVE().size();
	for(int i = 0; i < tamano;i++){
		cout << ((Vertice*)G->getSecuencia()->getConjuntos()[0]->getVE()[i])->toStringConEtiqueta();
		if(i < tamano - 1)
			cout << ", ";
	}
	cout << " }" << endl << endl;
}

void verticesMenu(){
	cout << endl;
	int opcion;
	cout << "1. Anadir Vertice" << endl;
	cout << "2. Cargar Archivo txt" << endl;
	cout << "3. Etiquetar Vertice" << endl;
	cout << "4. Imprimir Vertices Etiquedos" << endl;
	cout << "Ingrese la opcion: ";
	opcion = inputValido();
	if(opcion == 1)
		anadirVertice();
	if(opcion == 2)
		cargarArchivoVertice();
	if(opcion == 3)
		etiquetarVertice();
	if(opcion == 4)
		verticeConEtiqueta();
}

void menu(){
	int opcion;
	do{
		cout << endl;
		cout << "0. Salir" << endl;
		cout << "1. Vertices" << endl;
		cout << "2. Aristas" << endl;
		cout << "3. Grafo" << endl;
		cout << "Ingrese la opcion: ";
		opcion = inputValido();
		if(opcion == 1)
			verticesMenu();
		else if(opcion == 2)
			aristasMenu();
		else if(opcion == 3)
			grafoMenu();
	}while(opcion != 0);
}


int main(int argc, char** argv) {
	G->getSecuencia()->setConjunto(new Set());
	G->getSecuencia()->setConjunto(new Set());
	menu();
	return 0;
}



