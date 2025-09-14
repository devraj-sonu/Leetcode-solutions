class solution:
    def twoSum(self, nums:list[int],target:int) ->list[int]:
        m = {}

        for i,num in enumerate(nums):
            complement = target - num
            if complement in m:
                return [m[complement],i]
            m[num] = i
