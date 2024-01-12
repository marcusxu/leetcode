def findSingStr(words:list) -> set:
    result,note=set(),set()
    for word in words:
        if word not in note:
            if word not in result:
                result.add(word)
            else:
                result.remove(word)
                note.add(word)
    return result

class Solution:
    def countWords(self, words1, words2) -> int:
        return len(findSingStr(words1)&findSingStr(words2))

sol=Solution()
print(sol.countWords(["leetcode","is","amazing","as","is"],["amazing","leetcode","is"]))
print(sol.countWords(["b","bb","bbb"],["a","aa","aaa"]))
print(sol.countWords(["a","ab"],["a","a","a","ab"]))