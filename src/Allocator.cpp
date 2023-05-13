#include "Allocator.h"
using namespace foxintango::mm;

Allocator::Allocator(){
}

Allocator::~Allocator(){
}

void* Allocator::alloc(const unsigned int& size){
    return new char[size];
}

int Allocator::release(const void* m){
    if(m) { delete (const char*)m; return 1; }
    return 0;
}
