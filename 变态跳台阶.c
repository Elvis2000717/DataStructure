class Solution {
public:
	int jumpFloor(int number) {
		//��̬��̨���㷨
		int ret = 1;
		if(number < 1)
		{
			return 0;
		}
		if(number == 1)
		{
		    return ret;
		}
		for(int i = 1; i < number; i++)
		{
			ret *= 2;
		}
		return ret;
	}
};