class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
	int n = strs.size();
	if (n == 0) return "";
	string longest = strs[0];
	for (int i = 1; i < strs.size(); i++) {
		int index = 0;
		while (index < longest.length() && index < strs[i].length() && longest[index] == strs[i][index]) index++;

		longest = longest.substr(0, index);
		if (index == 0) break;
	}

	return longest;
}
};
