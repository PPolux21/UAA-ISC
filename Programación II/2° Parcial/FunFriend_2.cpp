#include <iostream>

using namespace std;

class Gato;

class Perro
{
public:
	Perro(string nombre, int edad) : nombre(nombre), edad(edad) {}
	
	friend class Gato;
	
private:
	string nombre;
	int edad;
};

class Gato
{
public:
	Gato(string nombre, int edad) : nombre(nombre), edad(edad) {}
	
	void setAmigoPerruno(Perro *p)
	{
		this->amigoPerruno = p;
	}
	
	void amigos()
	{
		if(this->amigoPerruno)
		{
			cout<<this->nombre<<" es amigo de "<<this->amigoPerruno->nombre<<endl;
		}else{
			cout<<this->nombre<<" no tiene amigos"<<endl;
		}
	}
	
private:
	string nombre;
	int edad;
	Perro *amigoPerruno;
};

int main()
{
	cout<<"Wenas :D\n";
	
	Perro perro("Ronnie",4);
	Gato gato("Sky",2);
	
	gato.setAmigoPerruno(&perro);
	gato.amigos();
	
	Gato gatoSolitario("Nick",8);
	
	gatoSolitario.amigos();
	
	return 0;
}