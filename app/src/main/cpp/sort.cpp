//
// Created by csq on 2017/12/26.
//

#include "Sort.h"


void CSort::sort(int *a, int n, ESortType type) {
    switch (type) {
        case ekSortType_Bubble:
            sortBubble(a, n);
            break;
        case ekSortType_Bubble_BiDirect:
            sortBubbleBiDirect(a, n);
            break;
        case ekSortType_Insert:
            sortInsert(a, n);
            break;
        case ekSortType_Insert_Dichotomy:
            sortInsertDichotomy(a, n);
            break;
        case ekSortType_Select:
            sortSelect(a, n);
            break;
        case ekSortType_Exchange:
            sortExchange(a, n);
            break;
        case ekSortType_Quick:
            sortQuick(a, n);
            break;
        case ekSortType_Merge:
            sortMerge(a, n);
            break;
        case ekSortType_MinHeap:
            sortMinHeap(a, n);
            break;
        case ekSortType_Shell:
            sortShell(a, n);
            break;
        case ekSortType_Radix:
            sortRadix(a, n);
            break;
        default:
            break;
    }
}

void CSort::sortBubble(int *a, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }

}

void CSort::sortBubbleBiDirect(int *a, int n) {
    int low = 0;
    int high = n - 1;
    while (high > low) {
        for (int i = low; i < high; i++) {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
        high--;
        for (int i = high; i > low; i--) {
            if (a[i - 1] > a[i])
                swap(a[i - 1], a[i]);
        }
        low++;
    }
}

void CSort::sortInsert(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int val = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > val) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = val;
    }
}

void CSort::sortInsertDichotomy(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int val = a[i];
        //find insert pos
        int low = 0;
        int high = i - 1;
        int mid;
        while (high >= low) {
            mid = (low + high) / 2;
            if (a[mid] > val)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (int j = i - 1; j >= low; j--) {
            a[j + 1] = a[j];
        }
        a[low] = val;
    }

}

void CSort::sortSelect(int *a, int n) {
    int minIdx;
    for (int i = 0; i < n - 1; i++) {
        minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}

void CSort::sortExchange(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

void CSort::sortQuick(int *a, int n) {
    __sortQuick(a, 0, n - 1);
}

void CSort::sortMerge(int *a, int n) {
    int *b = new int[n];
    __sortMerge(a, 0, n - 1, b);
    delete[]b;
}


void CSort::sortMinHeap(int *a, int n) {
    makeMinHeap(a, n);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        minHeapFixDown(a, i, 0);
    }
    int start = 0;
    int end = n - 1;
    while (end > start) {
        swap(a[start++], a[end--]);
    }

}

void CSort::sortShell(int *a, int n) {

    for (int step = n / 2; step > 0; step /= 2) {
        for (int group = 0; group < step; group++) {
            for (int i = group + step; i < n; i += step) {
                int val = a[i];
                int j = i - step;
                while (j >= group && a[j] > val) {
                    a[j + step] = a[j];
                    j -= step;
                }
                a[j + step] = val;
            }
        }
    }

}

void CSort::sortRadix(int *a, int n) {
    int *count = new int[10];
    int *bucket = new int[n];
    int maxLen = maxNumLen(a, n);
    int divisor = 1;

    for (int i = 0; i < maxLen; i++) {
        for (int j = 0; j < 10; j++)
            count[j] = 0;
        for (int j = 0; j < n; j++) {
            int num = (a[j] / divisor) % 10;
            count[num]++;
        }
        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }

        for (int j = n - 1; j >= 0; j--) {
            int num = (a[j] / divisor) % 10;
            bucket[count[num] - 1] = a[j];
            count[num]--;
        }
        for (int j = 0; j < n; j++) {
            a[j] = bucket[j];
        }
        divisor *= 10;
    }

    delete[]count;
    delete[]bucket;
}


void CSort::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void CSort::__sortQuick(int *a, int start, int end) {

    if (start >= end)
        return;
    int key = a[start];
    int low = start;
    int high = end;
    while (high > low) {
        while (high > low && a[high] >= key) {
            high--;
        }
        a[low] = a[high];
        while (high > low && a[low] <= key) {
            low++;
        }
        a[high] = a[low];
    }
    a[low] = key;
    __sortQuick(a, 0, low - 1);
    __sortQuick(a, low + 1, end);
}

void CSort::mergeArray(int *a, int start, int mid, int end, int *b) {
    int first = start;
    int second = mid + 1;
    int idx = start;
    while (first <= mid && second <= end) {
        if (a[first] > a[second]) {
            b[idx++] = a[second++];
        } else {
            b[idx++] = a[first++];
        }
    }
    while (first <= mid) {
        b[idx++] = a[first++];

    }
    while (second <= end) {
        b[idx++] = a[second++];
    }
    for (int i = start; i <= end; i++)
        a[i] = b[i];
}

void CSort::__sortMerge(int *a, int start, int end, int *b) {
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    __sortMerge(a, start, mid, b);
    __sortMerge(a, mid + 1, end, b);
    mergeArray(a, start, mid, end, b);
}


void CSort::minHeapFixDown(int *a, int n, int i) {
    int val = a[i];
    int child = i * 2 + 1;
    while (child <= n - 1) {
        if (child + 1 <= n - 1 && a[child + 1] < a[child])
            child = child + 1;
        if (a[child] >= val)
            break;
        a[(child - 1) / 2] = a[child];
        child = child * 2 + 1;
    }
    a[(child - 1) / 2] = val;

}

void CSort::makeMinHeap(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapFixDown(a, n, i);
}


int CSort::maxNumLen(int *a, int n) {
    int maxLen = 1;
    int divisor = 10;
    for (int i = 0; i < n; i++) {
        while (a[i] / divisor > 0) {
            maxLen++;
            divisor *= 10;
        }
    }
    return maxLen;
}
