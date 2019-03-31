#include <stdio.h>

int SumOfArrResult3(int(*parr)[2], int);
int SumOfArrResult4(int(*parr)[3], int);

int main(void)
{
	int arr3[2][2] = {1, 3, 5, 7};
	int arr4[2][3] = {1, 2, 3, 4, 5, 6};
	int ret;
	
	ret = SumOfArrResult3(arr3,2);
	printf("1, 3, 5, 7의 합 : %d\n",ret);

	ret = SumOfArrResult4(arr4,2);
	printf("1, 2, 3, 4, 5, 6의 합 : %d\n",ret);

	return 0;
}

int SumOfArrResult3(int (*parr)[2], int column)
{
	int total=0;
	int i,j;

	for(i=0; i<column; i++)
	{	
		for(j=0; j<2; j++)
			total += parr[i][j];
	}
	return total;
}

int SumOfArrResult4(int (*parr)[3], int column)
{
	int total=0;
	int i,j;

	for(i=0; i<column; i++)
	{	
		for(j=0; j<3; j++)
			total += parr[i][j];
	}
	return total;	
}
