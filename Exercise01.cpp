
#include <iostream>
#include <sstream>
#include <algorithm>

template<typename T>
class dynamic_array {

public:
    dynamic_array(int n);

    dynamic_array(const dynamic_array &other);

    T &operator[](int index);

    const T &operator[](int index) const;

    T &at(int index);

    size_t size() const;

    ~dynamic_array();

    T *begin();

    const T *begin() const;

    T *end();

    const T *end() const;

    friend dynamic_array operator+(const dynamic_array &arr1, const dynamic_array &arr2);

private:
    T *data;
    size_t n;

};

template<typename T>
dynamic_array<T>::dynamic_array(int n) {
    this->n = n;
    data = new T[n];
}

template<typename T>
dynamic_array<T>::dynamic_array(const dynamic_array<T> &other) {
    n = other.n;
    data = new T[n];

    for (int i = 0; i < n; ++i) {
        data[i] = other[i];
    }
}

template<typename T>
T &dynamic_array<T>::operator[](int index) {
    return data[index];
}

template<typename T>
const T &dynamic_array<T>::operator[](int index) const {
    return data[index];
}

template<typename T>
T &dynamic_array<T>::at(int index) {
    if (index < n)
        return data[index];
    throw "Index out of range";

}

template<typename T>
size_t dynamic_array<T>::size() const {
    return n;

}

template<typename T>
dynamic_array<T>::~dynamic_array() {
    delete[] data;

}

template<typename T>
T *dynamic_array<T>::begin() {
    return data;
}

template<typename T>
const T *dynamic_array<T>::begin() const {
    return data;
}

template<typename T>
T *dynamic_array<T>::end() {
    return data + n;
}

template<typename T>
const T *dynamic_array<T>::end() const {
    return data + n;
}

template<typename T>
dynamic_array<T> operator+(const dynamic_array<T> &arr1, const dynamic_array<T> &arr2) {
    dynamic_array<T> result(arr1.size() + arr2.size());
    std::copy(arr1.begin(), arr1.end(), result.begin());
    std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

    return result;
}
