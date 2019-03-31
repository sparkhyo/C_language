#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW_LEN	5

void ReadArr();
void BubbleSortArr();
void PrintArr();

int main(void)
{
	
	ReadArr();
	BubbleSortArr();
	PrintArr();
	
	return 0;
}

void ReadArr()
{
	char * str[ROW_LEN];
	char * arr;
	int idx;

	for(idx=0; idx<ROW_LEN; idx++)
    {
		printf("문자열 입력 %d : ", idx+1);
        fgets();
    }
}

void BubbleSortArr()
{
	for(j=ROW_LEN; j>1; j--)
    {
    	for(i=0; i<j-1; i++)
        {
        	if(strlen(str[i]) > strlen(str[i+1]))
            {
            	strcpy(tmp,str[i]);
                strcpy(str[i],str[i+1]);
                strcpy(str[i+1],tmp);
            }
        }
    }
}

void PrintArr()
{
	for(i=0; i<ROW_LEN; i++)
    {
		printf("%s\n",str[i]);
    }
	
}
