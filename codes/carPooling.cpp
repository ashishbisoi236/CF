
// Optimal Solution
 bool carPooling(vector<vector<int>>& trips, int capacity) {
    
    
    vector<int> timestamp(1001,0);
    
    for(auto trip : trips)
    {
        timestamp[trip[1]]+=trip[0];
        timestamp[trip[2]]-=trip[0];
    }
    
    int c=0;
    
    for(auto number : timestamp)
    {
        c+=number;
        if(c>capacity)
        {
            return false;
        }
    }
    
    return true;
    
    
}

Naive Approach O(N^2)

Iterate all the trips and fill the count at each time stamp from start to end of that ith trip.
Chceckout the maximum people at any timestamp and just compare with allowed capacity and return.

class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] count = new int[1001];
        for(int[] t : trips) 
            for(int i = t[1]; i < t[2]; i++) 
                count[i] += t[0];
        return Arrays.stream(count).max().getAsInt() <= capacity; // this is java-8 syle for getting max form array
    }
}

Optimal Approach O(N)

As, from the Naive Apporach we filled all rage of time stamp - while if you carefully see what is matter us when ith trip start at that time boarding how many person add on that time and when trip end de-board subtract that many person.

Check in all timestamp if at any point we boarded more than allowed capapcity.

class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] timestamp = new int[1001];
        for(int[] t : trips) {
            timestamp[t[1]] += t[0];
            timestamp[t[2]] -= t[0];
        }
        
        for (int number : timestamp) {
            capacity -= number;
            if(capacity < 0)
                return false;
        }
        
        return true;
    }
}