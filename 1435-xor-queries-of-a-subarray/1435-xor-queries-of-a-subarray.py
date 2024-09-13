class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        
        xor_arr = []
        xor = 0

        for i in arr:
            xor ^= i
            xor_arr.append(xor)

        ans = []

        for query in queries:
            l = query[0]-1
            r = query[1]

            if l < 0:
                ans.append(xor_arr[r])
            else:
                ans.append(xor_arr[r]^xor_arr[l])

        return ans
