class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) { 
            if (nums[j] == 0) { 
                k--; 
            }
            if (k < 0) { // If the number of 0s that can be flipped becomes negative
                if (nums[i] == 0) { 
                    k++; // Increment the number of 0s that can still be flipped
                }
                i++;
            }
            j++;
        }
        return j - i; // Return the length of the longest subarray
    }
};