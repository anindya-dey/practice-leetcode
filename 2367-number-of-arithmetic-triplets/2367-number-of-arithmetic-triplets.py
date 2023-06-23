class Solution(object):
    def arithmeticTriplets(self, nums, diff):
        """
        :type nums: List[int]
        :type diff: int
        :rtype: int
        """
        count = 0
        s = set(nums)
        
        for num in nums:
            if ((num - diff) in s) and ((num + diff) in s):
                count += 1
        
        return count
        