//
// Created by genius on 18-8-16.
//
#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
#include "bst.h"
#include "FileOps.h"
#include "SequenceST.h"

using namespace std;

//二分查找法，在有序数字vec中查找target
//如果找到target，返回相应的索引index
//若果没有找到target，返回-1

template <typename T>
int binarySearch(const vector<T>&vec, int n ,T target){
    // vec[l...r]之中查找target
    int l =0, r = n-1;
    while(l <= r){
        // 防止极端情况下溢出，使用下面的逻辑求出mid
        int mid = l + (r -l)/2;

        if(vec[mid] == target)
            return mid;
        if (vec[mid] > target)
            r = mid -1;
        else
            l = mid + 1;
        return -1;

    }

}

template <typename T>
int __binarySearch2( const vector<T> &vec, int l, int r, T target){
    if (l >r)
        return  -1;
    int mid = l+ (r-l)/2;

    if ( vec[mid] == target)
        return mid;
    else if(vec[mid] > target)
        return __binarySearch2(vec,l, mid -1, target);
    else
        return __binarySearch2(vec,mid +1 , r, target);

}
template <typename T>
int binarySearch2(const vector<T> &vec,int n, T target){
    __binarySearch2(vec,0,n-1,target);
}

int main(){
   /* vector<int>vec(1000000);
    int n = vec.size();
    for (int i =0 ;i < vec.size(); i++)
        vec[i] = i;
    clock_t startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1

    for( int i = 0 ; i < 2*vec.size() ; i ++ ){
        int v = binarySearch(vec, vec.size(), i);
        if( i < vec.size() )
            assert( v == i );
        else
            assert( v == -1 );
    }
    clock_t endTime = clock();
    cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;

    // 测试递归的二分查找法
    startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch2(vec, n, i);
        if( i < n )
            assert( v == i );
        else
            assert( v == -1 );
    }
    endTime = clock();
    cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;

//    delete[] vec;
    */

    // 使用圣经作为我们的测试用例
//    string filename = "bible.txt";
//    vector<string> words;
//    if( FileOps::readFile(filename, words) ) {
//
//        cout << "There are totally " << words.size() << " words in " << filename << endl;
//        cout << endl;
//
//
//        // 测试 BST
//        time_t startTime = clock();
//
//        // 统计圣经中所有词的词频
//        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
//        // 在这里只做性能测试用
//        BST<string, int> bst = BST<string, int>();
//        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
//            int *res = bst.search(*iter);
//            if (res == NULL)
//                bst.insert(*iter, 1);
//            else
//                (*res)++;
//        }
//
//        // 输出圣经中god一词出现的频率
//        if(bst.contain("god"))
//            cout << "'god' : " << *bst.search("god") << endl;
//        else
//            cout << "No word 'god' in " << filename << endl;
//
//        time_t endTime = clock();
//
//        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
//        cout << endl;
//
//
//        // 测试顺序查找表 SST
//        startTime = clock();
//
//        // 统计圣经中所有词的词频
//        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
//        // 在这里只做性能测试用
//        SequenceST<string, int> sst = SequenceST<string, int>();
//        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
//            int *res = sst.search(*iter);
//            if (res == NULL)
//                sst.insert(*iter, 1);
//            else
//                (*res)++;
//        }
//
//        // 输出圣经中god一词出现的频率
//        if(sst.contain("god"))
//            cout << "'god' : " << *sst.search("god") << endl;
//        else
//            cout << "No word 'god' in " << filename << endl;
//
//        endTime = clock();
//
//        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
//    }
//
//
    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();

    // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
    int n = 100;
    int m = 100;
    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%m;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        //cout<<key<<" ";
        bst.insert(key,value);
    }
    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

    // 测试 removeMin
    // 输出的元素应该是从小到大排列的
    cout<<"Test removeMin: "<<endl;
    while( !bst.isEmpty() ){
        cout<<"min: "<<bst.minimum()<<" , ";
        bst.removeMin();
        cout<<"After removeMin, size = "<<bst.size()<<endl;
    }
    cout << endl;


    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%n;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        //cout<<key<<" ";
        bst.insert(key,value);
    }
    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

    // 测试 removeMax
    // 输出的元素应该是从大到小排列的
    cout<<"Test removeMax: "<<endl;
    while( !bst.isEmpty() ){
        cout<<"max: "<<bst.maximum()<<" , ";
        bst.removeMax();
        cout<<"After removeMax, size = "<<bst.size()<<endl;
    }


    return 0;


}
