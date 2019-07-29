
plistSize = 0;
cur = 0;
plistPos = 0;


def genPlist(stop):
    cur = 3
    plistPos = 0
    plist = []
    plist.append(2)
    plistPos = plistPos + 1
    while(cur <= stop):
        p = True
        for pNum in plist:
            if(cur % pNum == 0):
                if(cur == stop):
                    print(str(cur)+" % "+str(pNum)+" = 0")
                p = False
                break
        if(p):
            plist.append(cur)
        cur = cur + 1

    return plist


def isP(n):
    lis = genPlist(n)
    if(not (lis[plistPos-1] == n)):
        return False
    else:
        return True




if __name__ == '__main__':
    print('=== IsItPrime? (IIP) v1.0 python ===')
    print('Input 1 to exit.')
    print()
    s = int(input('>>'))
    while(not (s==1)):
        res = isP(s)
        if(res):
            print('\t-> Prime')
        else:
            print('\t-> Not Prime')
        s = int(input('>>'))
    exit()
    
