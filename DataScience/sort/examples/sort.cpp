template <class KEY, class OTHER>
struct SET{
    KEY key;
    OTHER other;
};

//直接插入排序
template <class KEY, class OTHER>
void simpleInsertSort(SET<KEY, OTHER> arr[], int size){
    int k;
    SET<KEY, OTHER> tmp;
    for (int i = 1; i<size; i++){//默认前面有序，对i位置，逐个往前比较
        for(k = i-1; k>=0 && tmp.key < arr[k].key; --k) arr[k+1] = arr[k];
        arr[k+1] = tmp;//前面用了--，退出循环的时候会多用一个--
    }
}

//二分插入排序
template <class KEY, class OTHER>
void binaryInsertSort(SET<KEY, OTHER> a[], int size){
    SET<KEY, OTHER> tmp;
    for (int i=1; i<size; i++){
        tmp = a[i];

        int left = 0;
        int right = i - 1;
        int mid;
        while (left <= right){
            mid = (left + right)/2;
            if (tmp.key < a[mid].key) right = mid - 1;
            else left = mid + 1;
        }

        for (int j = i-1; j > left; --j)
        a[j + 1] = a[j];

        a[l] = tmp;
    }
}

//希尔排序
template <class KEY, class OTHER>
void shellSort(SET<KEY, OTHER> a[], int size){
    int step, i, j;
    SET<KEY, OTHER> tmp;
    for (step = size/2; step>0; step /= 2){
        for (i = step; i<size; ++i){//对间隔为step的元素用直接插入排序
            tmp = a[i];
            for (j = i-step; j >= 0 && a[j].key > tmp.key; j -= step) a[j + step] = a[j];
        }
        a[j+step] = tmp;
    }
}

