#matplot.lib

*基本操作*
```
ax = df.plot() #绘制图形，保存到ax
plt.show() #绘制figure对象，阻塞程序执行，会将图形从当前图形栈中弹出并销毁
plt.savefig("pic.png") #与show通常二选一，如果要同时执行的话放在show前面，否则保存的是空白，可以指定格式，保存在当前目录下
```

*外观及参数*
```
colors = ["Green", "Lime","Yellow"] #可获得渐变的颜色
#color参数可以用十六进制代码或者用HTML颜色，HTMLColorCodex.com维护了可用颜色名称列表

plt.grid(
    axis="y" #添加网格线，使用axis的y参数可以消除x方向的线，默认是both
    which = "major" #针对主刻度（默认）还是副刻度（minor），两个都画是both
)

plt.xlim(0,5000) #设置x轴范围



alpha=0.7 #alpha可以调整透明度

linestyle="--" #用于改变线条样式

from matplotlib.ticker import AutoMinorLocator
ax.yaxis.set_minor_locator(AutoMinorLocator(2)) #为y坐标轴添加次级刻度，把每个主刻度分为两部分

ax.spines["top"].set_visible(False) #将顶部边框设置为空，left-左 right-右 bottom-下

ax.yaxis.set_ticks([]) #用空列表置空y轴刻度
```

*文字标注及参数*
```
plt.title("") #添加标题

plt.xlabel("") #x轴标注
plt.ylabel("") #y轴标注

plt.xticks(
    xticks=[1,2,3] #要显示刻度的位置
    labels=["A","B","C"] #对应的标签
    rotation=0 #标签旋转角度
)

fontsize=16 #设置字体大小，16一般用于标题，14可以用于坐标轴
fontweight="bold" #加粗

pad=15 #调整与周围元素的距离

plt.annotate(
    text="your_annotation", #注释的内容
    xy=(4,50)， #基准点的位置
    xytext=(-10,30), #offset
    textcoords="offset points", #offset的参考坐标系，默认是data（数据坐标系），offset points表示相对xy点的偏移量（单位是像素）
    arrowprops=dict(facecolor="black"，arrowstyle='->')#添加一个从注释指向其所指的注释点的箭头，facecolor是填充色，edgecolor是边框色
)
```

*图例及参数*
```
plt.legend() #用于绘制图例

head=“Grade” #给图例添加标题

bbox_to_anchor=(1,1) #图例框的放置位置，x和y轴都是0-1，配合loc使用可以指定哪个点为基准
```

*分组柱状图*
```
#用isin快速筛选出需要的行
#用groupby(["state","grade"])获得中间数据
#用unstack进行数据重塑
#此时plot就可以获得分组柱状图

df.unstack() #把行索引中的某一层旋转到列索引上
```

*堆叠柱状图*
```
grouped_df = df.groupby(["grade","homeownership"])["loan_amount"].sum().unstack()
grouped_df.plot(
    kind="bar",
    stack=True #画堆叠柱状图
    color=["Green","red"]
)

#更复杂一点还可以创建100%堆叠图
```

*散点图*
```
#用于可视化两个数值特征之间的关系
plt.scatter(
    df["character1"],df["character2"]，
    alpha=0.5, #对于点比较多的情况可以降低透明度，方便看清集中部分
    marker="^" #控制点的形状
) #创建散点图

plt.axvline(x=df["annual_income"].quantile(0.95)) #绘制一条垂直分割线
```