#ifndef SEARCH
#define SEARCH

template <class KEY, class OTHER>
struct SET{
    KEY key;
    OTHER other;
};

//无序表
template <class KEY, class OTHER>
int nseqSearch(SET<KEY,OTHER> data[], int size, const KEY &x);

//有序表
template <class KEY, class OTHER>
int seqSearch(SET<KEY,OTHER> data[], int size, const KEY &x);

//二分查找
template <class KEY, class OTHER>
int binarySearch(SET<KEY, OTHER> data[], int size, const KEY &x);

#endif