#常量表达式和constexpr
常量表达式是指一个表达式的值是固定值，这个值不会因为程序的运行状态而改变
编译器在编译过程中可以将这个表达式用结果值替换，提高程序性能
常量表达式由字面量 常量 函数 运算符组成（编译时都可以获得值）

*constexpr*
告诉编译器如果表达式在编译期就可以计算出来，就直接计算
'''
constexpr int square(int x)
{
    return x * x;
}

constexpr int a = square(5);   //合法
'''

constexpr定义变量一定要初始化，且初始值一定是常量表达式
'''
constexpr int a{12};

const int a{12};//只有int用const声明才能作为常量表达式
constexpr int b{a+13};

constexpr float a{12};//float以及其他类型必须用constexpr声明
constexpr float b{a+3};
'''

用constexpr（编译时的常量）定义的一定是const（运行时的只读变量或编译时的常量），反之不一定

*常量表达式函数*
用constexpr声明的函数
当常量表达式函数的实参都是常量表达式时，函数的调用也是常量表达式

成为常量表达式的要求：
·函数的返回值和传参是字面类型
·函数中不能调用非constexpr函数
·不能抛出异常

常量表达式函数支持递归调用
递归深度有限制（如gcc中的参数fconstexpr-depth,默认值512）

constexpr类的定义需要将类的构造函数前面加constexpr
编译阶段需要使用的类函数也要加constexpr

constexpr函数不能调用非constexpr函数，很多标准库中的函数是不能调用的，如iostream thread但是cmath中的可以
