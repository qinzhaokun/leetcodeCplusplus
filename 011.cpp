class Solution {
public:
    int maxArea(vector<int>& height) {
	int i = 0; int j = height.size()-1;
	int max = 0;
	while (i < j) {
		if (height[i] <= height[j]) {
			if (max < (j - i)*height[i]) {
				max = (j - i)*height[i];
				
			}
			int k = i;
			while (i < j && height[i] <= height[k]) i++;
		}
		else {
			
				if (max < (j - i)*height[j]) {
					max = (j - i)*height[j];
				}
				int k = j;
				while (i < j && height[k] >= height[j]) j--;
		}
	}
	return max;
}
};
