package com.chen.sort;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import java.util.Arrays;
import java.util.Random;

public class MainActivity extends AppCompatActivity {
    public final static String TAG = "Sort";
    public final static int SORT_TYPE_START = 0;
    public final static int SORT_TYPE_BUBBLE = 0;
    public final static int SORT_TYPE_BUBBLE_BI_DIRECT = 1;
    public final static int SORT_TYPE_INSERT = 2;
    public final static int SORT_TYPE_INSERT_DICHOTOMY = 3;
    public final static int SORT_TYPE_SELECT = 4;

    public final static int SORT_TYPE_EXCHANGE = 5;
    public final static int SORT_TYPE_QUICK = 6;
    public final static int SORT_TYPE_MERGE = 7;
    public final static int SORT_TYPE_MINHEAP = 8;
    public final static int SORT_TYPE_SHELL = 9;
    public final static int SORT_TYPE_RADIX = 10;
    public final static int SORT_TYPE_END = 10;

    //debug
    private boolean verbose = false;

    private Random random;
    private TextView sortName;
    private TextView input;
    private TextView output;
    private int[] array;
    private int sortIdx;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        sortName = findViewById(R.id.sortName);
        input = findViewById(R.id.inText);
        output = findViewById(R.id.outText);
        findViewById(R.id.prev).setOnClickListener(clickListener);
        findViewById(R.id.genArray).setOnClickListener(clickListener);
        findViewById(R.id.next).setOnClickListener(clickListener);

        sortIdx = SORT_TYPE_START;
        random = new Random();
        genArray();
        sort();
        output.setText(Arrays.toString(array));
    }

    private void updateSortName() {
        String name = "";
        switch (sortIdx) {
            case SORT_TYPE_BUBBLE:
                name = "冒泡";
                break;
            case SORT_TYPE_BUBBLE_BI_DIRECT:
                name = "双向冒泡";
                break;
            case SORT_TYPE_INSERT:
                name = "插入";
                break;
            case SORT_TYPE_INSERT_DICHOTOMY:
                name = "二分插入";
                break;
            case SORT_TYPE_SELECT:
                name = "选择";
                break;
            case SORT_TYPE_EXCHANGE:
                name = "交换";
                break;
            case SORT_TYPE_QUICK:
                name = "快速";
                break;
            case SORT_TYPE_MERGE:
                name = "归并";
                break;
            case SORT_TYPE_MINHEAP:
                name = "堆";
                break;
            case SORT_TYPE_SHELL:
                name = "希尔";
                break;
            case SORT_TYPE_RADIX:
                name = "基数";
                break;
            default:
                break;
        }
        sortName.setText(name);
    }

    private void prev() {
        genArray();
        sort();
        output.setText(Arrays.toString(array));
        sortIdx = sortIdx == 0 ? sortIdx = SORT_TYPE_END : --sortIdx % (SORT_TYPE_END + 1);
    }

    private void next() {
        genArray();
        sort();
        output.setText(Arrays.toString(array));
        sortIdx = ++sortIdx % (SORT_TYPE_END + 1);
    }

    private void genArray() {
        int len = (int) (4 + random.nextDouble() * 10 + 0.5);
        array = new int[len];
        for (int i = 0; i < len; i++) {
            array[i] = (int) (random.nextDouble() * 100 + 0.5);
        }
        input.setText(Arrays.toString(array));
        output.setText("");
        test();
    }

    private void sort() {
        updateSortName();
        printArray(array);
        if (verbose)
            sort(array, SORT_TYPE_RADIX);
        else
            sort(array, sortIdx);
        printArray(array);
    }

    private void printArray(int[] arr) {
        String str = Arrays.toString(arr);
        Log.d(TAG, str);
    }


    private View.OnClickListener clickListener = new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            switch (view.getId()) {
                case R.id.prev:
                    prev();
                    break;
                case R.id.next:
                    next();
                    break;
                case R.id.genArray:
                    genArray();
                    break;
                default:
                    break;
            }
        }
    };

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native void sort(int[] arr, int type);

    public native void test();

}
