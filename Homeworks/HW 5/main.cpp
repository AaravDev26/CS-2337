// Aarav Dev
// axd220001

#include <iostream>

using namespace std;

int compCounter = 0;
int SwapCounter = 0;
int counter = 0;

int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int main()
{
    int arr1[5000];
    int arr2[5000];
    int arr3[5000];
    int arr4[5000];
    int arr5[5000];
    for (int i = 0; i < 5000; i++)
    {
        int r = rand() % 100000;
        arr1[i] = r;
        arr2[i] = r;
        arr3[i] = r;
        arr4[i] = r;
        arr5[i] = r;
    }
    // sorting first array with bubble sort
    int comps1 = 0;
    int swaps1 = 0;
    for (int i = 0; i < 4999; i++)
    {
        for (int j = 0; j < 4999 - i; j++)
        {
            comps1++;
            if (arr1[j] > arr1[j+1])
            {
                swap(arr1[j], arr1[j + 1]);
                swaps1++;
            }
        }
    }
    cout << "Bubble Sort: " << comps1 << " Element Comparisons and " << swaps1 << " Swaps" << endl;
    
    // sorting second array with selection sort
    int comps2 = 0;
    int swaps2 = 0;
    for (int i = 0; i < 5000; i++)
    {
        int min = i;
        int old = min;
        for (int j = i + 1; j < 5000; j++)
        {
            if (arr2[j] < arr2[min])
            {
                min = j;
            }
            comps2++;
        }
        if (old != min)
        {
            swap(arr2[min], arr2[i]);
            swaps2++;                         
        }
    }
    cout << "Selection Sort: " << comps2 << " Element Comparisons and " << swaps2 << " Swaps" << endl;
    
    // sorting third array with insertion sort
    int comps3 = 0;
    int swaps3 = 0;
    for (int i = 1; i < 4999; i++)
    {
        int j = i;
        while (j > 0)
        {
            comps3++;
            if (arr3[j - 1] > arr3[j])
            {
                swap(arr3[j], arr3[j - 1]);
                swaps3++;
                j--;
            }
            else
            {
                break;
            }
        }
    }
    cout << "Insertion Sort: " << comps3 << " Element Comparisons and " << swaps3 << " Swaps" << endl;
    
    // sorting fourth array with quick sort
    quickSort(arr4, 0, 4999);
    cout << "Quick Sort: " << compCounter << " Element Comparisons and " << SwapCounter << " Swaps" << endl;
    
    // sorting linked list with merge sort
    mergeSort(arr5, 0, 4999);
    cout << "Merge Sort: " << counter << " Element Comparisons" << endl;
    return 0;
}

int partition(int array[], int low, int high) 
{ 
    int pivot = array[high];  
    int i = (low-1); 
    for (int j = low; j < high; j++) 
    {
        compCounter++;
        if (array[j] <= pivot) 
        { 
            i++; 
            int temp = array[i]; 
            array[i] = array[j]; 
            array[j] = temp; 
            SwapCounter++;
        } 
    } 

    int temp = array[i+1]; 
    array[i+1] = array[high]; 
    array[high] = temp; 
    SwapCounter++;

    return i+1; 
} 

void quickSort(int array[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pivotPoint = partition(array, low, high); 
        quickSort(array, low, pivotPoint-1); 
        quickSort(array, pivotPoint+1, high); 
    } 
} 

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        counter++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
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


