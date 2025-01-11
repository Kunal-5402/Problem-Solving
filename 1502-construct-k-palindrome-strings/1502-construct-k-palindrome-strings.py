class Solution:
    def canConstruct(self, s: str, k: int) -> bool:

        if len(s) < k:
            return False

        freq = {}
        for ch in s:
            if ch in freq:
                freq[ch] += 1
            else:
                freq[ch] = 1

        odd_count = 0

        for key, val in freq.items():
            if val % 2 != 0:
                odd_count += 1
        
        if odd_count > k:
            return False
            
        return True