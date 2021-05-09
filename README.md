# hash-lock
本次作业使用visual studio完成，共包含一个newstruct.h头文件和一个hash-lock.cpp主程序
哈希函数说明：
1.本次使用hash算法为KEY除5商a余b，hash（KEY）=10*a+b
使用方法：
1.使用add添加具有新ID的标签，返回该ID在服务器中分配到metalid
2.使用read阅读标签，阅读的值为该标签对应的metalid
3.输入e退出程序
范例：
1.添加ID为12的标签（在命令窗口输入add12）。
返回ID:12 add successfully with metalid152
2.阅读器阅读到metalid=152的标签（在命令窗口输入read152），即可进行匹配。
返回：find key:77 for metalid:152
ID:12 match successfuly
在命令窗口输入read153，因数据库只添加了ID：12标签的各种信息无法找到152对应metalid
返回：cannot find
3.可连续添加新标签活跃度标签。
4.退出程序（在命令窗口输入e）。
