class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        seen = {}

        for i,x in enumerate(nums):
            complement = target-x
            if complement in seen:
                return [seen[complement],i]
            
            seen[x] = i
        return []
        