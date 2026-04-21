#ifndef SLINKLIST_WITH_ITR
#define SLINKLIST_WITH_ITR

template <class elemType>
class Cyclelist{
    private:
        struct node{
            elemType data;
            node *next;

            node():next(nullptr){}
            node(const elemType &x, node *n){data = x; next = n;}
            ~node(){}
        };

        node *head

    public:
    Cyclelist():head(nullptr) {}
    ~Cyclelist(){
        if (head != nullptr){
            node *tmp, *beg = head;
            do {
                tmp = head->next;
                delete head;
                head = tmp;
            }
            while (head != beg);//do while要加分号，对于循环链表，head回到原位置beg的时候代表循环完成，书上的==是错的
        }
    }
};

class ITR{};



#endif