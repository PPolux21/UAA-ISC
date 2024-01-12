// Actividad Viernes 10/03/2023
#include <iostream>

using namespace std;

void operacion (int numA, int numB, char operador, float* resultado);

int main()
{
	int numA,numB;
	char op;
	float res=0;
	
	cout<<"Dame el primer numero: ";
	cin>>numA;
	cout<<"Dame el segundo numero: ";
	cin>>numB;
	cout<<"Dame el operador que se utilizara: ";
	cin>>op;
	if(op=='+'||op=='-'||op=='*'||op=='/'||op=='%')
	{
		operacion(numA,numB,op,&res);
		cout<<"El resultado de "<<numA<<" "<<op<<" "<<numB<<" es: "<<res<<endl;
	}
	else
	{
		cout<<"Operador no valido! D:"<<endl;
	}
	
}

void operacion (int numA, int numB, char operador, float* resultado)
{
	switch(operador)
	{
		case '+':
			*resultado=numA+numB;
			break;
		case '-':
			*resultado=numA-numB;
			break;
		case '*':
			*resultado=numA*numB;
			break;
		case '/':
			*resultado=numA/numB;
			break;
		case '%':
			*resultado=numA%numB;
			break;
	}
}
