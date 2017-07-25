
# IPython简明教程 

## 四个重要的Help
两种模式：命令模式及编辑模式。 用Esc切换至命令模式，用Enter切换至编辑模式。


## Magic functions

Line magics: 以%开头
Cell magics: 以%%开头


```python
lists = [i for i in range(5)]
lists?

%timeit range(1000)


```

    The slowest run took 7.16 times longer than the fastest. This could mean that an intermediate result is being cached.
    100000 loops, best of 3: 6.39 µs per loop
    


```python
%lsmagic
```




    Available line magics:
    %alias  %alias_magic  %autocall  %automagic  %autosave  %bookmark  %cat  %cd  %clear  %colors  %config  %connect_info  %cp  %debug  %dhist  %dirs  %doctest_mode  %ed  %edit  %env  %gui  %hist  %history  %killbgscripts  %ldir  %less  %lf  %lk  %ll  %load  %load_ext  %loadpy  %logoff  %logon  %logstart  %logstate  %logstop  %ls  %lsmagic  %lx  %macro  %magic  %man  %matplotlib  %mkdir  %more  %mv  %notebook  %page  %pastebin  %pdb  %pdef  %pdoc  %pfile  %pinfo  %pinfo2  %popd  %pprint  %precision  %profile  %prun  %psearch  %psource  %pushd  %pwd  %pycat  %pylab  %qtconsole  %quickref  %recall  %rehashx  %reload_ext  %rep  %rerun  %reset  %reset_selective  %rm  %rmdir  %run  %save  %sc  %set_env  %store  %sx  %system  %tb  %time  %timeit  %unalias  %unload_ext  %who  %who_ls  %whos  %xdel  %xmode
    
    Available cell magics:
    %%!  %%HTML  %%SVG  %%bash  %%capture  %%debug  %%file  %%html  %%javascript  %%js  %%latex  %%perl  %%prun  %%pypy  %%python  %%python2  %%python3  %%ruby  %%script  %%sh  %%svg  %%sx  %%system  %%time  %%timeit  %%writefile
    
    Automagic is ON, % prefix IS NOT needed for line magics.




```python
%run test_run.py
```

    /Users/weixi/mygit/lab/DevTools/Conda简明教程.ipynb
    /Users/weixi/mygit/lab/DevTools/ipynb_to_markdown.ipynb
    /Users/weixi/mygit/lab/DevTools/IPython简明教程.ipynb
    /Users/weixi/mygit/lab/DevTools/Python闭包与装饰器.ipynb
    /Users/weixi/mygit/lab/DevTools/testIPython.ipynb
    /Users/weixi/mygit/lab/DevTools/十大方程.ipynb
    


```python
!iPython profile locate default
```

    /Users/weixi/.ipython/profile_default



```python
ls /Users/weixi/.ipython/profile_default
```

    [34mdb[m[m/                       ipython_kernel_config.py  [34msecurity[m[m/
    history.sqlite            [34mlog[m[m/                      [34mstartup[m[m/
    ipython_config.py         [34mpid[m[m/



```python
from IPython.lib import passwd
my_psss = passwd('weixi')
my_psss

```




    'sha1:03f62c0d5d14:490f11660e2c1209cd19ecc206c9646e429a028e'




```python
%who
```

    file	 files	 i	 list_ext_files	 lists	 my_psss	 os	 passwd	 path_should_ignore	 
    
    


```python
class MyData(object):
    pass

mathObj = MyData()
mathObj.x = 10
mathObj.y = 20
z = mathObj.x + mathObj.y
z
```




    30




```python
class AddressBook(object):
    def __init__(self, name, phone):
        self.name = name
        self.phone = phone
        print "Address create: {}, {}".format(self.name, self.phone)

class EmpolyeeAB(AddressBook):
    def __init__(self, name, phone, title):
#         super(EmpolyeeAB, self).__init__(name, phone)
        AddressBook.__init__(self, name, phone)
        self.title = title
        print "Employee create: {}".format(self.title)

eab = EmpolyeeAB("weixi", "130", "cxo")

print eab.title, eab.name, eab.phone
```

    Address create: weixi, 130
    Employee create: cxo
    cxo weixi 130
    


```python
import this
```

    The Zen of Python, by Tim Peters
    
    Beautiful is better than ugly.
    Explicit is better than implicit.
    Simple is better than complex.
    Complex is better than complicated.
    Flat is better than nested.
    Sparse is better than dense.
    Readability counts.
    Special cases aren't special enough to break the rules.
    Although practicality beats purity.
    Errors should never pass silently.
    Unless explicitly silenced.
    In the face of ambiguity, refuse the temptation to guess.
    There should be one-- and preferably only one --obvious way to do it.
    Although that way may not be obvious at first unless you're Dutch.
    Now is better than never.
    Although never is often better than *right* now.
    If the implementation is hard to explain, it's a bad idea.
    If the implementation is easy to explain, it may be a good idea.
    Namespaces are one honking great idea -- let's do more of those!
    


```python
colors = ['red','green','blue']
str_colors = ','.join(colors)
str_colors
```




    'red,green,blue'




```python
type(range(10))
type(reversed(range(10)))
list(reversed(range(10)))
```




    [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]




```python
a = [1, 2, 3, 4, 5, 6]
zip(*([iter(a)]*1))

from itertools import islice
```


```python
def one(*x):
    print x[0]
a = [1, 2, 3, 4, 5, 6]
one(*a)
```

    1
    


```python
import keyword
print keyword.kwlist
```

    ['and', 'as', 'assert', 'break', 'class', 'continue', 'def', 'del', 'elif', 'else', 'except', 'exec', 'finally', 'for', 'from', 'global', 'if', 'import', 'in', 'is', 'lambda', 'not', 'or', 'pass', 'print', 'raise', 'return', 'try', 'while', 'with', 'yield']
    


```python

```
