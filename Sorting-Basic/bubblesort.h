//
// Created by genius on 18-8-15.
//

#ifndef ALGORITHMS_BUBBLESORT_H
#define ALGORITHMS_BUBBLESORT_H

#include<vector>
using namespace std;
template<typename T>
void bubblesort(vector<T>& vec, int n){
    bool swapped;
    do{
        swapped = false;
        for(int i =1; i < n; i++)
        {
            if(vec[i-1]> vec[i]){
                swap(vec[i-1], vec[i]);
                swapped = true;
            }

        }
        n--;
    }while(swapped);
}
template<typename T>
void bubblesort1(vector<T> &vec, int n){
    int newn;
    do{
         newn=0;
        for (int i= 1; i < n;i++)
        {
            if(vec[i-1] > vec[i]){
                swap(vec[i-1],vec[i]);

                newn = i;
            }

        }
        n = newn;
    }while(newn > 0);
}



#endif //ALGORITHMS_BUBBLESORT_H
