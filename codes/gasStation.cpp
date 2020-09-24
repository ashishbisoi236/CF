
// O(n) solution
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int n = gas.size();
        for(int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
        }
        
        if(sum < 0)
            return -1;
        
        int start = 0, tank = 0;
        for(int i = 0; i < n; i++) {
            tank += gas[i] - cost[i];
            if(tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }
        
        return start;
    }
};

// O(n2) solution
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        for(int i = 0; i < n; i++) {
            int total = 0, stopCount = 0, j = i;
            while(stopCount < n) { // loop for n stops
                total += gas[j % n] - cost[j % n];
                if(total < 0) // starting from this stop we can't complete trip break
                    break;
                stopCount++;
                j++;
            }
            if(stopCount == n && total >= 0)  // if we are able to cover all the stop and fuel +ve return i'th stop
                return i;
        }
      
        return -1;
    }
}