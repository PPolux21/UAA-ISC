// Espinoza Sanchez Jose Luis - 280676 - 3°C ISC

#include "CMatriz.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	CMatriz matrix1;
	CMatriz matrix2(1,2,3,4,5,6,7,8,9);
	CMatriz matrix3(matrix2);
	
	cout<<matrix1<<endl;
	cout<<matrix2<<endl;
	cout<<matrix3<<endl;
	
	cin>>matrix1;
	//suma de matrices
	matrix3 = matrix1 + matrix2;
	
	cout<<matrix1<<"\t+\n"<<matrix2<<"\t=\n"<<matrix3<<endl;
	
	getchar();
	getchar();
	cout<<endl<<endl;
	//resta de matrices
	matrix3 = matrix1 - matrix2;
	
	cout<<endl<<matrix1<<"\t-\n"<<matrix2<<"\t=\n"<<matrix3<<endl;
	
	getchar();
	cout<<endl<<endl;
	
	//operadores logicos
	if(matrix1==matrix2) // ==
		cout<<matrix1<<"\n  es igual que \n\n"<<matrix2<<endl;
	else
		cout<<matrix1<<"\n  no es igual que \n\n"<<matrix2<<endl;
	
	getchar();
	cout<<endl<<endl;
	
	if(matrix1!=matrix2)// !=
		cout<<matrix1<<"\n  es diferente de \n\n"<<matrix2<<endl;
	else
		cout<<matrix1<<"\n  no es diferente de \n\n"<<matrix2<<endl;
	
	return 0;
}