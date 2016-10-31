#ifndef DYNAMICAYYAY_H_
#define DYNAMICAYYAY_H_

#include "iostream"
using namespace std;

template <typename Type>
class DynamicArray{
public:
  Type* parray_;
  int size_;
  int capacity_;
  DynamicArray();
  Type Get(int i);
  bool Set(int i, Type value);
  void PushBack(Type value);
  bool Remove(int i);
  int Size();
  ~DynamicArray();
};




template <typename Type >
DynamicArray<Type>::DynamicArray(){
  Type* temp = new Type[2];
  this->parray_ = temp;
  this->size_ = 0;
  this->capacity_ = 2;
}

template <typename Type >
int DynamicArray<Type>::Size(){
  return this->size_;
}

template <typename Type >
Type DynamicArray<Type>::Get( int i ){
  if (i < 0 && i > this->size_){
    cout << "Index error !" << endl;
    return ;
  }
  return this->parray_[i];
}

template <typename Type >
bool DynamicArray<Type>::Set( int i, Type value ){
  if (i < 0 && i > this->size_){
    cout << "Index error !" << endl;
    return false;
  }
  this->parray_[i] = value;
  return true;
}

template <typename Type >
void DynamicArray<Type>::PushBack( Type value ){
  if (this->size_ == this->capacity_){
    Type* temp = new Type[2 * this->capacity_];
    for(int i=0; i<this->capacity_; i++)
      temp[i] = this->parray_[i];
    delete [] this->parray_;
    this->parray_ = temp;
  }

  this->parray_[this->size_] = value;
  this->size_ += 1;
  this->capacity_ *= 2;
  return ;
}

template <typename Type >
bool DynamicArray<Type>::Remove( int i ){
  if (i < 0 && i > this->size_){
    cout << "Index error !" << endl;
    return false;
  }

  for(int j=i+1; j<this->size_; j++)
    this->parray_[j-1] = this->parray_[j];
  return true;
}

template <typename Type >
DynamicArray<Type>::~DynamicArray(){
  delete [] this->parray_;
}


#endif
