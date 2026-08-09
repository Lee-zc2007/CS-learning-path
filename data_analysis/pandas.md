#PANDAS

*基本操作*
```
df = pd.read_csv("file_path") #读取文件
df["column_name"] #选择一列
df.sample(n) #随机抽取n个数据
df.unique() #去重（不对原来修改）
df[(df['ages']>20) & (df['ages']<75>)] #前后两个是series，不能用and判断
df[df['age'].between(2,4,inclusive = 'both')] #判断这列数据是否在两值之间
df.groupby('animals')['ages'].mean() #groupby先按照某个字段分类，对每一类分类统计
df.drop(labels=None, axis=0, index=None, columns=None, inplace=False) #axis=0代表行 1代表列 label要配合axis使用，columns直接用就行，inplace决定是否修改原数据
df.sort_values(by='ages',ascending=False) #按照ages排序，默认升序，ascending为False降序，多列排序需要提供两个list分别给by和ascending
df.sort_index() #按照索引排序
df.set_index(keys, drop=True, append=False, inplace=False, verify_integrity=False) #将其中一列设置为索引
```

*查看信息*
```
df.info() #获取详细信息
df.dtypes #查看每一列类型
df.columns #查看列名
df.head(n) #显示前n个数据，默认n=5
df.iloc[] #索引器，按照索引获取，左闭右开
df.loc[] #索引器，按照名字获取，双闭，也可以用于添加行
```

*数值统计*
```
df.describe() #获取详细信息，主要是数值统计
df.mean() #求平均值
df.sum() #求总和
df['animal'].value_counts() #统计每个值出现的频率
df["age"].count() #记录非空值的数量
s.median() #求中位数
s.std() #求标准差
s.quantile(x) #求x百分位数
s.skew() #求偏度
df.corr() #求相关系数，只能对数值类型操作
```

*作图与表格*
```
df.hist() #画直方图
df.plot(kind="sort_of_graph") #用于画图
df.pivot_table(
    index="NumberofChildren" #对应透视表的行
    columns="IsSoftwareDev" #对应列
    values="HoursSpentlearning" #对应值
    aggfunc="sum" #聚合函数，默认是算平均值
)
```