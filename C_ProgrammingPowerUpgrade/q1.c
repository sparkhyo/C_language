#include <stdio.h>

int main()
{
	char c;
	int i;
	float f;
	char * s;

	printf("[문자,정수,실수,문자열]의 포맷으로 입력:");
	scanf("%c,%d,%6f,%s",&c,&i,&f,s);
	printf("입력된 데이터 출력: %c,%d,%6f,%s\n",c,i,f,s);

	return 0;
}
