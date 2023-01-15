import numpy

class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        v=[[0]*n for _ in range(n)]
        ans=numpy.array(v);
        for i in queries:
            ans[i[0]:i[2]+1,i[1]:i[3]+1]+=1;
        return ans