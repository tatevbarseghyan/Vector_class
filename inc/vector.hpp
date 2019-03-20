#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <assert.h>

template <typename T> class Vector;

template <typename T>
std::ostream& operator <<(std::ostream& out, const Vector<T>& v);

template <typename T>
class Vector
{
    private:
        int m_size;
        int m_capacity;
        T* m_vector;
        void resize();
    public:
        Vector();
        ~Vector();

        Vector(const Vector&);
        Vector& operator= (const Vector& obj);

        T& operator[] (int index);
        int get_size() const;
        void print() const;

        void insert(int p, T a);
        void remove(int p);

        void push_back(T a);
        T pop_back();

        friend std::ostream& operator<< <>(std::ostream& out, const Vector& v);
};
#include "vector.tpp"
#endif
