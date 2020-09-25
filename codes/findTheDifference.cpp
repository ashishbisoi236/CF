class Solution {
  public:
  char findTheDifference(string s, string t) {

    unordered_map<char,int> mp;
    
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
    }
    
    for(int i=0;i<t.length();i++)
    {
        if(!mp.count(t[i])) return t[i];
        
        if(mp.count(t[i]) and mp[t[i]]==0)
        {
            return t[i];
        }
        
        mp[t[i]]--;
        
    }
    
    return ' ';

}


class Solution {
    public:
    char findTheDifference(string s, string t) {
    
        sort(s.begin(),s.end());
    
        sort(t.begin(),t.end());
    
    
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=t[i])
            {
                return t[i];
            }
        }
    
        return t[t.length()-1];
    }
}



class Solution {
   public:
   char findTheDifference(string s, string t) {
    
    char x = 0;
    
    for(auto ch : s)
    {
        x^=ch;
    }
    
    for(auto ch: t)
    {
        x^=ch;
    }
    
    return x;
    
}

Given two strings (all lowercase letters only) and we have to find out an extra character in second string.

Idea is ascii sum of second string - ascii sum in first string will leave us with ascii of the extra letter.

And the sum will always give correct and positive answer even though letters are jumbles in the second string.

Eg:
s = "abc"
t = "bcac"

Now sum = (b-a) + (c-b) + (a-c) + c

sum = 1 + 1 + (-2) + 99 = 99 [which is ascii for 'c']
// Here's the code:

public char findTheDifference(String s, String t) {
    int i = -1,sum=0;
    while((++i)<s.length()) {
        sum += t.charAt(i)-s.charAt(i);
    }
    sum += t.charAt(i);
    return (char)sum;
}