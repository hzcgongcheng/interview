#include "ini_parser.h"

#include <assert.h>
using namespace qh;
/*
void test1()
{
    const char* ini_text= "a=1\nb=2\n"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("a", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test2()
{
    const char* ini_text= "a=1||b=2||c=3"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("a", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test3()
{
    const char* ini_text= "||||a:1||b:2||||c:3||||||"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("a", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}
*/
void test4()
{
	INIParser parser;
//	bool found;
	char* init_buffer= "  [section1]  aa = 1 \n bb = 2 \n [section2] \n cc = 3 \n [section3] \n dd = 4 \n ff = 5\n"; 
	parser.Parse(init_buffer,strlen(init_buffer),"\n","=");
	const std::string& a = parser.Get("aa", NULL);
    assert(a == "1");
	
    std::string b = parser.Get("bb", NULL);
    assert(b == "2");  
	
}
int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好

  //  test1();
  //  test2();
  //  test3();
	test4();
	printf("All test success\n");
    return 0;
}


