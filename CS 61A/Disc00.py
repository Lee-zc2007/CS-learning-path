def f(x):
    return x - 1

def g(x):
    return (x + 1) * 2

def h(x,y):#对象引用传递对于int str tuple不能直接改变值，会创建新的对象，新对象不保存就丢失了
    count = 0
    tmp = y;
    while (tmp != 0):
        tmp //= 10 #python中/=是浮点数除法 //=才是整除
        count += 1
    return x * (10 ** count) +y
#return int(str(x) + str(y)) 字符串拼接也可以

print(f(5))
print(g(5))
print(h(789,12))