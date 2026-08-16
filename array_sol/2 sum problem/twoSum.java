import java.util.HashMap;
import java.util.Arrays;

public class twoSum {
    public static int[] twosum(int[] nums, int target) {
        HashMap<Integer,Integer>map = new HashMap<>();

        for(int i=0; i<nums.length; i++) {
            int needMore = target - nums[i];
            if(map.containsKey(needMore)) {
                return new int[]{map.get(needMore),i};
            }
            map.put(nums[i],i);
        }
        return new int[]{};
    }


    public static void main(String[]args) {
        int nums[] = {2,7,11,15};
        int target = 9;
        int[] result = twosum(nums, target);
        System.out.println(Arrays.toString(result));
    }

}
