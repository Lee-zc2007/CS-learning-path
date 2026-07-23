#algorithm
*copy_if(first,last,out,pred)*
将一个容器中，符合条件的元素拷贝到新的容器中
'std::copy_if(vec.begin(),vec.end(),std::back_inserter(res),pred)'
前两个是开始和末尾的迭代器
第三个参数是元素拷贝到的新容器，back_inserter()创建了一个迭代器，自动插入容器尾部
第四个参数是一个可调用对象，用于判断元素是否符合条件

copy_if还可以用views::filter替代
'auto res = words | std::views::filter(hasWord);'
hasWord是用于判断符合条件的词的闭包

*partition*
'auto bound1 = std::partition(numbers.begin(),numbers.end(),[](int v){return v%3 == 0});'
用于将数组根据规则分为两个部分，返回分界处的迭代器（bound及之后不满足条件）

'set_difference'
找到在第一个集合，不在第二个集合的元素

'set_symmetric_difference'
找到两个集合中不同时存在的元素

*for_each*
对每个元素操作，不关心返回值

*transform*
对每个元素进行转换并存到指定位置
'''
transform(nums.begin(), nums.end(), back_inserter(strs),[](int x){return to_string(x);});
'''

*remove_if*
按照条件将符合条件的元素移动到前面，要真的删除需要配合erase

*reduce*
std::reduce(begin, last, init, operation)
按照operation进行合并

*inner_product*
算内积，可以看作transform_reduce的特殊情况

*transform_reduce*
将transform和reduce操作合并

*transform_exclusive_scan*
与transform_reduce类似，将r0，r1一直到rn-1次的操作公式存储到一个输出容器中