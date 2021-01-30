#ifndef HMK_ARRAY_H
#define HMK_ARRAY_H

#include <iostream>
#include <iterator>
#include <initializer_list>

template<class T, unsigned int Length>
class Array {

	protected:

	T *data;
	unsigned int length;

	public:

	Array(unsigned int _length = Length+1) : length(_length) {
		data = new T[length];
		data[Length] = -32767;
	}

	class iterator : public std::iterator<std::input_iterator_tag, T> {
		protected:

		T *p;

		public:

		iterator(T* x) :p(x) {}
		iterator(const iterator& mit) : p(mit.p) {}
		iterator& operator++() {++p; return *this;}
		iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
		iterator& operator--() {--p; return *this;}
		iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
		bool operator==(const iterator& rhs) const {return p==rhs.p;}
		bool operator!=(const iterator& rhs) const {return p!=rhs.p;}
		T& operator*() {return *p;}
	};

	iterator begin() { return iterator(data); }
	iterator end() { return iterator(data+Length); }
	iterator cbegin() const { return begin(); }
	iterator cend() const { return end(); }

	Array(std::initializer_list<T> list) {
		auto dlit = begin(), drit = end();
		auto lit = list.begin(), rit = list.end();
		for(; lit != rit && dlit != drit; ++lit, dlit++) *dlit = *lit;
	}

	T& operator[](int i) {
		switch(i >= 0) {
			case true: return data[(i<Length?i:Length)];
			case false: return data[(Length+i>=0?Length+i:Length)]; }
	}

	unsigned int size() {
		return Length;
	}

	friend std::istream& operator>>(std::istream& os, Array<T, Length>& obj) {
		for(auto& i : obj) os >> i;
		return os;
	}

	friend std::ostream& operator<<(std::ostream& os, Array<T, Length>& obj) {
		for(auto& i : obj) os << i << ' ';
		return os;
	}
};

#endif

int main() {
	;
}
