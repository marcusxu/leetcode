# 贪心：解答错误 1688 / 2028
def minExtraChar1(self, s: str, dictionary):
    while(True):
        # for each elem in dic, find the elem which make the left of s min, then remove it from s
        lengthLeft=len(s)
        elemToBeRemoved=''
        for elem in dictionary:
            if len(s.replace(elem,''))<lengthLeft:
                elemToBeRemoved=elem
                lengthLeft=len(s.replace(elem,''))
        # if no elem in s, exit, return rest length
        if(s.replace(elemToBeRemoved,'')==s):
            return len(s)
        else:
            s=s.replace(elemToBeRemoved,'')

# 动态规划，通过
# f(s)=f(s-1)<min(%s)?f(s-1):min(%s)
# min(%s)= foreach m(s[-1:])+f(s-1) m(s[-2:])+f(s-2)
def atomJudge(sJudge:str, dictionary,note):
    result=note[len(sJudge)-1]+1
    for leftStrStartPos in range(-1, -len(sJudge)-1,-1):
        leftStr=sJudge[leftStrStartPos:]
        if leftStr in dictionary:
            result=min(result,note[len(sJudge)+leftStrStartPos])
    return result
        
def minExtraChar(s: str, dictionary):
    note=[0,]
    for i in range(1,len(s)+1):
        newLen=atomJudge(s[:i],dictionary,note)
        if (note[i-1]+1)<newLen:
            note.append(note[i-1]+1)
        else:
            note.append(newLen)
    return note[-1]

print(minExtraChar("leetscode",["leet","code","leetcode"]))