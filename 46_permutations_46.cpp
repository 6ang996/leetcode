#include <iostream>

#define LINE_MAX 17000
int v[LINE_MAX] = {0};
void robot(int *nums, int numsSize, int *path, int **result, int idx, int *reIndex)
{
	if (idx >= numsSize)
	{
		result[*reIndex] = (int *)malloc(sizeof(int) * numsSize);
		for (int i = 0; i < numsSize; i++)
		{
			result[*reIndex][i] = path[i];
			printf(" %d ", path[i]);
		}
		printf("\n");
		*reIndex = *reIndex + 1;
		return;
	}

	for (int i = 0; i < numsSize; i++)
	{
		if (v[i] == 0)
		{
			path[idx] = nums[i];
			v[i] = 1;
			robot(nums, numsSize, path, result, idx + 1, reIndex);
			v[i] = 0;
		}
	}
}
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{

	int **result = (int **)malloc(LINE_MAX * sizeof(int *));
	int reIndex = 0;
	int path[LINE_MAX];

	robot(nums, numsSize, path, result, 0, &reIndex);
	*returnSize = reIndex;

	*returnColumnSizes = (int *)malloc(sizeof(int) * LINE_MAX);
	for (int i = 0; i < reIndex; i++)
	{
		(*returnColumnSizes)[i] = numsSize;
	}

	return result;
}

void permutations_46()
{
	int p = 0;
	int *pp = NULL;
	int **ppp = NULL;
	int height[] = {-4, 7, 8};
	ppp = permute(height, sizeof(height) / sizeof(int), &p, &pp);
	return;
}