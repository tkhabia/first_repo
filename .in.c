#include <stdio.h>
int rand(int n){
return (n*13+14)%10000;
}
int main(){
	printf("100\n");
int 	j= 5;
for (int i = 0; i < 100; ++i)
{
	printf("10000\n");

	for (int k = 0; k < 10000; ++k)
	{
		printf("%d ",rand(j));
		j = 	rand(j);
	}

	printf("\n");
}
 return 0;
}
