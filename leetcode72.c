#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a)<(b) ? (a) : (b))
int minDistance(char * word1, char * word2) {
	int size1 = strlen(word1) + 1;
	int size2 = strlen(word2) + 1;
	int *data = (int *)malloc(size1*size2 * sizeof(int));
	int **dp = malloc(size2 * sizeof(int*));
	for (int i = 0; i < size2; i++) {
		dp[i] = data + (size1*i);
	}
	for (int i = 0; i < size1; i++) {
		dp[0][i] = i;
	}
	for (int j = 0; j < size2; j++) {
		dp[j][0] = j;
	}  
	for (int i = 1; i < size2; i++) {
		for (int j = 1; j < size1; j++) {
			if (word1[j-1] == word2[i-1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = MIN(MIN(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1])+1;
		}
	}
	return dp[size2-1][size1-1];
}
int main() {
	char* word1 = "horse";
	char* word2 = "ros";
	int res = minDistance(word1, word2);
	printf("%d", res);
	return 0;
}
