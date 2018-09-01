#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class MyString{
private:
    char *buffer;
    int len;
public:
    
    MyString(const char* initstring){
        buffer = nullptr;
        if(initstring){
            buffer = new char[strlen(initstring)+1];
            memcpy(buffer,initstring,strlen(initstring));
        }
    }
    
    MyString(const MyString& copy){
        buffer = nullptr;
        if(copy.buffer){
            buffer = new char[strlen(copy.buffer)];
            memcpy(buffer,copy.buffer,strlen(copy.buffer));
        }
    }
    
    MyString& operator=(const MyString& copy){
        if((this != &copy) && copy.buffer !=nullptr){
            if(buffer){
                delete buffer;
            }
            buffer = new char[strlen(copy.buffer)];
            memcpy(buffer,copy.buffer,strlen(copy.buffer));
        }
        return *this;
    }
    
    MyString& operator+=(const MyString& concat){
           if(concat.buffer){
            len = strlen(buffer)+ strlen(concat.buffer);
            buffer = (char*)realloc(buffer,len);
            strcat(buffer,concat.buffer);
        }
        return *this;
    }
    
    ~MyString(){
        delete buffer;
    }
    
    operator const char*(){
        return buffer;
    }
    
    int getLength(){
        return strlen(buffer);
    }
    
    friend MyString operator +(const MyString& concat1,const MyString& concat2);
    friend bool operator ==(const MyString& comp1,const MyString& comp2);
    friend bool operator < (const MyString & comp1, const MyString & comp2);
    friend bool operator > (const MyString & comp1, const MyString & comp2);
};



int main()
{
    MyString s1("hello");
    MyString s2("world");
    s1+=s2;
    cout<<s1<<endl;

    return 0;
}
