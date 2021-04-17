<!--
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-03-01 14:43:51
-->

# 不用int

## 看题时着重注意
- 输出时对顺序有什么要求，选择方便的数据结构
- C++： floor(),ceil(),round()

## string
- 字符串切片 substr(pos,n)
- string转int，double  stoi(string)，stod(string)
- int转string  to_string(int)
- string[i]的类型是char，别搞错了。
- C++ 的string和char都没有乘法的，别理所当然写习惯了。
  

## 输入输出
- 我们主要还是用cin好了，加上取消同步,cin输入string方便一点
- main 里加上 ios::sync_with_stdio(false);
- 要是真遇上卡样例的情况，可以试试把cin改成scanf；
- cin 读取整行数据到string，使用getline(cin,string),
- 当cin和getline混用时，要在cin之后加上，cin.clear();cin.ignore(),来清除缓冲区里的"\n"，
- cin读到\n会停止读入，下次读则会跳过一开始的\n，而getline则会把缓冲区里的\n一起读入，然后删除\n，所以如果不清除缓冲区，cin之后的getline只会读到一个空串。


## map
- map判断某key是否存在，map.count(key)==1则存在，key是唯一的。
- 或者map.find(key)!=map.end()
- map键值中的值为int时，每新增元素，会默认赋值为0，所以用unordered_map<T，int>来当字典统计很好用。
- map键值中的值为vector<int>时，每新增元素，会默认赋值为空容器，也很好用。
- map内部是红黑树，有序的，unorder_map内部是散列，无序但快很多,```尽量都用unordered_map```
- 只需要输入second最大、最小的某个值，不需要对值排序，很麻烦。暂存temp_max作比较就行了。

## set
- 判断某key是否存在：set.find(a)!=set.end(),和map一样
- set内部会对元素自动排序，字典序

## stack
- stack的pop无返回值，访问用top

## vector
- vector初始化:vector<int>a(10,3),vector<string>a(10," ")
- 数组初始话： intA[100]={0};
- 返回vector的最后一个元素  *vector.back()*, 和 popback 搭配使用
- tmp.insert(```tmp.begin()```,1);
- 使用vector的构造函数实现类似python的切片功能。如```vector<int>(pre.begin()+1+root_index,pre.end()```


### 判溢出
- -2^63~2^63-1,用long long 就行了，64位   

你要知道的是，1111...111是-1，100000....000是2^-63，0111111...111是最大正数2^63-1。

上一行都是补码，10000……000是-0，定义成能表示的最小值

所以判正溢出就是t1>0,t2>0,t1+t2<0. 判负溢出就是t1<0,t2<0,t1+t2>=0.

- 当遇到要对1e9+7取模的情况，就要警惕溢出了，可能计算的中间值会溢出，这个时候要考虑用longlong

### 超时优化方法

- PAT 1046 解决超时的方法
- PAT 1047 TLE 尚未处理
- 存在等差数列的情况下，一定要用公式，不要图省事循环。
- 找到之前出现的最小值，用优先队列，底层堆实现。logn。

### 避免奇怪的错误

- 编号，ID什么的就用string存，不要用int，避免转换，补0等问题。  例：A1022的ID
- 不要起太大众的变量名，time就不能取
- 字符串处理的某个样例没过，可能是忘记了循环外面最后一层，处理掉子串剩余内容。
- 输出格式，可能要求保持一致，比如输出00：00，时分都要02d。

### 一些英语

- case sensitive/insensitive

### 方便的STL

- 序列求和
  include<numeric>
  accumulate(vector.begin(),vector.end(),(long)0)

- 查找元素，返回下标
  include<algorithm>
  find(vec.begin(),vec.end(),10)

- unique 
  使用前要先排序，将数组重复的元素放到最后面，返回第一个重复元素的迭代器。