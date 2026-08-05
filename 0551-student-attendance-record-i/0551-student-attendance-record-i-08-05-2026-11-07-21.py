class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        if s.count('A') < 2 and not ('LLL') in s:
            return True
        return False