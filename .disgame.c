#include <stdio.h>

long long int ncr(long long int n,long long int r,long long int mod){
	if(r==0)
		return 1;
	printf("%lld %lld\n",((n-r+1)*ncr(n, r-1,mod)/(r))%mod ,r );
	return ((n-r+1)*ncr(n, r-1,mod)/(r))%mod;
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
		printf("%lld\n", ans);
	}
	return 0;
}