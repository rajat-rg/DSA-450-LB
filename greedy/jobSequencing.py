n = int(input("Enter number of jobs"))
j=list()
c,h=0,0
for i in range(n):
    a = list()
    d = int(input("Enter deadline: "))
    p = int(input("Enter profit: "))
    a.append(d)
    a.append(p)
    j.append(a)
j.sort(key = lambda x:x[1],reverse=True)
print(j)
for i in range(n):
    if j[i][0]>h:
        c+=j[i][1]
        h+=1
print(c)
print(h)
# (1,2,100)(2,1,19)(3,2,27)
# (4,1,25)(5,1,15)