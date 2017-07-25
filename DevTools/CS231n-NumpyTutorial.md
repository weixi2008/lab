

```python
#快速排序
def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + middle + quicksort(right)

print(quicksort([3,6,9,10,8,2,7,1,5,1,4,8]))
```

    [1, 1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 10]
    


```python
#带index的枚举，以及%来format
animals = ['cat', 'dog', 'monkey']
for idx, animal in enumerate(animals):
    print('#%d: %s' % (idx+1, animal))
```

    #1: cat
    #2: dog
    #3: monkey
    


```python
#列表推导
nums = [0, 1, 2, 3, 4]
even_squares = [x ** 2 for x in nums if x % 2 == 0]
print(even_squares)
```

    [0, 4, 16]
    


```python
#Numpy Array
#numpy array是一组网格化的数据，这些数据的类型完全相同（不同于Python自带的list），并且被非0整数作为索引。有两个属性。 
#dimension维度，描述了array的级数。
#shape描述了给定维度下的数组形状。
import numpy as np

a = np.array([1,2,3])
print(type(a))
print(a.shape)
print(a.ndim)
```

    <class 'numpy.ndarray'>
    (3,)
    1
    
