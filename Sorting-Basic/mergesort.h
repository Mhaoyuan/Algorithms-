//
// Created by genius on 18-8-16.
//

#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H

#include <vector>
using  namespace std;
template<typename T>
void __merge(vector<T> &vec, int l, int mid, int r){
    vector<T>temp(r-l+1);
    for(int i = l; i <=r; i++){
        temp[i-l] = vec[i];
    }

    int i = l; int j = mid + 1;
    for(int k = l; k<=r ;++k){

        if (i> mid) {
            vec[k] = temp[j-l];
            j++;
        }
        else if(j > r){
            vec[k] = temp[i-l];
            i++;
        }
        else if(temp[i-l] < temp[j-l]){
            vec[k] = temp[i-l];
            i++;
        }
        else{
            vec[k] = temp[j-l];
            j++;
        }

    }

}






template<typename T>
void __mergesort1(vector<T> &vec , int l, int r){
    if (r-l<=15) {
        insertionsort1(vec, l, r);
        return;
    }
    int mid= (r +l)/2;
    __mergesort1(vec,l,mid);
    __mergesort1(vec,mid+1,r);
    __merge(vec,l, mid, r);
}
template<typename T>
void __mergesort(vector<T> &vec , int l, int r){
    if (l>=r) {
        return;
    }
    int mid= (r +l)/2;
    __mergesort(vec,l,mid);
    __mergesort(vec,mid+1,r);
    __merge(vec,l, mid, r);
}



template<typename T>
void mergesort(vector<T> &vec, int n){
    __mergesort(vec, 0, n-1);
}



#endif //ALGORITHMS_MERGESORT_H
