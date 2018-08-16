//
// Created by genius on 18-8-16.
//

#include <iostream>
#include <time.h>
#include "heap.h"
using namespace std;
//int main() {
//    MaxHeap<int> heap = MaxHeap<int>(100);
//    srand(time(NULL));
//
//    int n = 100;
//    for (int i = 0; i < n; i++) {
//        heap.insert(rand() % 100);
//    }
//    MaxHeap<int> heap1(heap);
//    vector<int> vec(100);
//    for (auto &e:vec) {
//        e = heap.extractMax();
//        cout << e << " ";
//    }
//    cout << endl;
//
//
//
//    for (int i =1; i< vec.size();++i)
//        assert(vec[i-1] >= vec[i]);
//
//    vector<int> vec1(100);
//    for (auto &e:vec1){
//        e = heap1.extractMax();
//        cout << e << " ";
//    }
//
//
//
//}