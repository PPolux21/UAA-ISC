//lectura de Archivos bmp

#include <iostream>
#include <fstream>

using namespace std;

class Bmp{
public:
//	char tipo[2]; // 1 byte
	int tamArch;
	int reserv;
	int imagenI;
	int tamBitmap;
	int ancho;
	int alto; // 4 bytes
	unsigned short int planos;
	unsigned short int tamPunto; // 2 bytes 
	int comp;
	int tamImag; 
	int resH;
	int resV;
	int tamTablaC;
	int contC;// 4 bytes
};

int main()
{
	char archivo[]="T-BMP.bmp";
	
	Bmp imagen;
	
	cout<<"Archivo .bmp"<<endl;
	
	fstream archBin(archivo, ios::binary | ios::in);
	
	archBin.seekp(2);
	archBin.read(reinterpret_cast<char*>(&imagen),sizeof(Bmp));
	
	
//	archBin.read(reinterpret_cast<char*>(&imagen.tipo[0]),sizeof(char)*2);
//	cout<<"tipo= "<<imagen.tipo[0]<<imagen.tipo[1]<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.tamArch),sizeof(int));
	cout<<"tam archivo= "<<imagen.tamArch<<endl;
//	archBin.seekp(10);
	
//	archBin.read(reinterpret_cast<char*>(&imagen.imagenI),sizeof(int));
	cout<<"Inicio de datos imagen= "<<imagen.imagenI<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.tamBitmap),sizeof(int));
	cout<<"Tamano del bitmap= "<<imagen.tamBitmap<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.ancho),sizeof(int));
	cout<<"Ancho= "<<imagen.ancho<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.alto),sizeof(int));
	cout<<"Alto= "<<imagen.alto<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.planos),sizeof(unsigned short int));
	cout<<"Numero de planos= "<<imagen.planos<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.tamPunto),sizeof(unsigned short int));
	cout<<"Tamano de cada punto= "<<imagen.tamPunto<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.comp),sizeof(int));
	cout<<"Compresion= "<<imagen.comp<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.tamImag),sizeof(int));
	cout<<"Tamano de imagen= "<<imagen.tamImag<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.resH),sizeof(int));
	cout<<"Resolucion Horizontal= "<<imagen.resH<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.resV),sizeof(int));
	cout<<"Resolucion Vertical= "<<imagen.resV<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.tamTablaC),sizeof(int));
	cout<<"Tamano de la tabla de color= "<<imagen.tamTablaC<<endl;
	
//	archBin.read(reinterpret_cast<char*>(&imagen.contC),sizeof(int));
	cout<<"Contador de colores importantes= "<<imagen.contC<<endl;
	
	archBin.close();
}
