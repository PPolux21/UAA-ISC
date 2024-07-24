#include <iostream>
#include <string.h>
using namespace std;

struct Administradores{
	char nombre[15], apellidos[15], residencia[20], cuenta[10], contrasena[8], fechaNac[10];
};

struct Usuarios {
    char nombre[15], apellidos[15], residencia[20], fechaNac[10], cuenta[6], contrasena[8];
    int estatus;// 1 activo 	0 inactivo
};

struct Animales {
    char nombre[10], tipo[10], raza[10], edad[10];
};

struct Refugio {
    char nombre[20], direccion[50], telefono[15];
};




void editarInfoUsuario();
void eliminarUsuario();
void revisarEstadisticas();
void solicitudes();






void editarInfoUsuario(){
	FILE *archClientes;
	Usuarios reg;
	char cuentaBusca[6];
	int pos=0;
	
	cout<<"Dame la cuenta a editar: "
	cin>>cuentaBusca;
	
	archUsuarios = fopen("usuarios.txt", "a+");
	
	if(archClientes==NULL){
		cout<<"Error I/O \n";
		exit(1);
	}
	
	while(!feof(archClientes)){
		fscanf(archClientes,"%s\t%s\t%s\t%s\t%s\t%s\t%d",reg.nombre,reg.apellidos,reg.residencia,reg.fechaNac,reg.cuenta,reg.contrasena,reg.estatus);
		//compara si la cuenta está en el archivo
		if(strcmp(reg.cuenta,cuentaBusca)){
			//de ser así se vuelven a ingresar los datos del usuario
			cout<<"Nombre: ";
			cin>>reg.nombre;
			cout<<"Apellido: ";
			cin>>reg.apellidos;
			cout<<"Ciudad de residencia: ";
			cin>>reg.residencia;
			cout<<"Fecha de Nacimiento (DD/MM/AAAA): ";
			cin>>reg.fechaNac;
			cout<<"Cuenta: ";
			cin>>reg.cuenta;
			cout<<"Contrasena: ";
			cin>>reg.contrasena;
			cout<<"Estatus: ";
			cin>>reg.estatus;
			
			//se regresa al comieno del renglón
			pos = ftell(archClientes)-sizeof(Usuarios);
			fseek(archClientes,pos,SEEK_SET);
			
			//edita el renglón del usuario
			fprintf(archClientes,"%s\t%s\t%s\t%s\t%s\t%s\t%d",reg.nombre,reg.apellidos,reg.residencia,reg.fechaNac,reg.cuenta,reg.contrasena,reg.estatus);
		}
	}
	
	fclose(archClientes);
}

void eliminarUsuario(){
	FILE *archClientes;
	Usuarios reg;
	char cuentaBusca[6];
	
	cout<<"Dame la cuenta a eliminar: "
	cin>>cuentaBusca;
	
	archUsuarios = fopen("usuarios.txt", "a+");
	
	if(archClientes==NULL){
		cout<<"Error I/O \n";
		exit(1);
	}
	
	while(!feof(archClientes)){
		fscanf(archClientes,"%s\t%s\t%s\t%s\t%s\t%s\t%d",reg.nombre,reg.apellidos,reg.residencia,reg.fechaNac,reg.cuenta,reg.contrasena,reg.estatus);
		//compara si la cuenta está en el archivo
		if(strcmp(reg.cuenta,cuentaBusca)){
			//se elimina de forma lógica
			reg.estatus=0;
			
			//se regresa al comieno del renglón
			pos = ftell(archClientes)-sizeof(Usuarios);
			fseek(archClientes,pos,SEEK_SET);
			
			//edita el renglón del usuario
			fprintf(archClientes,"%s\t%s\t%s\t%s\t%s\t%s\t%d",reg.nombre,reg.apellidos,reg.residencia,reg.fechaNac,reg.cuenta,reg.contrasena,reg.estatus);
			
			cout<<"Usuario eliminado\n";
		}
	}
	
	flcose(archClientes);
}

void revisarEstadisticas(){
	
}

void solicitudes(){
	
}