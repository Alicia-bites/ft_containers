#pragma once

namespace ft
{
	// true if for every iterator i in the range [first_a, last_a) the following corresponding con-
	// ditions hold: *i == *(first_b + (i - first_a)), pred(*i, *(first_b + (i -
	// first_a))) != false. Otherwise, returns false.
    template <class InputIt1, class InputIt2>
    bool    equal(InputIt1 first_a, InputIt1 last_a, InputIt2 first_b)
    {
        for (; first_a != last_a; ++first_a, ++first_b)
        {
            if (!(*first_a == *first_b))
                return (false);
        }
        return (true);
    }

	// true if for every iterator i in the range [first_a, last_a) the following corresponding con-
	// dition holds: pred(*i, *(first_b + (i - first_a))) != false. Otherwise, returns false.
    template <class InputIt1, class InputIt2, class BinaryPredicate>
    bool    equal(InputIt1 first_a, InputIt1 last_a, InputIt2 first_b, BinaryPredicate input_function)
    {
        for (; first_a != last_a; ++first_a, ++first_b)
        {
            if (input_function(*first_a, *first_b) == 0)
                return (false);
        }
        return (true);
    }

	// Returns true if the range [first_a,last_a) compares lexicographically less than the range [first_b,last_b).
    template <class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first_a, InputIt1 last_a, InputIt2 first_b, InputIt2 last_b)
    {
		while (first_a != last_a && first_b != last_b)
		{
			if (*first_a < *first_b)
				return true;
			if (*first_b < *first_a)
				return false;
			++first_a;
			++first_b;
		}
		return (first_a == last_a && first_b != last_b);
    }

	// Returns true if the range [first_a,last_a) compares lexicographically less than the range [first_b,last_b).
	// Compare is a template argument that specifies a comparison function.
    template <class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first_a, InputIt1 last_a, InputIt2 first_b, InputIt2 last_b, Compare comp)
    {
		while (first_a != last_a && first_b != last_b)
		{
			if (comp(*first_a, *first_b))
				return true;
			if (comp(*first_b, *first_a))
				return false;
			++first_a;
			++first_b;
		}
		return (first_a == last_a && first_b != last_b);
    }

	// Exchanges the values of a and b.
    template <class T>
    void    swap(T & a, T & b)
    {
        T c(a);
        
        a = b;
        b = c;
    }
}