class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size(), i, j;
        vector<int> L_product(n), R_product(n), res(n);
        L_product[0] = 1;
        R_product[n-1] = 1;
        for(i=1; i<n; i++)
        {
            j = (n - 1) - i;
            L_product[i] = L_product[i-1] * nums[i-1];
            R_product[j] = R_product[j+1] * nums[j+1];
        }
        for(i=0; i<n; i++)
            res[i] = L_product[i] * R_product[i];
        return res;
    }
};