class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int j = numbers.size()-1; int i = 0;
        while(i < j){
            if(numbers[i] + numbers[j] == target){
                ret.push_back(i+1);
                ret.push_back(j+1);
                break;
            }
            else if(numbers[i] + numbers[j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        return ret;
    }
};
