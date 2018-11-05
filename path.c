#include <stdio.h>
#include <stdlib.h>
int ar[120][120], visit[120][120], ar2[120][120];

int mine(int a,int b){
	return a>b?b:a;
}
int check(int sx,int sy,int n,int m){
	if (sx<0 || sy < 0)
	{
		return 0;
	}else if(sx > n-1 || sy > m- 1 || visit[sx][sy] || !ar[sx][sy] )
		return 0;
	else return 1;
}
int len(int sx, int sy,int fx,int fy,int n,int m,int count){
	if(sx == fx && sy == fy){
		return count;
	}
	int lent[5]={0};
	if (check(sx+1,sy,n,m))
	{
		visit[sx][sy]= 2;
		// printf("down %d %d \n",sx ,sy);
		if(ar2[sx+1][sy]== 0)
			ar2[sx+1][sy] = len(sx+1,sy,fx,fy,n,m,count+1);
		lent[0] = ar2[sx+1][sy];
		visit[sx][sy]= 0;
	}else
		lent[0]= 99999;
	if (check(sx-1,sy,n,m))
	{
		visit[sx][sy]= 2;
		// printf("up %d %d \n",sx-1 ,sy);
		if(ar2[sx-1][sy]== 0)
			ar2[sx-1][sy] = len(sx-1,sy,fx,fy,n,m,count+1);
		lent[1]=ar2[sx -1][sy];
		visit[sx][sy]= 0;
	}else
		lent[1]= 99999;
	if (check(sx,sy-1,n,m))
	{
		visit[sx][sy]= 2;
		// printf("left %d %d \n",sx ,sy-1);
		if(ar2[sx][sy-1]== 0)
			ar2[sx][sy-1] = len(sx,sy-1,fx,fy,n,m,count+1);
		lent[2]=	ar2[sx][sy-1];
		visit[sx][sy]= 0;
	}else
		lent[2]= 99999;
	if (check(sx,sy+1,n,m))
	{
		visit[sx][sy]= 2;
		// printf("right %d %d \n",sx ,sy+1);
		if(ar2[sx][sy+1]== 0)
			ar2[sx][sy+1] = len(sx,sy+1,fx,fy,n,m,count+1);
		lent[3] = ar2[sx][sy+1];
		visit[sx][sy]= 0;
	}else
		lent[3]= 99999;

	if(lent[0]<99999||lent[1]<99999||lent[2]<99999||lent[3]<99999)
		return mine(lent[3],mine(mine(lent[0],lent[1]),lent[2]));
	else 
		return 99999;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n,m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				ar[i][j] = 0;
				visit[i][j]= 0;
				ar2[i][j]= 0;
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
		int sx, fx,sy, fy,min;
		scanf("%d %d %d %d", &sx,&sy,&fx,&fy);
		if(len(sx,sy,fx,fy,n,m,0) > 9999)
			min = -1;
		else
			min= len(sx,sy,fx,fy,n,m,0);

		if(!(ar[fx][fy]))
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",min);
	}
}