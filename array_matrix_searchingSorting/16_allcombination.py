dp = {}
def getMEthod(a,k):
    
    if k == 0 :
        return [[]]
    result = []
    if k in dp:
        return dp[k] 

    for num in a:
        rem = k-num
        if rem >=0:
            combi = getMEthod(a,rem)
            if combi is not None:
                combi.append(num)
                # print(combi)
                dp[k]= combi
                return dp[k]
    dp[k] = None
    return dp[k]


n = int(input("Enter number"))
a = list()

for i in range (n):
    a.append(int(input()))
v = getMEthod(a,6)
print(v)