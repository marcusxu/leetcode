class Solution:
    def singleNumber(self, nums):
        note=dict()
        for num in nums:
            if num not in note.keys():
                note[num]=0
            else:
                note[num]+=1
                if note[num]==2:
                    note.pop(num)
        print(note.keys())
        return list(note.keys())[0]
solution=Solution()
print(solution.singleNumber([2,1,2,2]))