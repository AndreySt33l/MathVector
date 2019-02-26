//
//  main.cpp
//  MVector
//
//  Created by Andrey Stalnoy on 2/10/19.
//

#include "MathVector.hpp"
#include <iostream>

using namespace std;

/*template <typename T, int N>
class MathVectorsa
{
private:
    T mathVector[N];
public:
    T getElement(int i) const { return mathVector[i]; }
    
    int getDimension() const { return N; }
    
    void displayArray(T array[], int size) {
        for (int i = 0; i < size; i++)
            cout << array[i] << " ";
        cout << endl;
    }
    
    void setMathVector(T array[N]) {
        for (int i = 0; i < N; i++) mathVector[i] = array[i];
    }
    

    int findPeakUtil(int arr[], int low, int high, int n)
    {
        // Find index of middle element
        int mid = low + (high - low)/2;  // (low + high)/2
        
        // Compare middle element with its neighbours (if neighbours exist)
        if ((mid == 0 || arr[mid-1] <= arr[mid]) &&
            (mid == n-1 || arr[mid+1] <= arr[mid]))
            return mid;
        
        // If middle element is not peak and its left neighbour is greater
        // than it, then left half must have a peak element
        else if (mid > 0 && arr[mid-1] > arr[mid])
            return findPeakUtil(arr, low, (mid -1), n);
        
        // If middle element is not peak and its right neighbour is greater
        // than it, then right half must have a peak element
        else return findPeakUtil(arr, (mid + 1), high, n);
    }
    
    // A wrapper over recursive function findPeakUtil()
    int getPeakIndex()
    {
        T arr[N];
        for (int i = 0; i < N; i++) arr[i] = mathVector[i];
        
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
        cout << endl;
        
        int n = sizeof(arr)/sizeof(arr[0]);
        
        return findPeakUtil(arr, 0, n-1, n);
    }
    
    Quick Sort
    
    // A utility function to swap two elements
    void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    
    /This function takes last element as pivot, places
     the pivot element at its correct position in sorted
     array, and places all smaller (smaller than pivot)
     to left of pivot and all greater elements to right
     of pivot
    int partition (T arr[], int low, int high)
    {
        int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element
        
        for (int j = low; j <= high- 1; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot)
            {
                i++;    // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    
    /The main function that implements QuickSort
     arr[] --> Array to be sorted,
     low  --> Starting index,
     high  --> Ending index
    void quickSort(T arr[], int low, int high)
    {
        if (low < high)
        {
             pi is partitioning index, arr[p] is now
             at right place
            int pi = partition(arr, low, high);
            
            // Separately sort elements before
            // partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
 */

int main(int argc, const char * argv[]) {
    int const size = 4;
    int array [size] = {1,2,6,4};
    
    MathVector<int, size> mv1;
    mv1.setVector(array);
    mv1.displayVector();
 
    
    MathVector<int, size> mv2(array);
    mv2.displayVector();
    
    cout << mv1 + mv2;
    cout << mv1 * 3;
    cout << mv2 + mv1 * 3;
    return 0;
}
