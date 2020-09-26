class Solution {
public:
    
    static bool comp(string &s1, string &s2){
        return (s1 + s2) >= (s2 + s1);
    }
    
    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        int x = 0;
        for(int i = 0; i < len; i++)
            if(nums[i] == 0)
                x++;
        if(x == len) return "0";
        
        vector<string> s(len, "");
        
        for(int i = 0; i < len; i++)
            s[i] = to_string(nums[i]);
        
        sort(s.begin(), s.end(), comp);
        
        string ans = "";
        for(int i = 0; i < len; i++)
            ans += s[i];
        
        return ans;
    }
};