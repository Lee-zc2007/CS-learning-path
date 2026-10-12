#promise 和 future

为线程之间提供了简单的通信机制
一个线程通过promise设置值或者异常，另一个通过future来接受
通过类对象shared state

*promise*

有一个主模板和两个特化
```
template<typename Res> class promise;//两个线程之间按照值传递
template<typename Res> class promise<Res&>;//按照引用传递
template<> class promise<void>;//两个线程间发送任务完成的信号而不传递数据
```

常用函数
```
promise()//默认构造函数，创建共享创建对象，用shared_ptr封装
promise(promise&& x)//移动构造函数
get_future//创建future对象，用共享状态对象初始化
set_value//设置共享状态对象的值
set_exception//设置共享状态的异常
```

*future*

一般用get_future来获得

常用函数
```
get//获得结果
wait//等待状态就绪
wait_for//等待指定市场，返回状态码(ready, timeout, deferred)
wait_until//等到指定时刻，返回状态码
share//让多个线程获得结果（使用future对象获得对象只能使用一次）
```

为了避免传递的promise和future对象引用被提前销毁，可以在线程传参的时候采用移动语义

除了传递值外，也可以用于设置异常，在catch中pr.set_exception(std::current_exception()); try中 auto result = future.get();来接受

一个future对象只能与一个共享状态对象关联，只能用移动或者引用的方式使用

shared_future对象则可以多个同时共享状态，因此可以拷贝使用

还可以用无参数特化来传递任务的完成