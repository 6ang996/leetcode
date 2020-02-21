// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int strtonum()
{
	return 0;
}

int lengthOfLongestSubstring(char *s)
{
	int strLen = strlen(s);
	int outLen = 0;
	int max = 0;

	for (int i = 0; i < strLen; i++)
	{
		outLen = 0;
		for (int j = i; j < strLen; j++)
		{
			for (int k = i; k < j; k++)
			{
				if (s[k] == s[j])
				{
					break;
				}
				else
				{
					outLen = outLen + 1;
				}
			}
		}
		max = outLen > max ? outLen : max;
	}
	return max;
}

int lengthOfLongestSubstring1(char *s)
{
	int start = 0, end = 0, maxlen = 0;
	char map[256] = {0};
	map[(int)*(s + start)] = 1;

	while (*(s + end) != 0)
	{
		maxlen = maxlen > (end - start + 1) ? maxlen : (end - start + 1);
		++end;
		while (0 != map[(int)*(s + end)]) //将要加入的新元素与map内元素冲突
		{
			map[(int)*(s + start)] = 0;
			++start;
		}
		map[(int)*(s + end)] = 1;
	}

	return maxlen;
}

int lengthOfLongestSubstring3(char *s)
{
	int i = 0;
	int j, k, tmpLen;
	int maxLen = 0;
	int stringLen = strlen(s);

	if (stringLen == 0 || stringLen == 1)
	{
		return stringLen;
	}
	for (j = 1; j < stringLen; j++)
	{
		for (k = j - 1; k >= i; k--)
		{
			printf("i = %d, j=%d, k=%d\n", i, j, k);
			if (s[k] == s[j])
			{
				i = k + 1;
				break;
			}
		}
		tmpLen = j - k;
		maxLen = maxLen > tmpLen ? maxLen : tmpLen;
	}

	return maxLen;
}

/* 最大面积 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define LINE_MIN 2

int maxArea(int *height, int heightSize)
{
	int ans = 0;

	if (heightSize < LINE_MIN)
	{
		return 0;
	}
	for (int i = 0; i < heightSize - 1; i++)
	{
		for (int j = i + 1; j < heightSize; j++)
		{
			int area = MIN(height[i], height[j]) * (j - i);
			ans = MAX(ans, area);
		}
	}
	return ans;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
	int *results = NULL;

	results = (int *)malloc(numsSize * sizeof(int));
	if (results == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	for (int i = 0; i < numsSize; i++)
	{
		int res = 1;
		for (int j = 0; j < numsSize; j++)
		{
			if (j == i)
			{
				continue;
			}
			res = res * nums[j];
		}
		results[i] = res;
	}
	*returnSize = numsSize;
	return results;
}
int *productExceptSelf_O_n(int *nums, int numsSize, int *returnSize)
{
	int *results = NULL;
	int left = 1;
	int right = 1;

	results = (int *)malloc(numsSize * sizeof(int));
	if (results == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	for (int i = 0; i < numsSize; i++)
	{
		results[i] = left;
		left *= nums[i];
	}
	for (int j = numsSize - 1; j >= 0; j--)
	{
		results[j] *= right;
		right *= nums[j];
	}
	*returnSize = numsSize;
	return results;
}
/* 198. 打家劫舍 */
int sove(int *sums, int index)
{
	if (index < 0)
	{
		return 0;
	}
	return MAX(sums[index] + sove(sums, index - 2), sove(sums, index - 1));
}
int rob(int *nums, int numsSize)
{

	return sove(nums, numsSize - 1);
}

int sove1(int *sums, int index, int *result)
{
	if (index < 0)
	{
		return 0;
	}
	if (result[index] >= 0)
	{
		return result[index];
	}

	result[index] = MAX(sums[index] + sove1(sums, index - 2, result), sove1(sums, index - 1, result));

	return result[index];
}

int rob1(int *nums, int numsSize)
{
	int *result = (int *)malloc(numsSize * sizeof(int));
	int mony = 0;
	if (result == NULL)
	{
		return 0;
	}
	for (int i = 0; i < numsSize; i++)
	{
		result[i] = -1;
	}
	mony = sove1(nums, numsSize - 1, result);
	free(result);

	return mony;
}

int rob2(int *nums, int numsSize)
{
	int *result = (int *)malloc(numsSize * sizeof(int));
	int mony = 0;
	if (result == NULL)
	{
		return 0;
	}
	for (int i = 0; i < numsSize; i++)
	{
		result[i] = -1;
	}

	result[0] = nums[0];
	result[1] = MAX(nums[0], nums[1]);

	for (int i = 2; i < numsSize; i++)
	{
		result[i] = MAX(nums[i] + result[i - 2], result[i - 1]);
	}
	mony = result[numsSize - 1];
	free(result);

	return mony;
}

int fn(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	return n * fn(n - 1);
}

int fn1(int n)
{
	int *f = (int *)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i <= n; i++)
	{
		f[i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] * i;
	}
	return f[n];
}
/*
int fn(int n) {
	if (n <= 1) {
		return 1;
	}
	if (result[n] >= 0) {
		return result[n];
	}
	return fn(n - 1) + f(n - 2);
}*/

/*
	废弃那波数列
	递归改地推
	自顶向下：递推
	自底向上：递归
*/
/*
int fib(int n) {

	f(0) = 0;
	f(1) = 1;
	f(2) = 1;
	for (int i = 3; i < n; i++){
		f(n) = f(n - 1) + f(n - 2);
	}
	return f[n];
}
*/
/*
	小兵向上冲
*/
int fnm(int n, int m)
{
	if ((n == 0) || (m == 0))
	{
		return 0;
	}
	if ((n == 1) || (m == 1))
	{
		return 1;
	}
	return fnm(n - 1, m) + fnm(n, m - 1);
}

int fnm2(int n, int m)
{
	if ((n == 0) || (m == 0))
	{
		return 0;
	}
	if ((n == 1) || (m == 1))
	{
		return 1;
	}
	return fnm2(n - 1, m) + fnm2(n, m - 1) + fnm(n - 2, m) + fnm(m, m - 2);
}

int tj(int n)
{

	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	return tj(n - 1) + tj(n - 2);
}

/* 爬楼梯问题 */
int climbStairs(int n)
{
	int resultNum = 0;
	int *result = (int *)malloc((n + 1) * sizeof(int));
	if (result == NULL)
	{
		return 0;
	}
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	memset(result, 0, (n + 1) * sizeof(int));
	result[0] = 0;
	result[1] = 1;
	result[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		result[i] = result[i - 1] + result[i - 2];
	}
	resultNum = result[n];
	free(result);
	return resultNum;
}
/* 32. 最长有效括号 */
#define LEF '('
#define RIG ')'
int longestValidParentheses(char *s)
{
	int sLen = strlen(s);
	int sigMax = 0;
	int max = 0;

	for (int i = 0; i < sLen; i++)
	{
		if (s[i] == ')')
		{
			continue;
		}
		sigMax = 0;
		int startFlag = 1;
		int leftNum = 1;
		int rightNum = 0;
		int tmp = 0;
		for (int j = i + 1; j < sLen; j++)
		{ //()(())
			if (s[j] == ')' && startFlag == 1)
			{
				tmp++;
				leftNum--;

				if (leftNum == 0)
				{
					sigMax = tmp;
					startFlag = 0;
				}
			}
			else if (s[j] == '(' && startFlag == 0)
			{
				startFlag = 1;
				leftNum++;
			}
			else if (s[j] == '(' && leftNum != 0)
			{
				startFlag = 1;
				leftNum++;
			}
			else
			{
				break;
			}
		}
		max = MAX(max, sigMax);
	}
	return 2 * max;
}

/* 3 无重复最长字串 
int lengthOfLongestSubstring5(char* s) {
	int strLen = strlen(s);
	int outLen = 0;
	int max = 0;

	for (int i = 0; i < strLen; i++) {
		outLen = 0;
		for (int j = i + 1; j < strLen; j++) {
			char* buf = (char*)malloc(j - i + 1);
			memcpy(buf, s + 1, j - i + 1);
			for (int k = i; k < j; k++) {
				if (NULL != strstr(buf, s[k]) {
					break;
				}
			}
			free(buf);
		}
		max = MAX(max, outLen);
	}
	return max;
}*/
/*
 * 输入people是长度为peopleSize的数组指针的数组，其中每个元素（也是一个数组）的长度组成peopleColSize数组作为另一输入，peopleColSize数组的长度也为peopleSize
 * 返回为 *returnSize大小的数组指针的数组，其中每个元素（也是一个数组）的长度组成*returnColumnSizes数组返回，*returnColumnSizes数组的长度也为 *returnSize。
 * 注意：返回的数组以及其数组元素、和 *returnColumnSizes数组都必须在给定的函数内进行内存分配，由框架代码进行内存释放。
 [[8,0], [4,4], [8,1], [5,0], [6,1], [5,2]]
 */
#define PEOPLEAMAX 1100
int **ReconstructQueue(int **people, int peopleSize, int *peopleColSize, int *returnSize, int **returnColumnSizes)
{
	int ans[PEOPLEAMAX][PEOPLEAMAX] = {0};
	for (int i = 0; i < peopleSize; i++)
	{
		//printf("people= [%d %d]\n", (*people)[0],(*people)[1]);
		//printf("sieze =%d people= [%d %d]\n", peopleSize,people[i][0], people[i][1]);
		//printf("peopleColSize= %d\n",peopleColSiize[i]);
	}

	return NULL;
}

int **ReconstructQueue1(int **people, int peopleSize, int *peopleColSize, int *returnSize, int **returnColumnSizes)
{
	*returnColumnSizes = (int *)malloc(peopleSize * sizeof(int));
	int **output = (int **)malloc(peopleSize * sizeof(int *));

	int i, j;
	*returnSize = peopleSize;
	for (i = 0; i < peopleSize; i++)
	{
		(*returnColumnSizes)[i] = 2;
		output[i] = (int *)malloc(sizeof(int) * 2);
		output[i][0] = 0;
		output[i][1] = 0;
	}

	for (i = 0; i < peopleSize; i++)
	{
		for (j = i; j < peopleSize; j++)
		{
			int *temp;
			if (people[i][0] < people[j][0])
			{
				temp = people[i];
				people[i] = people[j];
				people[j] = temp;
			}

			if (people[i][0] == people[j][0] && people[i][1] > people[j][1])
			{
				temp = people[i];
				people[i] = people[j];
				people[j] = temp;
			}
		}
	}

	for (i = 0; i < peopleSize; i++)
	{
		int temp1 = people[i][1];
		for (j = i; j > temp1; j--)
		{
			output[j][0] = output[j - 1][0];
			output[j][1] = output[j - 1][1];
		}
		output[temp1][0] = people[i][0];
		output[temp1][1] = people[i][1];
	}
	return output;
}
void test(int **returnColumnSizes)
{
	int peopleSize = 6;
	*returnColumnSizes = (int *)malloc(peopleSize * sizeof(int));
	for (int i = 0; i < peopleSize; i++)
	{
		(*returnColumnSizes)[i] = 2;
	}
}
#define MAXSIZE 256
bool isAnagram1(char *s, char *t)
{
	int sLen = strlen(s);
	int tlen = strlen(t);

	if (sLen != tlen)
	{
		return false;
	}
	for (int i = 0; i < sLen; i++)
	{
		for (int j = 0; j < sLen - i; j++)
		{
			if (s[i] > s[j])
			{
				int tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
			if (t[i] > t[j])
			{
				int tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
		}
	}
	for (int i = 0; i < sLen; i++)
	{
		if (s[i] != t[i])
		{
			return false;
		}
	}
	return true;
}

/*  242. 有效的字母异位词 */
#define MAXSIZE 256
bool isAnagram(char *s, char *t)
{
	int sLen = strlen(s);
	int tlen = strlen(t);
	int tMap[MAXSIZE] = {0};
	int sMap[MAXSIZE] = {0};

	if (sLen != tlen)
	{
		return false;
	}

	for (int i = 0; i < sLen; i++)
	{
		tMap[s[i]]++;
		sMap[t[i]]++;
	}
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (tMap[i] == sMap[i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int *findAnagrams(char *s, char *p, int *returnSize)
{
	if (s == NULL || p == NULL)
	{
		*returnSize = 0;
		return NULL;
	}
	int sLen = strlen(s);
	int pLen = strlen(p);
	if (sLen == 0 || pLen == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	int j = 0;

	if (pLen > sLen)
	{
		*returnSize = 0;
		return NULL;
	}
	int *out = (int *)malloc(sizeof(int) * sLen);
	if (!out)
	{
		*returnSize = 0;
		return NULL;
	}
	memset(out, 0, sizeof(int) * sLen);

	char *buf = (char *)malloc(pLen + 1);
	memset(buf, 0, pLen + 1);
	for (int i = 0; i <= sLen - pLen; i++)
	{
		memcpy(buf, s + i, pLen);
		if (isAnagram(buf, p) == true)
		{
			out[j] = i;
			j++;
		}
	}
	free(buf);
	*returnSize = j;
	return out;
}

bool checkInclusion(char *s1, char *s2)
{
	int s1Len = strlen(s1);
	char *s1Buf = (char *)malloc(s1Len + 1);
	memset(s1Buf, 0, s1Len + 1);
	memcpy(s1Buf, s1, s1Len);

	for (int i = 0; i < s1Len / 2; i++)
	{
		int tmp = s1Buf[i];
		s1Buf[i] = s1Buf[s1Len - 1 - i];
		s1Buf[s1Len - 1 - i] = tmp;
	}
	if (strstr(s2, s1) != NULL)
	{
		return true;
	}

	if (strstr(s2, s1Buf) != NULL)
	{
		return true;
	}
	return false;
}

/* 1055. 形成字符串的最短路径 */
#define SIZE_MAX_MARK 26
int shortestWay(char *source, char *target)
{
	int sourceList[SIZE_MAX_MARK] = {0};
	int targetList[SIZE_MAX_MARK] = {0};
	int targetLen = strlen(target);
	int sourceLen = strlen(source);
	char *sourceTmp = source;
	char *targetTmp = target;
	int cnt = 0;

	while (*sourceTmp != '\0')
	{
		sourceList[*sourceTmp - 'a']++;
		sourceTmp++;
	}
	while (*targetTmp != '\0')
	{
		targetList[*targetTmp - 'a']++;
		targetTmp++;
	}

	for (int i = 0; i < SIZE_MAX_MARK; i++)
	{
		if (targetList[i] != 0 && sourceList[i] == 0)
		{
			return -1;
		}
	}
	int start = 0;
	int end = 0;
	int i = 0;
	while (i < targetLen)
	{
		while (source[start] != target[i])
		{
			start++;
		}
		end = start + 1;

		i++;
		while (i < targetLen && end < sourceLen)
		{
			if (source[end] == target[i])
			{
				i++;
			}
			end++;
		}
		cnt++;
		start = 0;
	}

	return cnt;
}
/* 392. 判断子序列 */
bool isSubsequence(char *s, char *t)
{
	int sourceList[SIZE_MAX_MARK] = {0};
	int targetList[SIZE_MAX_MARK] = {0};
	if (s == NULL || t == NULL)
	{
		return false;
	}
	int targetLen = strlen(t);
	int sourceLen = strlen(s);
	char *sourceTmp = s;
	char *targetTmp = t;

	if (sourceLen == 0)
	{
		return true;
	}
	while (*sourceTmp != '\0')
	{
		sourceList[*sourceTmp - 'a']++;
		sourceTmp++;
	}
	while (*targetTmp != '\0')
	{
		targetList[*targetTmp - 'a']++;
		targetTmp++;
	}

	for (int i = 0; i < SIZE_MAX_MARK; i++)
	{
		if (sourceList[i] != 0 && targetList[i] == 0)
		{
			return false;
		}
	}

	int start = 0;
	int end = 0;
	int i = 0;
	while (t[start] != s[i])
	{
		start++;
	}
	end = start + 1;
	i++;
	while (i < sourceLen && end < targetLen)
	{
		if (t[end] == s[i])
		{
			i++;
		}
		end++;
	}

	if (i == sourceLen)
	{
		return true;
	}

	return false;
}

/* 392. 判断子序列 */
bool isSubsequence1(char *s, char *t)
{
	int sourceList[SIZE_MAX_MARK] = {0};
	int targetList[SIZE_MAX_MARK] = {0};
	if (s == NULL || t == NULL)
	{
		return false;
	}
	int targetLen = strlen(t);
	int sourceLen = strlen(s);
	char *sourceTmp = s;
	char *targetTmp = t;

	if (sourceLen == 0)
	{
		return true;
	}
	int j = 0;
	for (int i = 0; i < targetLen; i++)
	{
		if (t[i] == s[j])
		{
			j++;
		}
	}
	if (j == sourceLen)
	{
		return true;
	}

	return false;
}

int numMatchingSubseq(char *S, char **words, int wordsSize)
{
	int num = 0;
	for (int i = 0; i < wordsSize; i++)
	{
		if (isSubsequence(words[i], S) == true)
		{
			num++;
		}
	}

	return num;
}
#define MAX_MAX(i, j) (((i) > (j)) ? (i) : (j))
int maxSubArray(int *nums, int numsSize)
{
	int max = 0;
	int sum = 0;
	int max1 = 0;
	if (numsSize == 1)
	{
		return nums[0];
	}
	for (int i = 0; i < numsSize; i++)
	{
		sum = 0;
		for (int j = i; j < numsSize; j++)
		{
			if (sum + nums[j] > max1)
			{
				max1 = sum + nums[j];
			}
			sum = sum + nums[j];
		}
		max = MAX_MAX(max1, max);
	}
	return max;
}
void swp(int start, int end, char *s)
{
	if (start >= end)
	{
		return;
	}
	int tmp = s[start];
	s[end] = s[start];
	s[start] = tmp;
	swp(start + 1, end - 1, s);
	return;
}
void reverseString(char *s, int sSize)
{

	swp(0, sSize - 1, s);
	return;
}


struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct ListNode* tmp = head->next;
	head->next = tmp->next;//swapPairs(tmp->next);
	tmp->next = head;

	return tmp;
}
struct ListNode *retLis = NULL;


int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	printf("%d %x %p\n", numRows, *returnSize, returnColumnSizes);
	//swap(numRows);
	*returnSize = numRows;
	*returnColumnSizes = (int*)malloc(numRows * sizeof(int*));
	int** res = (int**)malloc(numRows * sizeof(int*));
	for (int i = 0; i < numRows; i++) {
		(*returnColumnSizes)[i] = i + 1;
		res[i] = (int*)malloc((i+1)*sizeof(int));
		res[i][0] = 1;
		res[i][i] = 1;
	}
	for (int i = 2; i < numRows; i++){
		for (int j = 1; j < i; j++){
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}
	return res;
}
#define ROWMAX 33
int* getRow1(int rowIndex, int* returnSize) {
	if (rowIndex == 0 || rowIndex > ROWMAX) {
		return 0;
	}
	*returnSize = rowIndex + 1;
	int* ret = (int*)malloc(*returnSize * sizeof(int));
	int ans[ROWMAX + 1][ROWMAX + 1] = { 0 };

	for (int i = 0; i < ROWMAX+1; i++) {
		ans[i][0] = 1;
		ans[i][i] = 1;
	}
	for (int i = 2; i < *returnSize; i++) {
		for (int j = 1; j < i; j++) {
			ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
	}
	for (int i = 0; i < *returnSize; i++) {
		ret[i] = ans[*returnSize - 1][i];
	}
	return ret;
}
\
#define ROWMAX 33
int* getRow(int rowIndex, int* returnSize) {
	if (rowIndex == 0 || rowIndex > ROWMAX) {
		return 0;
	}
	*returnSize = rowIndex + 1;
	int* ret = (int*)malloc(*returnSize * sizeof(int));
	int** ans = (int**)malloc((*returnSize) * sizeof(int*));
	//int ans[ROWMAX + 1][ROWMAX + 1] = { 0 };

	for (int i = 0; i < *returnSize; i++) {
		ans[i] = (int*)malloc((i+1)*sizeof(int));
		ans[i][0] = 1;
		ans[i][i] = 1;
	}


	for (int i = 2; i < *returnSize; i++) {
		for (int j = 1; j < i; j++) {
			ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
	}
	for (int i = 0; i < *returnSize; i++) {
		ret[i] = ans[*returnSize - 1][i];
	}

	for (int i = 0; i < *returnSize; i++) {
		ans[i] = (int*)malloc((i + 1) * sizeof(int));
		ans[i][0] = 1;
		ans[i][i] = 1;
	}
	free(ans);

	return ret;
}
void permutations_46();
void combinations_77();
void subsets_ii_90();
void subsets_78();
void combinationSum_39();
void pow_x_n_50();
void merge_two_sorted_lists_21();
void sort_list_148();
void k_th_symbol_in_grammar_779();
void nextgreaterelementiii();

int main() {
	struct ListNode* retList = NULL;
	retLis =(struct ListNode*) malloc(sizeof(struct ListNode));
	retLis->val = 1;
	retLis->next =(struct ListNode*) malloc(sizeof(struct ListNode));
	retLis->next->val = 2;
	retLis->next->next = 0;

	retList = swapPairs(retLis);
	int p = 0;
	int* pp = NULL;
	generate(5, &p, &pp);
	getRow(3, &p);

	int **ppp = NULL;
	//permutations_46();
	//ombinations_77();
	//subsets_ii_90();
	//subsets_78();
	//combinationSum_39();
	//pow_x_n_50();
	//merge_two_sorted_lists_21();
	//sort_list_148();
	k_th_symbol_in_grammar_779();
	nextgreaterelementiii();
}

int main1()
{
	int result = 0;
	int *resultp = NULL;
	int returnSize = 0;
	int **ans = NULL;
	printf("%s", "Hello World!");
	result = lengthOfLongestSubstring3((char *)"pwwkew");

	int out[6][2] = {{8, 0}, {4, 4}, {8, 1}, {5, 0}, {6, 1}, {5, 2}};

	int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	result = maxArea(height, sizeof(height) / sizeof(int));

	int nums[] = {1, 2, 3, 4};
	resultp = productExceptSelf_O_n(nums, sizeof(nums) / sizeof(int), &returnSize);

	int nums_rob[] = {2, 7, 9, 3, 1};
	result = rob2(nums_rob, sizeof(nums_rob) / sizeof(int));
	result = fn1(5);
	result = fnm(2, 2);
	result = climbStairs(1);
	result = longestValidParentheses((char *)"()(()");
	//ans = ReconstructQueue1((int**)out,6, &result, &result, &resultp);

	int *p = NULL;
	test(&p);
	result = isAnagram((char *)"anagram", (char *)"nagaram");

	int return_1 = 0;
	resultp = findAnagrams((char *)"aaaaaaaaaa", (char *)"aaaaaaaaaaaaa", &return_1);

	result = checkInclusion((char *)"ab", (char *)"eidboaoo");
	result = shortestWay((char *)"xyz", (char *)"xzyxz");

	result = isSubsequence((char *)"abc", (char *)"ahbgdcdfs");
	result = isSubsequence1((char *)"abc", (char *)"ahbgdcdfs");

	//int  nums[] = { -2,1,-3,4,-1,2,1,-5,4 };
	//int numMatchingSubseq(char* S, char** words, int wordsSize);

	return 0;
}
