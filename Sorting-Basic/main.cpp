//
// Created by genius on 18-8-15.
//

#include<iostream>
#include <vector>
#include "SortHelp.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "bubblesort.h"
#include "shellsort.h"
#include "mergesort.h"
#include "quicksort.h"
using namespace std;

int main(){
    vector<int> vec= SortTestHelper::generateRandomArray(100000000,0,10);
    vector<int>vec1(vec);
    vector<int>vec2(vec);
    vector<int>vec3(vec);
    vector<int>vec4(vec);
    vector<int>vec5(vec);
    vector<int>vec6(vec);
    vector<int>vec7(vec);
//    SortTestHelper::testSort("selectsort",SelectionSort,vec,vec.size());
//    SortTestHelper::testSort("insertionsort",insertionsort, vec1, vec.size());
//    SortTestHelper::testSort("insertionsort1",insertionsort1, vec2, vec.size());
//    SortTestHelper::testSort("bubblesort",bubblesort, vec3, vec.size());
//    SortTestHelper::testSort("bubblesort1",bubblesort1, vec4, vec.size());
//    SortTestHelper::testSort("shellsort",shellsort, vec5, vec.size());
//    SortTestHelper::testSort("mergesort",mergesort, vec6, vec.size());
    SortTestHelper::testSort("quicksort",quicksort3ways, vec7, vec.size());

}
