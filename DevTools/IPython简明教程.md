
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

    100000 loops, best of 3: 6.49 µs per loop
    


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




    'sha1:89a3f0ccfb1b:769802f294cbb05b18db3a28180fdf54222fe190'




```python
%who
```

    Interactive namespace is empty.
    
