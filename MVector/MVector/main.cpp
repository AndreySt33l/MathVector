//
//  main.cpp
//  MVector
//
//  Created by Andrey Stalnoy on 2/10/19.
//  Copyright © 2019 SmartSol SER. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename T, int N>
class MathVector
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
    
    /*Peak search*/
    int findPeakUtil(int arr[], int low, int high, int n)
    {
        // Find index of middle element
        int mid = low + (high - low)/2;  /* (low + high)/2 */
        
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
    
    /*Quick Sort*/
    
    // A utility function to swap two elements
    void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    
    /* This function takes last element as pivot, places
     the pivot element at its correct position in sorted
     array, and places all smaller (smaller than pivot)
     to left of pivot and all greater elements to right
     of pivot */
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
    
    /* The main function that implements QuickSort
     arr[] --> Array to be sorted,
     low  --> Starting index,
     high  --> Ending index */
    void quickSort(T arr[], int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
             at right place */
            int pi = partition(arr, low, high);
            
            // Separately sort elements before
            // partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    /*Overloaded operators*/
    // Vector Out
    template <typename U, int I>
    friend ostream & operator << (ostream &, const MathVector<U, I> &);
    // Addition
    template <typename U, int I>
    friend MathVector<U,I> operator + (MathVector<U, I> const &, MathVector<U, I> const &);
    // Subtraction
    template <typename U, int I>
    friend MathVector<U,I> operator - (MathVector<U, I> const &, MathVector<U, I> const &);
    // Multiplication (scalar * vector)
    template <typename U, int I, typename O>
    friend MathVector<U,I> operator * (O const &, MathVector<U, I> const &);
    // Multiplication (vectro * scalar)
    template <typename U, int I, typename O>
    friend MathVector<U, I> operator * (MathVector<U, I> const &, O const &);
    
};

/*Realization*/
// Out--------------------
template <typename U, int I>
ostream & operator << (ostream &out, const MathVector<U, I> &mv)
{
    out << "{";
    for (int i = 0; i != mv.getDimension(); i++) {
        if(i < mv.getDimension()-1) out << mv.getElement(i) << ", ";
        else out << mv.getElement(i);
    }
    out << "}" << endl;
    return out;
}
// Addition----------------
template <typename U, int I>
MathVector<U, I> operator + (MathVector<U, I> const &mv1, MathVector<U, I> const &mv2) {
    U array[I];
    for (int i = 0; i < I; i++){
        array[i] = mv1.getElement(i) + mv2.getElement(i);
    }
    
    MathVector<U, I> mvres;
    mvres.setMathVector(array);
    
    return mvres;
}
// Subtraction----------------
template <typename U, int I>
MathVector<U, I> operator - (MathVector<U, I> const &mv1, MathVector<U, I> const &mv2) {
    U array[I];
    for (int i = 0; i < I; i++){
        array[i] = mv1.getElement(i) - mv2.getElement(i);
    }
    
    MathVector<U, I> mvres;
    mvres.setMathVector(array);
    
    return mvres;
}
// Multiplication (scalar * vector)
template <typename U, int I, typename O>
MathVector<U, I> operator * (O const &scalar, MathVector<U, I> const &mv2) {
    U array[I];
    for (int i = 0; i < I; i++){
        array[i] = scalar * mv2.getElement(i);
    }
    
    MathVector<U, I> mvres;
    mvres.setMathVector(array);
    
    return mvres;
}
// Multiplication (vector * scalar)
template <typename U, int I, typename O>
MathVector<U, I> operator * (MathVector<U, I> const &mv2, O const &scalar) {
    U array[I];
    for (int i = 0; i < I; i++){
        array[i] = scalar * mv2.getElement(i);
    }
    
    MathVector<U, I> mvres;
    mvres.setMathVector(array);
    
    return mvres;
}


int main(int argc, const char * argv[]) {
    int const size = 4;
    int array [size] = {1,2,6,4};
    
    MathVector<int, size> mv;
    
    cout << mv.getDimension() << endl;
    
    mv.setMathVector(array);
    
    cout << mv.getElement(mv.getPeakIndex()) << endl;
    
    mv.quickSort(array, 0, size-1);
    mv.displayArray(array, size);
    
    return 0;
}
