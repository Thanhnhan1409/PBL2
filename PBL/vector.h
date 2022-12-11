#pragma once
#include <iostream>
using namespace std;
template <typename T>
class vector
{
private:
    int current;
    int capacity;
    T* array;
public:
    vector();
    vector(const T&);
    ~vector();

     void push_back(T x);
     void pop();
     int  size();
     bool search(T);

    T& operator[](int index);
};
template <typename T>
vector<T>::vector()
{
    array = new T[20];
    capacity = 1;
    current = 0;
}
template <typename T>
vector<T>::vector(const T& a)
{
    current = a.current;
    capacity = a.capacity;
    array = new T[current];
    for (int i = 0; i < current; i++)
        array[i] = a.array[i];
}

template <typename T>
vector<T>::~vector()
{
    delete[] array;
}

template <typename T>
T& vector<T>:: operator[](int i)
{
    return array[i];
}

template <typename T>
void vector<T>::push_back(T data)
{
    if (current == capacity) 
    {
        T* temp = new T[2 * capacity];
        for (int i = 0; i < capacity; i++) {
            temp[i] = array[i];
        }
        delete[] array;
        capacity *= 2;
        array = temp;
    }
    array[current] = data;
    current++;
}

template <typename T>
void vector<T>::pop()
{
    if (current == 0)
    {
        cout << "Empty!" << endl;
        return;
    }
    current--;
}

template <typename T>
int vector<T>::size()
{
    return current;
}

template <typename T>
bool vector<T>::search(T a)
{
    for (int i = 0; i < capacity; i++)
    {
        if (array[i] == a)
        {
            return true;
            break;
        }

    }
    return false;
}

