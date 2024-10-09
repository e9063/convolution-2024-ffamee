#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
	double start, end;

    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);
    long long int *S = malloc(sizeof(long long int) * (NA - NF + 1));

	for(int i = 0; i < NA; i++){
		scanf("%d", &A[i]);
	}
	for(int i = 0; i < NF; i++){
		scanf("%d", &F[NF - 1 - i]);
	}
	// ---- end input and malloc----

	// implement here
	int NUM_THREADS;
	// if (NF >= 20000 && (NF %  8 < 2 || NF % 8 > 5)){
	if (NF >= 200000){
		NUM_THREADS = 8;
	}
	else if (NF >= 20000){
		NUM_THREADS = 4;
	}
	else if (NF >= 200){
		NUM_THREADS = 2;
	}
	else{
		NUM_THREADS = 1;
	}
	start = omp_get_wtime();
	for(int i = 0; i <= NA - NF; i++){
		S[i] = 0;
		#pragma omp parallel num_threads(NUM_THREADS)
		{
			#pragma omp for reduction(+:S[i])
			for (int j = 0; j < NF; j++){
				S[i] += (long long int)(A[i + j]) * (long long int)F[j];
			}
		}
	}
	end = omp_get_wtime();

	// ---- output
	for(int i = 0; i <= NA - NF; i++){
		printf("%lld\n", S[i]);
	}

    // ---- free memory ----
    free(F);
    free(A);
	free(S);
    // ---- end free ----

	printf("%f", (double)(end - start));
    return 0;
}
