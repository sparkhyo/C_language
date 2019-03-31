#include <stdio.h>
#include <string.h>
#define ROW_LEN	5
#define COL_LEN	20

int main(void)
{
	int idx,i,j;
	char str[ROW_LEN][COL_LEN];
	char tmp[COL_LEN];

	for(idx=0; idx<ROW_LEN; idx++)
	{
		printf("문자열 입력 %d : ", idx+1);
		fgets(str[idx],sizeof(str)/ROW_LEN,stdin);
		//gets(str[idx]);
	}

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

	for(i=0; i<ROW_LEN; i++)
	{
		printf("%s",str[i]);
		//puts(str[i]);
	}

}
