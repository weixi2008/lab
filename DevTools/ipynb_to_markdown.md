

```python
# _*_ coding: utf-8 _*_
'''
递归当前目录及子目录中的ipynb，转为markdown
忽略以下目录：
.git: git repo目录
.ipynb_checkpoints: 临时存储目录
综上，忽略以.开头的目录
'''
import os

def path_should_ignore(path):
    head, tail = os.path.split(path)
    if tail.startswith('.'):
        return True
    else:
        return False
    
def list_ext_files(dir_path, ext):
    result_files = []
    for root, dirs, files in os.walk(dir_path):
        if path_should_ignore(root):
            continue
        for file in files:
            if file.endswith(ext):
                result_files.append(os.path.join(root, file))
    return result_files

# 注意：下面的注释语句没有输出， 虽然系统shell能够解析~/mygit, 但函数解析不了。
# print list_ext_files("~/mygit", ".ipynb")
# for Mac
# files = list_ext_files("/Users/weixi/mygit", ".ipynb")
# for Windows
files = list_ext_files('D:/MyGit/lab/DevTools', '.ipynb')
```


```python
for file in files:
    command = "jupyter nbconvert --to markdown {}".format(file);
    os.system(command)
```
