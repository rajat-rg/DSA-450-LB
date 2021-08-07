n = int(input("Enter number: "))
def knapsack(wp,k):
    for i in range(len(wp)):
        wp[i][1] = wp[i][1]/wp[i][0]

    wp.sort(key = lambda x: x[1],reverse=True)
    print(wp)
    pro,i = 0,0
    while k>0 and i<=len(wp)-1:
        if k > wp[i][0]:
            pro+= wp[i][0]*wp[i][1]
            k-= wp[i][0]
        else:
            pro += k*wp[i][1]

        i+=1

    print(pro)








wp = list()
for i in range(n):
    a = list()
    a.append(int(input("Enter weight: ")))
    a.append(int(input("Enter profit: ")))
    wp.append(a)
k = int(input("Enter size of knapsack: "))
mx = knapsack(wp,k)