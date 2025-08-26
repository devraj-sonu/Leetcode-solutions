from typing import List

# from typing import List is only use for here VS CODE but for LEETCODE there is no use of it.

class solution:
    def maxArea(self, height: List[int]) ->int:
        maxWater = 0
        lp =0
        rp = len(height) - 1

        while lp<rp:
            width = rp-lp
            currentHight = min(height[lp],height[rp])
            currentWater = width * currentHight
            maxWater = max(currentWater,maxWater)

            if height[lp] < height[rp]:
                lp += 1
            else:
                rp -= 1

        return maxWater