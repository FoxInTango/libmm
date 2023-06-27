#ifndef _MM_ALLOCATOR_H_foxintango
#define _MM_ALLOCATOR_H_foxintango

#include <libcpp/libcpp.h>

namespaceBegin(foxintango)
namespaceBegin(mm)
class foxintangoAPI Allocator{
public:
    Allocator();
    virtual ~Allocator();
public:
public:
    virtual void* alloc(const unsigned int& size);
    virtual int release(const void* address);
public:// 析构通知机制
    template <typename T> T* alloc() { 
        T* t = alloc(sizeof(T) + sizeof(Allocator*)); 
        if(t){ 
            Allocator*& alloctor = (Allocator*)(t + sizeof(T));
            alloctor = this;
            return  new(t)T();
        } 
    }
};
namespaceEnd
namespaceEnd
#endif // !_MM_ALLOCTOR_H_foxintango
