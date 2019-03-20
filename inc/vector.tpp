
    template <typename T>
Vector<T>::Vector()
    : m_size(0)
    , m_capacity(10)
      , m_vector(0)
{
    m_vector = new T[m_capacity];
    assert(m_vector);

}

    template <typename T>
Vector<T>::~Vector()
{
    if (m_vector != 0) {
        delete [] m_vector;
    }
    m_vector = 0;
}

    template <typename T>
Vector<T>::Vector(const Vector<T>& obj)
    : m_vector(0)
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
Vector<T>& Vector<T>::operator=(const Vector<T>& obj)
{
    if (this == &obj) {
        return *this;
    } else {
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;
        m_vector = new T [m_capacity];
        for (int i = 0; i < m_capacity; ++i) {
            m_vector[i] = obj.m_vector[i];
        }
        return *this;
    }
}

    template <typename T>
T& Vector<T>::operator [] (int index)
{
    assert(index >=0 && index < m_size && "Index out of range");
    return m_vector[index];
}

template <typename T>
void Vector<T>::print() const
{
    for (int i = 0; i < m_size; i++) {
        std::cout << m_vector[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
int Vector<T>::get_size() const
{
    return m_size;
}

    template <typename T>
void Vector<T>::insert(int i, T item)
{
    if (m_size == m_capacity) {
        resize();
    }
    ++m_size;
    for (int j = m_size - 1; j > i; --j) {
        m_vector[j] = m_vector[j - 1];
    }
    m_vector[i] = item;

}
    template <typename T>
void Vector<T>::remove(int p)
{
    for (int i = p; i < m_size; ++i) {
        m_vector[i] = m_vector[i + 1];
    }
    --m_size;
}

    template <typename T>
T Vector<T>::pop_back()
{
    T tmp = m_vector[m_size - 1];
    remove(m_size - 1);
    return tmp;
}

    template <typename T>
void Vector<T>::push_back(T a)
{
    if(m_size > m_capacity) {
        resize();
    }
    insert(m_size, a);
}

    template <typename T>
void Vector<T>::resize()
{
    T* vector = new T[m_capacity];
    for (int i = 0; i < m_capacity; ++i) {
        vector[i] = m_vector[i];
    }
    m_capacity *= 2;
    m_vector = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_vector[i] = vector[i];
    }
    delete [] vector;
}
    template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v)
{
    for (int i = 0; i < v.m_size; ++i) {
        out << v.m_vector[i] <<" ";
    }
    std::cout << std::endl;
    return out;
}








