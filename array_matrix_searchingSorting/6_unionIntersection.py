uni ={}
sett = ()
def union(a,b,n,m):
    for i in range (n):
        if a[i] not in uni:
            uni[a[i]] = 1
    for i in range (m):
        if b[i] not in uni:
            uni[b[i]] = 1
        
    print(len(uni))
    
a=[]
b=[]
n = int(input("Enter size of first array"))
m = int(input("Enter size of second array"))
print("Enter first array")
for  i in range(n):
    a.append(int(input()))
print("Enter second array")
for  i in range(m):
    b.append(int(input()))

union(a,b,n,m)