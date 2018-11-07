#include <stdio.h>
#include <stdlib.h>
    long long int x[1030000]; 
    long long int y[1030000],eqx[1003000],eqy[1003000], xs[1003000], ys[1003000], temp ,temp2,eq;
    long long int L[1030000], R[1030000],L1[1030000], R1[1030000];
void merge(long long int x[], long long int y[], long long int l, long long int m, long long int r) 
{ 
    long long int i, j, k; 
    long long int n1 = m - l + 1; 
    long long int n2 =  r - m; 
    
    for (i = 0; i < n1; i++){ 
        L[i] = x[l + i]; 
        L1[i] = y[l+ i];
    }
    for (j = 0; j < n2; j++){ 
        R[j] = x[m + 1+ j];  
        R1[j] = y[m + 1+ j];
    }
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            x[k] = L[i];
            y[k] = L1[i]; 
            i++; 
        } 
        else
        { 
            x[k] = R[j]; 
            y[k] = R1[j];           
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        x[k] = L[i]; 
        y[k] = L1[i];
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        x[k] = R[j];
        y[k] = R1[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(long long int x[],long long int y[], long long int l, long long int r) 
{ 
    if (l < r) 
    { 
        long long int  m = l+(r-l)/2; 
        mergeSort(x,y, l, m); 
        mergeSort(x,y, m+1, r);   
        merge(x,y, l, m, r); 
    } 
}  
void merge2(long long int x[], long long int y[], long long int l, long long int m, long long int r) 
{ 
    long long int i, j, k; 
    long long int n1 = m - l + 1; 
    long long int n2 =  r - m; 

    
    for (i = 0; i < n1; i++){ 
        L[i] = x[l + i]; 
        L1[i] = y[l+ i];
    }
    for (j = 0; j < n2; j++){ 
        R[j] = x[m + 1+ j];  
        R1[j] = y[m + 1+ j];
    }
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L1[i] <= R1[j]) 
        { 
            x[k] = L[i];
            y[k] = L1[i]; 
            i++; 
        } 
        else
        { 
            x[k] = R[j]; 
            y[k] = R1[j];           
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        x[k] = L[i]; 
        y[k] = L1[i];
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        x[k] = R[j];
        y[k] = R1[j]; 
        j++; 
        k++; 
    }     
} 
  
void mergeSort2(long long int x[],long long int y[], long long int l, long long int r) 
{ 
    if (l < r) 
    { 
        long long int  m = l+(r-l)/2; 
        mergeSort2(x,y, l, m); 
        mergeSort2(x,y, m+1, r);   
        merge2(x,y, l, m, r); 
    } 
} 
long long int mul2(long long int n, long long int m, long long int mod){
    
    long long int temp = m % mod;
    long long int ans2 =0;
            while(temp){
                if(temp&1)
                    ans2 = (ans2 + n)%mod;
                n = (n*2)%mod;
                temp /=2;
            }
            return ans2;
}
long long int ncr(long long int n,long long int mod){
    if(n==3)
        return 1;
    else if(n%3== 0){
        if(n-1%2==0)
            return mul2(n/3,mul2((n-1)/2,n-2,mod), mod);
        else
            return mul2(n/3,mul2((n-1),(n-2)/2,mod), mod);

    }else if(n-1%3){
        if(n%2==0)
            return mul2(n/2,mul2((n-1)/3,n-2,mod), mod);
        else
            return mul2(n,mul2((n-1)/3,(n-2)/2,mod), mod);
    }else {
        if(n%2==0)
            return mul2(n/2,mul2((n-1),(n-2)/3,mod), mod);
        else
            return mul2(n,mul2((n-1)/2,(n-2)/3,mod), mod);
    }
} 

int main() 
{ 
    long long int n, mod, i;
    scanf("%Ld %lld", &n,&mod);
    for (int i = 0; i < n; ++i)
    {
        scanf("%Ld %Ld",&x[i],&y[i]);
    } 
    mergeSort(x,y,0,n-1); 
  // printArray(x,y,n);  
    long long int sum = 0, sum2= 0,ans = 0;
    //temp = 0;
    for (int i = 1; i < n; ++i)
    {
        if(x[i]==x[i-1]&&y[i]==y[i-1]){
        
            eqx[temp]++;
        } 
        if(x[i]== x[i-1]){
        
            //if(i!= n-1 && x[i]==x[i+1] && y[i]!= y[i+1])
        
                xs[temp]++;
        
        }else{
        
            if(xs[temp]){
        
                temp++;
            }
        }
    }
     if(xs[temp]){
                temp++;
            }

    mergeSort2(x,y,0,n-1);
    for (int i = 1; i < n; ++i)
    {
        if(x[i]==x[i-1]&&y[i]==y[i-1]){
             eqy[temp2]++;
        }
        if(y[i]== y[i-1] /*&& i!= n-1&&y[i]==y[i+1]&&x[i]!= x[i+1]*/){
              ys[temp2]++;
        }else{
            if(ys[temp2]){
                temp2++;
            }
        }
    }
    if(ys[temp2]){
                temp2++;
            }
    for(i= 0;i< temp;i++){
        sum = (sum + ncr(xs[i]-eqx[i] + 1,mod))%mod;
        // printf("%lld", ncr(xs[i] + 2,mod));
    }
    for (int i = 0; i < temp2; ++i)
    {
        eq += eqy[i];
        sum2 = (sum2+ncr(ys[i] -eqy[i]+1 ,mod))%mod;
    }
    ans = (ncr(n-eq,mod)-(sum+sum2)%mod)%mod;
    printf("ys=%lld xs=%lld eq=%lld ncr %Ld sum2 %Ld sum %lld \n",ys[0], xs[0],eq,ncr(n-eq,mod),sum2,sum);
    printf("%Ld\n",ans);
    return 0; 
}