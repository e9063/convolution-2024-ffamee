#include<stdio.h>
#include<stdlib.h>

int main(){
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
	for(int i = 0; i <= NA - NF; i++){
		S[i] = 0;
		for (int j = 0; j < NF; j++){
			S[i] += (long long int)(A[i + j]) * (long long int)F[j];
		}
	}

	// ---- output
	for(int i = 0; i <= NA - NF; i++){
		printf("%lld\n", S[i]);
	}

    // ---- free memory ----
    free(F);
    free(A);
	free(S);
    // ---- end free ----

    return 0;
}
