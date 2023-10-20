from math import ceil

class Solution:
    # 超时
    def maxKelements1(self, nums, k: int) -> int:
        score=0
        for i in range(0,k):
            nums.sort()
            score+=nums[-1]
            nums[-1]=ceil(nums[-1]/3)
        return score
    
    def maxKelements(self, nums, k: int) -> int:
        score=0
        for i in range(0,k):
            val=max(nums)
            pos=nums.index(val)
            score+=val
            nums[pos]=ceil(val/3)
        return score


solution=Solution()
print(solution.maxKelements([10,10,10,10,10],5))