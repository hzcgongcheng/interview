#include "ini_parser.h"
#include <assert.h>

using namespace qh;

void test1()
{
    const char* ini_text= "a=1\nb=2\n"; 
    INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const string& a = parser.Get("a", NULL);
    assert(a == "1");

    string b = parser.Get("b", NULL);
    assert(b == "2");

    const string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test2()
{
    const char* ini_text= "a=1||b=2||c=3"; 
    INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
        assert(false);
    }

    const string& a = parser.Get("a", NULL);
    assert(a == "1");

    string b = parser.Get("b", NULL);
    assert(b == "2");

    const string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test3()
{
    const char* ini_text= "||||a:1||b:2||||c:3||||||"; 
    INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const string& a = parser.Get("a", NULL);
    assert(a == "1");

    string b = parser.Get("b", NULL);
    assert(b == "2");

    const string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test4()
{
	INIParser parser;
	char* init_buffer= "  [section1]  aa = 1 \n bb = 2 \n [section2] \n cc = 3 \n [section3] \n dd = 4 \n ff = 5\n"; 
	parser.Parse(init_buffer,strlen(init_buffer),"\n","=");
	const string& aa = parser.Get("aa", NULL);
    assert(aa == "1");	
    string bb = parser.Get("bb", NULL);
    assert(bb == "2");  
	string cc = parser.Get("section2","cc", NULL);
    assert(cc == "3");
	string dd = parser.Get("section3","dd", NULL);
    assert(dd == "4");
	string ff = parser.Get("section3","ff", NULL);
    assert(ff == "5");
	
}
void test5()
{
	INIParser parser;
	string path = "test5.txt";
	parser.Parse(path);
	const std::string& aa = parser.Get("aa", NULL);
	assert(aa == "1");
	string bb = parser.Get("bb", NULL);
	assert(bb == "2");  
	string cc = parser.Get("section2","cc", NULL);
	assert(cc == "3");
	string dd = parser.Get("section3","dd", NULL);
	assert(dd == "4");
	string ff = parser.Get("section3","ff", NULL);
	assert(ff == "5");

}
int main(int argc, char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	printf("All test success\n");
    return 0;
}


