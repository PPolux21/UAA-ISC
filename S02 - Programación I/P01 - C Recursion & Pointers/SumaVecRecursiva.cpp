//Sumatoria Recursiva

#include <iostream>

int sumaVec(int[],int);

using namespace std;

int main()
{
	int vec[]={1,2,4,5,6,7,7,9,0,2},sumatoria;
	sumatoria=sumaVec(vec,9);
	cout<<"Sumatoria: "<<sumatoria<<endl;
	return 0;
}

int sumaVec(int vector[],int tam)
{
	if(tam==0)
	{
		return vector[tam];
	}
	else
	{
		return sumaVec(vector,tam-1)+vector[tam];
	}
}