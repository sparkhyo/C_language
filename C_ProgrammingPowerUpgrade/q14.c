#include <stdio.h>

int main(void)
{
	int arr[5] = {0,};
	int i,j;
	int tmp;
	for(i=0; i<5; i++)
	{
		printf("숫자 %d 입력 : ", i+1);
		scanf("%d",&arr[i]);
	}

	for(j=sizeof(arr)/sizeof(int); j>0; j--)
	{
		for(i=0; i<j; i++)
		{
			if(arr[i]>arr[i+1])
			{
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
			}
		}
	}

	fputs("정렬된 출력 : ", stdout);
	for(i=0; i<5; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("");

	return 0;
}
