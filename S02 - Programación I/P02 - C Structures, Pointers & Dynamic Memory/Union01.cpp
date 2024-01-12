//Manejo de uniones

#include <iostream>

using namespace std;


//La union solo guarda un valor a la vez
union Numero{
	int numInt;
	float numFloat;
};

int main()
{
	Numero valor;
	valor.numInt=10;
	valor.numFloat=9.8;
	//en este caso el valor entero muestra basura ya que el último valor guardado fue en la parte real
	cout<<"Parte entera: "<<valor.numInt<<endl;
	cout<<"Parte real: "<<valor.numFloat<<endl;
}