#pragma once

#include <iostream>

namespace ft
{
	template <typename Key, typename Value >
	class mapIterator
	{
		public:
			typedef std::pair<const Key, Value > value_type;
			typedef value_type& reference;
			typedef value_type* pointer;
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;

		explicit map_iterator(typename std::map<Key, T>::iterator it)
	    : it_(it)
		{};

		reference operator*() const { return *it_; }
		pointer operator->() const { return &(*it_); }

		map_iterator& operator++()
		{
			++it_;
			return *this;
		};

		map_iterator operator++(int)
		{
			map_iterator tmp(*this);
			++(*this);
			return tmp;
		};


		map_iterator& operator--()
		{
			--it_;
			return *this;
		};

		map_iterator operator--(int)
		{
			map_iterator tmp(*this);
			--(*this);
			return tmp;
		};

		bool operator==(const map_iterator& rhs) const { return it_ == rhs.it_; }
		bool operator!=(const map_iterator& rhs) const { return it_ != rhs.it_; }

		private:
		typename std::map<Key, T>::iterator it_;
	};
}