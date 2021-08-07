from math import sqrt
def n_paratha(c):
    d = 4*c + 1
    d =  sqrt(d)
    return int((d - 1)//2)
    
def minimumRequiredTime(paratha, rank):
    low = min(rank)
    high = max(rank)
    low_time = (paratha*(2*low+ (paratha-1)*low))//2
    high_time = (paratha*(2*high+ (paratha-1)*high))//2
    while(low_time< high_time):
        total_parathe = 0
        for i in rank:
            time = (low_time+high_time)//i
            itne_parathe = n_paratha(time)
            print(itne_parathe ," at ", time, "by rank",i)
            total_parathe+= itne_parathe

            if total_parathe >= paratha:
                ans = time
                high_time = time-1
            else:
                low_time = time+1
                
    return ans

rank = list()
paratha = int(input("Enter number of required parathas :"))
cooks = int(input("Enter number of cooks :"))
print("Enter rank of cooks :")
for i in range (cooks):
    rank.append(int(input()))
rank.sort()
min_time= minimumRequiredTime(paratha, rank)
print(min_time)