#include "qh_string.h"

#include <string.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
		this->data_ = NULL;
		this->len_ = 0;
    }

    string::string( const char* s )
    {
		if(!s) 
		{
			this->data_ = 0;
			this->len_ = 0;		
		}
		else
		{
		    this->data_ = new char[strlen(s)+1];
			strcpy(data_,s);
			this->len_ = strlen(s);		
		}
    }

    string::string( const char* s, size_t len )
    {
		if(!len)
		{
			this->data_ = NULL;
			this->len_ = 0;		
		}
		else
		{
			this->data_ = new char[len+1];
			this->len_ = len;
			for(int i=0;i<len;i++)
				this->data_[i] = *s;		
		}
    }

    string::string( const string& rhs )
    {  
	
		if(!rhs.data_)
		{
			this->data_ = NULL;
			this->len_ = 0;		
		}
		else
		{
			this->data_ = new char[rhs.size()+1];
			strcpy(data_,rhs.data_);
			this->len_ = strlen(rhs.data_);
		}

    }

    string& string::operator=( const string& rhs )
    {
		if(this != &rhs)
		{
			delete[] this->data_;
			if(!rhs.data_)
			{
				this->data_ = 0;
				this->len_ = 0;			
			}
			else
			{
				this->data_ = new char[rhs.size()+1];
				strcpy(this->data_,rhs.data_);
				this->len_ = rhs.len_;			
			}
		
		}
        return *this;
    }

    string::~string()
    {
		if(this->data_)
		{
			delete[] this->data_;
			this->data_ = 0;
			this->len_ = 0;
		}

    }

    size_t string::size() const
    {
        return this->len_;
    }

    const char* string::data() const
    {
		char* data_copy = new char[this->len_];
		strcpy(data_copy,this->data_);
        return data_copy;
    }

    const char* string::c_str() const
    {
		char* data_copy = new char[this->len_+1];
		strcpy(data_copy,this->data_);
		data_copy[this->len_] = '\0';
        return data_copy;
    }

    char* string::operator[]( size_t index )
    {
		if(index>=0&&index<=this->len_-1)
        return &this->data_[index];
    }
}
