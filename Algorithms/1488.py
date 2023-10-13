class Solution:
    # 可能失败的场景：提前把湖抽成-1，下两次雨 【0，1，】
    def avoidFlood(self, rains):
        fullLake=set()
        chance=0
        operationHis=[]
        for rain in rains:
            if rain != 0:
                if rain not in fullLake:
                    fullLake.add(rain)
                elif chance==0:
                    return []
                else:
                    chance-=1
                    operationHis.append(rain)
            else:
                chance+=1
        result=[]
        toBeOperatePos=0
        for rain in rains:
            if rain==0:
                if toBeOperatePos<len(operationHis):
                    result.append(operationHis[toBeOperatePos])
                    toBeOperatePos+=1
                else:
                    result.append(1)
            else:
                result.append(-1)
        return result

solution=Solution()
print(solution.avoidFlood([1,2,0,0,2,1]))