n = int(input("Enter number"))
a = list()
for i in range(n):
    print("Enter the intervals")
    b = list()
    b.append(int(input()))
    b.append(int(input()))
    a.append(b)

a.sort(key= lambda x: x[0])
for i in range(len(a)-2):
    if a[i][1] <= a[i+1] [1]:
        b = list()
        b.append(a[i][0])
        b.append(max(a[i][1],a[i+1][1]))
        a[i] = b
        a.pop(i+1)
print(a)
