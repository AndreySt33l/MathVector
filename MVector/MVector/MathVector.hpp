//
//  MathVector.hpp
//  MVector
//
//  Created by Andrey Stalnoy on 2/26/19.
//

#ifndef MathVector_hpp
#define MathVector_hpp

#include <stdio.h>
#include <iostream>

template <typename T, int N>
class MathVector {
private:
    T mathvector[N];
public:
    /*Default Constructor*/
    MathVector() {};
    
    /*Constructor which takes an array*/
    MathVector(T array[N])
    {
        for (int i = 0; i < N; i++) mathvector[i] = array[i];
    };
    
    /*Get the size of mathvector*/
    int getDimension() const
    {
        return N;
    };
    
    /*Get the element of mathvector*/
    T getElement(int i) const
    {
        return mathvector[i];
    };
    
    /*Setter*/
    void setVector(T array[N])
    {
        //std::cout << "Setting vector..." << std::endl;
        for (int i = 0; i < N; i++) mathvector[i] = array[i];
        //std::cout << "Vector had been set" << std::endl;
    };
    
    /*Showing the vector*/
    void displayVector()
    {
        std::cout << "{";
        for (int i = 0; i < N; i++) {
            if (i == N-1){
                std::cout << mathvector[i];
            }
            else
                std::cout << mathvector[i] << ", ";
        }
        std::cout << "}" << std::endl;
    };
    
    /*Overloaded operators*/
    // Vector Out
    template <typename U, int I>
    friend std::ostream & operator << (std::ostream &, const MathVector<U, I> &);
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

// Out--------------------
template <typename U, int I>
std::ostream & operator << (std::ostream &out, const MathVector<U, I> &mv)
{
    out << "{";
    for (int i = 0; i != mv.getDimension(); i++) {
        if(i < mv.getDimension()-1) out << mv.getElement(i) << ", ";
        else out << mv.getElement(i);
    }
    out << "}" << std::endl;
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
    mvres.setVector(array);
    
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
    mvres.setVector(array);
    
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
    mvres.setVector(array);
    
    return mvres;
}

#endif /* MathVector_hpp */
