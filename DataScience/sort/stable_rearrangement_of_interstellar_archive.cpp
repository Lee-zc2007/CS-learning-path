//插入排序，时间复杂度不够

// #include <iostream>
// using namespace std;

// class sort_archive{
//     private:
//         struct Node{
//             int level;
//             int time;
//             int id;
//             Node *next;
//             Node *pre;
//             Node():next(nullptr), pre(nullptr){}
//             Node(int l, int t, int i, Node *n=nullptr, Node *p=nullptr){level = l; time = t; id = i; next = n; pre = p;}
//             ~Node(){}
//         };
//         Node *head;
//         Node *tail;
    
//     public:
//         sort_archive();
//         void filt();
//         void add(int l, int t, int i);
//         ~sort_archive();
//         void switcher(Node *n1);
//         void traverse();
// };

// sort_archive::sort_archive(){
//     head = tail = nullptr;
// }

// sort_archive::~sort_archive(){
//     Node *tmp = head;
//     while (head != nullptr){
//         head = head->next;
//         delete tmp;
//         tmp = head;
//     }
// }

// void sort_archive::switcher(Node *n1){
//     Node *tmp = n1->pre;
//     Node *tmp_p = tmp->pre;
//     tmp->pre = n1;
//     tmp->next = nullptr;
//     n1->next = tmp;
//     n1->pre = tmp_p;
//     tmp_p->next = n1;
// }

// void sort_archive::filt(){
//     Node *tmp = tail;
//     while (tmp->pre != nullptr && tmp->level > tmp->pre->level)
//     switcher(tmp);

//     while (tmp->pre != nullptr && tmp->level == tmp->pre->level && tmp->time < tmp->pre->time)
//     switcher(tmp);
// }

// void sort_archive::add(int l, int t, int i){
//     if (tail == nullptr){
//         head = tail = new Node(l,t,i,nullptr,head);
//     }
//     else{
//         tail->next = new Node(l,t,i,nullptr,tail);
//         tail = tail->next;
//         filt();
//     }
// }

// void sort_archive::traverse(){
//     Node *p = head;
//     while (p != nullptr){
//         cout << p->id << endl;
//         p = p->next;
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//     int l, t;
//     sort_archive ans;
//     for (int j=1; j<n+1; j++){
//         cin >> l >> t;
//         ans.add(l, t, j);
//     }

//     ans.traverse();
// }


//归并排序
#include <iostream>
using namespace std;

struct Data{int level; int time; int id;};

bool before(const Data &a, const Data &b){
    if (a.level != b.level) return a.level > b.level;
    if (a.time != b.time) return a.time < b.time;
    return a.id < b.id;//优先输入保证在前面
}

void merge(Data *ans, int left, int mid, int right){
    Data *tmp = new Data[right - left + 1];
    int i = left, j = mid, k=0;
    while (i < mid && j <= right){
        if (before(ans[i],ans[j])) tmp[k++] = ans[i++];
        else tmp[k++] = ans[j++];
    }

    while (i < mid) tmp[k++] = ans[i++];
    while (j <= right) tmp[k++] = ans[j++];

    for (int t=0; t<k; t++) ans[t + left] = tmp[t];
    delete []tmp;
}

void mergeSort(Data *ans, int left, int right){
    int mid = (left + right)/2;
    if (left == right) return;
    mergeSort(ans, left, mid);
    mergeSort(ans, mid + 1, right);
    merge(ans, left, mid+1, right);
}

int main(){
    int n;
    cin >> n;
    Data *ans = new Data[n];
    for (int i = 0; i<n; i++){
        cin >> ans[i].level >> ans[i].time;
        ans[i].id = i;
    }
    mergeSort(ans, 0, n - 1);
    for (int i=0; i<n; i++)
    cout << ans[i].id + 1 << endl;
}