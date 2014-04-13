#include "ini_parser.h"


string substr(const char* strg,int start,int len)
{
	char* substring = new char[len+1];
	for(int i=0;i<len;i++)
	{
		substring[i] = strg[start];
		start++;
	}
	substring[len] = '\0';
	string str;	
	str = str.assign(substring);
	delete substring;
	return str;
}
void moveblank(string& str)
{
	char *p = new char[str.size()+1];
	const char *q = str.c_str();
	int i = 0;
	while(*q!='\0')
	{
		if(*q == ' ')
		{
			q++;
			continue;
		}		 
		p[i] = *q;
		q++;
		i++;
	}
	p[i]= '\0';
	str = p;
}

bool Iskey(const char *c,const std::string& l_seperator)
{
   string s = substr(c,0,l_seperator.size());
   if(strcmp(s.c_str(),l_seperator.c_str())==0)
	return false;
   else 
	  if (*c >= 'a' && *c <= 'z' ||  
	      *c >= 'A' && *c <= 'Z' ||  
	      *c >= '0' && *c <= '9') 
		  return true;
	  else
		  return false;
}
bool Iskey_value_seperator(const char *c,const std::string& k_v_seperator)
{
	string s = substr(c,0,k_v_seperator.size());
	if(strcmp(s.c_str(),k_v_seperator.c_str())==0)
		return true;
	else 
		return false;
}
bool Isline_seperator(const char *c,const std::string& l_seperator)
{
	string s = substr(c,0,l_seperator.size());
	if(strcmp(s.c_str(),l_seperator.c_str())==0)
		return true;
	else 
		return false;
}
namespace qh
{
	INIParser::INIParser()
	{
		section_first = NULL;
		section_last = NULL;
	}
	INIParser::~INIParser()
	{
	}
	bool INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator , const std::string& key_value_seperator )
	{
		enum ParseState {
		StartState,  
		SectionLabelState,  
		KeyState,  
		ValueState,  
		CommentState  
		}; 
		unsigned offset = 0; 
		unsigned start_offset;  
		std::string key;  
		std::string value;  
		ParseState parse_state = StartState; 
		while(offset<ini_data_len)
		{
			switch(parse_state)
			{
			case StartState:
				if(ini_data[offset]=='[')
				{
					parse_state = SectionLabelState;
					start_offset = offset + 1;
					break;
				}
			if(ini_data[offset]==';')
			{
				parse_state = CommentState;
				break;					
			}
			if(Iskey(&ini_data[offset],line_seperator))
			{
				parse_state = KeyState;
				start_offset = offset;
				break;
			}
			break;
			case SectionLabelState:
				if(ini_data[offset]==']')
				{
					parse_state = StartState;
					struct section *sect = new struct section;
					sect->name = substr(ini_data,start_offset,offset-start_offset);
					
					sect->next = NULL;
					if(this->section_first == NULL)
					{
						this->section_first = sect;
						this->section_last = sect;
					}
					else
					{
						this->section_last->next = sect;
						this->section_last = sect;
					}				
					break;
				}
				break;
			case KeyState:
				if(Iskey_value_seperator(&ini_data[offset],key_value_seperator))//出现key和value的分隔符表示这里是key的结尾
				{
					parse_state = ValueState;
					key = substr(ini_data,start_offset,offset-start_offset);
					moveblank(key);
					start_offset = key_value_seperator.size() + offset;
					break;
				}
				break;
			case ValueState:
				if(Isline_seperator(&ini_data[offset],line_seperator))//判断是不是line_seperator，若是这表示这里是value的结尾
				{
					parse_state = StartState;
					value = substr(ini_data,start_offset,offset-start_offset);
					moveblank(value);
					this->section_last->properties[key] = value;
				//	printf("%s",this->section_last->properties[key].c_str());
					break;
				}
				break;
			case CommentState:
				if(Isline_seperator(&ini_data[offset],line_seperator))//若是line_seperator，则注释状态结束
				{
					parse_state = StartState;
					break;
				}
				break;
			default:
				break;
			}
			offset++;
		}
		if(parse_state == ValueState)
		{
			parse_state = StartState;
			value = substr(ini_data,start_offset,offset-start_offset+1);
			this->section_last->properties[key] = value;
		}	
		return true;
	}
	const string& INIParser::Get(const std::string& key, bool* found)
	{
		
		string *value = new string; 				
	//	printf("%s",section_first->name.c_str());
	//	printf("%s",section_first->properties["aa"].c_str());		
		*value = section_first->properties[key];
		/*
	    if(value.data()=="\0")
			*found = false;
		else
			*found = true;
			*/
		return *value;	
		
	}
}