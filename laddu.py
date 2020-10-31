for _ in range(int(input())):
    n , k = map(int , input().split())
    ar = list(map(int , input().split()))
    if  k == 1 :
        print(0)
        continue
    ar.sort()
    dif = []
    k -=  1  
    for i in range(1 , n ):
        dif.append(ar[i] -  ar[i-1 ])
    tem = 0 
    for i in range(k):
        tem+= dif[i]
    
    ans = tem
    # print(tem)
    for i in range(k , len(dif)):
        tem += dif[i] - dif[i-k]
        ans = min(tem , ans)
    print(ans)
