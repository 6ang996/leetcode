#include <iostream>

#define MAX 16
int nextGreaterElement(int n)
{
	char nStr[MAX] = {0};
	int result = -1;
	sprintf_s(nStr, MAX, "%d", n);
	int nStrLen = strlen(nStr);
	printf("%s %d\n", nStr, nStrLen);
	int flag = 0;

	for (int i = nStrLen - 1; i >= 1; i--)
	{
		if (nStr[i] > nStr[i - 1])
		{
			int tmp = nStr[i];
			nStr[i] = nStr[i - 1];
			nStr[i - 1] = tmp;
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		sscanf_s(nStr, "%d", &result);
		printf("result=%d", result);
		return result;
	}
	else
	{
		return -1;
	}
}

#define MAX_INT 0x7FFFFFFF

int compare(const void *a, const void *b)
{
	char v1 = *(char *)a;
	char v2 = *(char *)b;
	return v2 - v1;
}

int nextGreaterElement1(int n)
{
	char num[32] = {0};
	int idx = 0;
	int s = n;
	int min = -1;

	while (s > 0)
	{
		num[idx] = s % 10;
		s = s / 10;
		idx++;
	}

	long long r = 0;
	for (int i = 0; i < idx; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (num[i] < num[j])
			{
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
				//printf("%d %d\n", i, j);
				qsort(num, i, 1, compare);

				idx = idx - 1;
				while (idx >= 0)
				{
					r = r * 10 + num[idx];
					idx--;
				}
				if (r > MAX_INT)
				{
					return -1;
				}
				return r;
			}
		}
	}

	return -1;
}

int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
	int *result = (int *)malloc(sizeof(int) * nums1Size);
	*returnSize = nums1Size;

	for (int i = 0; i < nums1Size; i++)
	{
		int resultIndex = -1;
		int find = 0;
		for (int j = 0; j < nums2Size; j++)
		{
			if (find == 1)
			{
				if (nums2[j] > nums1[i])
				{
					resultIndex = nums2[j];
					break;
				}
			}
			if (nums1[i] == nums2[j])
			{
				find = 1;
				continue;
			}
		}
		result[i] = resultIndex;
	}

	return result;
}

int reultnum(int *nums, int numsSize, int n)
{
	int result = -1;

	for (int j = 0; j < numsSize; j++)
	{
		if (nums[j] > n)
		{
			return nums[j];
		}
	}
	return result;
}
int *nextGreaterElements(int *nums, int numsSize, int *returnSize)
{
	int *result = (int *)malloc(sizeof(int) * numsSize);
	*returnSize = numsSize;
	for (int i = 0; i < numsSize; i++)
	{
		int resultIndex = -1;
		int j;
		for (j = i; j < numsSize; j++)
		{
			if (nums[j] > nums[i])
			{
				resultIndex = nums[j];
				result[i] = resultIndex;
				break;
			}
		}
		if ((j == numsSize - 1) && (resultIndex == -1))
		{
			result[i] = reultnum(nums, numsSize, nums[i]);
		}
		else
		{
			result[i] = resultIndex;
		}
	}

	return result;
}

int findRepeatNumber(int *nums, int numsSize)
{
	if((numsSize > 100000) || (numsSize < 2){
		return 0;
    }
	
    for(int i=0;i<numsSize;i++){
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[j] == nums[i])
			{
				return nums[j];
			}
		}
    }
    return 0;
}
void nextgreaterelementiii()
{
	int p = 0;
	int *ret = NULL;
	int nums1[] = {1, 2, 3, 4, 3};
	int nums2[] = {1, 3, 4, 2};
	p = nextGreaterElement1(230421);
	ret = nextGreaterElement(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int), &p);
	ret = nextGreaterElements(nums1, sizeof(nums1) / sizeof(int), &p);
	return;
}
