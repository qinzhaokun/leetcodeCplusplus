class Solution {
public:
    string getPermutation(int n, int k) {
        int *save = new int[n];
        int sum = 1;
        bool *V = new bool[n];
        save[0] = 1;
        for(int i = 1;i < n;i++){
            sum *= i;
            save[i] = sum;
            V[i] = true;
        }
        V[0] = true;
        k--;
        int i = n-1;
        string ret = "";
        while(i >= 0){
            int index = k/save[i];
            int num = find(V,n,index);
            V[num] = false;
            num++;
            ret += to_string(num);
            k %= save[i];
            i--;
            
        }
        return ret;
    }
    
    int find(bool* V, int n,int index){
        int count = -1;
        for(int i = 0;i < n;i++){
            if(V[i]) count++;
            if(V[i] && count == index) return i;
        }
        return n-1;
        
    }
};
