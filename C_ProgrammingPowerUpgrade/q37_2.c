#include <stdio.h>

int main(void)
{
	int i,num;
	FILE * fp = fopen("numeric.dat","rb");
	if(fp==NULL)
	{
		puts("파일 'nemeric.dat'가 열리지 않습니다.");
		return -1;
	}

	for(i=0; i<5; i++)
	{
		fread(&num,sizeof(int),1,fp);
		printf("%d 번째 입력 된 숫자 : %d \n", (i+1),num);
	}

	fclose(fp);
	puts("출력이 완료되었습니다.");
	return 0;
}
