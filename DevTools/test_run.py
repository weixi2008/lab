
# coding: utf-8

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

files = list_ext_files("/Users/weixi/mygit", ".ipynb")
for file in files:
    print file
