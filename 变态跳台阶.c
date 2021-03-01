class Solution {
public:
	int jumpFloor(int number) {
		//±äÌ¬ÌøÌ¨½×Ëã·¨
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