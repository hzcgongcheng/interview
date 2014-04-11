#include "qh_string.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using qh::string;
int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
	string  str1;	
	string str2("hello world!");
	int len = str2.size();
	assert(len==12);//测试string::string( const char* s )构造函数
	assert(str1.size()==0);//测试string::string(): data_(NULL), len_(0)构造函数
	const char s='c';
	string *str3 = new string(&s,10);
	assert(str3->size()==10);//测试string::string( const char* s, size_t len )构造函数
	delete str3;	
	string str4(str2);
	assert(str4.size()==str2.size());//测试string::string( const string& rhs )构造函数
	str1 = str2;
	assert(str1.size()==str2.size());//测试string& string::operator=( const string& rhs )操作函数
	//assert(strcmp())
	const char* data_copy = new char[str2.size()];
	data_copy = str2.data();
	assert(strcmp(data_copy,str2.data())==0);//测试 const char* string::data() const成员函数
	assert(*str2[str2.size()-1]=='!');//测试char* string::operator[]( size_t index )操作函数
	assert(data_copy[strlen(data_copy)-1]==*str2[str2.size()-1]);//测试data()返回字符数组最后为非NULL
	assert(strcmp(str1.data(),str2.data())==0);
	assert(strcmp(str4.data(),str2.data())==0);
	const char* data_copy_str = str2.c_str();
	assert(strcmp(data_copy_str,str2.data())==0);//测试const char* string::c_str() const成员函数
	assert(data_copy_str[str2.size()]=='\0');//测试c_str()返回结果为以null终止的c字符串
	printf("All test OK\n");

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

