#include <stdio.h>
#include <stdlib.h>
#include "p2.h"

void print_matrix(int *matrix, int row, int col) {
    int **x = (int**)(matrix);
    int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d ",*( *(x + i) + j));
			if (j == (col-1))
				printf("\n");
		}
	}
}

void read_matrices(int**A, int**B,int**C, int*m,int*n,int*p, char *filename) {
	int *arr;
	int c, i, j;
	int tracker = 0;


    FILE *file;
	file = fopen(filename, "r");
    if (file) {
		fscanf(file,"%d", m);
		fscanf(file,"%d", n);
		fscanf(file,"%d", p);
        arr = (int*)malloc((*n)*(*m+*p) * sizeof(int));
		do {
			fscanf(file, "%d", &c);
            *(arr+tracker) = c;
			if (feof(file))
				break;
            tracker++;			
		} while (1);
		fclose(file);
    }
	
        tracker = 0;
    for (i = 0; i < *m; i++) {
        *(A+i) = (int*)malloc(sizeof(int)*(*n));
        for (j = 0; j < *n; j++) {
            *(*(A + i) + j) = *(arr+tracker);
            tracker++;
      
        } 
    }
	    for (i = 0; i < *n; i++) {
		*(B+i) = (int*)calloc((*p),sizeof(int));
        for (j = 0; j < *p; j++) {
            *(*(B + i) + j) = *(arr+tracker);
          	    tracker++;
        } 
	    }
    for (i=0; i < *m; i++) {
		*(C+i) = (int*)malloc(sizeof(int)*(*p));
	}
}
void mult_matrices(int *A, int *B, int *C, int m, int n, int p) {
	int **mA, **mB, **mC, i, j, k; 
	mA = (int**)(A);
	mB = (int**)(B);
	mC = (int**)(C);

	for(i=0; i < m; i++)
    	for(j=0; j < p; j++) {
        	*(*(mC + i) + j) = 0;
        	for(k=0; k < n; k++)
            	*(*(mC + i) + j) += ( *(*(mA+i)+k) ) * ( *(*(mB+k)+j) );
        	}	
}
int main(int argc, char **argv){
    char *filename;
	if (argc == 0) {
		filename = "sample.txt";
	} else {
		filename = *(argv+1);
	} 

    int m, n, p;
    int *A, *B, *C;
    A = (int *)(int**)malloc(sizeof(int*)*(100));
    B = (int *)(int**)malloc(sizeof(int*)*(100));
    C = (int *)(int**)malloc(sizeof(int*)*(100));
    read_matrices((int**) A, (int**) B, (int**) C,&m, &n, &p, filename);
	mult_matrices(A, B, C, m, n, p);

	printf("Matrix A contents:\n");
    print_matrix(A, m, n);
	printf("\n");

	printf("Matrix B contents:\n");
    print_matrix(B, n, p);
	printf("\n");

	printf("Matrix A * B is:\n");
	print_matrix(C, m, p);
    return 0;
}