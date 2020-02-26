#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
// assert(断言)是 C 语言给我们提供用来判断指针或其他条件是否成立 类似于宏
// 当条件不成立时, 该assert将直接终止程序运行 并告诉你程序出错的原因 包括行号

// 模拟实现strlen
// C语言没有字符串类型 决定了对字符串操作必须得单独编写相关的接口 编写逻辑
// 首先求字符串长度本质是求字符串里元素的个数, '\0'不算字符串的内容 是结束分隔符

// 1. 计算器方法
// 通过while不断对count实现++,返回count
int my_strlen(const char* str){
	int count = 0;
	while (*str){// 可以不和'\0'比较 因为一直往后走一定会碰到'\0' 然后退出
		count++;
		str++;
	}
	return count;
}

// 2. 递归策略(不创建临时变量计数器)
// "abcdefg" 求a-g和求任意字母到'g'的方法是一样的
// 若一个字符串的长度不为0 那么他的长度等于1 + 剩余长度
// "abcdeg" = 1 + "bcdefg"
size_t my_strlen2(const char* str){
	if (*str == '\0'){
		return 0;// 说明它的长度就为 0
	}
	return 1 + my_strlen(str + 1);
}

// 3.指针-指针方式
// "abcd",'s'指向'a' =>  p指向'a',p往后走 
// 当p指向'\0'时,p-s表示这两个指针之间经历的元素个数 = 字符串长度
int my_strlen3(char* s){
	char* p = s;
	while (*p != '\0'){
		p++;
	}
	return p - s;
}
int main(){

	size_t s = my_strlen("hello");
	printf("%d\n", s);// 5
	
	//const char* str = "I love you!";
	//char arr[] = "I love you!";

	//printf("%d\n", my_strlen(str));
	//printf("%d\n", strlen(str));// 11
	//printf("%d\n", strlen(arr));// 11
	//printf("%d\n", sizeof(str));// 4
	//printf("%d\n", sizeof(arr));// 12
	system("pause");
	return 0;
}
