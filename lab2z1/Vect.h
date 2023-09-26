// Vect.h

#ifndef _VECT_
#define _VECT_
#include <iostream>
#include <string>
#include "VectError.h"

using namespace std;

template <class T>
class Vect {                                           // Template class Vect
public:
	explicit Vect() : first(0), last(0) {}
	explicit Vect(size_t _n, const T& _v = T()) {
		Allocate(_n);
		for (size_t i = 0; i < _n; ++i) {
			*(first + i) = _v;
		}
	}

	Vect(const Vect&);                                 // конструктор копировани€
	Vect& operator =(const Vect&);                     // операци€ присваивани€
	~Vect() {
#ifdef DEBUG
		cout << "Destruction of " << markName << endl;
#endif 
		Destroy();
		first = 0, last = 0;
	}

	void mark(std::string name) { markName = name; }   // установить отладочное им€
	std::string mark() const { return markName; }      // получить отладочное им€
	size_t size() const;                               // получить размер вектора
	T* begin() const { return first; }                 // получить указатель на 1-й элемент
	T* end() const { return last; }                    // получить указатель на элемент, следующий за последним
	T& operator[] (size_t i);                          // операци€ индексировани€
	void insert(T* _P, const T& _x);                   // вставка элемента в позицию _P
	void push_back(const T& _x);                       // вставка элемента в конец вектора
	void pop_back();                                   // удаление элемента из конца вектора
	void show() const;                                 // вывод в cout содержимого вектора

protected:
	void Allocate(size_t _n) {
		first = new T[_n * sizeof(T)];
		last = first + _n;
	}

	void Destroy() {
		for (T* p = first; p != last; ++p) p->~T();
		delete[] first;
	}

	T* first;                                         // указатель на 1-й элемент
	T* last;                                          // указатель на элемент, следующий за последним
	std::string markName;
};

template <class T>
Vect<T>::Vect(const Vect& other) {                    // ----------------  онструктор копировани€
	size_t n = other.size();
	Allocate(n);
	for (size_t i = 0; i < n; ++i) *(first + i) = *(other.first + i);
	markName = string("Copy of ") + other.markName;
#ifdef DEBUG
	cout << "Copy constructor: " << markName << endl;
#endif
}

template <class T>
Vect<T>& Vect<T>::operator=(const Vect& other) { // --------------------- ќпераци€ присваивани€
	if (this == &other) return *this;
	Destroy();
	size_t n = other.size();

	Allocate(n);
	for (size_t i = 0; i < n; ++i) *(first + i) = *(other.first + i);
	return *this;
}

template <class T>
size_t Vect<T>::size() const { // --------------------------------------- ѕолучение размера вектора
	if (first > last) throw VectError();
	return (0 == first ? 0 : last - first);
}

template <class T>
T& Vect<T>::operator[](size_t i) { // ---------------------------------- ќпераци€ доступа по индексу
	if (i < 0 || i >(size() - 1))
		throw VectRangeErr(0, last - first - 1, i);
	return (*(first + i));
}

template <class T>           // ---------------------- ¬ставка элемента со значением _x в позицию _P
void Vect<T>::insert(T* _P, const T& _x) {
	size_t n = size() + 1;                                  // новый размер
	T* new_first = new T[n * sizeof(T)];
	T* new_last = new_first + n;
	size_t offset = _P - first;
	for (size_t i = 0; i < offset; ++i) *(new_first + i) = *(first + i);
	*(new_first + offset) = _x;
	for (size_t i = offset; i < n; ++i) *(new_first + i + 1) = *(first + i);
	Destroy();
	first = new_first;
	last = new_last;
}

template<class T>
void Vect<T>::push_back(const T& _x) { // --------------------- ¬ставка элемента в конец вектора
	if (!size()) { Allocate(1); *first = _x; }
	else insert(end(), _x);
}

template<class T>
void Vect<T>::pop_back() { // ---------- ”даление элемента из конца вектора
	if (last == first) throw VectPopErr();
	T* p = end() - 1;
	p->~T();
	last--;
}

template<class T>
void Vect<T>::show() const { // ----------------------------- ¬ывод в cout содержимого вектора
	cout << "\n===== Contents of " << markName << "=====" << endl;
	size_t n = size();
	for (size_t i = 0; i < n; ++i) cout << *(first + i) << " ";
	cout << endl;
}

#endif /* _VECT_ */
