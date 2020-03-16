//
// Created by abuzaid268 on 2/27/20.
//

#ifndef DNA_SEQUENCE_C___UNIQUEPTR_H
#define DNA_SEQUENCE_C___UNIQUEPTR_H
//
// Created by abuzaid268 on 2/18/20.
//

#ifndef uniquePtr_C___UNIQUEPTR_H
#define uniquePtr_C___UNIQUEPTR_H

template <typename U>
struct uniquePtr{

    explicit uniquePtr(U& ptr): ptr(ptr) {}

    U& operator*(){
        return *ptr;
    }

    U* get()const{
        return ptr;
    }

    U* operator->(){
        return ptr;
    };

    ~uniquePtr(){
        delete ptr;
    }

    friend U* move(uniquePtr<U>& src);

    uniquePtr<U>& operator = (U *other){
        this->ptr = other;
        return *this;
    }

private:
    U* ptr;
    explicit uniquePtr (uniquePtr& other){
        other.ptr = ptr;
        ptr = 0;
    }
};

template <typename T>
T* move(uniquePtr<T>& src){
    T * x = src.ptr;
    src.ptr = 0;
    return x;
}

#endif //uniquePtr_C___UNIQUEPTR_H
#endif //DNA_SEQUENCE_C___UNIQUEPTR_H
