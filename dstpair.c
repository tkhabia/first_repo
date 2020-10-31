#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	long long int  q,w;
}la;

int cmp (const void *a, const void *b ){
	la *a1= (la*)a;
	la *b1 = (la*)b;
	return a1->q-b1->q;
}

//la a[100230],b[102030];

int  main(){
	int i, n, m;

	scanf(" %d  %d" , &n,&m);
	la *a = malloc(n*sizeof(la));
	la *b = malloc(m*sizeof(la));
	for(i= 0;i<n;i++){
		a[i].w = i;
		scanf(" %lld",&a[i].q);
	}

	for(i = 0;i< m;i++){
		b[i].w= i;
		scanf(" %lld", &b[i].q);
	}

	qsort(a,n,sizeof(la), cmp);
	qsort(b,m,sizeof(la), cmp );

	i = 0;int j = 0 ;
	
	while(j < m){
		printf(" %lld  %lld\n",a[i].w,b[j].w);
		j++;
	}
	i++;
	j--;
	while(i < n){
		printf(" %lld  %lld\n",a[i].w , b[j].w);
		i++;
	}
}
