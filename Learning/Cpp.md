# 概述

C++的**内容、特性**远比课程中学习的部分要多，多积累，多实践，才能“熟练掌握C++”。

## 智能指针

动机：程序员申请动态内存时，若没有释放内存，归还操作系统，会找内存泄漏的问题。智能指针就是为了解决这种情况。

实现原理：在C++中，类变量的生命周期结束时，会自动调用析构函数，在析构函数中设置自动释放内存的功能，有效避免内存泄漏。

四种智能指针：
1. `auto_ptr`：(98提出，11废弃)当多个智能指针指向同一个初始指针时，可能发生问题；
2. `unique_ptr`：独占式，不允许智能指针相互赋值，或多个智能指针指向同一个指针；
3. `share_ptr`：共享式，内部有计数器，当最后一个指向指针的引用被销毁时，释放内存；
4. `weak_ptr`：弱引用，解决`share_ptr`可能引起的死锁问题。

> 智能指针如何实现内存保护？\
> 利用局部变量销毁时自动调用析构函数的机制，在析构函数中释放指针指向内容并将指针置为空；\
> 需要实现哪些内容？\
> 需要将指针的重定义所有指针运算符（*、++、->等）

## 指针、引用

从函数参数传递角度看：
- 指针的本质是值传递，传递值是参数的地址，对地址中内容的修改需要程序员显式地对地址操作；
- 引用传递则是隐式地传递参数地址，函数内对形参的操作会被映射到原变量，该工作由编译器在编译时完成。

## 关键字

- **const**
- **static**
- **virtual**：用于声明虚函数，实现多态的一种重要方法。
- **default**
- **final**：禁用继承、覆盖，该关键字在C++11提出，修饰类时，可以禁止该类被其他类继承；修饰虚函数时，可以防止虚函数被覆盖。\
  与其它修饰符不同，该关键字常放在被修饰变量后。
  ```cpp
  class F final { };
  class F {
      virtual void func final () {}
  };
  ```
  在C++11以前，可以通过私有构造函数的方法禁用继承，该方法让其无法被任何其他类构造，从而间接禁止继承。缺点在于其同样限制了类的使用，需要另外实现一个静态成员函数用于实体化类。

# C++11

> C++的三大特性：**封装、继承、多态**，同时也是面向对象编程的特性。

## 面向对象编程

思想：面向对象编程就是把问题分解成各个对象，建立对象的目的不是为了完成一个步骤，而是为了描述某个事物在整个解决问题的步骤中的行为。

## 封装

将客观事物封装成抽象的类，并赋予抽象类对自身数据和方法的控制访问权限，仅让该类信任的类或方法访问。

## 继承

派生类继承父类，获得父类的属性，可以调用父类的方法，并运行派生类在父类基础上进行拓展，实现更多功能。

继承特性提高了代码的拓展性、可复用性。

## 多态

向不同的对象发送同一个消息，不同对象会有调用不同的方法，即一个接口(同名函数)实现多种方法。

多态实现的基础是动态绑定，编译器预先制作同名函数(接口)表，当调用该函数时，具体条件决定具体跳转的位置。

## 重载、重写、重定义

- 重载：根据参数列表匹配对应函数，不关注函数的返回类型；
- 重写：派生类重写父类中的虚函数，除函数体、访问标识符外，函数名、参数列表、返回值等完全相同；
- 重定义(隐藏)：派生类重定义父类中同名的非虚函数，参数列表、返回值均可不同。

## new/delete与malloc/free

new/delete：实际上都是执行了两个过程；
- new：1.分配未初始化内存空间；2.调用参数类型的构造函数，返回空间首地址；
- delete：1.调用参数类型的析构函数；2.回收内存。

功能上，对于C++内部数据类型，new/delete的功能与malloc/free相同，new/delete可以实现自定义数据类型的快速分配，使用更加简便；性质上，malloc/free是函数，灵活性较差；new/delete是关键字+操作符，可以由编译器控制，通过重载实现更高的灵活性。

> 关于重载new/delete是一个比较复杂的内容，需要小心操作。

## 左值/右值

显式的理解：对于表达式`a = b`，`a`为左值，`b`为右值；  
更为严格的解释：左值：表达式结束后持续存在；右值：表达式结束后就销毁的临时变量。

左右值的功能不同：
- 左值：可以取地址、取引用，例如：变量、类实体、指针、++a；
- 右值：仅可以读取它的值，不可以作为引用返回，例如：表达式、函数返回值、常量。（纯右值/将亡值）

**左值/右值引用**：引用的本质是为变量取一个别名，无论是左值/右值引用，都必须立即初始化。
- 左值引用：为左值变量起别名，符号：`&`，是常见的引用类型；
  - 左值引用分为常量引用`const type &`和非常量引用`type &`；
  - 常量左值引用可以绑定任何值（左值/右值/常量左值），非常量左值引用只能绑定左值。
- 右值引用：为不具名的右值起别名，符号：`&&`。
  - 右值引用让一个右值在表达式结束后不会立即消亡，而是等待其引用生命周期结束，有时能进行一些性能优化。

# STL





# 基础知识

## 宏和const

宏在编译阶段处理，将变量替换为常量，会在常量区存放多个副本，效率较低；而`const`本质是一个变量，内存中只保存一份，不需要编译替换，效率更高。

## 构造、析构函数的执行过程

自顶向下，基类构造函数先执行；自底向上，派生类的构造函数先执行。

## 静态绑定、动态绑定

区别静态/动态编译的概念：绑定决定程序运行时的行为；编译则决定程序如何运行。

- 静态绑定：在编译阶段决定调用函数、变量的地址，常用于实现函数重载(使用函数签名)；
- 动态绑定：在运行阶段决定调用函数、变量的地址，常用于虚函数(虚函数地址表)；

## 深/浅拷贝