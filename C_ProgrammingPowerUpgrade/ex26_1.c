#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXT_SIZE	5
int ExtendMemForString(char ** pStr, int strLen);

int main(void)
{
	int strLen=5;
	char * str = (char*)malloc(sizeof(char)*strLen);

	strcpy(str, "Best");
	puts(str);

	strLen=ExtendMemForString(&str, strLen);
	printf("확장된 문자열 길이 : %d \n", strLen);
	strcat(str, " guy!");
	puts(str);

	return 0;
}

/* 함	수 : int ExtendMemForString(char ** pStr, int strLen)
 * 기	능 : 문자열 저장을 위해 메모리 공간을 확장
 *
 * 반	환
 *	return : 확장된 길이, 오류 발생시 -1
 *	첫 번째 매개변수 : 새로 할당된 메모리 공간의 주소
 *
 * 특이사항
 *		반드시 반환되는 포인터를 대상으로 free 함수를 호출해야 함
 */
int ExtendMemForString(char ** pStr, int strLen)
{
	int i;
	char * newStrPtr;

	newStrPtr=(char*)malloc(sizeof(char)*(strLen+EXT_SIZE));
	if(newStrPtr==NULL)
		return -1;

	for(i=0; i<strLen; i++)
		newStrPtr[i] = (*pStr)[i];

	free(*pStr);
	*pStr=newStrPtr;
	return strLen+EXT_SIZE;
}
