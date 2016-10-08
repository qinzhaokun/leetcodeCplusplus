class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long n = numerator; long d = denominator;
        bool isNegative = false;
        if((n < 0 && d > 0) || n > 0 && d < 0) isNegative = true;
        if(n < 0) n = -n;
        if(d < 0) d = -d;
        long a = n/d;
        long b = n%d;
        vector<long> arr;
        unordered_map<long,int> map;
        int left = -1;
        map[b] = 0;
        while(b != 0){
            b*=10;
            if(map.find(b) != map.end()){
                left = map[b];
                break;
            }
            else{
                long l = b/d;
                arr.push_back(l);
                map[b] = arr.size()-1;
            }
            b%=d;
        }
        string ret = to_string(a);
        ret += arr.size() == 0 ? "":".";
        if(left >= 0){
            for(int i = 0;i < arr.size();i++){
                if(left == i){
                    ret += "(";
                }
                ret += to_string(arr[i]);
            }
            ret+=")";
        }
        else{
            for(int i = 0;i < arr.size();i++){
                ret += to_string(arr[i]);
            }
        }
        if(isNegative) ret = "-"+ret;
        return ret;
    }
};
