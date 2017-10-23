#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


void	insertSort(int *arr, int n){
	int i, j;
	int cur;
	for(i = 1; i < n; i++){
		cur = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > cur){
			arr[j+1] = arr[j];
			j --;
		}
		arr[j+1] = cur;

	}




	return;
}



int main(){
	srand48(time(NULL));
	int n = 20;
	int *arr = malloc(n*sizeof(int));
	int i, rand;
	for(i = 0; i < n; i++){
		rand = (int) (drand48()*n);
		arr[i] = rand;
	}


	insertSort(arr, n);

	for(i = 0; i < n; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");

	return 0;

}
