#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// 模拟实现strcpy
// 要定义一个缓冲区dst 把src拷到缓冲区
// my_strcpy函数的返回值就是 dst
// 要拷贝 先要证明两个指针的合法性
// 拷贝的时候 是把元素一个个的放进去 不放'\0'
char* my_strcpy(char* dst, char* src){
	// 若传的参数dst或src为空 程序直接崩掉(assert的作用) 
	// assert 像 if (但是判定失败 就会直接终止, if还会继续运行)
	assert(dst != NULL);
	assert(src != NULL);
	// char* 的返回值是dst,dst一直在变, 最终指向字符串结尾
	// 先保存一下dst, 最终返回的是dst字符串的起始地址
	char* ret = dst;
	// ++ 优先级高于 *,后置++先使用再++ => 最终还是先执行解引用再++(先赋后加)
	// 但是完全不一样, 道理好比送礼物别人接受与否还是要送 
	// 先判断dst的值是否为'\0', 不为则成立 继续循环,赋值 再判断 
	// 当src = '\0'时, 赋值 判定 条件不走了 但是最终把'\0'也赋给了dst
	// 最终把src里包括'\0'的全部都拷贝到dst中

	//while (*dst++ = *src++); 最简便的
	while (*dst = *src){
		dst++, src++;
	}// 简单清晰
	return ret;

}
int main(){
	char* src = "abcd1234";// src指向的是字符常量区
	char dst[16];// dst为缓冲区, 要把src放到dst中, 空间由我们提供

	my_strcpy(dst, src);
	printf("%s\n", dst);
	system("pause");
	return 0;
}
