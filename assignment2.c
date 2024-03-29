#include<stdio.h>
#include<time.h>
void swap(int *variable1, int *variable2){ //pass the address of the variables to swap
	int temp;
	temp=*variable1;
	*variable1=*variable2;
	*variable2=temp;
}
void bubbleSort(int *array, int size){
	int sortIndex, unsortIndex;
	for (sortIndex = 0; sortIndex < (size-1); ++sortIndex)
	{
		for (unsortIndex = 0; unsortIndex < (size-(sortIndex+1)); ++unsortIndex)
		{
			if (array[unsortIndex]>array[unsortIndex+1])
			{
				swap(&array[unsortIndex], &array[unsortIndex+1]);
			}
		}
	}      
}

void merge(int *array, int leftElementIn, int mergeElementIn, int rightElementIn){
	int n1 = mergeElementIn-leftElementIn+1;
	int n2 = rightElementIn-mergeElementIn;//r-(m+1)+1;
	int leftArr[n1], rightArr[n2];
	int leftIndex,rightIndex,mergeIndex;
	/* Copy data to temp arrays leftArr[] and R[] */
    for (leftIndex = 0; leftIndex < n1; leftIndex++)
        leftArr[leftIndex] = array[leftElementIn + leftIndex];
    for (rightIndex = 0; rightIndex < n2; rightIndex++)
        rightArr[rightIndex] = array[(mergeElementIn + 1) + rightIndex];
	leftIndex = 0; // Initial index of first or left subarray
    rightIndex = 0; // Initial index of second or right subarray
    mergeIndex = leftElementIn; // Initial index of merged subarray
    while(leftIndex<n1 && rightIndex<n2){
    	if (leftArr[leftIndex]<=rightArr[rightIndex])
    	{
    		array[mergeIndex] = leftArr[leftIndex];
    		leftIndex++;
    	} else{
    		array[mergeIndex] = rightArr[rightIndex];
    		rightIndex++;
    	}
    	mergeIndex++;
    }
    while (leftIndex < n1) { // right is empty
        array[mergeIndex] = leftArr[leftIndex];
        leftIndex++;
        mergeIndex++;
    }
    while (rightIndex < n2) { // left is empty
        array[mergeIndex] = rightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
    }
}
void mergeSort(int *array, int leftElementIn, int rightElementIn){//recursive function
	int mergeElementIn;
	/* leftElementIn is for left index and r is right index of the sub-array of arr to be sorted 
	 split if there are more than 1 elements: when leftElementIn<rightElementIn */
	if (leftElementIn < rightElementIn)
	{
		/* split the array and length = (r-l)+1
		we will use (l+r)/2 */
		mergeElementIn = (leftElementIn+rightElementIn)/2;
		// call mergeSort() for left subarray
		mergeSort(array, leftElementIn, mergeElementIn);
		// call mergeSort() for right subarray
		mergeSort(array, mergeElementIn+1, rightElementIn);
		// merge the left and right subarray
		merge(array, leftElementIn, mergeElementIn, rightElementIn);
	}
}
int printArray(int *array, int size){
	int count;
	for (count = 0; count < size; ++count)
	{
		// printf("\narray[%d] = %d", count, array[count]);
		printf("\narray[%d] = %d", count, *(array+count));
	}
	return (count+1);// returns the number of elements printed
}
int getInput(int *array, int size){
	int count;
	for (count = 0; count < size; ++count)
	{
		printf("Enter array[%d]=",count);
		scanf(" %d", (array+count));
	}
	return (count+1);// returns the number of elements read
}

int main()
{
	int arr[10];
    
    printf("\n\t\t\t\tWelcome back Parmeet Kour\n");
    printf("\nHint : You can take these values as input\n 1, 3, 42, 2, 41, 66, 66, 33, 98, 0\n\n");
    getInput(arr, 10);
	clock_t begin = clock();
    bubbleSort(arr, 10);
    printArray(arr, 10);
    printf("\n\n");
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Bubble sort took time for the processing : %f ms\n", time_spent * 1000);
    printf("\n\n");
    begin = clock();
    mergeSort(arr, 0, 9);
    printArray(arr, 10);
    printf("\n\n");
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Merge sort took time for the processing : %f ms\n", time_spent * 1000);
    return 0;
}

// Explanation : Which algorithm is more efficient and faster?
/* Time complexity for Merge-sort is O(n log n) and Bubble Sort is O(n) for the best case
while for the worst case time complexity is O(n log n) and O(n^2) respectively.
As it is also observed that the more time efficiency you have, the less space efficiency you have and vice versa. 
However Merge-sort needs an auxiliary extra space to sort and cause more memory access therefore requires less time 
for the execution i.e has best time efficiency. On the other hand, Bubble-sort may perform better for small data-set 
but also requires less space which takes time for the execution and is less time efficient than Merge-sort. 
Therefore the efficiency of Bubble sort decreases while working with large data sets. So for any reasonable size data 
Merge-sort will outperform Bubble sort. */