//
//  Algorithm.hpp
//  MVector
//
//  Created by Andrey Stalnoy on 2/26/19.
//  Copyright © 2019 SmartSol. All rights reserved.
//

#ifndef Algorithm_hpp
#define Algorithm_hpp

#include <stdio.h>

class Algorithm{
public:
    template <typename T, int N> static int getPeakIndex();
    static void quickSort();

};
#endif /* Algorithm_hpp */
