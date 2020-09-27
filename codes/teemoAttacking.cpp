// My solution

class Solution {
public:
    int findPoisonedDuration(vector<int>& time, int duration) {
        int len = time.size();
        if(len == 0)
            return 0;
        int ans = 0;
        int lastActive = -1;
        for(int i = 0; i < len; i++) {
            if(time[i] > lastActive) {
                ans += duration;
                
            }
            else
                ans += time[i] + duration - 1 - lastActive;
                
            lastActive = time[i] + duration - 1;
        }
        return ans;
    }
};

// Idea
// If teemo attack at time - t1, that will poison till the duration, or teemo can attack again before t1 + duration over at time t2.
// Which means contribution of first attack is either duration or t2 - t1 whichever minimum.
// From time t2 this attack will take care in same way.

// And, for the last teemp attack that will keep max duration as no more attack after that.

// Iterate timeSeries and add min(duration, timeSeries[i + 1] - timeSeries[i]) in totalTime
// And for the last time add the duration.

// Java

class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        if(timeSeries.length == 0) return 0;
        int totalTime = 0;
        for(int i = 0; i < timeSeries.length - 1; i++)
            totalTime += Math.min(duration, timeSeries[i + 1] - timeSeries[i]);
        return totalTime + duration;
    }
}

// Python

// class Solution:
//     def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
//         if len(timeSeries) == 0: return 0
//         totalTime = 0
//         for i in range(0, len(timeSeries) - 1):
//             totalTime += min(duration, timeSeries[i + 1] - timeSeries[i])
//         return totalTime + duration
// C++

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0) return 0;
        int totalTime = 0;
        for(int i = 0; i < timeSeries.size() - 1; i++)
            totalTime += min(duration, timeSeries[i + 1] - timeSeries[i]);
        return totalTime + duration;
    }
};