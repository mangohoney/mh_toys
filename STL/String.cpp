#include "String.hpp"
#include <algorithm>
#include <iostream>

std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return { str, std::uninitialized_copy(b, e, str) };
}

void String::range_initializer(const char *b, const char *e)
{
    auto newstr = alloc_n_copy(b, e);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char *s)
{
    char *tem = const_cast<char*>(s);
    while(*tem) {
        ++tem;
    }
    range_initializer(s, ++tem);
}

String::String(const String &s)
{
    range_initializer(s.elements, s.end);
    std::cout << " copy constructor " << std::endl;
}

void String::free()
{
    if (elements) {
        std::for_each(elements, end, [this](char &c){ alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

String::~String()
{
    free();
}

String& String::operator=(const String &rht)
 {
     auto newstr = alloc_n_copy(rht.elements, rht.end);
     free();
     elements = newstr.first;
     end = newstr.second;
     std::cout << " copy assignment " << std::endl;
     return *this;
 }
