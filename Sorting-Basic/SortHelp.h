//
// Created by genius on 18-8-15.
//

//
// Created by genius on 18-7-24.
//

#ifndef PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H
#define PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H

#include<iostream>
#include<ctime>
#include<cassert>
#include<vector>
using namespace std;

namespace SortTestHelper{
    vector<int>generateRandomArray (int n, int rangeL, int rangeR)
    {
        assert(rangeL< rangeR);
        vector<int> vec(n);
        srand(time(NULL));
        for (auto &v : vec)
        {
            v = rand() % (rangeR -rangeL +1) + rangeL;
        }
        return vec;
    }
    template <typename T>
    void printVec(vector<T> vec, int n)
    {
        for(auto &v:vec)
            cout << v << " ";
        cout << endl;
        return;
    }
    template<typename T>
    bool isSort(const vector<T>&vec,int n)
    {
        for(int i =0 ;i< n-1;++i)
            if (vec[i]>vec[i+1])
                return false;
        return true;
    }

    template <typename T>
    void testSort(string name, void(*sort)(vector<T>&,int),vector<T>& vec, int n)
    {
        clock_t startTime = clock();
        sort(vec,n);
        clock_t endTime =clock();
        bool ex = isSort(vec,vec.size());
        cout << name <<":"<< double(endTime-startTime) /CLOCKS_PER_SEC <<" "<< ""<< "isSort: "<< ex<< endl ;
        return;

    }



}
#endif //PLAY_WITH_ALGORITHMS_SORTTESTHELPER_H