#include <stdio.h>
#include <stdlib.h>
    long long int x[1030000]; 
    long long int y[1030000],eq, xs[1003000], ys[1003000], temp ,temp2/*,xe[1000300]={0},ye[1000030]={0}*/ ;
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
// long long int mul2(long long int n, long long int m, long long int mod){
    
//     long long int temp = m % mod;
//     long long int ans2 =0;
//             while(temp){
//                 if(temp&1)
//                     ans2 = (ans2 + n)%mod;
//                 n = (n*2)%mod;
//                 temp /=2;
//             }
//             return ans2;
// }
    long long int C[1002000]; 
long long int ncr(long long int n ,long long int r,long long int mod){
  
    C[0] = 1;  
  
    for (long long int i = 1; i <= n; i++) 
         for (int j =i>r?r:i ; j > 0; j--) 
             C[j] = (C[j] + C[j-1])%mod; 
    
    return C[r];
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
    for (int i = 2; i < n; ++i)
    {
        if(x[i]==x[i-1]&&y[i]==y[i-1]){
            eq++;
        }else if(x[i]== x[i-1]){
            if(i!= n-1 && x[i]==x[i+1] && y[i]!= y[i+1])
                xs[temp]++;
        }else{
            if(xs[temp]){
                temp++;
            }
        }
    }
    mergeSort2(x,y,0,n-1);
   // printArray(x,y,n);
    for (int i = 1; i < n; ++i)
    {
        if(x[i]==x[i-1]&&y[i]==y[i-1]){
             continue;
        }else if(y[i]== y[i-1]&&i!= n-1&&y[i]==y[i+1]&&x[i]!= x[i+1]){
              ys[temp2]++;
        }else{
            if(ys[temp2]){
                temp2++;
            }
        }
    }
    for(i= 0;i< temp;i++){
        sum = (sum + ncr(xs[i] + 2,3,mod))%mod;
    }
    for (int i = 0; i < temp2; ++i)
    {
        sum2 = (sum2+ncr(ys[i] + 2,3,mod))%mod;
    }
    ans = (ncr(n-eq,3,mod)-(sum+sum2)%mod)%mod;
    printf("%Ld\n",ans);
//printf("ys=%lld xs=%lld eq=%lld\n",ys[0], xs[0],eq);
    return 0; 
}