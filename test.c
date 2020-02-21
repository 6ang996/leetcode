#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void dfs(int *nums, int size, int start, int **results, int *count)
{
    int i;
    if (start == size)
    {
        results[*count] = malloc(size * sizeof(int));
        memcpy(results[*count], nums, size * sizeof(int));
        (*count)++;
    }
    else
    {
        for (i = start; i < size; i++)
        {
            swap(nums + start, nums + i);
            dfs(nums, size, start + 1, results, count);
            swap(nums + start, nums + i);
        }
    }
}

/**
 ** Return an array of arrays of size *returnSize.
 ** Note: The returned array must be malloced, assume caller calls free().
 **/
static int **permute(int *nums, int numsSize, int *returnSize)
{
    int count = 0, cap = 5000;
    int **results = malloc(cap * sizeof(int *));
    *returnSize = 0;
    dfs(nums, numsSize, 0, results, returnSize);
    return results;
}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        fprintf(stderr, "Usage: ./test ...");
        exit(-1);
    }

    int i, j, count = argc - 1;
    int *nums = malloc(count * sizeof(int));
    for (i = 0; i < count; i++)
    {
        nums[i] = atoi(argv[i + 1]);
    }

    int **lists = permute(nums, argc - 1, &count);
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < argc - 1; j++)
        {
            printf("%d", lists[i][j]);
        }
        putchar('');
    }

    return 0;
}

void dfs(int *nums, int numsSize, int *mark, int *path, int index, int **result, int *reIndex)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (mark[i] == 0)
            continue;
        mark[i] = 0;
        path[index] = nums[i];
        printf("get:%d \n", nums[i]);
        index = index + 1;

        if (index == numsSize)
        {
            result[*reIndex] = (int *)malloc(sizeof(int) * numsSize);
            for (int j = 0; j < numsSize; j++)
            {
                result[*reIndex][j] = path[j];
                printf(" %d ", path[j]);
            }
            printf("\n");
            *reIndex = *reIndex + 1;
        }

        dfs(nums, numsSize, mark, path, index, result, reIndex);
        mark[i] = 1;
        index = index - 1;
    }
}
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int mark[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
        mark[i] = 1;
    }
    int path[numsSize];
    int index = 0;
    int **result = (int **)malloc(sizeof(int *) * 17000);
    int reIndex = 0;
    dfs(nums, numsSize, mark, path, index, result, &reIndex);
    *returnSize = reIndex;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 17000);
    for (int i = 0; i < reIndex; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }
    return result;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void DFS(int *nums, int numsSize, int level, int *returnSize, int **returnColumnSizes, int *tmp, int **result, int index)
{
    result[*returnSize] = malloc(sizeof(int) * level);
    for (int j = 0; j < level; j++)
        result[*returnSize][j] = tmp[j];
    (*returnColumnSizes)[*returnSize] = level;
    (*returnSize)++;

    for (int i = index; i < numsSize; i++)
    {
        tmp[level] = nums[i];
        DFS(nums, numsSize, level + 1, returnSize, returnColumnSizes, tmp, result, i + 1);
    }
}

int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    int **result = malloc(sizeof(int *) * 4096);
    *returnColumnSizes = calloc(sizeof(int), 4096);
    int *tmp = malloc(sizeof(int) * numsSize);

    DFS(nums, numsSize, 0, returnSize, returnColumnSizes, tmp, result, 0);

    free(tmp);
    return result;
}
/* 位运算
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int **result = malloc(sizeof(int *) * 4096);
    *returnColumnSizes = calloc(sizeof(int), 4096);

    for (int bits = 0; bits < pow(2, numsSize); bits++) {
        result[*returnSize] = malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            if ((bits >> i) & 1 == 1) {
                result[*returnSize][(*returnColumnSizes)[*returnSize]] = nums[i];
                (*returnColumnSizes)[*returnSize]++;
            }
        }
        (*returnSize)++;
    }

    return result;
}
*/