#include <stdio.h>

int ArrSub(int*, int);

int main(void)
{
	int arr1[3]={5,10,15};
	int arr2[5]={1,2,3,4,5};
	int ret;

	ret = ArrSub(arr1, sizeof(arr1)/sizeof(int));
	printf("%d, %d, %d의 합 : %d\n",arr1[0],arr1[1],arr1[2],ret);

	ret = ArrSub(arr2, sizeof(arr2)/sizeof(int));
	printf("%d, %d, %d, %d, %d의 합 : %d\n",arr2[0],arr2[1],arr2[2],arr2[3],arr2[4],ret);

	return 0;
}

int ArrSub(int * parr, int arrLen)
{
	int result=0;
	int i;
	
	for(i=0; i < arrLen; i++)
		result += parr[i];

	return result;
}
