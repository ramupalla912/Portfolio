for i in range(int(input())):
    n,m=map(int,input().split())
    # print(int(str(n)[::-1])>m)
    if(n<m):
        
        if(int(str(n)[::-1])>m or int(str(m)[::-1])<n or int(str(n)[::-1])>int(str(m)[::-1])):
            print("YES")
        else:
            print("NO")
        