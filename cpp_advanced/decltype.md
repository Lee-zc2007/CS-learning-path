#decltype
通过这个运算符可以获得一个变量或者表达式的值的类型
decltype(变量或表达式)

*对变量使用*
对变量使用可以获得类型，引用类型，cv-qualifier(cv限定符 const和volatile)
'''
int a;
decltype(a) b;//相当于int b
'''

与auto的区别：
auto通过初始化表达式来推导类型，decltype根据表达式本身推导类型
'''
const int a = 3;
const int& b = a;
decltype(b) c = a;//c是const int&类型
auto d = b;//d是int类型
'''
auto只能推导基本类型，不能获得引用类型和cv限定符，需要手动添加

*对表达式使用*
'''
int a;
decltype((a)) b = a;相当于int&
'''
这里的(a)是个表达式

decltype对表达式的处理：
先获得表达式的值去除引用后的基本类型，然后分类
左值lvalue 类型的引用
右值prvalue 类型
xvalue 类型的右值引用

对于函数调用，decltype推导出来的类型正好是函数的返回值类型

decltype里的表达式只用于类型推导，并不真正执行
'''
std::string s1 = "Hello";
decltype(s1 + ",world") s2 = s1;
decltype(s1.append(",world")) s3 = s1;
'''
所以这里的s3仍然是Hello

*decltype(auto)*
decltype(auto)和auto一起统称为占位类型说明符
推导方法：
decltype(初始值表达式) 变量 = 初始值表达式；
'''
std::string s1 = "Hello";
decltype(auto) s2 = s1 + ",world";
decltype(auto) s3 = s1.append(",world");
'''
变量和上例中类型相同，不同点在于表达式会执行

*常见用法*
在定义函数模板的时候用于函数返回值类型的自动推导
'''
//c++11
template<typename T, typename U>
auto add(T&& t, U&& u) -> decltype (std::forward<T>(t) + std::forward<U>(u))
{return std::forward<T>(t) + std::forward<U>(u);};
//这里->代表尾置返回类型，auto只是占位


//c++14
template<typename T, typename U>
decltype(auto) add(T&& t, U&& u)
{
    return std::forward<T>(t) + std::forward<U>(u);
};
'''