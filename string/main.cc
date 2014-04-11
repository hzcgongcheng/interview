#include "qh_string.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using qh::string;
int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�
	string  str1;	
	string str2("hello world!");
	int len = str2.size();
	assert(len==12);//����string::string( const char* s )���캯��
	assert(str1.size()==0);//����string::string(): data_(NULL), len_(0)���캯��
	const char s='c';
	string *str3 = new string(&s,10);
	assert(str3->size()==10);//����string::string( const char* s, size_t len )���캯��
	delete str3;	
	string str4(str2);
	assert(str4.size()==str2.size());//����string::string( const string& rhs )���캯��
	str1 = str2;
	assert(str1.size()==str2.size());//����string& string::operator=( const string& rhs )��������
	//assert(strcmp())
	const char* data_copy = new char[str2.size()];
	data_copy = str2.data();
	assert(strcmp(data_copy,str2.data())==0);//���� const char* string::data() const��Ա����
	assert(*str2[str2.size()-1]=='!');//����char* string::operator[]( size_t index )��������
	assert(data_copy[strlen(data_copy)-1]==*str2[str2.size()-1]);//����data()�����ַ��������Ϊ��NULL
	assert(strcmp(str1.data(),str2.data())==0);
	assert(strcmp(str4.data(),str2.data())==0);
	const char* data_copy_str = str2.c_str();
	assert(strcmp(data_copy_str,str2.data())==0);//����const char* string::c_str() const��Ա����
	assert(data_copy_str[str2.size()]=='\0');//����c_str()���ؽ��Ϊ��null��ֹ��c�ַ���
	printf("All test OK\n");

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

