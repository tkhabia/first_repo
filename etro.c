#include <stdio.h>

int gcd(int a,int b)
{
	if(b== 0)
		return a;
	return gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
	int t,a,b,c;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a,&b, &c);
		if(c%gcd(a,b))
			printf("NO\n");
		else  
			printf("YES\n");
	}
	return 0;
}