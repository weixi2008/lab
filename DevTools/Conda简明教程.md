
# Conda 简明教程

## Conda是什么

一句话，Conda是包（Package）、依赖（Dependency）及环境（Environment）的管理工具。对于python来讲，它相当于pip+virtualenv。本文以Mac OS下的Conda为例进行说明。使用Conda可以管理多个Python环境，本文以安装Python3为例。

**Conda的设计理念是将一切可管理的包都视为package，甚至包括python以及conda自身。**基于此，可以使用conda升级conda自身。


## 安装Conda

1. 安装Anaconda,直接在[官网](https://www.continuum.io)下载相应的安装程序，安装即可。下面以安装Anaconda 4.3.1 For macOS的Python 2.7版本为例。
2. 设置Path：Anaconda 3.4.1会自动在~/.profile文件中加入下述Path。如果cat后发现没有，可以用如下语句加入。

```bash
# 将anaconda的bin目录加入PATH
echo 'export PATH="~/anaconda/bin:$PATH"' >> ~/.bashrc
# 更新bashrc以立即生效
source ~/.bashrc
```

3. 设置国内镜像

```bash
# 添加清华镜像，会生成~/.condarc
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
# 设置搜索时显示通道地址
conda config --set show_channel_urls yes
```

4. 验证

```bash
# conda的安装信息
conda --version
conda info
# 当前所有安装的环境, 带*号的为当前激活的环境
conda env list
```

## 使用Conda管理环境

通过Conda，我们可以安装多个不同版本的Pyton，并能进行环境切换。下面以安装Python3为例。

```bash
# 安装python3
conda create --name python3 python=3
# 激活python3
source activate python3
# 确认python版本
which python
python --version
# 列出python3下安装的包
conda list
# 退出python3的环境
source deactivate
# 当前所有安装的环境, 带*号的为当前激活的环境
conda env list
# 删除python3
conda remove --name python3 --all
```

## 使用Conda管理包

类似pip，通过conda，我们可以管理多个环境中的包。

```bash
# 列出当前环境下安装的包，或者其他环境安装的包
conda list
conda list --name python3

# 为当前环境安装numpy, 或者其他环境安装numpy
conda install numpy
const install --name python3 numpy

# 更新包
conda update numpy

#删除包
conda remove numpy

#甚至可以利用conda管理conda
conda update conda
conda update anaconda
conda update python

```
## 备注

上述命令的参数，很多都可以用短参数替代。例如 --version = -v, --name = -n 等。

## 参考资料

1. [Conda官方文档](https://docs.continuum.io/docs_oss/conda/)
2. [conda vs. pip vs. virtualenv](https://conda.io/docs/_downloads/conda-pip-virtualenv-translator.html)
3. [PterYuan: Anaconda使用总结](http://www.jianshu.com/p/2f3be7781451#)

