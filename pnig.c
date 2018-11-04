#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long int pri[12000], nu[12000], sp[12000];
void prime(){
	long long int count = 0;
	for (long long int i = 2; i < 10200; ++i)
	{
		for(long long int j = i;j< 10200;j+=i){
			nu[j]++;
		
			if(nu[j] == 1)
				sp[j]= i;
		}
	}
	for (long long int i = 0; i < 10200; ++i)
		if(nu[i]== 1)
			pri[count++]= i;
}
void fact(long long int b[], long long int n,long long int a[]){
	for (int i = 0; i < n; ++i)
	{
		long long int temp = b[i];

		if(temp == 1)
			continue;
		while(temp % sp[temp]== 0){
			a[sp[temp]]++;
			temp/= sp[temp];
			if(temp == 1)
				break;
		}
	}

}
int main(void)
{
	prime();

	long long int t;
	scanf("%lld", &t);
	while(t--){
		long long int n, a[12000]= {0}, count = 0, j= 0, b[14000]={0};
		scanf("%lld", &n);
		for (long long int i = 0; i < n; ++i)
		{
			scanf("%lld", &b[i]);
		}
		// // qsort(b,n,sizeof(long long int),cmpfunc);
		// j = 0;
		// long long int i = 0;
		// while(pri[j]){
		// 	if(b[i] == 1 || sqrt(b[i]) < pri[j]){
		// 		i++;
		// 		j=0;
		// 	if(i== n){
		// 		break;
		// 	}
		// 		continue;					
		// 	}
		// if(b[i]%pri[j] == 0){
		// 		a[pri[j]]++;
		// 		// printf("%lld\n",pri[j]);
		// 	}
		// 	if(pri[j] >= 10000)
		// 		break;
		// 	j++;
		// }
		// // sev(a,b,n);
		fact(b,n,a);
		for (long long int i = 1; i < 10000; ++i)
		{
			if(a[i]){
				count++;
				// printf("a[%lld]%lld count %lld\n",i,a[i], count );
			}else continue;
		}
		printf("%lld\n", count);
	}
	return 0;
}
