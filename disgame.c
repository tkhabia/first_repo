#include <stdio.h>
long long int ncr(long long int n ,long long int r,long long int mod){
	long long int b[503][1004]= {0};
	int i,j;
	b[1][0]= 1;
	b[1][1]= 1;
	if (n== r|| r== 0)
	{
		return 1;
	}
	for (i = 2; i <= n; ++i)
	{
		for(j= 0;j<=i;j++)
		{
			if(j==0|| j == n){
				b[i][j]= 1;
				continue;
			}
			b[i][j]= (b[i-1][j]+ b[i-1][j-1])%mod;
			// printf("%lld %d %d\n",b[i][j],i,j);
			if(j == r && i == n)
			return b[i][j];
				
		}		
		if(j == r && i == n)
			return b[i][j];
	}

			return b[i][j];
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		long long int n,m,mod, ans;
		scanf("%lld %lld %lld", &n,&m,&mod);
		m = (n-m)>m?m:(n-m);
		ans  = ncr(n,m,mod);
		if(n>=m)
		printf("%lld\n", ans);
	else printf("0\n");
	}
	return 0;
}