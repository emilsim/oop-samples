﻿#pragma once

#include <iostream>

class Array
{
private:
	///
	/// Представя един от елементите на масива
	///
	class ElementProxy
	{
	private:
		Array* pArray;
		size_t ElementIndex;

	public:
		ElementProxy(Array* pArray, size_t ElementIndex);

		operator int() const;
		ElementProxy& operator=(const int);
	};

public:
	///
	/// Итерира елементите на масива последователно,
	/// започвайки от дадена начална позиция
	///
	class Iterator
	{
	protected:
		Array* pArray;
		size_t InitialPos;
		size_t CurrentPos;
		bool EndReached;
	public:
		Iterator(Array*, size_t);

	public:
		void Rewind();
		bool Next();
		bool IsOver() const;
		int& Value();
		size_t Index() const;
	};

	///
	/// Итерира елементите на масива в обратен ред,
	/// започвайки от дадена начална позиция
	///
	class BackwardIterator : public Iterator
	{
	public:
		BackwardIterator(Array*, size_t);
		bool Next();
	};

	friend class Iterator;

private:
	int *pArr;
	size_t Size;

public:
	Array();
	Array(size_t Size);
	Array(Array const &);
	~Array();
	Array& operator=(Array const &);

public:
	Array& operator+=(Array const &);
	Array operator+(Array const &) const;

	const ElementProxy operator[](size_t) const;
	ElementProxy operator[](size_t);

private:
	void CopyFrom(Array const &);

public:
	void SetSize(size_t NewSize);
	size_t GetSize() const;

	void SetAt(size_t index, int Value);
	void SetAtAutoResize(size_t index, int Value);
	int GetAt(size_t index) const;

	void Release();

	Iterator GetIterator();
	BackwardIterator GetBackwardIterator();
};

std::ostream& operator<< (std::ostream&, Array const&);