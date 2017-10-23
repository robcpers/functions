#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


void	bubbleSort(int *arr, int n){
	int i, j;
	int temp;
	int swap;

	for(i = 0; i < n-1; i++){
		swap = 0;
		for(j = 0; j <n-i-1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swap = 1;
			}
		}
		if(swap == 0){
			break;
		}
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


	bubbleSort(arr, n);

	for(i = 0; i < n; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");

	return 0;

}
