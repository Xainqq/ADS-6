// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
  T arr[100];
  int first;
  int last;

 public:
    TPQueue() : first(0), last(0) {}
    int getSize() {
      return last - first;
    }
    void push(T temporary) {
      if (getSize() >= size) {
        throw std::string("full"); // не работает
      } else {
          int a = last++;
          while ((--a >= first) && (arr[a % size].prior < temporary.prior)) {
            arr[(a + 1) % size] = arr[a % size];
        }
        arr[(a + 1) % size] = temporary;
       }
    }
    T front() {
        return arr[(first) % size];
    }
    T back() {
        return arr[(last - 1) % size];
    }
    T pop() {
        return arr[(first++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
