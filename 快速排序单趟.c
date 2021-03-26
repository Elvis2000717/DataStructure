//快速排序单趟排序O（n）
//void QuickSort(int* a, int n)
//{
//	int begin = 0;
//	int end = n - 1;
//	int keyi = end;
//	while (begin < end)
//	{
//		//左边先走 找大
//		while (begin < end && a[begin] <= keyi)
//		{
//			begin++;
//		}
//
//		//找小
//		while (begin < end && a[end] >= keyi)
//		{
//			end--;
//		}
//
//		Swap(&a[begin], &a[end]);
//	}
//
//	Swap(&keyi, a[begin]);
//}