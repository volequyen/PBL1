#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Sign(x) (x % 2 ? -1 : 1)

float** capmang(int row, int col);
float subdet(float **A, int sz);
double Det1(float **A, int sz);
double Det2(float **A, int sz);

int main() {
    int n;
    float **A;
    unsigned char run;
    int x;
    FILE *f;
    FILE *fo;
    char c[10];
    do {
        printf("Nhap ten file: ");
        scanf("%s", c);
        int tt;
        if (strcmp(c, "matran1") == 0) {
            f = fopen("matran1.txt", "r");
            fscanf(f, "%d", &n);
            tt = 0;
        } else if (strcmp(c, "matran2") == 0) {
            f = fopen("matran2.txt", "r");
            fscanf(f, "%d", &n);
            tt = 0;
        } else if (strcmp(c, "matran3") == 0) {
            f = fopen("matran3.txt", "r");
            fscanf(f, "%d", &n);
            tt = 0;
        } else if (strcmp(c, "matran4") == 0) {
            f = fopen("matran4.txt", "r");
            fscanf(f, "%d", &n);
            tt = 0;
		} else if (strcmp(c, "matran5") == 0) {
            f = fopen("matran5.txt", "r");
            fscanf(f, "%d", &n);
            tt = 0;
		} else if (strcmp(c, "matran6") == 0) {
            f = fopen("matran6.txt", "r");
            fscanf(f, "%d", &n);
            tt = 0;
		} else if (strcmp(c, "matran7") == 0) {
            f = fopen("matran7.txt", "r");
            fscanf(f, "%d", &n);
            tt = 1;
    	} else if (strcmp(c, "matran10") == 0) {
            f = fopen("matran10.txt", "r");
            fscanf(f, "%d", &n);
            tt = 1;
		} else if (strcmp(c, "matran20") == 0) {
            f = fopen("matran20.txt", "r");
            fscanf(f, "%d", &n);
            tt = 1;
		} else if (strcmp(c, "matran50") == 0) {
            f = fopen("matran50.txt", "r");
            fscanf(f, "%d", &n);
            tt = 1;
		} else {
            printf("Ten file khong hop le.\n");
            continue;
        }
        A = capmang(n, n);
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                fscanf(f, "%f", &A[i][j]);
            }
        }
        fo = fopen("output.txt", "w");
            fprintf(fo, "%f", Det2(A, n));
        fclose(f);
		printf("\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%.2f ", A[i][j]);
            }
            printf("\n");
        }
		printf("\n");
        if (tt == 0) {
            printf("\nDet(A) = %.2lf\n", Det1(A, n));
        } else {
            printf("\nDet(A) = %.2lf\n", Det2(A, n));
        }
        printf("Nhan 'y' de tiep tuc hoac nhan phim bat ky de ket thuc: ");
        scanf(" %c", &run);
    } while (run == 'y');

    return 0;
}

float** capmang(int row, int col) {
    int i;
    float **pA;
    pA = (float**)malloc(row * sizeof(float*));
    if (!pA) {
        return NULL;
    }
    for (i = 0; i < row; i++) {
        pA[i] = (float*)malloc(col * sizeof(float));
        if (!pA[i]) {
            return NULL;
        }
    }
    return pA;
}

float subdet(float **A, int sz) {
    int i, j;
    for (i = 0; i < sz; i++) {
        for (j = 0; j < sz; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n\t\t ");
    }
    return 0;
}

double Det1(float **A, int sz) {
    int i, j, k, p = 0;
    double det = 0;
    int m, n;
    float **subA;
    if (sz < 2) return A[0][0];
    if (sz == 2) return (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
    else {
        subA = capmang(sz - 1, sz - 1);
        if (!subA) {
            return -1;
        }
        for (i = 0; i < sz; i++) {
            m = n = 0;
            for (j = 1; j < sz; j++) {
                for (k = 0; k < sz; k++) {
                    if (k != i) {
                        subA[m][n] = A[j][k];
                        n++;
                        if (n == sz - 1) {
                            m++;
                            n = 0;
                        }
                    }
                }

            }
            printf("Buoc %d: %2d*%.2f* ", i + 1, Sign(i), A[0][i]);
            printf("",subdet(subA, sz - 1));
			printf("\n");
            det += Sign(i) * A[0][i] * Det1(subA, sz - 1);
        }
    }
    return det;
}

double Det2(float **A, int sz) {
    int i, j, k, p = 0;
    double det = 0;
    int m, n;
    float **subA;
    if (sz < 2) return A[0][0];
    if (sz == 2) return (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
    else {
        subA = capmang(sz - 1, sz - 1);
        if (!subA) {
            return -1;
        }
        for (i = 0; i < sz; i++) {
            m = n = 0;
            for (j = 1; j < sz; j++) {
                for (k = 0; k < sz; k++) {
                    if (k != i) {
                        subA[m][n] = A[j][k];
                        n++;
                        if (n == sz - 1) {
                            m++;
                            n = 0;
                        }
                    }
                }

            }
            det += Sign(i) * A[0][i] * Det2(subA, sz - 1);
        }
    }
    return det;
}
