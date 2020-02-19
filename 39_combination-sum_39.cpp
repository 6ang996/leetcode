#include <iostream>

#define LINE_MAX 17000
static void dfs(int* nums, int numsSize, int target, int** result, int idx, int* reIndex, int* returnColumnSizes){
	if (idx == target){
		result[*reIndex] = (int*)malloc(sizeof(int) * numsSize);
		int j = 0;
		for (int i = 0; i < numsSize; i++) {
			 {
				result[*reIndex][j] = nums[i];
				printf(" %d ", nums[i]);
				j++;
			}
		}
		returnColumnSizes[*reIndex] = j;
		printf("\n");
		*reIndex = *reIndex + 1;
		return;
	}
	if (idx > target) {
		return;
	}

	for (int i = 0; i < numsSize; i++)
	{
		dfs(nums, numsSize, target, result, idx + nums[i], reIndex, returnColumnSizes);
	}
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {

	int** result = (int**)malloc(LINE_MAX * sizeof(int*));
	int reIndex = 0;
	int path[LINE_MAX];

	*returnColumnSizes = (int*)malloc(sizeof(int) * LINE_MAX);

	dfs(candidates, candidatesSize, target, result, 0, &reIndex, *returnColumnSizes);
	*returnSize = reIndex;

	return result;
}

void combinationSum_39() {
	int p = 0;
	int* pp = NULL;
	int** ppp = NULL;
	int height[] = { 2,3, 6, 7 };
	int target = 7;
	ppp = combinationSum(height, sizeof(height) / sizeof(int), target,&p, &pp);
	return;
}