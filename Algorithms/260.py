from collections import Counter


class Solution:
    # use set
    def singleNumber1(self, nums):
        note = set()
        for num in nums:
            if num not in note:
                note.add(num)
            else:
                note.remove(num)
        return list(note)

    # use built-in counter
    def singleNumber(self, nums):
        note = Counter(nums)
        result = []
        for item in note:
            if note[item] == 1:
                result.append(item)
        return result


solution = Solution()
print(solution.singleNumber([1, 2, 1, 3, 2, 5]))
