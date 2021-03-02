class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
		{
			return 0;
		}

		int ret = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			array[i] = max(array[i - 1] + array[i], array[i]);
			ret = max(ret, array[i]);
		}

		return ret;
	}
};