class Solution:
    def findTheArrayConcVal(self, nums) -> int:
        result=0
        posLeft=0
        posRight=len(nums)-1
        if posRight== -1:
            return result
        while posRight-posLeft>=1:
            result+=int(str(nums[posLeft])+str(nums[posRight]))
            posLeft+=1
            posRight-=1
        if posRight==posLeft:
            result+=nums[posLeft]
        return result

solution=Solution()
print(solution.findTheArrayConcVal([1,2,3]))