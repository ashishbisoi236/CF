int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int currMin = nums[0];
        int currMax = nums[0];
        int maxProduct = nums[0];
        
        for(int i = 1; i < len; i++) {
            if(nums[i] < 0)
                swap(currMin, currMax);
            
            currMin = min(currMin * nums[i], nums[i]);
            currMax = max(currMax * nums[i], nums[i]);
            
            maxProduct = max(currMax, maxProduct);
        }
        
        return maxProduct;
        
    }