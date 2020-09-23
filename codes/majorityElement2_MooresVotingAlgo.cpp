// Moore's voting algo for finding elements with more than n/3 occurances

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int count1 = 0;
        int element1,element2;
        int count2=0;
        for(int i =0;i<nums.size();i++)
        {
           if(element1==nums[i]){
               count1=count1+1;
           }
            else if(element2==nums[i]){
                count2=count2+1;
            }
            else if(count1==0){
                element1=nums[i];
                count1=count1+1;
            }
            else if(count2==0){
                element2=nums[i];
                count2=count2+1;
            }
            else{
                count1--;
                count2--;
            }
            
        }
        int val1=0;
        int val2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==element1){
                val1++;
            }
            else if(nums[i]==element2){
                val2++;
            }
        }
       int n=nums.size()/3;
        vector<int>v;
        if(val1>n){
            v.push_back(element1);
        }
        if(val2>n){
            v.push_back(element2);
        }
        return v;
    }
};


// My solution
class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
        if(n == 1)
            return v;
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i = 0; i < n;) {
            int j = i+1;
            // cout << "j " << j << nl;
            while(j < n && v[j] == v[i]) {
                j++;
            }

            // cout << j << " " << i << nl;
            if((j - i) >= n/3 + 1){
                ans.push_back(v[i]);

            }
            i = j;
        }
        return ans;
    }
};