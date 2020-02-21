#include <iostream>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define LINE_MAX 17000
void robot(int n, int k, int *path, int **result, int idx, int kk, int *reIndex)
{
	if (kk == 0)
	{
		result[*reIndex] = (int *)malloc(sizeof(int) * k);
		for (int i = 0; i < k; i++)
		{
			result[*reIndex][i] = path[i];
			printf(" %d ", path[i]);
		}
		printf("\n");
		*reIndex = *reIndex + 1;
		return;
	}
	for (int i = idx; i <= n; i++)
	{
		path[kk - 1] = i;
		robot(n, k, path, result, i, kk - 1, reIndex);
	}
}
int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
	int **result = (int **)malloc(LINE_MAX * sizeof(int *));
	int reIndex = 0;
	int path[LINE_MAX] = {0};

	robot(n, k, path, result, 1, k, &reIndex);
	*returnSize = reIndex;

	*returnColumnSizes = (int *)malloc(sizeof(int) * reIndex);
	for (int i = 0; i < reIndex; i++)
	{
		(*returnColumnSizes)[i] = k;
	}
	return result;
}

void combinations_77()
{
	int n = 4;
	int k = 2;
	int p = 0;
	int *pp = NULL;
	int **ppp = NULL;

	ppp = combine(n, k, &p, &pp);
	return;
}

char *replaceSpace(char *s)
{
	int len = strlen(s);
	if (len == 0)
	{
		return NULL;
	}
	int j = 0;
	char *resultBuf = (char *)malloc(len * 3);
	memset(resultBuf, 0, len * 3);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ')
		{
			resultBuf[j] = '%';
			resultBuf[j] = '2';
			resultBuf[j] = '0';
			j += 3;
		}
		else
		{
			resultBuf[j] = s[i];
			j++;
		}
	}
	return resultBuf;
}