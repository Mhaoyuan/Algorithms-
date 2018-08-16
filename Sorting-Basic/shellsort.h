//
// Created by genius on 18-8-15.
//

#ifndef ALGORITHMS_SHELLSORT_H
#define ALGORITHMS_SHELLSORT_H

#include <vector>
using namespace std;
template <typename T>
void shellsort(vector<T> &vec, int n){
    int h = 1 ;
    while(h < n/3)
        h = 3 * h +1;        //1,4,13,40,121
    while(h >= 1){
        for (int i = h; i < n;++i ){
            T e = vec[i];
            int j;
            for(j = i ; i >=h && e < vec[j -h];j-=h)
                vec[j] = vec[j-h];
            vec[j]=e;
        }
        h/=3;
    }
}
#endif //ALGORITHMS_SHELLSORT_H
