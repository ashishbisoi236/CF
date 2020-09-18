// count no of subarrays 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int count = 0;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum == k)
                count++;
            if(um.find(sum - k) != um.end())
                count += um[sum - k];
            
            um[sum]++;
            
        }
        return count;
    }
};

// position of first subarray
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n, s;
	    cin >> n >> s;
	    int a[n];
	    for(int i = 0; i < n; i++) 
	        cin >> a[i];
	    int sum = 0, pivot = 0, flag = 0;
	    for(int i = 0; i < n; i++) {
	        sum += a[i];
	        while(sum > s) {
	            sum -= a[pivot];
	            pivot++;
	        }
	        if(sum == s) {
	            cout << pivot + 1 << " " << i + 1 << "\n";
	            flag = 1;
	            break;
	        }
	    }
	    if(flag == 0)
	        cout << -1 << "\n";
	}
	return 0;
}