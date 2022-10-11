# Help-Goods——上海交通大学软件工程课程作业（一）
## 声明  
&emsp;&emsp;本项目为上海交通大学软件工程第一次课程作业。由于本人目前水平所限，本程序主要目的为训练规范编程和回顾基础知识。程序以命令行的方式运行，仅能实现基础功能，没有针对不规范输入的预防措施，点一碗炒饭就会崩溃。（感觉不如Excel实用）  
## PSP统计  
https://www.cnblogs.com/zyq39n/p/16750974.html  
## 程序介绍  
&emsp;&emsp;使用一个txt文件用于存储物品信息，创了一个Object类，成员为物品名称和信息。每次操作前，使用readTXT函数读取文件中的信息并全部存储在Object的线性表中。addObject，deleteObject，dispalyObject和findObejct四个函数分别进行物品的添加、删除、显示物品列表和查找物品。每次操作后，使用saveTXT将Object线性表中的数据存储在txt文件里。其余辅助函数都进行了封装，不在main函数中出现。（反复读取+存储的意义是防止程序不小心关闭后数据丢失）  
&emsp;&emsp;在用户端，只需通过0-4选择想要的功能后按提示操作即可。每个操作都有详尽的提示，绝对保姆级。（绝对不是怕用户点炒饭导致程序崩溃）  
## 程序的不足  
&emsp;&emsp;由于在进行这个项目之前已经许久没写过程序，很多东西都是我做完后才想起来。以及还有部分问题由于本人水平所限，暂不能想出好的解决方案。目前发现的问题有：  
&emsp;&emsp;1.由于>> 在遇到空格时会断掉，所以如果物品的名称和物品信息中间有空格，会使readTXT把txt中文字转化为Object时发生严重错误。本人暂时想不到解决这个问题的方法，或许不使用输入流的读取txt的函数可以避开这个问题。  
&emsp;&emsp;2.Object类没有物尽其用，仅仅是相当于一个结构体。四大功能函数可以作为Object类的公有成员，辅助函数作为私有成员。把函数放在类中，可以使这个Object类变得完善，同时以后如果有修改复用的需求也会更加容易。  
&emsp;&emsp;3.本程序中线性表有256个的上限，并且没有设置doubleSpace函数。使用链表代替线性表，可以在不浪费空间的同时避免物品种类达到上限，同时降低删除物品的时间复杂度。  
## 总结  
&emsp;&emsp;这个程序作为一个cpp实现了它需要的功能，但从软件工程的角度来讲，仍有许多优化空间。
