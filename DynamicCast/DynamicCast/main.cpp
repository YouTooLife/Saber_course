//
//  main.cpp
//  MyCastTest
//
//  Created by YouTooLife on 18/01/2019.
//  Copyright © 2019 YouTooLife. All rights reserved.
//

#include <iostream>
#include "RTTI/rtti.h"



class Base
{
    virtual void print() = 0;
public:
    DEFINE_RTTI_ROOT(Base)
};

class A: public Base
{
public:
    void print() {}
    DEFINE_RTTI_OBJECT(A, Base)
};

class V
{
    void print() {  };
public:
    DEFINE_RTTI_ROOT(V)
};

class B: public A, virtual public V
{
    void print() {  };
public:
    DEFINE_RTTI_OBJECT(B, A, V)
};

class C: public B
{
    void print() {  };
public:
    DEFINE_RTTI_OBJECT(C, B)
};

class D: public B
{
    void print() {  };
public:
    DEFINE_RTTI_OBJECT(D, B)
};


class E: public C, public D
{
    void print() {  };
public:
    DEFINE_RTTI_OBJECT(E, C, D)
};




template <class T, class C>
void printIsCanCast(C* obj)
{
    T* t = Base::DynamicCast<T>(obj);
    std::cout << GET_OBJECT_TYPE_NAME(obj) << " is " << (t?"": "not ") << GET_CLASS_TYPE_NAME(T) << "\n";
}


int main()
{
  
    
    const A* a = new A();
    const A* b = new B();
    const A* c = new C();
    const A* d = new D();
    
    const D* e01 = new E();
    const C* e02 = new E();
    const A* e1 = e01;
    const A* e2 = e02;
    
    const V* e3 = new E();
    
    
    std::cout<< "a is " << GET_OBJECT_TYPE_NAME(a) << std::endl;
    std::cout<< "b is " << GET_OBJECT_TYPE_NAME(b) << std::endl;
    std::cout<< "c is " << GET_OBJECT_TYPE_NAME(c) << std::endl;
    std::cout<< "d is " << GET_OBJECT_TYPE_NAME(d) << std::endl;
    std::cout<< "e1 is " << GET_OBJECT_TYPE_NAME(e1) << std::endl;
    std::cout<< "e2 is " << GET_OBJECT_TYPE_NAME(e2) << std::endl;
    std::cout<< "e3 is " << GET_OBJECT_TYPE_NAME(e3) << std::endl << std::endl;
    
    std::cout<< "can cast to A: \n";
    printIsCanCast<const A>(a);
    printIsCanCast<const A>(b);
    printIsCanCast<const A>(c);
    printIsCanCast<const A>(d);
    printIsCanCast<const A>(e1);
    printIsCanCast<const A>(e2);
    printIsCanCast<const A>(e3);
    std::cout<< "\n";
    
    std::cout<< "can cast to V: \n";
    printIsCanCast<const V>(a);
    printIsCanCast<const V>(b);
    printIsCanCast<const V>(c);
    printIsCanCast<const V>(d);
    printIsCanCast<const V>(e1);
    printIsCanCast<const V>(e2);
    printIsCanCast<const V>(e3);
    std::cout<< "\n";
    
    
    std::cout<< "can cast to B: \n";
    printIsCanCast<const B>(a);
    printIsCanCast<const B>(b);
    printIsCanCast<const B>(c);
    printIsCanCast<const B>(d);
    printIsCanCast<const B>(e1);
    printIsCanCast<const B>(e2);
    printIsCanCast<const B>(e3);
    std::cout<< "\n";
    
    
    std::cout<< "can cast to C: \n";
    printIsCanCast<const C>(a);
    printIsCanCast<const C>(b);
    printIsCanCast<const C>(c);
    printIsCanCast<const C>(d);
    printIsCanCast<const C>(e1);
    printIsCanCast<const C>(e2);
    printIsCanCast<const C>(e3);
    std::cout<< "\n";
    
    
    std::cout<< "can cast to D: \n";
    printIsCanCast<const D>(a);
    printIsCanCast<const D>(b);
    printIsCanCast<const D>(c);
    printIsCanCast<const D>(d);
    printIsCanCast<const D>(e1);
    printIsCanCast<const D>(e2);
    printIsCanCast<const D>(e3);
    std::cout<< "\n";
    
    
    std::cout<< "can cast to E: \n";
    printIsCanCast<const E>(a);
    printIsCanCast<const E>(b);
    printIsCanCast<const E>(c);
    printIsCanCast<const E>(d);
    printIsCanCast<const E>(e1);
    printIsCanCast<const E>(e2);
    printIsCanCast<const E>(e3);
    

    
    return 0;
}
