import sys
def findLongest(s):
    start = s.find("0")
    res = -1
    i=0
    while i < len(s):
        current = 0
        idx = (start + i)%len(s)
        while s[idx] == "1":
           # print("At: " + str(idx))
            current = current + 1
            i = i+1
            idx = (start + i)%len(s)
        res = max(res, current)
        i = i+1
    return res
t = int(input())
for i in range(0, t):
    s = input()
    leng = len(s)
    longest = None
    if s.find("0") == -1:
        longest = leng
        print(longest*longest)
        continue
    else:
        longest = findLongest(s)

    #print(longest)
    if longest % 2 == 0:
        print(str(int((longest/2)*(longest/2+1))))
    else:
        print(str(int(((longest+1)/2)*((longest+1)/2))))