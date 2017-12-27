//
// Created by csq on 2017/12/26.
//
#include <stack>

#ifndef SORT_SORT_H
#define SORT_SORT_H

typedef enum {
    ekSortType_Bubble = 0,
    ekSortType_Bubble_BiDirect,
    ekSortType_Insert,
    ekSortType_Insert_Dichotomy,
    ekSortType_Select,
    ekSortType_Exchange,
    ekSortType_Quick,
    ekSortType_Merge,
    ekSortType_MinHeap,
    ekSortType_Shell,
    ekSortType_Radix

} ESortType;

class CSort {
public:
    static void sort(int a[], int n, ESortType type);

public:
    static void sortBubble(int a[], int n);

    static void sortBubbleBiDirect(int a[], int n);

    static void sortInsert(int a[], int n);

    static void sortInsertDichotomy(int a[], int n);

    static void sortSelect(int a[], int n);

    static void sortExchange(int a[], int n);

    static void sortQuick(int *a, int n);

    static void sortMerge(int *a, int n);

    static void sortMinHeap(int a[], int n);

    static void sortShell(int a[], int n);

    static void sortRadix(int a[], int n);


private:
    static void swap(int &a, int &b);

    static void __sortQuick(int *a, int start, int end);

    static void mergeArray(int *a, int start, int mid, int end, int *b);

    static void __sortMerge(int *a, int start, int end, int *b);

    static void minHeapFixDown(int *a, int n, int i);

    static void makeMinHeap(int *a, int n);

    static int maxNumLen(int *a, int n);

};



class MaxStack {

public:
    MaxStack() {};

    ~MaxStack() {};

    void push(int val);

    int top();

    int  pop();


private:
    std::stack<int> m_dataStack;
    int max;
};


#endif //SORT_SORT_H
