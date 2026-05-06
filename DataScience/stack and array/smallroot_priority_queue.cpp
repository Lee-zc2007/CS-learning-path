#include <iostream>
using namespace std;

class pri_queue{
    private:
    struct Node{
        int val;
        Node *next;
        Node(int v, Node *n = nullptr){val = v; next = n;}
        ~Node(){}
    };
    Node *head;
    int currentLength;

    public:
    pri_queue(){head = new Node(0); currentLength = 0;}//head使用哑节点，空指针不能访问next
    ~pri_queue(){}
    void insert(const int &v);//对应操作1
    void pop();//对应操作2
    void filt();//向下过滤，与操作1解耦
};

void pri_queue::insert(const int &v){
        Node *temp = new Node(v, head->next);
        head->next = temp;
    filt();    
}

void pri_queue::filt(){
    Node *temp = head->next;
    while (temp->next != nullptr && temp->val > temp->next->val){ //顺序不能反，否则temp为空指针时访问val就会崩溃
        int t = temp->val;
        temp->val = temp->next->val;
        temp->next->val = t;
        temp = temp->next;
    }
    return ;
}

void pri_queue::pop(){
    cout<<head->next->val<<endl;
    Node *temp = head->next;
    head->next = temp->next;
    delete temp;
    return;
}

int main(){
    pri_queue myQueue;
    int n;
    cin>>n;
    int opt, val;
    for (int i=0; i<n; i++){
        cin>>opt;
        if (opt == 1){
            cin>>val;
            myQueue.insert(val);
        }
        else
        myQueue.pop();
    }
}