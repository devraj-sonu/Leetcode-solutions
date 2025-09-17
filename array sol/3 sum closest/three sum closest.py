class Solution:
    def threeSumClosest(self, nums, target):
        n = len(nums)
        if n < 3:
            raise ValueError("Need at least 3 numbers")

        nums.sort()
        closest = nums[0] + nums[1] + nums[2]

        for i in range(n - 2):
            left, right = i + 1, n - 1

            while left < right:
                current = nums[i] + nums[left] + nums[right]

                # Update closest if this sum is nearer to target
                if abs(current - target) < abs(closest - target):
                    closest = current

                # Move pointers based on comparison with target
                if current < target:
                    left += 1
                elif current > target:
                    right -= 1
                else:
                    # exact match, can't do better
                    return current

        return closest
