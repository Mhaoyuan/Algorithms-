//
// Created by genius on 18-8-15.
//

#include <iostream>
#include <vector>
#include "SortHelp.h"

using namespace std;

template <typename T>
void SelectionSort(vector<T> &vec, int n){
    for(int i = 0; i < n ;i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if(vec[j] <vec[minIndex])
                minIndex = j;
        }
        swap(vec[i],vec[minIndex]);
    }

}

