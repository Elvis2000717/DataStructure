class Solution {
public:
	int jumpFloor(int number) {
		//��̬��̨���㷨
		if (number == 0)
		{
			return 0;
		}
		return 1 << (number - 1);
	}
};