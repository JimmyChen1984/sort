package com.chen.sort;

/**
 * Created by csq on 2017/12/26.
 */

public class Sort {
    /**
     * 直接插入排序
     *
     * @param arr 待排序数组
     */
    static public void sortDirectInsert(int[] arr) {
        int temp;
        for (int i = 1; i < arr.length; i++) {
            temp = arr[i];
            int j = i - 1;
            for (; j >= 0 && arr[j] > temp; j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }

    /**
     * 二分插入排序，用二分法快速找到需要插入的位置
     *
     * @param arr 待排序数组
     */
    static public void sortDimidiateInsert(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int cur = arr[i];
            int left = 0;
            int right = i - 1;
            while (right >= left) {
                int mid = (left + right) / 2;
                if (arr[mid] > cur)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            for (int j = i - 1; j >= left; j--) {
                arr[j + 1] = arr[j];
            }
            arr[left] = cur;
        }
    }


    /**
     * 冒泡排序
     *
     * @param arr 待排序数组
     */
    static public void sortBubble(int[] arr) {
        int temp;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    /**
     * 双向冒泡排序
     *
     * @param arr 待排序数组
     */

    static public void sortBubbleBiDirect(int[] arr) {
        int temp;
        int left = 0;
        int right = arr.length - 1;
        while (left < right) {
            for (int i = left; i < right; i++) {
                if (arr[i] > arr[i + 1]) {
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
            right--;
            for (int i = right; i > left; i--) {
                if (arr[i - 1] > arr[i]) {
                    temp = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = temp;
                }
            }
            left++;
        }
    }

    /**
     * 交换排序 （第一次确定最小的，然后依次）
     *
     * @param arr 待排序数组
     */
    static public void sortExchange(int[] arr) {
        int temp;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

    }

    /**
     * 选择排序
     *
     * @param arr 待排序数组
     */
    static public void sortSelect(int[] arr) {
        int minIdx, temp;
        for (int i = 0; i < arr.length - 1; i++) {
            minIdx = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIdx])
                    minIdx = j;
            }
            if (minIdx != i) {
                temp = arr[i];
                arr[i] = arr[minIdx];
                arr[minIdx] = temp;
            }
        }
    }


    /**
     * 希尔排序，步长从n/2递减至1，按步长分组，组内进行插入排序
     *
     * @param arr 待排序数组
     */
    static public void sortShell(int arr[]) {
        for (int step = arr.length / 2; step > 0; step /= 2) {
            for (int group = 0; group < step; group++) {
                for (int i = group + step; i < arr.length - 1; i += step) {
                    int cur = arr[i];
                    int j = i - step;
                    while (j >= group && arr[j] > arr[j + step]) {
                        arr[j + step] = arr[j];
                        j -= step;
                    }
                    arr[j + step] = cur;
                }
            }
        }
    }

    /**
     * 快速排序，选定一个key,让小于key的值都放在左边，大于k的值都放在右边，递归key左边和key右边的数组
     *
     * @param arr   待排序数组
     * @param left  左起点
     * @param right 右终点
     */
    static public void sortQuick(int[] arr, int left, int right) {
        if (left >= right)
            return;
        int low = left;
        int high = right;
        int key = arr[left];
        while (high > low) {
            while (high > low && arr[high] >= key) {
                high--;
            }
            arr[low] = arr[high];
            while (high > low && arr[low] <= key) {
                low++;
            }
            arr[high] = arr[low];
        }

        arr[low] = key;
        sortQuick(arr, left, low - 1);
        sortQuick(arr, low + 1, right);
    }

    /**
     * 归并排序：先将数组分为左右两个有序的数组，然后合并有序数组，
     * 如何将数组分为左右连个有序的数组，答案是递归的将左右两个数组分为两个更小的有序数组，
     * 当分到数组长度分别为1时，进行合并
     * 合并有序数组
     *
     * @param arr   待合并数组
     * @param left  左
     * @param mid   中间位置
     * @param right 右
     * @param temp  临时数组
     */
    static public void mergeArray(int[] arr, int left, int mid, int right, int[] temp) {
        int i = left;
        int j = mid + 1;
        int k = left;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        //将temp中排好的数组放回到arr
        for (int l = left; l <= right; l++) {
            arr[l] = temp[l];
        }

    }

    /**
     * 归并排序：先将数组分为左右两个有序的数组，然后合并有序数组，
     * 如何将数组分为左右连个有序的数组，答案是递归的将左右两个数组分为两个更小的有序数组，
     * 当分到数组长度分别为1时，进行合并
     *
     * @param arr   待排序数组
     * @param left  左
     * @param right 右
     * @param temp  临时数组
     */
    static public void sortMerge(int[] arr, int left, int right, int[] temp) {
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        sortMerge(arr, left, mid, temp);
        sortMerge(arr, mid + 1, right, temp);
        mergeArray(arr, left, mid, right, temp);
    }


    /**
     * 向上修复堆，插入一般是放到数组最后面，和（i-1）/2根节点比较大小，找到插入位置插入
     *
     * @param arr 数组
     * @param i   插入节点的索引
     */
    static public void MinHeapFixUp(int[] arr, int i) {
        int temp = arr[i];
        int j = (i - 1) / 2;
        while (j >= 0 && arr[j] > temp) {
            arr[i] = arr[j];
            i = j;
            j = (i - 1) / 2;
        }
        arr[i] = temp;
    }

    /**
     * 堆插入
     *
     * @param arr  数组
     * @param n    数组的大小
     * @param uNum 待插入值
     */
    static public void insertMinHeap(int[] arr, int n, int uNum) {
        arr[n] = uNum;
        MinHeapFixUp(arr, n);
    }

    /**
     * 向下修复小根堆，对应的根节点（i-1）/2，左子节点2i+1, 右子节点2i+2，找到最小的子节点比较大小与之交换重复
     *
     * @param arr 数组
     * @param i   待修复根节点
     * @param n   数组大小
     */
    static public void MinHeapFixDown(int[] arr, int i, int n) {
        int temp = arr[i];
        int j = 2 * i + 1;
        while (j < n) {
            if (j + 1 < n && arr[j + 1] < arr[j])
                j++;
            if (arr[j] >= temp)
                break;
            arr[i] = arr[j];
            i = j;
            j = 2 * i + 1;
        }
        arr[i] = temp;
    }

    /**
     * 删除堆顶的元素
     *
     * @param arr 数组
     * @param n   大小
     */
    static public void DeleteMinHeap(int[] arr, int n) {
        int temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
        MinHeapFixDown(arr, 0, n - 1);
    }

    /**
     * 生成堆 从最后一个叶子节点对应的根节点修复堆，一直向前遍历
     *
     * @param arr 数组
     * @param n   大小
     */
    static public void MakeMinHeap(int[] arr, int n) {

        for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
            MinHeapFixDown(arr, i, n);
        }
    }

    /**
     * 堆排序，最后一位与小根堆堆顶交换，然后修复堆，倒数第2位与堆顶交换再修复堆，最后是逆序数组
     *
     * @param arr 待排序数组
     */
    static public void sortMinHeap(int[] arr) {
        MakeMinHeap(arr, arr.length);
        int temp;
        for (int i = arr.length - 1; i > 0; i--) {
            temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            MinHeapFixDown(arr, 0, i);
        }
        int left = 0;
        int right = arr.length - 1;

        while (right > left) {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    /**
     * 找到数组中最多的位数
     *
     * @param arr 待排序数组
     */
    static public int maxNumLength(int[] arr) {
        int maxLen = 1;
        int divisor = 10;
        for (int i = 0; i < arr.length; i++) {
            while (arr[i] >= divisor) {
                maxLen++;
                divisor *= 10;
            }
        }
        return maxLen;
    }

    /**
     * 基数排序
     *
     * 基数排序是非比较排序，计数排序，桶排序：
     * 用bucket[n]表示桶，用来记录每次基数排序后的结果，一共需要做元素位数最大值次排序，从bucket中依次取出元素就是每次基数排序后的结果
     * 基数为0到9，每次排序，用count[10]先记录含有对应基数所包含的元素的总数，然后将count[10]转化为记录在某个桶中的最后一个元素的下标，用来确定元素在bucket中的位置
     * 每次排序都要清空count数组
     *
     * @param arr 待排序数组            
     */
    static public void sortRadix(int[] arr) {
        //arr中元素位数的最大值，共多少次基数排序
        int maxNumLen = maxNumLength(arr);
        //包含对应基数的元素的个数：count[0]含基数0的元素的个数，依次类推
        int[] count = new int[10];
        //排序用的桶，大小等于arr的大小
        int[] bucket = new int[arr.length];
        //用以获取元素每一位上的值进行基数排序，从个位到最高位 (data/divisor)%10
        int divisor = 1;
        for (int i = 0; i < maxNumLen; i++) {
            //每次排序count数组置为零
            for (int j = 0; j < count.length; j++)
                count[j] = 0;
            //填充count 用于记录在某个桶中的最后一个元素的下标
            for (int j = 0; j < arr.length; j++) {
                //元素某一位上对应的基数
                int num = (arr[j] / divisor) % 10;
                count[num]++;
            }
            //累计count,变成每个元素在bucket中的索引
            for (int j = 1; j < count.length; j++) {
                count[j] += count[j - 1];
            }
            //填充bucket, 从arr倒序遍历
            for (int j = arr.length - 1; j >= 0; j--) {
                int num = (arr[j] / divisor) % 10;
                bucket[count[num] - 1] = arr[j];
                count[num]--;
            }

            //从bucket放回到arr进行下一位的排序
            for (int j = 0; j < arr.length; j++)
                arr[j] = bucket[j];
            divisor *= 10;
        }
    }

}
