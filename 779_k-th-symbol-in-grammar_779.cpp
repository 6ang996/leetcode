#include <iostream>


/* 779. µÚK¸öÓï·¨·ûºÅ */

int kthGrammar(int N, int K) {
	if (N == 1) {
		return 0;
	}
	int temp = kthGrammar(N - 1, (K + 1) / 2);
	return (K + 1) % 2 == 0 ? temp : (temp + 1) % 2;
}

void k_th_symbol_in_grammar_779() {

	int  result = 0;
	result = kthGrammar(32, 5);
	return;
}