//Práctica recursividad

#include <iostream>

using namespace std;

int divRestasSus(int,int);
void invertirNum(int);
int sumaDigit(int);
void llenaVec(int*,int);
int sumaVec(int*,int);
int multVec(int*,int);

int main()
{
	int opc;
	int num,aux,*vec,**mat;
	
	do
	{
		system("cls");
		cout<<"\tPracticas Recusrividad"<<endl;
		cout<<"Division por restas sucesivas - - - 1"<<endl;
		cout<<"Invertir numero - - - - - - - - - - 2"<<endl;
		cout<<"Suma de digitos - - - - - - - - - - 3"<<endl;
		cout<<"Suma de elmentos de un vector - - - 4"<<endl;
		cout<<"Multiplicar elmentos de un vector - 5"<<endl;
		cout<<"Maximo comun divisor  - - - - - - - 6"<<endl;//Completar
		cout<<"Numero positivo - - - - - - - - - - 7"<<endl;//Completar
		cout<<"Suma de elmentos de una matriz  - - 8"<<endl;//Completar
		cout<<"Salir - - - - - - - - - - - - - - - 9"<<endl;
		cout<<"\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				cout<<"\nDivisor: ";
				cin>>num;
				cout<<"Dividendo: ";
				cin>>aux;
				cout<<"Resultado: "<<divRestasSus(num,dividendo)<<endl;
				system("pause");
				break;
			case 2:
				cout<<"Numero a invertir: ";
				cin>>num;
				invertirNum(num);
				cout<<endl;
				system("pause");
				break;
			case 3:
				cout<<"Numero a sumar digitos: ";
				cin>>num;
				cout<<"Resultado: "<<sumaDigit(num)<<endl;
				system("pause");
				break;
			case 4:
				cout<<"Cantidad de elementos en el vector: ";
				cin>>num;
				vec = new int [num];
				llenaVec(vec,num);
				cout<<"Resultado: "<<sumaVec(vec,num-1)<<endl;
				system("pause");
				break;
			case 5:
				cout<<"Cantidad de elementos en el vector: ";
				cin>>num;
				vec = new int [num];
				llenaVec(vec,num);
				cout<<"Resultado: "<<multVec(vec,num-1)<<endl;
				system("pause");
				break;
			case 6:
				system("pause");
				break;
			case 7:
				system("pause");
				break;
			case 8:
				system("pause");
				break;
			case 9:
				break;
			default:
				cout<<"\nOpcion no valida"<<endl;
				system("pause");
				break;
		}
	}while(opc!=9);
	
	return 0;
}

int divRestasSus(int divisor,int dividendo)
{
	if(divisor<dividendo)
	{
		return (1 + divRestasSus(divisor,dividendo-divisor));
	}
	else
	{
		return 1;
	}
}

void invertirNum(int num)
{
	if(num>0)
	{
		cout<<num%10;
		invertirNum(num/10);
	}
}

int sumaDigit(int num)
{
	if(num>=10)
	{
		return (num%10) + sumaDigit(num/10);
	}
	else 
	{
		return num;
	}
}

void llenaVec(int *vec,int num)
{
	for(int i=0;i<num;i++)
	{
		cout<<"Dame un numero: ";
		cin>>vec[i];
	}
}

int sumaVec(int *vec,int num)
{
	if(num==0)
	{
		return vec[0];
	}
	else
	{
		return vec[num] + sumaVec(vec,num-1);
	}
}

int multVec(int *vec,int num)
{
	if(num==0)
	{
		return vec[0];
	}
	else
	{
		return vec[num] * multVec(vec,num-1);
	}
}

