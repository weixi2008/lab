================================================================================
    VC2008 : TestFileEncoding 项目概述
===============================================================================

此工程用几个编码不同的文件，测试了VisualStudio 2008 对于不同编码的文件的支持情况。

因为git及github的diff不支持UTF16编码的文件，而FNP的源代码的编码为UTF16的，因此创建一个工程测试多编码。

头文件
UTF16BOM.h	带BOM头的UTF16文件，codepage为1200
UTF8BOM.h	带BOM头的UTF8文件， codepage为65001
UTF8.h		不带BOM头的UTF16文件， codepage为65000
每个文件中都是中日文混合。
过程
1. UTF8.h, VC编译失败。因为编译器将此文件的代码页识别为936，应该是编译器的问题。
2. UTF8BOM.h, VC编译成功。并且git及github可以比较差异。
3. UTF16BOM.h, VC编译成功。但git识别为二进制文件，无法比较差异。
4. 资源文件rc，只能用ANSI编码或UTF16（1200）编码。因为rc编译器仅支持上述两种，不支持UTF8

结论：
1. 源文件.h,.cpp等，使用带BOM头的UTF8文件， codepage为65001。（第3条为特例）
2. rc文件，使用带BOM头的UTF16文件，codepage为1200。
3. resource.h， 使用与rc一样的UTF16编码。 因为即使使用utf8编码，在用资源编辑器编辑后，也会变为ansi编码。 而使用utf16编码会保留。


参考资料：
1. BOM头
Byte-order mark Description 
EF BB BF UTF-8 
FF FE UTF-16 aka UCS-2, little endian 
FE FF UTF-16 aka UCS-2, big endian 
00 00 FF FE UTF-32 aka UCS-4, little endian. 
00 00 FE FF UTF-32 aka UCS-4, big-endian.
http://www.cnblogs.com/DDark/archive/2011/11/28/2266085.html

2. VC2008的资源编辑器，仅支持ansi编码或utf16编码。不支持utf8编码，否则编译资源会失败。
Resource files encoded as UTF-8 do not compile     
https://social.msdn.microsoft.com/Forums/vstudio/en-US/e212069d-678e-4ac8-957f-7d60d3e1c89f/resource-files-encoded-as-utf8-do-not-compile?forum=vcgeneral
Error RC2135 in C++ project due to UTF-8 encoding of RC file
https://stackoverflow.com/questions/15244065/error-rc2135-in-c-project-due-to-utf-8-encoding-of-rc-file

