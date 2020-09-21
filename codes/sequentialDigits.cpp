class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string dig = "123456789";
        int lDig = 0, hDig = 0;

        int temp = low;
        while(temp) {
            lDig++;
            temp = temp / 10;
        }

        temp = high;
        while(temp) {
            hDig++;
            temp = temp / 10;
        }

        while(lDig <= hDig) {
            int i = 0, j = lDig;
            while(i + j <= 9) {
                temp = stoi(dig.substr(i, j));
                if(temp >= low && temp <= high)
                    ans.push_back(temp);
                i++;
            }
            lDig++;
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/sequential-digits/discuss/854043/C%2B%2B-readable-algorithm-%2B-explanation

// Efficient solution

class Solution {
public:
    void helper(int low,int high,int i,int sum,vector<int> &numbers)
    {
        sum = sum*10 + i;
        if(sum >= low && sum <= high)
            numbers.push_back(sum);
        
        if(sum > high || i==9)
            return;
        
        helper(low,high,i+1,sum,numbers);
        
    }
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> numbers;
        
        for(int i=1;i<=9;i++)
            helper(low,high,i,0,numbers);
        
        sort(numbers.begin(),numbers.end());
        return numbers;
        
    }
};