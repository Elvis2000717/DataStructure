class Solution {
public:
	char firstUniqChar(string s) {
		char ret = ' ';
		vector<int> ans(26, 0);
		for (char e : s)
			ans[e - 'a']++;
		for (char e : s)
		{
			if (ans[e - 'a'] == 1)
			{
				ret = e;
				break;
			}
		}
		return ret;
	}
};