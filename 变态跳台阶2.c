class Solution {
public:
	int jumpFloor(int number) {
		//±äÌ¬ÌøÌ¨½×Ëã·¨
		if (number == 0)
		{
			return 0;
		}
		return 1 << (number - 1);
	}
};