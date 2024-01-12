/*
 ifstream descriptor (“nombre.extensión”);
 ofstream descriptor (“nombre.extensión”);
 
 ifstream descriptor(“nombre.extensión”,int modo); // para entrada
 ofstream descriptor(“nombre.extensión”,int modo); // para salida
 
 ios:: in // Modo entrada
 ios:: out // Modo salida (por defecto)
 ios:: app // Modo añadir, o sea, posicionar el cursor del fichero (ver abajo)
 // al final del archivo antes de cada escritura
 ios:: binary // El archivo se abre en modo binario
 ios:: ate // El archivo se abre y el cursor se posiciona al final
 ios:: nocreate // Genera un error si el fichero no existe
 ios:: noreplace // Genera un error si el fichero existe ya
 */

#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, const char * argv[]) {
    //CREACION Y ESCRITURA DE ARCHIVO
    //char archivo[]="/Users/jjpg/AppleApps/abc.txt";
    char archivo[]="abc.txt";
    ofstream salida(archivo);
    //tambien puede ser:
    //ofstream output;
    // output.open("Hello.txt");
    char c;
    int i=0;
    //Capturamos un char y lo agregamos al archivo
    cout<<"Ingresa una letra del abecedario ";
    cin >> c;
    for(i=0; (i+c)<='z';i++){
        salida << (char)(c+i)<<",";
    }
    salida<<i;
    salida.close();
    //output.close();
    
    //LECTURA DE ARCHIVO
    //ifstream entrada("Hola.txt");
    ifstream entrada(archivo);
   
    //Tambien puede ser
    //ifstream input;
    //input.open("Hello.txt");
    if (entrada.good())
        cout << "El archivo "<<archivo<<" fue abierto correctamente";
    else
        cout << "El archivo "<<archivo<<" no pudo ser abierto correctamente";
    cout << endl;
    entrada >> c;
    while(!entrada.eof()){
        cout << c <<" ";
        entrada >> c;
    }
    cout<<endl;
    entrada.close();
    //input.close();
}