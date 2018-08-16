//
// Created by genius on 18-8-15.
//

#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H

#include <vector>

using namespace std;

template <typename T>
void insertionsort(vector <T> &vec,int n){
    for(int i =1;i < n;i++){
        for(int j = i; j > 0 && vec[j] < vec[j-1]; j--){
            swap(vec[j], vec[j-1]);
        }
    }
    return;
}
template <typename T>
void insertionsort1(vector<T> &vec,int n){
    for (int i =i; i< n; i++)
    {
        T e = vec[i];
        int j;
        for(j = i;j < n && vec[j-1] >e ;j--)
        {
            vec[j] = vec[j-1];
        }
        vec[j] = e;
    }
    return;

}

template <typename T>
void insertionsort1(vector<T> &vec, int l, int r){
    for(int i = l+1;i <=r; i++){
        T e = vec[i];
        int j;
        for (j = i;j > l&& vec[j-1]>e;j--)
            vec[j] = vec[j-1];
        vec[j] = e;
    }
    return;
}
#endif //ALGORITHMS_INSERTIONSORT_H
