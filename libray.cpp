#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int cols = 2; 
	
string** libros; 

int size;

void escribirArchivo();

void leerArchivo();

void encontrarLibro(int posicion);

int main(){
	
	cout<<"Cuantos libros desea ingresar?";
	
	string entrada;
	
	getline(cin, entrada); 
	
	size = stoi(entrada); 
	
	libros = new string*[size]; 
	
	
	cout<<"Escriba la informacion de los libros: \n";
	string titulo,autor;
	
	for(int i=0; i<size; i++){
		libros[i] = new string[cols];
		cout<<"\n****** Libro"<<i+1<<"********\n";
		cout<<"Titulo: ";
		getline(cin,titulo);
		cout<<"Autores: ";
		getline(cin,autor); 
		libros[i][0] = titulo;
		libros[i][1] = autor;
	}
	
	escribirArchivo();
	
	leerArchivo();
	
	int posicion;
	cout << "Escribe que libro quieres: ";
	cin >> posicion;
	encontrarLibro(posicion);
	
	

	system("pause");
return 0;
}

void escribirArchivo(){
	ofstream archivoLibros;
	archivoLibros.open("libros.txt");
	if(!archivoLibros.is_open()){
		cout << "Error al crear el archivo";
	}
	else{
		for(int i = 0; i < size; i++){
			archivoLibros << libros[i][0] << " " << libros[i][1] << endl;
		}
		archivoLibros.close();
	}
	
}

void leerArchivo(){
	string linea;
	ifstream archivoLibros;
	archivoLibros.open("libros.txt");
	if(!archivoLibros.is_open()){
		cout << "Error al abrir el archivo";
	}
	else{
		while(getline(archivoLibros, linea)){
			cout << linea << "\n";
		}
		archivoLibros.close();
	}
}

void encontrarLibro(int posicion){
	string *direccionLibro;
	direccionLibro = libros[posicion];
	cout << "El libro seleccionado es " + *(direccionLibro) + " de " + *(direccionLibro + 1) + "\n"; 
}

