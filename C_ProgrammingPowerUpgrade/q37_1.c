#include <stdio.h>

int main(void)
{
	int i;
	int num;

	FILE * fp = fopen("numeric.dat","wb");
	if(fp==NULL)
	{
		puts("파일 'numeric.dat'가 열리지 않습니다.");
		return -1;
	}

	for(i=0; i<5; i++)
	{
		printf("파일에 저장할 숫자 %d : ", i+1);
		scanf("%d", &num);
		fwrite(&num, sizeof(int), 1, fp);
	}

	fclose(fp);
	puts("입력이 완료되었습니다.");
	return 0;
}
