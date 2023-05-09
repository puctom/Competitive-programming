t = int(input())
for i in range(0, t):
    s = input()
    res = 0
    leng = len(s)
    for j in range(1, leng):
        if s[j] == s[j-1] and s[j] == '_':
            #print("Two consecutive at index" + str(j) +"\n")
            res = res+1

    if s[0] == '_':
        res = res+1
    if(s[leng-1] == '_' or leng == 1):
        res = res+1
    print(res)

