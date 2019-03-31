#include <stdio.h>
#include <string.h>
#define	STR_SIZE	20

int main(void)
{	
	char arr1[STR_SIZE];	
	char arr2[STR_SIZE];	
	char arr3[STR_SIZE];	
	char arr4[STR_SIZE];	
	char arr5[STR_SIZE*4]={0,};
	char tmp[STR_SIZE];
	char * parr[4] = {arr1,arr2,arr3,arr4};
	int i,j;
	
	for(i=0; i<4; i++)
	{
		printf("문자열 입력 %d : ", i+1);
		//scanf("%s", parr[i]);
		fgets(parr[i],STR_SIZE,stdin);
	}

	/* 정렬 */
	for(i=4; i>1; i--)
	{
		for(j=0; j<i-1; j++)
		{
			if(*parr[j]>*parr[j+1])
			{
				strcpy(tmp, parr[j]);
				strcpy(parr[j],parr[j+1]);
				strcpy(parr[j+1],tmp);
			}
		}
	}
	for(i=0; i<4; i++)
	{
		printf("%c",*parr[i]);
	}
	puts("");

	for(i=0; i<4; i++)
	{
		strcat(arr5,parr[i]);
		//strcat(arr5," ");
		arr5[strlen(arr5)]=' ';
	}
	/*------*/
	/*
	fputs("정렬된 문자열 : ", stdout);
	for(i=0; i<4; i++)
	{
		printf("%s ",parr[i]);
	}
	puts("");
	*/
	printf("정렬된 문자열 : %s\n",arr5);

	return 0;
}
