#include "search.hpp"
//无序表
template <class KEY, class OTHER>
int nseqSearch(SET<KEY,OTHER> data[], int size, const KEY &x){
    data[0].key = x;
    int i;
    for (i = size; x != data[i].key; i--);
    return i;
}

//有序表
template <class KEY, class OTHER>
int seqSearch(SET<KEY,OTHER> data[], int size, const KEY &x){
    int i;
    data[0].key = x;
    for (i=size, x < data[i].key, i--);//提前终止可以提高效率
    if (x == data[i].key) return i;
    else return 0;
}

//二分查找
template <class KEY, class OTHER>
int binarySearch(SET<KEY, OTHER> data[], int size, const KEY &x){
    int l = 1, r = size, mid;
    while (l <= r){
        mid = (l+r)/2;
        if (data[mid].key < x) l = mid + 1;
        else if (data[mid].key > x) r = mid -1;
        else return mid;
    }
    return 0;

}