#include<stdio.h>

int main(){
	long long int t,n,j,i,a[100000],sum,co=0;
	scanf("%lld",&t);
	while(t--){
		co=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++){
				sum=a[i]^a[j];
				if(sum>=4&&sum%2==0)
					co++;
			}
		printf("%lld\n",co);
	}
	return 0;
}
