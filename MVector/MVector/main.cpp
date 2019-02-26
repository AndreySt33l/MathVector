//
//  main.cpp
//  MVector
//
//  Created by Andrey Stalnoy on 2/10/19.
//

#include "MathVector.hpp"
#include <iostream>

using namespace std;

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
