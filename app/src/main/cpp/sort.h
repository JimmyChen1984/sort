//
// Created by csq on 2017/12/26.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H

typedef enum {
    ekSortType_Bubble = 0,
    ekSortType_Insert,
    ekSortType_Select

}ESortType;

class CSort {
public:
    static void sort(int a[], int n, ESortType type);
public:
    static void sortBubble(int a[], int n);

    static void sortInsert(int a[], int n);

    static void sortSelect(int a[], int n);

private:
    static void swap(int &a, int &b);

};


#endif //SORT_SORT_H
