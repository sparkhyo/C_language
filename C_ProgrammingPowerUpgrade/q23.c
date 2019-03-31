#include <stdio.h>
#define	STR_MAX	100

int strLen(char * str);
int strCpy(char * dest, char * source);
int strCat(char * dest, char * source);
int strCmp(char * str1, char * str2);

int main(void)
{
	char str1[STR_MAX]="Good morning?";
	char str2[STR_MAX]="HaHaHa!";
	char buffString[STR_MAX];
	
	/** strLen test **/
	printf("length of \"%s\" : %d \n", str1, strLen(str1));
	printf("length of \"%s\" : %d \n", str2, strLen(str2));

	/** strCpy test **/
	strCpy(buffString, str1);
	printf("copy string : \"%s\" \n", buffString);

	/** strCat test **/
	strCat(buffString, str2);
	printf("concat string : \"%s\" \n", buffString);
	
	/** strCmp test **/
	printf("cmp str1, str1 : %d \n", strCmp(str1, str1));
	printf("cmp str2, str2 : %d \n", strCmp(str2, str2));
	printf("cmp str1, str2 : %d \n", strCmp(str1, str2));
	printf("cmp str2, str1 : %d \n", strCmp(str2, str1));
	return 0;
}

int strLen(char * str)
{
	int len=0;

	while((*str)!='\0')
	{
		len++;
		str++;
	}

	return len;
}
int strCpy(char * dest, char * source)
{
	int len = strLen(source)+1; //널(NULL)문자까지 복사
	int i;

	for(i=0; i< len; i++)
	{
		dest[i]=source[i];
	}
	return len;
}
int strCat(char * dest, char * source)
{
	int destLen=strLen(dest);
	int srcLen=strLen(source)+1;
	int i;

	for(i=0; i<srcLen; i++)
		dest[destLen+i]=source[i];

	return destLen+srcLen;
}
int strCmp(char * str1, char * str2)
{
	while((*str1) != 0 || (*str2) != 0)
	{
		if(*str1 > *str2)
			return 1;
		else if(*str1 < *str2)
			return -1;
		else
		{
			str1++;
			str2++;
			continue;
		}
	}

	return 0;
}
