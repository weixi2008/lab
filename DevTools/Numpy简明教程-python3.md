
# Numpy简明教程 

Numpy是高性能科学计算和数据分析的基础包。主要对象是ndarray，它是一个N维数组对象，内部数据必须是同一种数据类型，也称为通用的同构数据多维容器。


```python
import numpy as np
```

## 基础属性
ndarray比较重要的属性包括ndim, shape与dtype等。


```python
a = np.arange(12).reshape(4, 3)
```


```python
# ndim 在numpy中，维度称为axes（dimension），其值称为rank。 如a的rank为2
a.ndim
```




    2




```python
# shape 表示各维度大小的元组
a.shape
```




    (4, 3)




```python
# size array中的元素个数
a.size
```




    12




```python
# dtype 数据类型，ndarray中的数据类型必须一致
a.dtype.name
```




    'int32'




```python
# itemsize 每个元素的大小，以byte为单位
a.itemsize
```




    4




```python
# data 实际元素内容的内存，一般情况下我们无需此属性。
a.data
```




    <memory at 0x0000017F0C59F1F8>



## 创建ndarray


```python
# 通过array方法，直接通过数组创建. dtype可以显示指定，numpy也可以自动推断。默认int32(这与numpy官方例子中的返回值不同，它为int64)
# 注意，必须传递一个数组[],而不是多个参数np.array(0,1,2)。会报错。
a = np.array([0,1,2])
a.dtype.name
```




    'int32'




```python
b = np.array([1.1, 2.2, 3.3])
b.dtype.name
```




    'float64'




```python
# 用数组嵌套数组的方式，可以创建多维ndarray。同时，可以显示指定dtype为float64
c = np.array([[0,1],[2,3]],dtype=np.float64)
c
```




    array([[ 0.,  1.],
           [ 2.,  3.]])




```python
# 提供了一些简便方法，来创建有初值的ndarray。注意，默认dtype为float64
# zeros 全0. 注意，参数必须是一个元组。
np.zeros((2,2))
```




    array([[ 0.,  0.],
           [ 0.,  0.]])




```python
np.ones((2,2))
```




    array([[ 1.,  1.],
           [ 1.,  1.]])




```python
# 虽然在我机器上为全0，但官方例子说是随机值，取决于内存。
np.empty((2,2))
```




    array([[ 0.,  0.],
           [ 0.,  0.]])




```python
# arange，提供了类似range的创建一系列数的方式
np.arange(10, 30, 5)
```




    array([10, 15, 20, 25])




```python
# 对于float数值，最好用linspace指定个数，而非使用arange来指定step。
np.arange(0, 2, 0.25)
```




    array([ 0.  ,  0.25,  0.5 ,  0.75,  1.  ,  1.25,  1.5 ,  1.75])




```python
np.linspace(0, 2, 9)
```




    array([ 0.  ,  0.25,  0.5 ,  0.75,  1.  ,  1.25,  1.5 ,  1.75,  2.  ])




```python

```
