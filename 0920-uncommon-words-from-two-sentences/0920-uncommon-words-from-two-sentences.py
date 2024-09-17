class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:

        count = {}

        for word in s1.split():
            if word in count.keys():
                count[word] += 1
            else:
                count[word] = 1
        
        for word in s2.split():
            if word in count.keys():
                count[word] += 1
            else:
                count[word] = 1
        ans = []
        for key, val in count.items():
            if val == 1:
                ans.append(key)
        return ans

        return []