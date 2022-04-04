#include "template_class.h"

template<typename T>
vector<T>::~vector() {
    delete[] buf;
    buf = nullptr;
    len = 0;
}