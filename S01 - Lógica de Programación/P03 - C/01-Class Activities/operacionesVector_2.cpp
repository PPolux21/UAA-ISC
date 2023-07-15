#include <stdio.h>

int main()
{
	int largo,vec[largo];
	printf("largo de vector: ");
	scanf("%d",&largo);
	for(int i=0;i<largo;i++)
	{
		vec[i]=i+1;
	}
	for(int i=0;i<largo;i++)
	{
		printf("%d ",vec[i]);
	}
}