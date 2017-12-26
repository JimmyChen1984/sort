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
    public final static int SORT_TYPE_INSERT = 1;
    public final static int SORT_TYPE_SELECT = 2;
    public final static int SORT_TYPE_END = 2;

    private Random random;
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
        input = findViewById(R.id.inText);
        output = findViewById(R.id.outText);
        findViewById(R.id.prev).setOnClickListener(clickListener);
        findViewById(R.id.genArray).setOnClickListener(clickListener);
        findViewById(R.id.next).setOnClickListener(clickListener);

        sortIdx = SORT_TYPE_START;
        random = new Random();
        genArray();
    }

    private void prev() {
        sort(array, sortIdx);
        output.setText(Arrays.toString(array));
        sortIdx = sortIdx == 0 ? sortIdx = 2 : --sortIdx % (SORT_TYPE_END + 1);
    }

    private void next() {
        sort(array, sortIdx);
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

}