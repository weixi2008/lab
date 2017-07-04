================================================================================
    MICROSOFT 基础类库: TestFileEncoding 项目概述
===============================================================================

此工程用几个编码不同的文件，测试了VisualStudio对于不同编码的文件的支持情况。

因为git及github的diff不支持UTF16编码的文件，而FNP的源代码的编码为UTF16的，因此创建一个工程测试多编码。

头文件
UTF16BOM.h	带BOM头的UTF16文件，codepage为1200
UTF8BOM.h	带BOM头的UTF8文件， codepage为65001
UTF8.h		不带BOM头的UTF16文件， codepage为65000
每个文件中都是中日文混合。

1. UTF8.h, VC编译失败。因为编译器将此文件的代码页识别为936，应该是编译器的问题。
2. UTF8BOM.h, VC编译成功。并且git及github可以比较差异。
3. UTF16BOM.h, VC编译成功。但git识别为二进制文件，无法比较差异。
4. 资源文件rc，只能用ANSI编码或UTF16（1200）编码。因为rc编译器仅支持上述两种，不支持UTF8

结论：
源文件.h,.cpp等，使用带BOM头的UTF8文件， codepage为65001。
rc文件，使用带BOM头的UTF16文件，codepage为1200。


参考资料：
BOM头
Byte-order mark Description 
EF BB BF UTF-8 
FF FE UTF-16 aka UCS-2, little endian 
FE FF UTF-16 aka UCS-2, big endian 
00 00 FF FE UTF-32 aka UCS-4, little endian. 
00 00 FE FF UTF-32 aka UCS-4, big-endian.

http://www.cnblogs.com/DDark/archive/2011/11/28/2266085.html
