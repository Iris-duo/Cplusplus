# C语言：指针与函数

## 1. 字符指针变量

在指针的学习中我们知道有一种指针类型为字符指针 `char*`，一般这样使用：

```c
char ch = 'w';
char *pc = &ch;	// pc是指针变量
```

其实字符指针还有另一种使用方式——指向一个字符串：

```c
char arr[10] = "abcdef";
char* p1 = arr;	// 指向数组（栈区）

char* p2 = "abcdef";	// 指向字符串常量（只读区）
```

那么这两种方式有何区别呢？我们可以试着对代码进行修改分析来研究研究：

```c
int main()
{
	char arr[10] = "abcdef";
	char* p1 = arr;
	*p1 = 'w';	// p1指向数组，可以修改

	char* p2 = "abcdef";
	*p2 = 'w';	// p2指向字符串常量，不允许修改

	printf("%s\n", p1);
	printf("%s\n", p2);

	return 0;
}
```

![char1](images/char1.png)

这里虽然没有编译报错，但是程序运行时直接崩溃了，最终没有显示任何结果。这是为什么呢？是因为 `p2` 指向的是字符串常量，字符串常量存储在只读数据区，是不可修改的。为了防止误操作，最好显式地加上 `const` 限定，相当于：

```c
const char* p2 = "abcdef";
```

加上 `const` 之后，如果再试图修改，编译阶段就会直接报错（E0137：表达式必须是可修改的左值），把问题提前暴露出来：

![char2](images/char2.png)

那么现在我们来看一个例题：

```c
int main()
{
	char str1[] = "hello Sylvan.";
	char str2[] = "hello Sylvan.";

	const char *str3 = "hello Sylvan.";
	const char *str4 = "hello Sylvan.";

	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");

	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");

	return 0;
}
```

运行结果：

![char3](images/char3.png)

是不是有点出乎意料？下面我们来分析一下原因。

![str1234](images/str1234.png)

- `str1` 和 `str2` 是两个独立的数组，每个数组都会在内存中申请一块属于自己的空间。虽然它们存放的内容相同，但地址是完全不同的，所以 `str1 == str2` 为假。

![str1与str2](images/str1与str2.png)

- `str3` 和 `str4` 都是指向字符串常量的字符指针变量。字符串常量是不会改变的，所以当两个字符指针指向同一个字符串常量时，编译器没有必要创建两份，它们指向的是同一块内存，所以 `str3 == str4` 为真。

![str3与str4](images/str3与str4.png)

## 2. 数组指针变量

我们已经知道：

- 字符指针：`char*` —— 指向字符的指针
- 整型指针：`int*` —— 指向整型的指针

那么：

- 数组指针 —— 指向数组的指针

```c
int a = 10;		int* pa = &a;	// 整型指针
char ch = 'w';	char* pc = &ch;	// 字符指针

int arr[10] = { 0 };
// arr  —— 数组首元素的地址
// &arr —— 整个数组的地址
int (*parr)[10] = &arr;	// parr 是数组指针变量，存放整个数组的地址
```

![数组指针](images/数组指针.png)

那么数组指针有什么用呢？先看一段代码：

```c
int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

// 方式一：用整型指针遍历
int* p1 = arr;
for (int i = 0; i < 10; i++)
{
	printf("%d ", *p1);	// *p1 等价于 arr[i]
	p1++;
}
printf("\n");

// 方式二：用数组指针遍历
int (*p2)[10] = &arr;
for (int i = 0; i < 10; i++)
{
	printf("%d ", (*p2)[i]);	// (*p2)[i] 等价于 arr[i]
}
```

可以看到，对于一维数组，使用数组指针反而把问题弄复杂了。那么究竟应该将数组指针用在何处呢？

我们来看一下**二维数组传参的本质**：

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

这里实参是二维数组，形参也写成二维数组的形式，那么还有其他的写法吗？

首先我们再次理解一下二维数组：二维数组其实可以看做是每个元素都是一维数组的数组，也就是二维数组的每个元素是一个一维数组。那么二维数组的首元素就是第一行，是一个一维数组。

所以，根据"数组名是数组首元素的地址"这个规则，二维数组的数组名表示的就是第一行的地址，是一个一维数组的地址。根据上面的例子，第一行这个一维数组的类型是 `int[5]`，所以第一行地址的类型就是数组指针类型 `int(*)[5]`。这意味着二维数组传参本质上也是传递地址，传递的是第一行这个一维数组的地址，那么形参自然也可以写成指针形式，如下：

```c
void Print(int(*p)[5], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", *(*(p + i) + j));	// 等价于 p[i][j]
		}
		printf("\n");
	}
}
```

这就是数组指针真正的用武之地——**作为二维数组传参的形参形式**。

## 3. 函数指针变量

### 3.1 函数指针变量的创建

类比一下：

- 数组指针 —— 指向数组的指针 —— 存放数组的地址
- 函数指针 —— 指向函数的指针 —— 存放函数的地址

```c
int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int arr[10] = { 0 };
	int (*parr)[10] = &arr;
	// arr  —— 数组首元素地址
	// &arr —— 数组的地址

	int(*pf)(int, int) = Add;
	// Add、&Add 都是函数的地址
	// pf 是用来存放函数地址的，pf 就是函数指针变量

	return 0;
}
```

![函数指针变量的创建](images/函数指针变量的创建.png)

### 3.2 函数指针变量的使用

通过函数指针调用函数，下面两种写法是等价的（`*` 在这里只是摆设，写不写、写几个都一样）：

```c
int m = pf(3, 5);	// 等价于 Add(3, 5)
int n = (*pf)(5, 6);	// 等价于 Add(5, 6)

printf("%d\n", m);	// 8
printf("%d\n", n);	// 11
```

![函数指针变量的使用](images/函数指针变量的使用.png)

### 3.3 两个有趣的代码

**代码一：**

```c
(*(void(*)())0)();
```

逐步拆解：

```c
void(*)()		---> 函数指针类型
(void(*)())0	---> 把0强制类型转换为该函数指针类型
(*(void(*)())0)	---> 解引用，得到0地址处的函数
(*(void(*)())0)()	---> 调用0地址处这个无参、返回类型为void的函数
```

也就是：假设 0 地址处放着一个无参、返回类型是 `void` 的函数，这行代码最终就是调用 0 地址处的这个函数。

**代码二：**

```c
void(*signal(int, void(*)(int)))(int);
```

![函数指针变量](images/函数指针变量.png)

这是一次函数声明：`signal` 是一个函数，它有两个参数，第一个是 `int` 类型，第二个是 `void(*)(int)` 函数指针类型；它的返回类型也是 `void(*)(int)` 函数指针。

这样看这个函数的声明是比较复杂的，那么我们可以使用 `typedef`（类型重定义）来简化它。

## 4. typedef（类型重定义）

```c
typedef unsigned int u_int;
typedef int* ptr_t;
```

这是普通的类型重定义，但是数组指针和函数指针就不一样了，我们可以来看一看：

![类型重定义](images/类型重定义.png)

可以看见，把新类型名写在后面是不允许的（编译报错 E0040、E0065）。那么对于数组指针和函数指针，新类型名必须写在 `*` 的旁边：

```c
typedef int(*parr_t)[5];	// parr_t 就是数组指针类型 int(*)[5] 的新名字
```

函数指针同理：

```c
typedef int(*pf_t)(int, int);	// pf_t 就是函数指针类型 int(*)(int,int) 的新名字
```

于是上面的 `signal` 声明就可以简化成：

```c
void(*signal(int, void(*)(int)))(int);

// 使用 typedef 简化后：
typedef void(*pf1_t)(int);
pf1_t signal(int, pf1_t);
// 这样看起来就简洁很多
```

关于 `typedef` 我们再来看最后一个点：

```c
typedef int* ptr_t;
#define PTR_T int*

ptr_t p1, p2;
PTR_T p3, p4;
```

最后我们得到的结果是：

- `p1`、`p2` 都是 `int*` 类型
- `p3` 是 `int*` 类型，而 `p4` 是 `int` 类型

这是因为 `ptr_t` 是 `int*` 的一个整体别名，而 `#define` 只是简单的文本替换，`PTR_T p3, p4;` 替换后相当于 `int* p3, p4;`，`*` 只和 `p3` 结合，`int` 和 `*` 并不是一个整体。

## 5. 函数指针数组

先回顾一个概念：

```c
// 指针数组：数组中每个元素的类型都是 int*
int* arr[10];
```

如果有多个函数的地址需要存放，那么我们就可以使用**函数指针数组**：

```c
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
	// 函数指针数组：存放4个函数指针，每个元素类型为 int(*)(int,int)
	int (*parr[4])(int, int) = { Add, Sub, Mul, Div };	// 初始化之后 4 可以省略

	return 0;
}
```

那么函数指针数组有何用呢？

我们可以通过实现一个对两个整数进行加减乘除的计算器来看一看。先用普通的 `switch` 写法：

```c
// 两个整数的加减乘除（计算器）
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
	printf("---0.Exit    1.Add--------\n");
	printf("---2.Sub      3.Mul-------\n");
	printf("---4.Div-------------------\n");
	printf("--------------------------\n");
}

int main()
{
	int x = 0;
	int y = 0;
	int input = 0;

	do
	{
		menu();
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏。\n");
			break;
		case 1:
			printf("请输入要计算的数字：");
			scanf("%d %d", &x, &y);
			printf("%d\n", Add(x, y));
			break;
		case 2:
			printf("请输入要计算的数字：");
			scanf("%d %d", &x, &y);
			printf("%d\n", Sub(x, y));
			break;
		case 3:
			printf("请输入要计算的数字：");
			scanf("%d %d", &x, &y);
			printf("%d\n", Mul(x, y));
			break;
		case 4:
			printf("请输入要计算的数字：");
			scanf("%d %d", &x, &y);
			printf("%d\n", Div(x, y));
			break;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
	} while (input);

	return 0;
}
```

可以看见，仅仅完成加减乘除这四个操作，代码就已经变得冗长了，而且想要添加其他操作时会很麻烦（`switch` 里的每个分支逻辑几乎一模一样）。那么我们可以使用函数指针数组来改造一下：

```c
// 两个整数的加减乘除（计算器）—— 函数指针数组版
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
	printf("---0.Exit    1.Add--------\n");
	printf("---2.Sub      3.Mul-------\n");
	printf("---4.Div-------------------\n");
	printf("--------------------------\n");
}

int main()
{
	int x = 0;
	int y = 0;
	int input = 0;

	// 下标0占位，使菜单编号与数组下标一一对应
	int (*pf[5])(int, int) = { 0, Add, Sub, Mul, Div };

	do
	{
		menu();
		printf("请选择:> ");
		scanf("%d", &input);

		if (input > 0 && input <= 4)
		{
			printf("请输入要计算的数字：");
			scanf("%d %d", &x, &y);

			int z = pf[input](x, y);	// 通过下标直接调用对应的函数
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
	} while (input);

	return 0;
}
```

![简洁版](images/简洁版.png)

可以看见主函数明显简洁了很多，而且想要添加其他操作也很简单——只需要写好新函数，再把它加进函数指针数组即可。这就是函数指针数组的作用（这种用法也叫"转移表"）。
