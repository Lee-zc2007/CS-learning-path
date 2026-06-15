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

//直接选择排序
template <class KEY, class OTHER>
void simpleSelectSort(SET<KEY, OTHER> a[], int size){
    for (int i=0; i<size; i++){
        int min;
        SET<KEY, OTHER> tmp;
        for (int j = i+1; j<size; j++){
            if (a[j].key<a[min].key) min = j;
        }
        tmp = a[i]; a[i] = a[min]; a[min] = tmp;
    }
}

//堆排序
template <class KEY, class OTHER> 
void heapSort(SET<KEY, OTHER> a[], int size) {
    int i; 
    SET<KEY,OTHER> tmp; 
    //创建初始的堆
    for (i =size/ 2 - 1; i >= 0; i--) 
    percolateDown(a, i, size); //最大堆
    //执行 n-1 次 deQueue
    for (i = size - 1; i > 0; --i) { 
    tmp = a[0]; a[0] = a[i]; a[i] = tmp; //delete a[O]
    percolateDown(a, 0, i); //参数只能用i，队尾的位置已经排好了，不能重新带入
    }
}

template <class KEY, class OTHER> 
void percolateDown(SET<KEY, OTHER> a[], int hole, int size) {
    int child; 
    SET<KEY, OTHER> tmp = a[hole]; 
    for(; hole * 2 + 1 < size; hole = child) {
        child= hole* 2 + l; 
        if(child != size - 1 && a[child + 1].key > a[child].key) child++; 
        if(a[child].key > tmp.key) a[hole] = a[child]; 
        else break; 
    }
    a[hole] = tmp; 
}

//冒泡排序
template <class KEY, class OTHER> 
void bubbleSort(SET<KEY, OTHER> a[], int size) {
    bool flag = true;
    for (int i = 1; i < size && flag; ++i) {//flag直接放到if的判断条件中,i等于几表示在排第几大的元素
        flag = false;
        for (int j = 0; j < size - i; ++j) {
            if (a[j+1].key < a[j].key) {
                std::swap(a[j], a[j+1]);
                flag = true;
            }
        }
    }
}

//快速排序
template <class KEY, class OTHER> 
void quickSort(SET<KEY, OTHER> a[], int low, int high){
    int mid;
    if (low >= high) return;
    mid = divide(a, low, high);
    quickSort(a, low, mid - 1);
    quickSort(a, mid+1, high);
}

template <class KEY, class OTHER>
int divide(SET<KEY, OTHER> a[], int low, int high) {
    SET<KEY, OTHER> k = a[low];
    do {
        while (low < high && a[high].key >= k.key) --high;
        if (low < high) { a[low] = a[high]; ++low; }
        while (low < high && a[low].key <= k.key) ++low;
        if (low < high) { a[high] = a[low]; --high; }
    } while (low != high);
    a[low] = k;
    return low;
}

//归并排序两个序列
template <class KEY, class OTHER>
void merge(SET<KEY, OTHER> a[], int left, int mid, int right)
{
    SET<KEY, OTHER> *tmp = new SET<KEY, OTHER>[right-left+1];

    int i = left, j = mid, k = 0;

    while (i < mid && j <= right) // 两表都未结束
    if (a[i].key < a[j].key) tmp[k++] = a[i++];
    else tmp[k++] = a[j++];

    while (i < mid) tmp[k++] = a[i++]; // 前半部分没有结束
    while (j <= right) tmp[k++] = a[j++]; // 后半部分没有结束

    for (i=0, k = left; k<=right;) a[k++] = tmp[i++];
    delete [] tmp;
}

//归并排序
template <class KEY, class OTHER>
void mergeSort(SET<KEY, OTHER> a[], int left, int right)
{
    int mid = (left + right) / 2;

    if (left == right) return;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);//左右都排序再合并
    merge(a, left, mid + 1, right);
}

//口袋排序
template <class OTHER>
struct node {
    SET<int, OTHER> data;
    node *next;

    node() { next = NULL; }
    node(SET<int, OTHER> d): data(d) { next = NULL; }
};

template<class OTHER>
void bucketSort(node<OTHER>*& p) {
    node<OTHER>* bucket[10], *last[10];//bucket维护桶，last维护末尾，方便链接和节点接入
    int max = 0, base = 1;
    // 找最大值
    for (node<OTHER>* t = p; t; t = t->next)
        if (t->data.key > max) max = t->data.key;
    // 求位数
    int len = 0;
    if (max == 0) len = 1;
    else while (max > 0) { len++; max /= 10; }
    // 进行len次分配和收集
    for (int i = 0; i < len; i++) {
        // 初始化桶
        for (int j = 0; j < 10; j++) bucket[j] = last[j] = NULL;
        // 分配
        node<OTHER>* cur = p;
        while (cur) {
            int k = (cur->data.key / base) % 10;
            node<OTHER>* next = cur->next;
            cur->next = nullptr;//切断与原来桶的链接
            if (bucket[k] == NULL)
                bucket[k] = last[k] = cur;
            else {
                last[k]->next = cur;
                last[k] = cur;
            }
            cur = next;
        }
        // 收集
        p = NULL;
        node<OTHER>* tail = NULL;
        for (int j = 0; j < 10; j++) {
            if (bucket[j]) {
                if (p == NULL) p = bucket[j];
                else tail->next = bucket[j];
                tail = last[j];
            }
        }
        if (tail) tail->next = NULL;
        base *= 10;
    }
}