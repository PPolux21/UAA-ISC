// Memoeria Dinámica

#include <iostream>

using namespace std;

int main()
{
	int num=0,*ptrI,*vec;
	
	cout<<"Tamaño para el vector: ";
	cin>>num;
	vec=(int *)malloc(10*sizeof(int));
	for(int i=0;i<num;i++)
	{
		vec[i]=i*2;
		cout<<*(vec+i)<<endl;
	}
	return 0;
}