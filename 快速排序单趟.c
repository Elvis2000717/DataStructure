//��������������O��n��
//void QuickSort(int* a, int n)
//{
//	int begin = 0;
//	int end = n - 1;
//	int keyi = end;
//	while (begin < end)
//	{
//		//������� �Ҵ�
//		while (begin < end && a[begin] <= keyi)
//		{
//			begin++;
//		}
//
//		//��С
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