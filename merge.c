#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


void	merge(int *arr, int l, int m, int r){
	int lSize = m - l +1;
	int rSize = r - m;

	int *left = malloc(lSize * sizeof(int));
	int *right = malloc(rSize * sizeof(int));

	int i;

	// fill in temp arrays
	for(i = 0; i < rSize; i++){
		left[i] = arr[l+i];
		right[i] = arr[m+i+1];
	}
	left[lSize-1] = arr[l+lSize-1];


	// update arr
	i = 0;
	int j = 0, k = l;

	while(i < lSize && j < rSize){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}

		k++;
	}

	while(i < lSize){
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j < rSize){
		arr[k] = right[j];
		j++;
		k++;
	}

	free(left);
	free(right);

	return;
}





void	mergeSortRec(int *arr, int l, int r){

	if(l < r){
		int m = l + (r-l)/2;	// avoid overflow
		mergeSortRec(arr, l, m);
		mergeSortRec(arr, m+1, r);
		merge(arr, l, m, r);
	}


	return;
}



void	mergeSort(int *arr, int n){
	mergeSortRec(arr, 0, n-1);
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


	mergeSort(arr, n);

	for(i = 0; i < n; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");

	return 0;

}
