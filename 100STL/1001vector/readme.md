## 1001.cc emplace_back()和push_back()的区别
- 总结:emplace_back(构造参数列表)只调用一次构造函数，而push_back(构造参数列表)会调用一次构造函数+一次移动构造函数/拷贝构造。其余情况下，二者相同。
- emplace_back() 和 push_back() 的区别，就在于底层实现的机制不同。
- push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中(如果是拷贝的话，事后会自行销毁先前创建的这个元素)
- push_back() 在底层实现时，会优先选择调用移动构造函数，如果没有才会调用拷贝构造函数。
- emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。

## pair与map结合, pair与vector结合
### map通过键－值的形式保证一一对应关系，而multimap则可以出现一对多的关系，这两种数据类型在存储数据时，会根据pair<>的first成员进行'''排序''', 不同的是前者将不会插入对first成员重复的结构，而后者可以。 

### 当我们我们只想存储pair对，不需要对其排序时，就可以用到与vector进行，将pair对插入其中即可。下面就使用做一些简单说明: 
声明vector：
'''
vector<pair<int,int> >vec
'''

往vector中插入数据，需要用到make_pair:
'''
vec.push_back(make_pair<int,int>(10,50));
vec.push_back(make_pair(20,30));
'''

### 定义迭代器：
'''
vector<pair<int,int> > ::iterator iter;
for(iter=vec.begin();iter!=vec.end();iter++);
'''
#### 数据读取：
- 第一个数据:(*iter).first
- 第二个数据:(*iter).second

