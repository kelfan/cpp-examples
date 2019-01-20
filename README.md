# cpp-examples
simple c++ examples with functions, class, gtest and etc 

# & in argument = pass by reference

# 'L' means wchar_t, which, as opposed to a normal character, requires 16-bits of storage rather than 8-bits. Here's an example:
```cpp
"A"    = 41
"ABC"  = 41 42 43
L"A"   = 00 41
L"ABC" = 00 41 00 42 00 43
```


# 数据结构 
- vector的特色有支持随机存取，在集合尾端增删元素很快，但是在集合中间增删元素比较费时。

# 基本数据类型的引用
```cpp
#include <iostream>

using namespace std;
int main(void)
{
	int a=3;
	int &b=a; // 引用必须初始化 

	b=10;
	cout<<a<<endl;
	return 0;
}
```

# 结构体类型的引用 
```cpp
typedef struct 
{
	int x;
	int y;
}Coor; 

#include <iostream>
using namespace std;
int main(void)
{
	Coor c1;
	Coor &c=c1;
	c.x=10;
	c.y=20;
	cout<<c1.x<<c1.y;
	return 0;
}
```

# 指针类型的引用 
类型 *&指针引用名=指针;

```cpp
#include <iostream>
using namespace std;
int main(void)
{
	int a=10;
	int *p=&a;
	int *&q=p;
	*q=20;
	cout<<a<<endl;
	return 0;
}
```

# 引用作函数参数 
```cpp
void fun(int *a,int *b)
{
	int c=0;
	c=*a;
	*a=*b;
	*b=c;
}
int x=10, y=20;
fun(&x,&y);

对比 

void fun(int &a, int &b)
{
	int c=0;
	c=a; 
	a=b; 
	b=c;
}
```

# inline:内联函数 
内联函数是建议性的,由编译器决定
适用于
	逻辑简单,调用频繁的函数
递归函数无法使用内联方式 

```cpp
inline int max(int a, int b, int c);
int main()
{
	int i=10,j=20,k=30, m;
	m= max(i,j,k);
	cout<<"max="<<m<<endl;
	return 0;
}

-> 编译的时候上面的函数会变成
int main()
{
	int i=10,j=20,k=30, m;
	// 注意下面的变化
	int a,b,c;
	// 下面的部分型党与 m=max(i,j,k);
	a=i; b=j; c=k;
	if(b>a) a=b;
	if(c>a) a=c;
	m=a;
	cout<<"max="<<m<<endl;
	return 0;
}
```


# 内存管理: 申请/归还资源
内存本质是资源 
	-> 操作系统管理内存 
	-> 我们只能做 申请/归还 
内存管理 
	= 申请/归还内存资源

```cpp
// 申请内存
int *p = new int;

// 释放内存 
delete p;

// 申请块内存
int *arr = new int[10];

// 释放块内存 
delete []arr;
```

c语言管理方式,配套使用,不能混搭 

```c
// 申请内存 
void *malloc(size_t size);

// 释放内存 
void free(void *memblock);
```
注意事项 -> 内存分配失败 

```cpp
int *p=new int;
if(NULL == p)
{
	// 内存分配失败
	// 异常处理 
}
delete p;
p = NULL;

// 处理块
int *p=new int[1000];
if(NULL == p)
{
	// 内存分配失败
	// 异常处理 
}
delete []p;
p = NULL;

```

# ~:波浪号 表示析构函数 补数
这个表示这个是类的析构函数（可以理解为反构造函数，在类对象销毁前被系统调用）。
比特一的补数	~a	前置

# cygwin vs minGW
- Compile something in Cygwin and you are compiling it for Cygwin. 
  - The purpose of Cygwin is to make porting Unix-based applications to Windows much easier
- Compile something in MinGW and you are compiling it for Windows.
  - MinGW aims to simply be a Windows port of the GNU compiler tools, such as GCC, Make, Bash, and so on.


# Google test 是unit test
# GoogleMock是个很强大的东西，测试一个模块的时候，可能涉及到和其他模块交互，可以将模块之间的接口mock起来，模拟交互过程。

# inline: 内联函数 插入编译-->减少调用时间


# 数据结构 
- vector的特色有支持随机存取，在集合尾端增删元素很快，但是在集合中间增删元素比较费时。
- int arr[4] ={1,2,3,4}

# 基本数据类型的引用
```cpp
#include <iostream>

using namespace std;
int main(void)
{
	int a=3;
	int &b=a; // 引用必须初始化 

	b=10;
	cout<<a<<endl;
	return 0;
}
```

# 结构体类型的引用 
```cpp
typedef struct 
{
	int x;
	int y;
}Coor; 

#include <iostream>
using namespace std;
int main(void)
{
	Coor c1;
	Coor &c=c1;
	c.x=10;
	c.y=20;
	cout<<c1.x<<c1.y;
	return 0;
}
```

# 指针类型的引用 
类型 *&指针引用名=指针;

```cpp
#include <iostream>
using namespace std;
int main(void)
{
	int a=10;
	int *p=&a;
	int *&q=p;
	*q=20;
	cout<<a<<endl;
	return 0;
}
```

# 引用作函数参数 
```cpp
void fun(int *a,int *b)
{
	int c=0;
	c=*a;
	*a=*b;
	*b=c;
}
int x=10, y=20;
fun(&x,&y);

对比 

void fun(int &a, int &b)
{
	int c=0;
	c=a; 
	a=b; 
	b=c;
}
```

# inline:内联函数 
内联函数是建议性的,由编译器决定
适用于
	逻辑简单,调用频繁的函数
递归函数无法使用内联方式 

```cpp
inline int max(int a, int b, int c);
int main()
{
	int i=10,j=20,k=30, m;
	m= max(i,j,k);
	cout<<"max="<<m<<endl;
	return 0;
}

-> 编译的时候上面的函数会变成
int main()
{
	int i=10,j=20,k=30, m;
	// 注意下面的变化
	int a,b,c;
	// 下面的部分型党与 m=max(i,j,k);
	a=i; b=j; c=k;
	if(b>a) a=b;
	if(c>a) a=c;
	m=a;
	cout<<"max="<<m<<endl;
	return 0;
}
```


# 内存管理: 申请/归还资源
内存本质是资源 
	-> 操作系统管理内存 
	-> 我们只能做 申请/归还 
内存管理 
	= 申请/归还内存资源

```cpp
// 申请内存
int *p = new int;

// 释放内存 
delete p;

// 申请块内存
int *arr = new int[10];

// 释放块内存 
delete []arr;
```

c语言管理方式,配套使用,不能混搭 

```c
// 申请内存 
void *malloc(size_t size);

// 释放内存 
void free(void *memblock);
```
注意事项 -> 内存分配失败 

```cpp
int *p=new int;
if(NULL == p)
{
	// 内存分配失败
	// 异常处理 
}
delete p;
p = NULL;

// 处理块
int *p=new int[1000];
if(NULL == p)
{
	// 内存分配失败
	// 异常处理 
}
delete []p;
p = NULL;

```

# ~:波浪号 表示析构函数 补数
这个表示这个是类的析构函数（可以理解为反构造函数，在类对象销毁前被系统调用）。
比特一的补数	~a	前置

# cygwin vs minGW
- Compile something in Cygwin and you are compiling it for Cygwin. 
  - The purpose of Cygwin is to make porting Unix-based applications to Windows much easier
- Compile something in MinGW and you are compiling it for Windows.
  - MinGW aims to simply be a Windows port of the GNU compiler tools, such as GCC, Make, Bash, and so on.


# Google test 是unit test
# GoogleMock是个很强大的东西，测试一个模块的时候，可能涉及到和其他模块交互，可以将模块之间的接口mock起来，模拟交互过程。

# inline: 内联函数 插入编译-->减少调用时间

# 指针指向常量 const int const *p = &a;
# const *变量 vs * const 变量
- const *变量 = 固定值
- * const 变量 = 固定变量
- const &变量 = 固定别名 

# & 取别名/传参/取地址
# & 获取变量地址

# 指针类型引用 --> 类型 *&变量=指针
# *指针 &别名
- 别名必须初始化

# return this 
https://stackoverflow.com/questions/6919330/return-this-in-c
```cpp
myclass& myclass::MULT(int scalar){
      member1_ *= scalar;
      return *this; 
}
myclass* myclass::MULTP(double scalar){
      member2_ *= scalar;
      return this; 
}
```

# 添加 library 
1. 先静态编译文件
2. 找到编译后的include和lib文件夹
3. VC++ Dirctories 添加  Include Directories (include文件夹) 和 library directories (lib文件夹)
4. Linker/Input 下的 Additional Dependencies 添加相关.lib 如 (lib文件夹下的 .lib 文件)
5. C/C++|Preprocessor 下添加相关预编译变量
6. 修改 Code Generation 下的 runtime library


# curllib build success
[Visual Studio(VS2017)编译并配置C/C++-libcurl开发环境](https://blog.csdn.net/DaSo_CSDN/article/details/77587916)

1. x64 运行 
   1. 下载解压libcurl
      1. 运行 `buildconf.bat`
   2. 运行 x64 Native Tools Command Prompt for VS 2017
      1. cd 定位到 libcurl 下的 `winbuild` 文件夹 如 `cd E:\cpp\curl-7.63.0\winbuild`
      2. 静态编译 `nmake /f Makefile.vc mode=static VC=15 MACHINE=x64 DEBUG=yes`
         1. model=static 静态编译; model=dll 动态编译
         2. MACHINE=x64 64位; MACHINE=x86 32位;
         3. DEBUG=no; DEBUG=yes; -> 开启debug
         4. VC=15 是 VS2017
         5. 更详细的编译指令及说明可以打开winbuild文件夹中的`BUILD.WINDOWS.txt`查看
      3. 查看 `builds` 文件夹下的最短文件 如 `E:\cpp\curl-7.63.0\builds` 下的 `E:\cpp\curl-7.63.0\builds\libcurl-vc15-x64-debug-static-ipv6-sspi-winssl`
   3. 设置 VS 项目的 Properties: 右键 -> Properties
      1. VC++ Dirctories 里设置
         1. Include Directories 添加后如 `E:\cpp\curl-7.63.0\builds\libcurl-vc15-x64-debug-static-ipv6-sspi-winssl\include;$(IncludePath)`
         2. library directories 添加后如 `E:\cpp\curl-7.63.0\builds\libcurl-vc15-x64-debug-static-ipv6-sspi-winssl\lib;$(LibraryPath)`
      2. Linker/Input 下设置
         1. Additional Dependencies 添加后如 `libcurl_a_debug.lib;Ws2_32.lib;Wldap32.lib;winmm.lib;Crypt32.lib;Normaliz.lib;%(AdditionalDependencies)`
            1. libcurl_a.lib 或 libcurl_a.lib 是 E:\cpp\curl-7.63.0\builds\libcurl-vc15-x64-debug-static-ipv6-sspi-winssl\lib 下的lib包
      3. C/C++|Preprocessor 下
         1. `Preprocessor Definitions` 添加 `CURL_STATICLIB`
            1. 本文使用了静态编译libcurl，所以需要将CURL_STATICLIB添加至工程
            2. 如 CURL_STATICLIB;_DEBUG;_CONSOLE;%(PreprocessorDefinitions)
      4. Debug 不用修改 Code Generation 下的 Runtime Library 
         1. 如果没有编译debug版libcurl，则需要将“Runtime Library”改为Release版（即后面不带小写字母d）。同时官方并不建议使用“/MT”或“/MTd”。 
2. x86 运行
   1. 下载解压如上
   2. 运行 x86 Native Tools Command Prompt for VS 2017
      1. 静态编译 其他如上 除了 静态编译改为   `nmake /f Makefile.vc mode=static VC=15 MACHINE=x86 DEBUG=yes`
   3. 其他一样

测试代码
```c++
#include "pch.h"
#include <curl/curl.h>    

int main(int argc, char* argv[]) {
    CURL *curl = 0;
    CURLcode res;
    curl = curl_easy_init();
    if (curl != 0) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.baidu.com");
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        /* always cleanup */
        curl_easy_cleanup(curl);
    }

    return 0;
}
```


# curllib 
- [【libcurl】Visual Studio 2017编译和配置libcurl开发环境](https://blog.csdn.net/bency/article/details/80773932)
- [Visual Studio(VS2017)编译并配置C/C++-libcurl开发环境](https://blog.csdn.net/DaSo_CSDN/article/details/77587916)

- [Download file using libcurl in C/C++](https://stackoverflow.com/questions/1636333/download-file-using-libcurl-in-c-c)
- [Simple C++ HTTP download using libcurl easy API &#8211; TechOverflow](https://techoverflow.net/2013/03/15/simple-c-http-download-using-libcurl-easy-api/)
- [Using the curl library from C++ on Windows](https://mariusbancila.ro/blog/2018/03/13/using-curl-library-from-c-on-windows/)
- [libcurl库（C++）快速使用 - Oshyn —— 乐而学，学而乐 - CSDN博客](https://blog.csdn.net/u010487568/article/details/52958367)
- [【网络编程】httpClient抓取网页--linux C/C++ - mockmoon2011的专栏 - CSDN博客](https://blog.csdn.net/mockmoon2011/article/details/17962871)
- [C++ 用libcurl库进行http通讯网络编程 - 绿色冰点 - 博客园](https://www.cnblogs.com/moodlxs/archive/2012/10/15/2724318.html)
- [c里面使用libcurl库实现发送post并获取post到的内容](https://www.jianshu.com/p/9b5134fdbc29)
- [libcurl example - url2file.c](https://curl.haxx.se/libcurl/c/url2file.html)
- [libCURL开源库在VS2010环境下编译安装，配置详解 - flylong0204 - 博客园](https://www.cnblogs.com/flylong0204/p/4723155.html)
- [Visual Studio(VS2017)编译并配置C/C++-libcurl开发环境 - 九黑生魂 - CSDN博客](https://blog.csdn.net/DaSo_CSDN/article/details/77587916)

```cpp
#define CURL_STATICLIB
  #include <curl/curl.h>
  
  int main(int argc, char * argv[])
  {
      printf("%s\n", "main.cpp");
  
      CURL *curl;
      CURLcode res;
  
      curl = curl_easy_init();
      if (!curl)
      {
          printf("error\n");
          return 0;
      }
  
      curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com/");
      res = curl_easy_perform(curl);
  
      if (res != CURLE_OK)
          fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
  
      curl_easy_cleanup(curl);
  
      return 0;
  }

作者：研匠
链接：https://www.jianshu.com/p/518fc89abf2c
來源：简书
简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。
```


# webcrawler 
- [C++ A Simple Web Crawler](https://www.example-code.com/vcpp/spider_simpleCrawler.asp)
- [A very simple C++ web crawler/spider?](https://stackoverflow.com/questions/4278024/a-very-simple-c-web-crawler-spider)
- [Spider Examples for C++](https://www.example-code.com/vcpp/spider.asp)
- [MelvinKool/WebCrawler](https://github.com/MelvinKool/WebCrawler)


# fopen vs fopen_s 
https://blog.csdn.net/xingcen/article/details/56014478

# error LNK2019: unresolved external symbol __imp_curl_easy_init referenced
```cpp
#pragma comment(lib, "libcurl_imp.lib") 
```
- [Working with cURL:: Getting started the easy way (on Win32)](https://bobobobo.wordpress.com/2008/11/08/working-with-curl-getting-started-the-easy-way-on-win32/)
- [What can I solve the problem &quot;error LNK2019: unresolved external symbol&quot;](https://social.msdn.microsoft.com/Forums/vstudio/en-US/1bd29762-2469-4ab7-812a-cb042a4de83c/what-can-i-solve-the-problem-quoterror-lnk2019-unresolved-external-symbolquot?forum=vcgeneral)
- [VC++调用libcurl的VC库使用详解 -  - ITeye博客](https://dewei.iteye.com/blog/1572016)
- [Option for using static version of libcurl (Visual Studio 14 2015) · Issue #196 · whoshuu/cpr](https://github.com/whoshuu/cpr/issues/196)
- [Visual Studio 2015 curl will not statically link](https://stackoverflow.com/questions/41762859/visual-studio-2015-curl-will-not-statically-link)

# string error: argument of type "const char *" is incompatible with parameter type "LPCWSTR"
CreateDirectory("./img", NULL); --> CreateDirectory(L"./img", NULL);

# 在字符串前加一个L作用:  
  如 L"我的字符串" 表示将ANSI字符串转换成unicode的字符串，就是每个字符占用两个字节。  
  strlen("asd") = 3;   
  strlen(L"asd") = 6;  

C++在字符串前加一个L作用:

# _T宏可以把一个引号引起来的字符串，根据你的环境设置，使得编译器会根据编译目标环境选择合适的（Unicode还是ANSI）字符处理方式
   如果你定义了UNICODE，那么_T宏会把字符串前面加一个L。这时 _T("ABCD") 相当于 L"ABCD" ，这是宽字符串。 
   如果没有定义，那么_T宏不会在字符串前面加那个L，_T("ABCD") 就等价于 "ABCD"
--------------------- 
作者：whz_zb 
来源：CSDN 
原文：https://blog.csdn.net/whz_zb/article/details/7446901 
版权声明：本文为博主原创文章，转载请附上博文链接！

# #include <WinSock2.h> redefine error 
在#include <Windows.h> 前加上 #include <WinSock2.h> 
https://stackoverflow.com/questions/1372480/c-redefinition-header-files-winsock2-h

# no operator “<<” matches these operands [duplicate]
If you want to use `std::string` reliably, you must `#include <string>`.

# error C3646: 'm_host': unknown override specifier -> 有可能是namespace没用对 在类型前指定namespace


# separate file and folders
- [C++ Separate Header And Source Folders In Visual Studio 2017](https://www.youtube.com/watch?v=HExn9oTqdVo)
- [带你玩转 Visual Studio——带你多工程开发: 一个 Solution 多个 Project](http://wiki.jikexueyuan.com/project/visual-studio/11.html)


# 添加外部 DLL 项目
http://wiki.jikexueyuan.com/project/visual-studio/11.html
- 右键 solution -> add new project -> windows desktop | static library
- 右键 references -> add references
- 右键 project -> properties -> C/C++ 下 General Directories -> Additional Include Directories 添加相对路径如 "../Utils"
