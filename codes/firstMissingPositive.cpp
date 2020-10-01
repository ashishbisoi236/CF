// My Soln.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 1;
        vector<bool> v(len + 1, false);
        for(int i = 0; i < len; i++) {
            if(nums[i] <= len and nums[i] > 0)
                v[nums[i]] = true;
        }
        for(int i = 1; i <= len; i++)
            if(!v[i])
                return i;
        return len + 1;
    }
};


Solution 1: Java-8 Streams + Set
This solution is straight just add all numbers into set.
keep scanning until find i = 1 in set while(set.contains(i)) i++;

class Solution {
    public int firstMissingPositive(int[] nums) {
		// Set<Integer> set = new HashSet();
		// for(int num : nums) set.add(num);
        Set<Integer> set = Arrays.stream(nums).boxed().collect(Collectors.toSet());
        int i = 1;
        while(set.contains(i)) i++;
        return i;
    }
}
TC - O(n)
SC - O(n)

Detailed Video Explanation https://www.youtube.com/watch?v=4VpBKinOTYA



Solution 2: Using bucket of size n

First pass Just iterate the element and not down only numbers 1 to n at index 0 to n - 1.
Second pass scan the bucket and see whereever find bucket[i] = 0 break and return i + 1;
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        if(n == 0) return 1;
        
		int[] bucket = new int[n];
        for(int num: nums) {
            if(num > 0 && num <= n) {
                bucket[num - 1]++;
			}
        }
		
		int i = 0;
        while(i < n && bucket[i] != 0) {
			i++;
		}
        return i + 1;
    }
}
TC - O(n)
SC - O(n)

Solution 3: Linear Time Constant Space

This solution idea is from this problem - https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/ where all numbers are in the range [1, n] some of them appears twice while some missing.

class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
    
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
			}
        }
		
        for(int i = 0; i < n; i++) {
            int num = Math.abs(nums[i]);
            if(num > n) continue;
            num--;
            if(nums[num] > 0) {
                nums[num] = -1 * nums[num];
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
}
TC - O(n)
SC - O(1)

Solution 4: Linear Time Constant Space 2

class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
    
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        
        for(int i = 0; i < n; ++ i) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
    
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
TC - O(n)
SC - O(1)