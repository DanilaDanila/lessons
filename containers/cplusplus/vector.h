#pragma optimize("", off)
#ifndef VECTOR_H
#define VECTOR_H

namespace containers
{
	template <typename T>
	class vector
	{
	public:
		typedef T* vector_iterator;

		vector(unsigned int n = 10);

		const unsigned int size();

		const unsigned int capacity();

		T& operator[](unsigned int n);

		vector_iterator begin();

		vector_iterator end();

		void push_back(const T& x);

		T pop_back();

		void insert(vector_iterator p, T x);

		void erase(vector_iterator p);

	private:
		vector_iterator m_begin;
		vector_iterator m_end;
		vector_iterator m_capacity;
	};
}; // namespace containers

#endif // VECTOR_H
