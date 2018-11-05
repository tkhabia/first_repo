#include <stdio.h>
int mine(int a,int b,int c,int d){
	return a>b?b:a
}
int check(int sx,int sy,int n,int m){
	if (sx<0 || sy < 0)
	{
		return 0;
	}else if(sx > n-1 ||sy > m- 1||visit[sx][sy])
		return 0;
	else return 1;
}
int len(int sx, int sy,int fx,int fy,int n,int m,int count){
	if(sx == fx && sy == fy){
		return count;
	}
	int *lent,min = 9999999;
	lent= (int *)calloc(10,sizeof(int));
	
	if (check(sx+1,sy,n,m))
	{
		visit[sx][sy]= 2;
		lent[0]=len(sx+1,sy,fx,fy,n,m,count+1);
		visit[sx][sy]= 0;
	}
	if (check(sx-1,sy,n,m))
	{
		visit[sx][sy]= 2;
		lent[1]=len(sx-1,sy,fx,fy,n,m,count+1);
		visit[sx][sy]= 0;
	}
	if (check(sx,sy-1,n,m))
	{
		visit[sx][sy]= 2;
		lent[2]=len(sx,sy-1,fx,fy,n,m,count+1);
		visit[sx][sy]= 0;
	}
	if (check(sx,sy-1,n,m))
	{
		visit[sx][sy]= 2;
		lent[3]=len(sx,sy-1,fx,fy,n,m,count+1);
		visit[sx][sy]= 0;
	}
	if(lent[0]<99999||lent[1]<99999||lent[2]<99999||lent[3]<99999)
		return mine(lent[3],mine(mine(lent[0],lent[1]),lent[2]));
	else 
		return 99999;
	free(lent);
}
int ar[120][120], visit[120][120];

int main(){
	int t;
	scanf("%d", &n);
	while(t--){
		int n,m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				ar[i][j] = 0;
				visit[i][j]= 0;
			}
		}
		scanf("%d %d", &n,&m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d",&ar[i][j]);
			}
		}
		int sx, fx,sy, fy;
		scanf("%d %d %d %d", &sx,&sy,&fx,&fy);
		printf("%d",len(sx,sy,fx,fy,n,m,0));
	}
}