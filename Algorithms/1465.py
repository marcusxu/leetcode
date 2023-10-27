class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts, verticalCuts) -> int:
        horizontalList=[]
        horizontalCuts.sort()
        horizontalCuts.append(h)
        horizontalCuts.insert(0,0)
        for i in range(len(horizontalCuts)-1):
            horizontalList.append(horizontalCuts[i+1]-horizontalCuts[i])
        verticalList=[]
        verticalCuts.sort()
        verticalCuts.append(w)
        verticalCuts.insert(0,0)
        for i in range(len(verticalCuts)-1):
            verticalList.append(verticalCuts[i+1]-verticalCuts[i])
        return (max(horizontalList)*max(verticalList))%(10**9+7)


solution=Solution()
print(solution.maxArea(5, 4, [], []))
print(solution.maxArea(5, 4, [1,2,4], [1,3]))
print(solution.maxArea(5, 4, [3,1], [1]))
print(solution.maxArea(5, 4, [3], [3]))