#include <stdio.h>
#include<string.h>
#include <stdlib.h>

int main(){
	int n,x[120]={0}, y[120]= {0}, X,Y, count = 0,q , min= 9999999,pos1= 9999999,pos2= 9999999;
	scanf("%d",&n);
	scanf("%d", &q);
	char a[7],c[]="FIND";
	scanf("%d", &q);
	while(q--){
		scanf("%s %d %d",a,&X,&Y);
		min= 9999999;
		if(strcmp(a,c)== 0){
			for (int i = 0; i < count; ++i)
			{ 
				// printf("%d\n", min);
				if(abs(x[i] - X) + abs(y[i] -Y) <= min){
					if (min==abs(x[i] - X)+abs(y[i] -Y ))
					{
						if(pos1 >= x[i]){
						pos1= x[i];
						pos2 = y[i];
						}
						// printf("asljfl \n");
					}
					else
					{
						pos1= x[i];
						pos2 = y[i];
						// printf("FJLK\n");
					}
					
					min = abs(x[i] - X)+abs(y[i] -Y);
					
				}else {	continue;}


					printf("1- %d 2- %d min %d %d\n", pos1, pos2,abs(x[i] - X) + abs(y[i] -Y), min);
			}
			if(count != 0){
			printf("%d %d\n",pos1,pos2);
		}
			else 
				printf("-1 -1\n");	
		}else {
			x[count]= X;
			y[count]= Y;
			count++;
			// printf("fljads  %d\n", count);
		}

	}
}
