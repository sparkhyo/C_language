#include <stdio.h>
#define	PI	3.14

int main(void)
{
	double radius;
	double wc;

	fputs("반지름 입력 : ", stdout);
	scanf("%lf", &radius);
	
	wc = radius * radius * PI;

	printf("원의 넓이 : %lf \n", wc);

	return 0;
}
