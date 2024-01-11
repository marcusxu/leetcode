class Solution:
    def addMinimum(self, word: str) -> int:
        dic=dict()
        dic['aa']=[2,1]
        dic['ab']=[1,2]
        dic['ac']=[1,2]
        dic['ba']=[2,1]
        dic['bb']=[2,1]
        dic['bc']=[1,2]
        dic['ca']=[2,1]
        dic['cb']=[2,1]
        dic['cc']=[2,1]
        subWords=word.split('abc')
        result=0
        for subWord in subWords:
            if len(subWord)==1:
                result+=2
            else:
                pos=0
                while(pos<len(subWord)):
                    if pos==len(subWord)-1:
                        result+=2
                        pos+=1
                    else:
                        result+=dic[subWord[pos]+subWord[pos+1]][0]
                        pos+=dic[subWord[pos]+subWord[pos+1]][1]
        return result

sol=Solution()
print(sol.addMinimum('aa'))
print(sol.addMinimum('aaabca'))
print(sol.addMinimum('abc'))