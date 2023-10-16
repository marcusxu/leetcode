class Solution:
    def singleNumber(self, nums):
        note=set()
        for num in nums:
            if num not in note:
                note.add(num)
            else:
                note.remove(num)
        return list(note)


solution=Solution()
print(solution.singleNumber([1,2,1,3,2,5]))