class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        result=0
        for i in range (len(nums)):
            if int.bit_count(i)==k:
                result+=nums[i]
        return result