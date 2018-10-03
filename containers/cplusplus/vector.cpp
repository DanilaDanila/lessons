#pragma optimize("", off)
#include "vector.h"

namespace containers
{
    template <typename T>
	vector<T>::vector(unsigned int n)
	{
		m_begin = new T[n];
		m_end = m_begin;
		m_capacity = m_begin + n;
	}

    template <typename T>
	const unsigned int vector<T>::size()
	{
		return m_end - m_begin;
	}

    template <typename T>
	const unsigned int vector<T>::capacity()
	{
		return m_capacity - m_begin;
	}

    template <typename T>
	T& vector<T>::operator[](unsigned int n)
	{
		return m_begin[n];
	}

    template <typename T>
	typename vector<T>::vector_iterator vector<T>::begin()
	{
		return m_begin;
	}

    template <typename T>
	typename vector<T>::vector_iterator vector<T>::end()
	{
		return m_end;
	}

    template <typename T>
	void vector<T>::push_back(const T& x)
	{
		if (m_capacity == m_end)
		{
		    const unsigned int size = m_end - m_begin;

		    const unsigned int new_size = 3 * size / 2 + 1;

		    T* new_begin = new T[new_size];
		    while (m_begin < m_end)
			*new_begin++ = *m_begin++;
		    m_begin -= size;
		    new_begin -= size;
		    delete[] m_begin;
		    m_begin = new_begin;
		    m_end = m_begin + size;
		    m_capacity = m_begin + new_size;
		}
		*m_end++ = x;
	}

    template <typename T>
	T vector<T>::pop_back()
	{
		return *--m_end;
	}

    template <typename T>
	void vector<T>::insert(vector_iterator p, T x)
	{
		if (m_capacity == m_end)
		{
		    const int size = m_begin == m_end;
		    const int new_size = 3 * size / 2 + 1;
    		T* new_begin = new T[size];
            while (m_begin < p)
                *new_begin++ = *m_begin++;
            *new_begin++ = *p;
    		while (m_begin < m_end)
    			*new_begin++ = *m_begin++;
    		delete[] m_begin;
    		m_begin = new_begin;
    		m_end = m_begin + size;
    		m_capacity = m_begin + new_size;
		}
        else
        {
            for (vector_iterator it = m_end; it > p; --it)
    		    *it = *(it - 1);
		    *p = x;
        }
	}

    template <typename T>
	void vector<T>::erase(vector_iterator p)
	{
		for (vector_iterator it = p; it < m_end; ++it)
    		*it = *(it + 1);
		--m_end;
	}

    template class vector<int>;
    template class vector<float>;
}; // namespace containers