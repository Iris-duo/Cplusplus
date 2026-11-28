# C语言：指针与函数

## 1.字符指针变量

在制作类型中我们知道有一种指针类型为字符指针char*，一般使用：

```c
char ch = 'w';
char *pc = &ch;	//pc是指针变量
```

其实字符指针还有另一种表达方式

```c
char arr[10] = "abcdef";
char* p1 = arr;	

char* p2 = "abcdef";
```

那么这两种表示方式有何区别嘞，我们可以试着对代码进行修改分析来研究研究

```c
char ch = 'w';
char *pc = &ch;	//pc是指针变量

char arr[10] = "abcdef";
char* p1 = arr;	
*p1 = 'w';

char* p2 = "abcdef";
*p2 = 'w';

printf("%s\n", p1);
printf("%s\n", p2);
```

![char1](H:\Cplusplus\Cplusplus\ArticleWirting\指针与函数\Images\char1.png)

这里虽然没有报错但是我们可以看见，最终没有显示任何结果，这是为啥嘞，是因为p2对应的是字符串常量是不可修改的，就相当于const char* p2 = "abcdef";

![](H:\Cplusplus\Cplusplus\ArticleWirting\指针与函数\Images\char2.png)

那么现在我们来看一个例题

```c
char str1[] = "hello Sylvan.";
char str2[] = "hello Sylvan.";

const char *str3 = "hello Sylvan.";
const char *str4 = "hello Sylvan.";

if(str1 ==str2)
printf("str1 and str2 are same\n");
else
printf("str1 and str2 are not same\n");

if(str3 ==str4)
printf("str3 and str4 are same\n");
else
printf("str3 and str4 are not same\n");
```

![image-20261125211349915](C:\Users\DXY\AppData\Roaming\Typora\typora-user-images\image-20261125211349915.png)

![](H:\Cplusplus\Cplusplus\ArticleWirting\指针与函数\Images\str1234.png)

![](H:\Cplusplus\Cplusplus\ArticleWirting\指针与函数\Images\str1与str2.png)

![str3与str4](H:\Cplusplus\Cplusplus\ArticleWirting\指针与函数\Images\str3与str4.png)

## 2.数组指针变量

字符指针:char* --> 指向字符的指针

整型指针：int* --> 指向整型的指针

那么

数组指针 -->指向数组的指针

```c
int a = 10;		int* pa = &a;	//整型指针
char ch = 'w';	char* pc = &ch;	//字符指针
int arr[10] = { 0 };
//arr--数组元素的首地址
//&arr--数组的地址
int (*parr)[10] = arr;

```

![数组指针](H:\Cplusplus\Cplusplus\ArticleWirting\指针与函数\Images\数组指针.png)

那么数组指针有什么用呢？

```c
int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
int* p1 = arr;
for (int i = 0; i < 10; i++)
{
	printf("%d ", *p1);	//*&arr[0] == arr[0]
	p1++;
}

printf("\n");

int (*p2)[10] = &arr;
for (int i = 0; i < 10; i++)
{
	printf("%d ", (*p2)[i]);	//*&arr[i] == arr[i]
}
```

这里我们可以看到这里使用数组指针就把问题弄复杂了，那么究竟应该将数组指针用在何处呢？

我们来看一下二维数组传参的本质

```c
void Print(int arr[3][5], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = {
		{1,2,3,4,5},
		{2,3,4,5,6},
		{3,4,5,6,7}
	};

	Print(arr, 3, 5);

	return 0;
}
```

这里实参是二维数组，形参也写成二维数组的表现形式，那么还有其他的写法吗？

⾸先我们再次理解⼀下⼆维数组，⼆维数组其实可以看做是每个元素是⼀维数组的数组，也就是⼆维 数组的每个元素是⼀个⼀维数组。那么⼆维数组的⾸元素就是第⼀⾏，是个⼀维数组。

所以，根据数组名是数组⾸元素的地址这个规则，⼆维数组的数组名表⽰的就是第⼀⾏的地址，是⼀ 维数组的地址。根据上⾯的例⼦，第⼀⾏的⼀维数组的类型就是 型就是数组指针类型 int [5]  ，所以第⼀⾏的地址的类 int(*)[5]  。那就意味着⼆维数组传参本质上也是传递了地址，传递的是第⼀ ⾏这个⼀维数组的地址，那么形参也是可以写成指针形式的。如下；

```c
void Print(int(*p)[5], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", *(*(p+i)+j));
		}
		printf("\n");
	}
}
```

## 3.函数指针变量

### 3.1函数指针变量的创建

数组指针-->指针-->指向数组的-->存放数组的地址

函数指针-->函数-->指向函数的-->存放函数的地址

```c
int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int arr[10] = { 0 };
	int (*parr)[10] = &arr;
	//arr-->数组首元素地址
	//&arr-->数组的地址
	
	int(*pf)(int, int) = Add;
	//Add,&Add都是函数的地址
	//pf是用来存放函数地址的，pf就是函数指针变量

```

![函数指针变量的创建](H:\Cplusplus\Cplusplus\ArticleWirting\指针与函数\Images\函数指针变量的创建.png)

### 3.2函数指针变量的使用

```c
int m = pf(3, 5);
int n = (*pf)(5, 6);

printf("%d\n", m);
printf("%d\n", n);
```

![](H:\Cplusplus\Cplusplus\ArticleWirting\指针与函数\Images\函数指针变量的使用.png)



两个有趣的代码

```
(*(void(*)())0)();
void(*)()		--->函数指针类型
(void(*)())		--->强制类型转换
(void(*)())0	--->进行强制类型转换
((void(*)())0)()
假设0地址处放在无参，返回类型是void的函数
最终是调用0的地址处放的这个函数
```

![](H:\Cplusplus\Cplusplus\ArticleWirting\指针与函数\Images\函数指针变量.png)

这样子看这个函数的表达是比较复杂的，那么我们可以使用typedef（类型重定义）

## 4.typedef(类型重定义)

```c
typedef unsigned int u_int;
typedef int* ptr_t;
```

这是普通的类型重定义，单数数组指针和函数指针就不一样了，我们可以来看一看

![](H:\Cplusplus\Cplusplus\ArticleWirting\指针与函数\Images\类型重定义.png)

我们可以看见在这样子是不允许的那么我们应该怎样表示呢?

```c
typedef int(*parr_t)[5];
```

这样子就表示parr_t 表示 int(*)[5];这个数组指针变量类型啦，函数指针变量同理

```c
typedef int(*pf_t)(int,int);

void(* signal(int, void(*)(int)))(int);
这个同理：
    typedef void(*pf1_t)(int);
pf1_t signal(int,pf1_t)；
    这样子看起来就简洁很多
```

关于typedef我们来看最后一个点

```c
typedef int* ptr_t;
#define int* PTR_T

ptr_t p1,p2;
PTR_T p3,p4;
```

最后我们得到的结果是

- ​	p1，p2都是int*类型
- p3是int* 类型，p4为int类型

这是因为ptr_t 是int* 的另一种表现形式，而PTR_T只是将int * *重复一遍，int和* *并不是一个整体

## 5.函数指针数组

```c
指针数组：int *arr[10];数组中每个元素类型都为int*  

```

如果有三个函数的地址需要存放，那么我们就可以使用函数指针数组

```c
//函数指针数组
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int main()
{
	int (*parr[4])(int, int) = { Add,Sub,Mul,Div };	//初始化之后4可以省略

	return 0;
}
```

那么函数指针数组有何用呢？

我们可以通过计算机对两个整数的加减乘除来看一看

```c
//两个整数的加减乘除(计算器)
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("--------------------------\n");
	printf("---0.Exit   1.Add---------\n");
	printf("---2.Sub    3.MUL---------\n");
	printf("---4.Div       -----------\n");
	printf("--------------------------\n");

}

int main()
{
	int x = 0;
	int y = 0;
	int input = 0;

	menu();
	do
	{
		printf("请选择:> ");
		scanf("%d", &input);
		printf("请输入要计算的数字：");
		scanf("%d %d", &x, &y);
		switch(input)
		{
		case 0:
			printf("退出游戏。\n");
			break;
		case 1:
			Add(x, y);
			printf("%d\n", Add(x, y));
			break;
		case 2:
			Sub(x, y);
			printf("%d\n", Sub(x, y));

			break;
		case 3:
			Mul(x, y);
			printf("%d\n", Mul(x, y));

			break;
		case 4:
			Div(x, y);
			printf("%d\n", Div(x, y));

			break;
		default:
			printf("输入错误，请重新输入：");
		}
	} while (input);

	return 0;
}
```

我们可以看见使用这个方法仅仅只是完成加减乘除这四个操作代码就已经变得冗长了，而且我们想要添加其他操作时或很麻烦。那么我们可以使用函数指针数组来看一看

```c
//两个整数的加减乘除(计算器)
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("--------------------------\n");
	printf("---0.Exit   1.Add---------\n");
	printf("---2.Sub    3.MUL---------\n");
	printf("---4.Div       -----------\n");
	printf("--------------------------\n");

}

int main()
{
	int (*pf[5])(int, int) = { 0,Add,Sub,Mul,Div };

printf("请选择:> ");
scanf("%d", &input);

if (input > 0 && input <= 4)
{
	printf("请输入要计算的数字：");
	scanf("%d %d", &x, &y);

	int z = pf[input](x, y);
	printf("%d\n", z);

}
else if (input == 0)
{
	printf("退出游戏。\n");
}
else
{
	printf("选择错误，请重新选择。\n");
}
	return 0;
   }
```

![](H:\Cplusplus\Cplusplus\ArticleWirting\指针与函数\Images\简洁版.png)

我们可以看见主函数明显是简洁了很多，而且想要添加其他操作也是很简单的。这就是函数指针数组的作用。





