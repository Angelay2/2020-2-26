#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
// assert(����)�� C ���Ը������ṩ�����ж�ָ������������Ƿ���� �����ں�
// ������������ʱ, ��assert��ֱ����ֹ�������� ���������������ԭ�� �����к�

// ģ��ʵ��strlen
// C����û���ַ������� �����˶��ַ�����������õ�����д��صĽӿ� ��д�߼�
// �������ַ������ȱ��������ַ�����Ԫ�صĸ���, '\0'�����ַ��������� �ǽ����ָ���

// 1. ����������
// ͨ��while���϶�countʵ��++,����count
int my_strlen(const char* str){
	int count = 0;
	while (*str){// ���Բ���'\0'�Ƚ� ��Ϊһֱ������һ��������'\0' Ȼ���˳�
		count++;
		str++;
	}
	return count;
}

// 2. �ݹ����(��������ʱ����������)
// "abcdefg" ��a-g����������ĸ��'g'�ķ�����һ����
// ��һ���ַ����ĳ��Ȳ�Ϊ0 ��ô���ĳ��ȵ���1 + ʣ�೤��
// "abcdeg" = 1 + "bcdefg"
size_t my_strlen2(const char* str){
	if (*str == '\0'){
		return 0;// ˵�����ĳ��Ⱦ�Ϊ 0
	}
	return 1 + my_strlen(str + 1);
}

// 3.ָ��-ָ�뷽ʽ
// "abcd",'s'ָ��'a' =>  pָ��'a',p������ 
// ��pָ��'\0'ʱ,p-s��ʾ������ָ��֮�侭����Ԫ�ظ��� = �ַ�������
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
