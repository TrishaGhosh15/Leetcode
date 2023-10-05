class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> output = new ArrayList<>();
        int first = nums[0],second = nums[0],count1 = 0,count2 = 0;
        for(int i:nums){
            if(i==first) count1++; 
            else if(i==second) count2++;
            else if(count1 == 0) { first = i; count1++; } 
            else if(count2 == 0) { second = i; count2++; }
            else { count1--; count2--; }
        }
        count1 = 0;count2 = 0;
        for(int i:nums) if(i==first) count1++; else if(i==second) count2++;
        if(count1>(nums.length/3)) output.add(first); if(count2>(nums.length/3)) output.add(second);
        return output;
    }
}