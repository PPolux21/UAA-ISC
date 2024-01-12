// Punteros: La secuela

#include <iostream>

using namespace std;

int main()
{
	int index,dia,*ptr1,*ptr2;
	index=28;
	dia=3;
	
	ptr1=&index;
	
	ptr2=ptr1;
	
	cout<<"Index: "<<index<<"\t *ptr1: "<< *ptr1<<"\t *ptr2: "<< *ptr2<<endl;
	
	*ptr1=16;
	
	cout<<"Index: "<<index<<"\t *ptr1: "<< *ptr1<<"\t *ptr2: "<< *ptr2<<endl;
	
	*ptr2=32;
	
	cout<<"Index: "<<index<<"\t *ptr1: "<< *ptr1<<"\t *ptr2: "<< *ptr2<<endl;
	
	ptr2=&dia;
	
	cout<<"Index: "<<index<<"\t *ptr1: "<< *ptr1<<"\t *ptr2: "<< *ptr2<<endl;
	return 0;
}