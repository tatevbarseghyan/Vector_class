#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <assert.h>

template <typename T> class vector;

template <typename T>
std::ostream& operator <<(std::ostream& out, const vector<T>& v);

template <typename T>
class vector
{
    protected:
        int m_size;
        int m_capacity;
        T* m_vector;
        void resize();
    public:
        vector();
        ~vector();

        vector(const vector&);
        vector& operator= (const vector& obj);

        //the overload function of operator[]
        T& operator[] (int index);
        //the overload fuction of operator[] (for constant vector)
        const T& operator[](int i)  const
        {
            return m_vector[i];
        }
        //this function return size of vector
        int get_size() const;
        //this function cheks if vector is empty then return true, else return false
        bool is_empty();
        //this function return last element of vector
        T& end_element();
        //insert a element in p position
        void insert(int p, T a);
        //delete element from p position
        void remove(int p);
        //this functin add element in end of vector
        void push_back(T a);
        //this function delete last element of vector
        T pop_back();
        //the overload function of operator<<
        friend std::ostream& operator<< <>(std::ostream& out, const vector& v);
};
#endif

    template <typename T>
vector<T>::vector()
    : m_size(0)
    , m_capacity(10)
      , m_vector(NULL)
{
    m_vector = new T[m_capacity];
    assert(m_vector);

}

    template <typename T>
vector<T>::~vector()
{
    if (m_vector != 0) {
        delete [] m_vector;
    }
    m_vector = NULL;
}

    template <typename T>
vector<T>::vector(const vector<T>& obj)
    : m_vector(NULL)
    , m_capacity(10)
      , m_size(0)
{
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    m_vector = new T [m_capacity];
    for (int i = 0; i < m_capacity; ++i) {
        m_vector[i] = obj.m_vector[i];
    }
}

    template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& obj)
{
    if (this == &obj) {
        return *this;
    } else {
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;
        m_vector = new T [m_capacity];
        assert(m_vector);
        for (int i = 0; i < m_capacity; ++i) {
            m_vector[i] = obj.m_vector[i];
        }
        return *this;
    }
}

    template <typename T>
T& vector<T>::operator [] (int index)
{
    if (index >= 0 && index < m_size) {
        return m_vector[index];
    } else {
        std::cout << "Error - index out of range" << std::endl;
    }
}


template <typename T>
int vector<T>::get_size() const
{
    return m_size;
}

    template <typename T>
bool vector<T>::is_empty()
{
    return (m_size == 0);
}

    template <typename T>
T& vector<T>::end_element()
{
    if (m_size == 0) {
        std::cout << "Is empty" << std::endl;
    } else {
        return m_vector[m_size - 1];
    }
}
    template <typename T>
void vector<T>::insert(int i, T item)
{
    if (i > m_size) {
        std::cout << "Index out of range" << std::endl;
        return;
    }
    ++m_size;
    if (m_size > m_capacity) {
        resize();
    }
    for (int j = m_size - 1; j > i; --j) {
        m_vector[j] = m_vector[j - 1];
    }
    m_vector[i] = item;

}
    template <typename T>
void vector<T>::remove(int p)
{
    if (p > m_size - 1) {
        std::cout << "Index out of range" << std::endl;
        return;
    }
    for (int i = p; i < m_size; ++i) {
        m_vector[i] = m_vector[i + 1];
    }
    --m_size;
}

    template <typename T>
T vector<T>::pop_back()
{
    if (m_size == 0) {
        std::cout << "Is empty" << std::endl;
    } else {
        T tmp = m_vector[m_size - 1];
        remove(m_size - 1);
        return tmp;
    }
}

    template <typename T>
void vector<T>::push_back(T item)
{
    if(m_size > m_capacity) {
        resize();
    }
    insert(m_size, item);
}

    template <typename T>
void vector<T>::resize()
{
    m_capacity *= 2;
    T* vector = new T[m_capacity];
    assert(vector);
    for (int i = 0; i < m_size; ++i) {
        vector[i] = m_vector[i];
    }
    delete [] m_vector;
    m_vector = vector;
}
    template <typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& v)
{
    for (int i = 0; i < v.m_size; ++i) {
        out << v[i] <<" ";
    }
    std::cout << std::endl;
    return out;
}








