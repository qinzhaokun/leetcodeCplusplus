class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int *d = new int[n];
        int sum = 0;
        for(int i = 0;i < n;i++) {d[i] = gas[i]-cost[i];sum += d[i];}
        
        if(n == 0|| sum < 0) return -1;
        if(n == 1) return 0;
        int start = 0; int i = 1;
        sum = d[0];
        while(start != i){
            if(sum < 0){
                start = i;
                sum = d[i];
                i++;
            }
            else{
                sum+= d[i];
                i++;
            }
            i %=n;
        }
        return start;
    }
};
