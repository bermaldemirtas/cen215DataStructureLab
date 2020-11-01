#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void printArray(int arr[], int x) {

	int i;
	for (i = 0; i < x; i++)
	printf("%d", arr[i]);
	printf("\n", arr[i]);
}
void printArray_ch(char arr[], int x) {

	int i;
	for (i = 0; i < x; i++)
	printf("%c", arr[i]);
	printf("\n", arr[i]);
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void swap_ch(char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}
/* Insertion Sort */
void insertionSort(int arr[], int k) {
	int i, key, j;
	for (i = 1; i < k; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void insertionSort_ch(char array[], int k)
{
	int i, j;
	char key;
	for (i = 1; i < k; i++) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}


/* Selection Sort */
void SelectionSort(int array[],int size)
{
	int j,i;
	int currentmin;
	for ( i = 0; i < size - 1; i++)
	{
		currentmin = i;
		for ( j = i + 1; j < size; j++)
		{
			if(array[j]<array[currentmin])
			{
				currentmin = j;
			}
		}
		swap(&array[currentmin], &array[i]);
	}
}

void SelectionSort_ch(char array[], int size)
{
	int i, j;
	char min;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		swap_ch(&array[min], &array[i]);
	}
}


/* HeapSort */
void Heapify(int num[], int size, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (num[l] > num[largest] && l < size)
		largest = l;
	if (num[r] > num[largest] && r < size)
		largest = r;
	if (largest != i) {

		swap(&num[i], &num[largest]);
		Heapify(num, size, largest);
	}
}
void HeapSort(int num[], int size) {
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
		Heapify(num, size, i);
	for (i = size - 1; i > 0; i--) {
		swap(&num[0], &num[i]);
		Heapify(num, i, 0);
	}

}
void HeapifyChar(char name[], int size, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (name[l] > name[largest] && l < size)
		largest = l;
	if (name[r] > name[largest] && r < size)
		largest = r;
	if (largest != i) {

		swap_ch(&name[i], &name[largest]);
		HeapifyChar(name, size, largest);
	}
}
void HeapSort_Ch(char name[], int size) {
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
		HeapifyChar(name, size, i);
	for (i = size - 1; i > 0; i--) {
		swap_ch(&name[0], &name[i]);
		HeapifyChar(name, i, 0);
	}
}
/* Quick Sort */
int QuickSort(int num[], int low, int high)
{
	int pivot = num[high];
	int i = (low - 1);
	int j;
	for (j = low; j <= high - 1; j++)
	{
		if (num[j] <= pivot)
		{
			i++;
			swap(&num[i], &num[j]);
		}
	}
	swap(&num[i + 1], &num[high]);
	return (i + 1);
}
void quickSort(int num[], int low, int high)
{
	if (low < high)
	{
		int pi = QuickSort(num, low, high);
		quickSort(num, low, pi - 1);
		quickSort(num, pi + 1, high);
	}
}

int QuickSortChar(char name[], int low, int high)
{
	int pivot = name[high];
	int i = (low - 1);
	int j;
	for (j = low; j <= high - 1; j++)
	{
		if (name[j] <= pivot)
		{
			i++;
			swap_ch(&name[i], &name[j]);
		}
	}
	swap_ch(&name[i + 1], &name[high]);
	return (i + 1);
}
void quickSort_Ch(char name[], int low, int high)
{
	if (low < high)
	{
		int pi = QuickSortChar(name, low, high);
		quickSort_Ch(name, low, pi - 1);
		quickSort_Ch(name, pi + 1, high);
	}
}

//Merge Sort 
void merge(int arr[], int l, int m, int r)
{
	int i, a, b;
	int p1 = m - l + 1;
	int p2 = r - m;

	int L[p1];
	int R[p2];

	for (i = 0; i < p1; i++)
		L[i] = arr[l + i];
	for (a = 0; a < p2; a++)
		R[a] = arr[m + 1 + a];

	i = 0;
	a = 0;
	b = l;
	while (i < p1 && a < p2)
	{
		if (L[i] <= R[a])
		{
			arr[b] = L[i];
			i++;
		}
		else
		{
			arr[b] = R[a];
			a++;
		}
		b++;
	}

	while (i < p1)
	{
		arr[b] = L[i];
		i++;
		b++;
	}

	while (a < p2)
	{
		arr[b] = R[a];
		a++;
		b++;
	}
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* Bubble Sort */


void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
void bubbleSort_ch(char array[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (array[j] > array[j + 1])
				swap_ch(&array[j], &array[j + 1]);
}
/*End of Bubble Sort*/
void mergeChar(char arr[], int a, int b, int c)
{
    int j,i , m, k, n;

    m = b - a + 1;

    n = c - b;

    int A[m], B[n];

    for (i = 0; i < m; i++)

        A[i] = arr[a + i];
    for (j = 0; j < n; j++)


        B[j] = arr[b + 1 + j];
    i = 0;
    j = 0;
    k = a;

    while (i < m && j < n)
    {
        if (A[i] <= B[j])
        {
            arr[k] = A[i];
            i++;
        }
        else {
            arr[k] = B[j];
            j++;
        }
        k++;
    }

    while (i < m)
    {
        arr[k] = A[i];
        i++;
        k++;
    }

    while (j < n) {
        arr[k] = B[j];
        j++;
        k++;
    }
}

void mergeSort_Ch(char arr[], int r, int l)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort_Ch(arr, l, m);
        mergeSort_Ch(arr, m + 1, r);
        mergeChar(arr, l, m, r);
    }
}

int main(int argc, char const* argv[])
{
	

	int num[] = {2,0,1,8,5,5,6,0,2,1};
	char name[] = "Bermal Demirtas";
	int size = sizeof(num) / sizeof(num[0]);
	int sizename= strlen(name);
	clock_t c1, c2;
	double timeresult;


	//insertionsort
	/* timer */
	c1 = clock();
	insertionSort(num, size);
	/* timer */
	printArray(num, size);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeresult);

	c1 = clock();
	insertionSort_ch(name, sizename);
	/* timer */
	printArray_ch(name, sizename);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeresult);
	printf("Result of InsertionSort\n\n\n");
	//end of insertionsort
	
	//selectionsort
	/* timer */
	c1 = clock();
	SelectionSort(num, size);
	/* timer */
	printArray(num, size);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeresult);
	c1 = clock();	
	SelectionSort_ch(name, sizename);
	/* timer */
	printArray_ch(name, sizename);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	//print time
	printf("Time = %f\n", timeresult);
	printf("Result of SelectionSort\n\n\n");
	//end of selectionsort
	
	//bublesort
	/* timer */
	c1 = clock();
	bubbleSort(num, size);
	/* timer */
	printArray(num, size);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeresult);
	c1 = clock();
	bubbleSort_ch(name, sizename);
	/* timer */
	printArray_ch(name, sizename);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeresult);
	printf("Result of BubbleSort\n\n\n");
	//end of bubblesort
	
	//merge sort
	/* timer */
	c1 = clock();
	mergeSort(num,0, size-1);
	/* timer */
	printArray(num, size);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeresult);
	c1 = clock();
	mergeSort_Ch(name,0, sizename-1);
	/* timer */
	printArray_ch(name, sizename);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeresult);
	printf("Result of MergeSort\n\n\n");
	//end of mergesort

	//HeapSort
	/* timer */
	c1 = clock();
	HeapSort(num,size);
	/* timer */
	printArray(num, size);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeresult);
	c1 = clock();
	HeapSort_Ch(name,sizename);
	/* timer */
	printArray_ch(name, sizename);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeresult);
	printf("Result of HeapSort\n\n\n");
	//end of HeapSort

	//quick sort
	/* timer */
	c1 = clock();
	quickSort(num, 0, size - 1);
	/* timer */
	printArray(num, size);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeresult);
	c1 = clock();
	quickSort_Ch(name, 0, sizename - 1);
	/* timer */
	printArray_ch(name, sizename);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeresult);
	printf("Result of QuickSort\n\n\n");
	//end of quicksort

	
	return 0;
}
