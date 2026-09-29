import java.util.Arrays;
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int freq = 1;
        for(int i=1; i<n; i++) {
            if(nums[i] == nums[i-1]) {
                freq++;
            }else {
                freq = 1; 
            }

            if(freq > n/2) {
                return nums[i];
            }
        }
        return nums[0];
    }
}