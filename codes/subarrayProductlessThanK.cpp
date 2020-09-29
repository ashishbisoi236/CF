// My solution (not inc. naive approach(leads to TLE))

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0;
        int p = 1 ;
        int len = nums.size();
        int left = 0, right = 0;
        while(right < len) {
            p *= nums[right];
            while(p >= k) {
                p /= nums[left++];
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};


// Generate all subarrays and check if product of subarray is less than k.

// Example: [10, 5, 2, 6], k = 100

// [10], [5], [2], [6] -> length = 1 subarrays. ==> 4 all satisfy prod < k
// [10, 5], [5, 2], [2, 6] -> length = 2 subarrays. ==> 3 all satisfy prod < k
// [10, 5, 2], [5, 2, 6] ->length = 3 subarrays ==> only 1 satisfy prod < k
// [10, 5, 2, 6] -> length = 4 subarrays ==> no satisfy prod < k

// 4 + 3 + 1 = 8
// Detailed Video Explanation https://www.youtube.com/watch?v=bZQI58quN6E



class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int count = 0, n = nums.length;
        for (int left = 0; left < n; left++) {
            int prod = 1;
            for (int right = left; right < n; right++) {
                prod *= nums[right];
                if (prod < k) count++;
                else break;
            }
        }
        return count;
    }
}
TC - O(n^2)
SC - O(1)

Sliding Window / Two Pointer

// Lets take a window from left to right whose product prod is less than k.
// Now if we add next element x - there will be 2 cases arises.

// Case 1: prod * x < k => now we can have right - left + 1 more subarrays whose product is also less than k.
// Case 2: prod * x >= k => in this case we will update our window left pointer until prod >= k

class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;
        int count = 0, left = 0, right = 0, prod = 1;
        while (right < nums.length) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++];
            count += 1 + (right - left);
            right++;
        }
        return count;
    }
}
TC - O(n)
SC - O(1)