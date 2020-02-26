#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// ģ��ʵ��strcpy
// Ҫ����һ��������dst ��src����������
// my_strcpy�����ķ���ֵ���� dst
// Ҫ���� ��Ҫ֤������ָ��ĺϷ���
// ������ʱ�� �ǰ�Ԫ��һ�����ķŽ�ȥ ����'\0'
char* my_strcpy(char* dst, char* src){
	// �����Ĳ���dst��srcΪ�� ����ֱ�ӱ���(assert������) 
	// assert �� if (�����ж�ʧ�� �ͻ�ֱ����ֹ, if�����������)
	assert(dst != NULL);
	assert(src != NULL);
	// char* �ķ���ֵ��dst,dstһֱ�ڱ�, ����ָ���ַ�����β
	// �ȱ���һ��dst, ���շ��ص���dst�ַ�������ʼ��ַ
	char* ret = dst;
	// ++ ���ȼ����� *,����++��ʹ����++ => ���ջ�����ִ�н�������++(�ȸ����)
	// ������ȫ��һ��, ����ñ���������˽��������Ҫ�� 
	// ���ж�dst��ֵ�Ƿ�Ϊ'\0', ��Ϊ����� ����ѭ��,��ֵ ���ж� 
	// ��src = '\0'ʱ, ��ֵ �ж� ���������� �������հ�'\0'Ҳ������dst
	// ���հ�src�����'\0'��ȫ����������dst��

	//while (*dst++ = *src++); �����
	while (*dst = *src){
		dst++, src++;
	}// ������
	return ret;

}
int main(){
	char* src = "abcd1234";// srcָ������ַ�������
	char dst[16];// dstΪ������, Ҫ��src�ŵ�dst��, �ռ��������ṩ

	my_strcpy(dst, src);
	printf("%s\n", dst);
	system("pause");
	return 0;
}
