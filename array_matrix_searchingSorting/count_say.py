def countSay(n):
    if n==1:
        return "1."
    if n==2:
        return "11."
    if n>2:
        new_str = ""
        stri = countSay(n-1)
        i=1
        count=1
        curr= stri[1]
        while curr != '.':
            prev = stri[i-1]
            curr=stri[i]
            if(curr == prev):
                count+=1
                i+=1
            else:
                new_str+= str(count)+str(prev)
                count=1
                i+=1
    return new_str+'.' 




n = int(input("Enter number"))

print(countSay(n))