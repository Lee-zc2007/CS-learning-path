#互斥和锁 Mutex & Lock

数据竞争  
多线程程序中多个线程对同一个数据对象进行访问，至少有一个在写数据

C++中如果没有声明是原子操作就默认是非原子操作

互斥量Mutex提供了一种同步机制，允许多个线程安全访问共享对象

同步原语std::mutex
```
lock //锁定互斥量，即获得这个互斥量，如果被其他线程锁定，就进入阻塞
try_lock //试图锁定，立即返回，但返回false也不一定代表被其他线程锁定
unlock //释放互斥量
```

被lock和unlock包裹的区域叫临界区

为了防止上锁的时候抛出异常，导致互斥量没有释放，mutex通常配合以下函数使用
```
std::lock_guard //避免多次调用产生死锁，自动销毁
std::unique_lock
std::scoped_lock
```

```
#include <mutex>
void inc(){
    std::lock_guard lock(counter_mutex); //调用构造函数会自动调用lock
    m_count++; //调用lock_guard离开作用域后自动调用unlock释放互斥量

    //是一种RAII资源管理方式，把资源的获取和释放，绑定到对象的构造和析构上
}
```

*std::unique_lock*
*std::timed_mutex*

使用更为灵活，可以创建后暂时不锁定  
```
lock
try_lock
try_lock_for
try_lock_until
unlock
```