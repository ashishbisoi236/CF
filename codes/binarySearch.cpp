class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0)
            return -1;
        int lo = 0;
        int hi = len-1;
        int mid;
        while(lo <= hi) {
            mid = lo + (hi-lo)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return -1;
    }
};