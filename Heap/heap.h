//
// Created by genius on 18-8-16.
//

#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H

#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <assert.h>
//#include <bits/valarray_after.h>

using namespace std;
template <typename Item>
class MaxHeap{
private:
    Item *data;
    int size;
    int capacity;

    void shiftup(int k);
    void shiftdown(int k);

public:
    MaxHeap(int capacity);
    MaxHeap(const MaxHeap& heap);
    MaxHeap& operator=(const MaxHeap& heap);
    MaxHeap(const vector<Item>&vec, int n);
    ~MaxHeap(){delete[] data;}
    ssize_t getcapacity() const { return capacity;}
    ssize_t getsize() const {return size;}
    void insert(Item item);
    Item extractMax();
    Item getMax() const {return data[1];}

};

template <typename Item>
inline MaxHeap<Item>::MaxHeap(int capacity) {
    if (capacity < 0)
        return ;
    data = new Item[capacity+1];
    size = 0;
    this->capacity = capacity;
}
template <typename Item>
inline MaxHeap<Item>::MaxHeap(const MaxHeap &heap) {
    capacity = heap.getcapacity();
    data = new Item[capacity+1];
//    memcpy(data,heap.data,capacity+1);
        for (int i =1; i<= heap.getsize();i++)
            data[i] = heap.data[i];
    size = heap.size;

}
template <typename Item>
inline
MaxHeap<Item>::MaxHeap(const vector<Item>& vec, int n) {
    data = new Item[n+1];
    capacity = n;
    for(int i = 0; i< n; i++)
        data[i+1] = vec[i];
    size = n;

    for (int i = size/2; i >=1 ;i--)
        shiftdown(i);
}



template <typename Item>
inline MaxHeap<Item>& MaxHeap<Item>::operator=(const MaxHeap& heap){
    if(data = &heap)
        return *this;
    delete[] data;
    data = new Item[heap.capacity+1];
    for(int i =1 ;i <= heap.getsize(); i++)
        data[i] = heap.data[i];
    capacity = heap.capacity;
    size = heap.size;
    return *this;
}
template <typename Item>
inline void MaxHeap<Item>::shiftup(int k) {
    while(k > 1 && data[k/2] < data[k]){
        swap(data[k/2],data[k]);
        k /=2;
    }
}
template <typename Item>
inline void MaxHeap<Item>::insert(Item item) {
    assert(size+1 <= capacity);
    data[size+1] = item;
    size++;
    shiftup(size);
}
template <typename Item>
inline void MaxHeap<Item>::shiftdown(int k) {
    while (2 * k<= size)
    {
        int j = 2*k;
        if(j+1<=size && data[j+1] > data[j])
            j++;
        if(data[k] > data[j])
            break;
        swap(data[k],data[j]);
        k = j;
    }
}
template <typename Item>
inline
Item MaxHeap<Item>::extractMax(){
    assert(size > 0);
    Item ret = data[1];
    swap(data[1], data[size]);
    size--;
    shiftdown(1);
    return ret;
}


template <typename Item>
inline
void heapsort1(vector<Item> &vec, int n){
    MaxHeap<Item> maxheap = MaxHeap<Item>(n);
    for (const auto &e: vec)
        maxheap.insert(e);
    for (int i =n-1 ;i >=0; i--)
        vec[i] = maxheap.extractMax();
}

template <typename Item>
void heapsort2(vector<Item> &vec, int n){
    MaxHeap<Item> maxheap(vec,n);
    for (int i =n -1; i>=0; i--)
        vec[i] = maxheap.extractMax();
}





#endif //ALGORITHMS_HEAP_H
