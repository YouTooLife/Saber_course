//
//  rtti.h
//  MyCastTest
//
//  Created by YouTooLife on 23/01/2019.
//  Copyright © 2019 YouTooLife. All rights reserved.
//

#ifndef rtti_h
#define rtti_h

//#include <stdio.h>


class BaseType
{
    BaseType*  superClass;
    BaseType*  superClass2;
    const char*    className;
    
public:
    BaseType( BaseType* parent, const char* name): superClass(parent),
    className(name), superClass2(0) { }
    
    BaseType(BaseType* parent2, BaseType* parent, const char* name): superClass(parent),
    className(name), superClass2(0)
    {
        parent->superClass2 = parent2;
    }
    
    inline bool is(BaseType* objType) const
    {
        //printf("\n== %s : %s\n", this->getName(), objType? objType->getName() : "null");
        while( objType && objType != this )
        {
            objType = objType->superClass;
            //printf("~~ %s : %s  ", this->getName(), objType? objType->getName() : "null");
            if (objType) {
                bool isObjType2 = this->is(objType->superClass2);
                if (isObjType2)
                    return true;
            }
        }
        //printf("\n----\n");
        return objType == this;
    }
    
    inline BaseType*  getSuperPtr() const {return superClass; }
    inline const BaseType*  getSuperPtr2() const {return superClass2; }
    
    inline const char* getName() const { return className; }
};



#define RTTI_GET_TYPE(cls)      \
virtual  BaseType*  GetType() const { return &Type(); }


#define __VA_NARG__(...) \
__VA_NARG_(_0, ## __VA_ARGS__, __RSEQ_N())
#define __VA_NARG_(...) \
__VA_ARG_N(__VA_ARGS__)
#define __VA_ARG_N( \
_1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
_11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
_21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
_31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
_41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
_51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
_61,_62,_63,N,...) N
#define __RSEQ_N() \
62, 61, 60,                             \
59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
9,  8,  7,  6,  5,  4,  3,  2,  1,  0

#define JOIN(x,y) _JOIN(x,y)
#define _JOIN(x,y) x##y

#define DEFINE_RTTI_OBJECT(...) JOIN(DEFINE_RTTI_OBJECT,__VA_NARG__(__VA_ARGS__))(__VA_ARGS__)

#define DEFINE_RTTI_OBJECT0()    \
static inline BaseType&  Type() { static BaseType _type(0, "null"); \
return _type; }  \
RTTI_GET_TYPE(cls)

#define DEFINE_RTTI_OBJECT1()    \
static inline  BaseType&  Type() { static BaseType _type(0, "null"); \
return _type; }  \
RTTI_GET_TYPE(cls)


#define DEFINE_RTTI_OBJECT2(cls, super)    \
static inline  BaseType&  Type() { \
static BaseType _type(&cls::super::Type(), #cls); \
return _type; }  \
RTTI_GET_TYPE(cls)


#define GET_BASE_TYPE(VAL, BASE0, SUPER, cls) \
static BaseType VAL(BASE0.getSuperPtr(), &cls::SUPER::Type(), #cls);


#define DEFINE_RTTI_OBJECT3(cls, super, super1)    \
static inline  BaseType&  Type() { \
static BaseType _base0(&cls::super::Type(), #cls); \
GET_BASE_TYPE(_base1, _base0, super1, cls) \
return _base1; }  \
RTTI_GET_TYPE(cls)

#define DEFINE_RTTI_OBJECT4(cls, super, super1, super2)    \
static inline  BaseType&  Type() { \
static BaseType _base0(&cls::super::Type(), #cls); \
GET_BASE_TYPE(_base1, _base0, super1, cls) \
GET_BASE_TYPE(_base2, _base1, super2, cls) \
return _base2; }  \
RTTI_GET_TYPE(cls)

#define DEFINE_RTTI_OBJECT5(cls, super, super1, super2, super3)    \
static inline  BaseType&  Type() { \
staticBaseType _base0(&cls::super::Type(), #cls); \
GET_BASE_TYPE(_base1, _base0, super1, cls) \
GET_BASE_TYPE(_base2, _base1, super2, cls) \
GET_BASE_TYPE(_base3, _base2, super3, cls) \
return _base3; }  \
RTTI_GET_TYPE(cls)



#define DEFINE_RTTI_ROOT(cls)            \
static inline  BaseType&  Type() { \
static  BaseType _type(0, #cls); return _type; } \
RTTI_GET_TYPE(cls)            \
\
template <class T, class C> static inline T* DynamicCast(C* obj)      \
{                \
return GET_CLASS_TYPE(T)->is(GET_OBJECT_TYPE(obj)) ? reinterpret_cast<T*>(obj) : NULL;  \
}


#define GET_CLASS_TYPE(cls) (&cls::Type())
#define GET_CLASS_TYPE_NAME(cls) (GET_CLASS_TYPE(cls)->getName())

#define GET_OBJECT_TYPE(obj) (obj->GetType())
#define GET_OBJECT_TYPE_NAME(obj) (GET_OBJECT_TYPE(obj)->getName())

#define ADD_SUPER_CLASS(cls, parent) ( cls::AddSuperClass(&parent::Type()) )


#endif /* rtti_h */
