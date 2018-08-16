//
// Created by genius on 18-8-16.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H

#include <vector>
using namespace std;
template <typename T>
int __partition(vector<T>& vec, int l, int r){
    swap(vec[l], vec[rand()%(r-l+1) + l]);
    T v = vec[l];
    int j=l;
    for (int i = l+1;i <=r;i++)
        if(vec[i] < v)
        {
            j++;
            swap(vec[i],vec[j]);
        }
        swap(vec[l], vec[j]);
    return j;


}
template <typename T>
int __partition1(vector<T>&vec, int l, int r){
    swap(vec[l], vec[rand()%(r-l+1)+l]);
    T v = vec[l];
    int i = l+1;
    int j = r;
    while(1){
    while(i<=r && vec[i] < v)
        ++i;
    while(j>=l+1 && vec[j]> v)
        --j;
    if(i>j)
        break;
    swap(vec[i], vec[j]);
    ++i;
    --j;
    }
    swap(vec[l],vec[j]);
    return j;

}


template <typename T>
void __quicksort(vector<T> &vec,int l, int r){
    if(l>=r)
        return;
    int mid = __partition(vec,l,r);
    __quicksort(vec,l,mid-1);
    __quicksort(vec,mid+1,r);
}

template <typename T>
void __quicksort1(vector<T> &vec,int l, int r){
    if(r-l <= 15) {
        insertionsort1(vec,l,r);
        return;
    }
    int mid = __partition1(vec,l,r);
    __quicksort(vec,l,mid-1);
    __quicksort(vec,mid+1,r);
}



template <typename T>
void quicksort(vector<T>&vec,int n){
//    __quicksort(vec,0,n-1);
    __quicksort1(vec,0,n-1);
}


template <typename T>
void __quicksort3ways(vector<T>& vec, int l, int r) {


    if (r - l <= 15){
        insertionsort1(vec,l,r);
        return;
    }
    swap(vec[l], vec[rand()%(r-l+1) +l ]);
    T v = vec[l];

    int lt =l;
    int gt = r + 1;
    int i = l + 1;
    while(i < gt){
        if(vec[i] < v){
            swap(vec[i],vec[lt+1]);
            i++;
            lt++;
        }

        else if (vec[i] > v)
        {
            swap(vec[i],vec[gt-1]);
            gt--;
        }
        else i++;
    }

    swap(vec[l], vec[lt]);

    __quicksort3ways(vec,l,lt-1);
    __quicksort3ways(vec,gt,r);
}

template <typename T>
void quicksort3ways(vector<T> &vec, int n){
    __quicksort3ways(vec, 0,n-1);
}

#endif //ALGORITHMS_QUICKSORT_H
