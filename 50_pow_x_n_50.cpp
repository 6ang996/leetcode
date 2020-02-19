#include <iostream>


double f(double x, int n) {
	double half = 0;
	if (n == 0) {
		return 1.0;
	}
	half = f(x, n / 2);

	if (n % 2 == 0) {
		return half * half;
	}
	else {
		return half * half * x;
	}


}
double myPow(double x, int n) {
	int N = n;
	if (n < 0) {
		x = 1 / x;
		N = -N;
	}
	return f(x, N);
}

void pow_x_n_50() {
	double reult = 0.0;
	reult = myPow(2, 5);
}