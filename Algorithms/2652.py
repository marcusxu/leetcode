class Solution:
    def sumOfMultiples1(self, n: int) -> int:
        result = 0
        for i in range(3, n + 1):
            if i % 3 == 0 or i % 5 == 0 or i % 7 == 0:
                result += i
        return result

    def addElm(self, start: int, end: int, note: list):
        i = start
        while i <= end:
            note.append(i)
            i += start

    def sumOfMultiples(self, n: int) -> int:
        note = list()
        self.addElm(3, n, note)
        self.addElm(5, n, note)
        self.addElm(7, n, note)
        return sum(set(note))


solution = Solution()
print(solution.sumOfMultiples(7))
