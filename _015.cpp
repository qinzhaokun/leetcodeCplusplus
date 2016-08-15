class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	vector<vector<int>> ret;
	for (int i = 0; i < n; i++) {
		if (i == 0 || nums[i] != nums[i - 1]) {
			int j = i + 1; int k = n - 1;
			while (j < k) {
				int t = nums[j] + nums[k];
				if (t > -nums[i]) {
					k--;
				}
				else if (t < -nums[i]) {
					j++;
				}
				else {
					if ((j != i + 1 && nums[j] == nums[j-1]) 
					|| (k != n-1 && nums[k] == nums[k+1]) ) {
						//continue;
					}
					else {
						vector<int> tmp;
						tmp.push_back(nums[i]); tmp.push_back(nums[j]); tmp.push_back(nums[k]);
						ret.push_back(tmp);
					}
					j++;k--;
				}
			}
		}
	}
	return ret;
}
};
