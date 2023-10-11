import functools
class Solution:
    def calcScore(self, report,feedbackDic):
        score=0
        feedbackList=report.split(' ')
        for feedback in feedbackList:
            if feedback in feedbackDic.keys():
                score+=feedbackDic[feedback]
        return score
    def compareScore(self,scoreIdLeft,scoreIdRight):
        # if score is same, small id should in front
        if scoreIdLeft[1]==scoreIdRight[1]:
            if scoreIdLeft[0]<=scoreIdRight[0]:
                return -1
            else:
                return 1
        # if score is not same, higher score is in front
        elif scoreIdLeft[1]<scoreIdRight[1]:
            return 1
        else:
            return -1  
    # def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], 
    # report: List[str], student_id: List[int], k: int) -> List[int]:
    def topStudents(self, positive_feedback, negative_feedback, report, student_id, k):
        feedbackDic={}
        for feedback in positive_feedback:
            feedbackDic[feedback]=3
        for feedback in negative_feedback:
            feedbackDic[feedback]=-1
        scoreIdList=[]
        for i in range(len(report)):
            scoreIdList.append([student_id[i],self.calcScore(report[i],feedbackDic)])
        scoreIdList.sort(key=functools.cmp_to_key(self.compareScore))
        result=[]
        for i in range(k):
            result.append(scoreIdList[i][0])
        return result

solution=Solution()
print(solution.topStudents(["smart","brilliant","studious"],["not"],["this student is studious","the student is smart"],[1,2],2))
print(solution.topStudents(["smart","brilliant","studious"],["not"],["this student is not studious","the student is smart"],[1,2],2))