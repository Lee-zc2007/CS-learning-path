#include <iostream>
using namespace std;

class sort_archive{
    private:
        struct Node{
            int level;
            int time;
            int id;
            Node *next;
            Node *pre;
            Node():next(nullptr), pre(nullptr){}
            Node(int l, int t, int i, Node *n=nullptr, Node *p=nullptr){level = l; time = t; id = i; next = n; pre = p;}
            ~Node(){}
        };
        Node *head;
        Node *tail;
    
    public:
        sort_archive();
        void filt();
        void add(int l, int t, int i);
        ~sort_archive();
        void switcher(Node *n1);
        void traverse();
};

sort_archive::sort_archive(){
    head = tail = nullptr;
}

sort_archive::~sort_archive(){
    Node *tmp = head;
    while (head != nullptr){
        head = head->next;
        delete tmp;
        tmp = head;
    }
}

void sort_archive::switcher(Node *n1){
    Node *tmp = n1->pre;
    Node *tmp_p = tmp->pre;
    tmp->pre = n1;
    tmp->next = nullptr;
    n1->next = tmp;
    n1->pre = tmp_p;
    tmp_p->next = n1;
}

void sort_archive::filt(){
    Node *tmp = tail;
    while (tmp->pre != nullptr && tmp->level > tmp->pre->level)
    switcher(tmp);

    while (tmp->pre != nullptr && tmp->level == tmp->pre->level && tmp->time < tmp->pre->time)
    switcher(tmp);
}

void sort_archive::add(int l, int t, int i){
    if (tail == nullptr){
        head = tail = new Node(l,t,i,nullptr,head);
    }
    else{
        tail->next = new Node(l,t,i,nullptr,tail);
        tail = tail->next;
        filt();
    }
}

void sort_archive::traverse(){
    Node *p = head;
    while (p != nullptr){
        cout << p->id << endl;
        p = p->next;
    }
}

int main(){
    int n;
    cin >> n;
    int l, t;
    sort_archive ans;
    for (int j=1; j<n+1; j++){
        cin >> l >> t;
        ans.add(l, t, j);
    }

    ans.traverse();
}