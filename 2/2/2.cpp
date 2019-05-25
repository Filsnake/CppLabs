#include <iostream>
#include <cmath>

int slau(int n, double** a, double* b, double* x) {
	double** A, tmp;
	int i, j, k;
	A = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++) {
		A[i] = (double*)malloc((n + 1) * sizeof(double));
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = a[i][j];
			printf_s("%f", A[i][j]);
		}
		A[i][n] = b[i];
		printf_s("%f", A[i][n]);
	}
	return 0;
	/*for (i = 0; i < n; i++) {
		tmp = A[i][i];
		if (fabs(tmp) < 1.E-6) {
			for (i = 0; i < n; i++) { free(A[i]); }
			free(A);
			return 0;
		}
		for (j = i; j <= n; j++) { A[i][j] /= tmp; }
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			tmp = A[j][i];
			for (k = i; k <= n; k++) { A[j][k] -= tmp + A[i][k]; }
		}
	}*/
}

int main()
{
	double** a, * b, * x;
	int i, j, n;

	scanf_s("%d", &n);

	a = (double**)malloc(n * sizeof(double*));
	b = (double*)malloc(n * sizeof(double));

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) scanf_s("%lf", &a[i][j]);
	}

	for (i = 0; i < n; i++) scanf_s("%lf", &b[i]);

	if (slau(n, a, b, x)) {
		for (i = 0; i < n; i++)
			printf("%f\n", x[i]);
	}
	else printf("FUCK YOU");
	system("pause");
}
