//Ejercicios Recursividad Pt. 2

#include <iostream>

using namespace std;

int fibonacci(int);
int euclid(int,int);
int ackermann(int,int);
int particion(int,int);
int coefBin(int,int);

int main()
{
	int opc; 
	int num,num2;
	
	do
	{
		system("cls");
		cout<<"\t MENU"<<endl;
		cout<<"Fibonacci  - - - - - - - - - 1"<<endl;
		cout<<"Algoritmo Euclides - - - - - 2"<<endl;
		cout<<"Algoritmo Ackermann  - - - - 3"<<endl;
		cout<<"Algoritmo de Particion - - - 4"<<endl;
		cout<<"Coeficioentes Binomiales - - 5"<<endl;
		cout<<"Torres de Hanoi  - - - - - - 6"<<endl;
		cout<<"Salir  - - - - - - - - - - - 7"<<endl;
		cout<<"\nOpcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				cout<<"Posición de la serie de Fibonacci a buscar: ";
				cin>>num;
				cout<<fibonacci(num)<<endl;
				system("pause");
				break;
			case 2:
				cout<<"Numeros para encontrar Maximo Comun Divisor"<<endl;
				cout<<"\tNumero: ";
				cin>>num;
				cout<<"\tNumero: ";
				cin>>num2;
				cout<<euclid(num,num2)<<endl;
				system("pause");
				break;
			case 3:
				cout<<"Numeros para Algoritmo de Ackermann"<<endl;
				cout<<"\tNumero: ";
				cin>>num;
				cout<<"\tNumero: ";
				cin>>num2;
				cout<<ackermann(num,num2)<<endl;
				system("pause");
				break;
			case 4:
				cout<<"Numeros para Algoritmo de Particion"<<endl;
				cout<<"\tNumero: ";
				cin>>num;
				cout<<"\tNumero: ";
				cin>>num2;
				cout<<particion(num,num2)<<endl;
				system("pause");
				break;
			case 5:
				cout<<"Numeros para Coeficientes Binomiales"<<endl;
				cout<<"\tNumero: ";
				cin>>num;
				cout<<"\tNumero: ";
				cin>>num2;
				cout<<coefBin(num,num2)<<endl;
				system("pause");
				break;
			case 6:
				system("pause");
				break;
			case 7:
				break;
			default:
				break;
		}
	}while(opc!=7);
	
	return 0;
}

int fibonacci(int num)
{
	if(num<=1)
	{
		return 1;
	}
	else{
		return fibonacci(num-1)+fibonacci(num-2);
	}
}

int euclid(int m,int n)
{
	if(n==0)
	{
		return m;
	}else{
		return euclid(n,m%n);
	}
}

int ackermann(int m,int n)
{
	if(m==0)
		return n+1;
	else
		if(m>0 && n==0)
			return ackermann(m-1,1);
		else
//			if(m>0 && m>0)
				return ackermann(m-1,ackermann(m,n-1));

}

int particion(int m,int n)
{
	if(m==1 || n==1)
		return 1;
	if(m<n)
		return particion(m,m);
	if(m==n)
		return 1 + particion(m,m-1);
	if(m>n)
		return particion(m,m-1) + particion(m-n,n);
		
}

int coefBin(int n,int k)
{
	if(k=0 || k==n)
		return 1;
	if(n>k && k>0)
		return coefBin(n-1,k) + coefBin(n-1,k-1);
}