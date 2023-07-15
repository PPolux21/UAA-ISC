#include <stdio.h>

int main(){

	int arr[50],num,x=0,y=0,temp=0;

	printf("Please Enter the Number of Elements you want in the array: ");
	scanf("%d",&num);

	for(x=0; x<num; x++)
	{
		printf("Please Enter the Value of Elements: ");
		scanf("%d",&arr[x]);
	}

	for(x=0;x<num-1;x++)
	{
		for(y=0;y<num-x-1;y++)
		{	
			if(arr[y] > arr[y + 1])
			{
				temp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temp;
			}
		}
	}

	printf("Array after implementing bubble sort: ");

	for(x = 0; x < num; x++)
	{
		printf("%d  ", arr[x]);
	}
	return 0;
}