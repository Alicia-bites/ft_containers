#pragma once

#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <cstddef>
#include <memory>

#include "../colors/colors.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"
#include "algorithms.hpp"

#include "vectorIterator.hpp"

// Generalites sur le conteneur Vector :
// Il reprend la notion usuelle de tableau en autorisant un
// acces direct a un element quelconque avec une efficacite
// independante du nombre de ses elements.
// Cet acces peut se faire soit par le biais d'un iterateur
// a acces direct soit par l'operateur [], soit par la 
// fonction membre .at().
// Vector offre un cadre plus general que le tableau puisque :
// -- 1) La taille (cad le nb d'elements peut varier au cours
// 			de l'execution.)
// -- 2) On peut effectuer toutes les operations de construc-
//			tions (construction d'un conteneur vide,
//			construction d'un conteneur avec un nombre donne
//			d'elements, construction avec un nombre donne
//			d'elements initialises a une valeur et cons-
//			truction a partir d'une sequence + construc-
//			tion a partir d'un conteneur du meme type.)
//		 On peut effectuer toutes les operations d'affecta-
// 			tion (on peut affecter un conteneur d'un type
//			donne a un autre conteneur de meme type avec
//			l'operateur =, on peut affecter a un conteneur
//			existant les elements d'une sequence definie 
//			avec assign.)
// -- 3) On peut faire des insertions et des suppressions
//			ou on veut.
//			
// Remarque :
// Dans la definition d'un patron, on utilise le mot 'class'
// pour indiquer en fait un type quelconque, classe ou non.
// (comme ca --> 'template <class T> T' qui veut dire : le
// type T peut etre n'importe quel type.)
// Nonobstant, la norme a introduit le mot cle 'typename'
// pour remplacer le mot 'class' qui fait quand meme plus
// sens.

// The std::allocator class template is the default Allocator
// used by all standard library containers if no user-specified
// allocator is provided.

// size_type can store the maximum size of a theoretically 
// possible object of any type (including array)

namespace ft 
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		// struct MemoryChunk
		// {
		// 	T* start;
		// 	T* end;
		// 	MemoryChunk* next;
		// };

		public:
			// HOMEMADE TYPE DEFINITION
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef vectorIterator<T>						iterator;
			typedef vectorIterator<const T>					const_iterator;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t 							difference_type;
			typedef T										value_type;
			typedef Allocator								allocator_type;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> 	const_reverse_iterator;

	//		CONSTRUCTORS ----------------------------------------------------------------------------

			// no param constructor --> construct empty container,
			// we call Allocator() which is the default constructor
			// for the Allocator class.
			// "explicit" : Specifies that a constructor is explicit,
			// that is, it cannot be used for implicit conversions 
			// and copy-initialization.
			explicit vector(const Allocator & allocator = Allocator())
			: size_(0)
			, capacity_(0)
			, array_(0)
			, allocator_(allocator)
			{
				// std::cout << OLIVE << "Calling default constructor." 
				// 	<< std::endl << RESET;
			};

			// constructor with a given number of elements
			explicit vector(size_type size, const Allocator & allocator = Allocator())
			: size_(size)
			, capacity_(0)
			, array_(0)
			, allocator_(allocator)
			{
				// std::cout << OLIVE << "Calling empty conainter constructor." 
				// 	<< std::endl << RESET;

				// step 1 : allocate memory
				if (size_ != 0)
				{
					array_ = allocator_.allocate(size_);
					capacity_ = size_;
				}
				// step 2 : initialisation
				for (size_type i = 0; i < size_; i++)
				{
					// std::allocator::construct -- > Constructs an element object on the location pointed by p.
					allocator_.construct(array_ + i, T());
				}
			};


			// constructor with a given number of elements and a value to initialize the elements
			explicit vector(size_type size, const T & value, const Allocator & allocator = Allocator())
			: size_(size)
			, capacity_(0)
			, array_(0)
			, allocator_(allocator)
			{
				// std::cout << OLIVE << "Calling fill constructor." 
					// << std::endl << RESET;

				// step 1 : allocate memory
				if (size_ != 0)
				{
					array_ = allocator_.allocate(size_);
					capacity_ = size_;
				}
				// step 2 : initialisation
				for (size_type i = 0; i < size_; i++)
				{
					// std::allocator::construct -- > Constructs an element object on the location pointed by p.
					allocator_.construct(array_ + i, value);
				}
			};

//			range constructor : Constructs a container with as many elements as
//				the range [first,last), with each element constructed 
//				from its corresponding element in that range, in the same order.
//			type of the first argument will only be defined as input iterator if 
//				this argument is not an integer (iow scalars --> native types with 
//				a simple value, like int, char, long, bool...).
			template <typename InputIt>
				vector(typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last, const Allocator & allocator = Allocator())
				: size_(0)
				, capacity_(0)
				, array_(0)
				, allocator_(allocator)
				{
					// std::cout << OLIVE << "Calling range constructor." 
					// 	<< std::endl << RESET;

					InputIt remember_first = first;
					for (; first != last; first++)
						size_++;
					first = remember_first;
					if (size_)
					{
						array_ = allocator_.allocate(size_);
						capacity_ = size_;
					}
					for (size_type i = 0; i < size_; i++)
					{
						allocator_.construct(array_ + i, *first);
						first++;
					}
				};

	//			Copy constructor : Constructs a container with a copy of each of 
	//			the elements in original, in the same order.
				vector(const vector<T,Allocator> & original)
				: size_(0)
				, capacity_(0)
				, array_(0)
				, allocator_(original.allocator_)
				{

					// std::cout << OLIVE << "Calling copy constructor." 
					// 		<< std::endl << RESET;
					// std::cout << "Original contains : " << original << std::endl;
					if (original.capacity_)
					{
						array_ = allocator_.allocate(original.capacity_);
					}
					for (size_type i = 0; i < original.size_; i++)
					{
						allocator_.construct(array_ + i, original[i]);
						// std::cout << GREEN2 << "original[i] = " << original[i] << std::endl;
					}

					size_ = original.size_;
					capacity_ = original.capacity_;

					// if (this != &original)
						// this->insert(this->begin(), original.begin(), original.end());

					// if (this != &original)
						// assign(original.begin(), original.end());

				};

	//		DESTRUCTORS --------------------------------------------------------------------------------------
			~vector()
			{
				// std::cout << OLIVE << "Calling destructor." 
				// 	<< std::endl << RESET;

				// std::cout << DODGERBLUE2 << "-----------------------------------------------------------------------------" << std::endl;
				// std::cout << "vector size is " << size_ << std::endl;
				// std::cout << "vector capacity is " << capacity_ << std::endl;
				// for (size_t i = 0; i < size_; i++)
					// std::cout << this[i] << " | ";
				// std::cout << std::endl;
				// std::cout << DODGERBLUE2 << "-----------------------------------------------------------------------------" << RESET << std::endl;

				if (capacity_ == 0)
					return ;
				for (size_type i = 0; i < size_; i++)
					allocator_.destroy(array_ + i);

				allocator_.deallocate(array_, capacity_);
			};

//	MEMBER FUNCTIONS ---------------------------------------------------------------------------------

	//		GETTERS ----------------------------------------------------------------------------------------------------------------------------

			allocator_type get_allocator() const
			{
				return allocator_;
			};

			pointer	get_array() const
			{
				return array_;
			}

	//		ASSIGNEMENT ----------------------------------------------------------------------------------------------------------------------------
			vector<T,Allocator>& operator=(const vector<T,Allocator> & src)
			{
				if (this == &src)
					return (*this);

				this->~vector();
				// // placement new --> way to call the constructor of an object at a specific memory location.  The this pointer is passed as the memory location where the object is to be constructed.
				new (this) vector(src);
				return *this;
			};

			// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
			// The new contents are elements constructed from each of the elements in the range between first and last, in the same order.
			template <class InputIt>
				void assign(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last)
				{

					// find out how many elements must be assigned
					size_type n = std::distance(first, last);
					// reserve necessary capacity
					if (n > capacity_)
						reserve(n);
					// destroy elements in array_
					for (size_type i = 0; i < size_; i++)
						allocator_.destroy(array_ + i);
					size_type i = 0;
					// copy new elements
					for (; first != last; first++)
					{
						array_[i] = *first;
						i++;
					}
					// update size_
					size_ = n;
				};
			
			// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
			// The new contents are n elements, each initialized to a copy of val.
			 void    assign(size_type n, const T & val)
			 {
				// reserve necessary capacity
				if (n > capacity_)
					reserve(n);
				// destroy elements in array_
				for (size_type i = 0; i < size_; i++)
					allocator_.destroy(array_ + i);
				// update size_
				size_ = n;
				// copy new elements
				for (size_type i = 0; i < size_; i++)
					allocator_.construct(array_ + i, val);
			 }

	//		ITERATORS --------------------------------------------------------------------------------------
			// returns an iterator pointing to the first element in the vector.
			iterator	begin()
			{
				return array_;
			};

			const_iterator	begin() const
			{
				return array_;
			};

			// returns an iterator referring to the past-the-end element in the vector container.
			iterator	end()
			{
				return array_ + size_;
			};

			const_iterator	end() const
			{
				return array_ + size_;
			};
			
			// returns a reverse iterator pointing to the last element in the vector
			reverse_iterator	rbegin()
			{
				return reverse_iterator(end());
			};

			const_reverse_iterator	rbegin() const
			{
				return reverse_iterator(end());
			};

			// returns a reverse iterator pointing to the theoretical element
			// preceding the first element in the vector 
			// (which is considered its reverse end).
			reverse_iterator	rend()
			{
				return reverse_iterator(begin());
			};

			const_reverse_iterator 	rend() const
			{
				return reverse_iterator(begin());
			};

	//		CAPACITY --------------------------------------------------------------------------------------
			
			// returns the number of elements in the vector.
			size_type size() const
			{
				return size_;
			};

			// Returns the maximum number of elements that the vector can hold.
			size_type max_size() const
			{
				// max_size() returns the maximum size possible to allocate
				return allocator_.max_size();
			};

			// if n is greater than the current vector capacity, the function 
			// causes the container to reallocate its storage increasing its
			// capacity to n (or greater).
			void reserve(size_type newcapacity)
			{
				if (newcapacity < capacity_ || newcapacity == 0)
					return ;
				if (newcapacity > max_size())
					throw (std::length_error("Can´t reserve more space than max_size() allows. Try with a number smaller than max_size()"));
				
				// Allocate new memory
				pointer new_array = allocator_.allocate(newcapacity);
		
				// Copy elements to new memory
				for (size_t i = 0; i < size_; ++i)
					allocator_.construct(new_array + i, array_[i]);
		
				// Deallocate old memory
				for (size_t i = 0; i < size_; ++i)
					allocator_.destroy(array_ + i);
				allocator_.deallocate(array_, capacity_);

				// updates
				capacity_ = newcapacity;
				array_ = new_array;
			};


			// resizes the container so that it contains n elements.
			void resize(size_type newsize, T val = T())
			{
				if (newsize <= size_)
				{
					for (size_t i = newsize; i < size_; i++)
						allocator_.destroy(array_ + i);
					size_ = newsize;
				}
				else if (newsize > size_)
				{
					// step 1 : we increase the allocated space of our vector with reserve() 
					try
					{
						if (newsize > capacity_)
							reserve(newsize);
					}
					catch(const std::exception& e)
					{
						throw (std::bad_alloc());
						return ;
					}
					// step 2 : we add elements until newsize is satisfied
					// if val is not specified, val will automatically be set to 0
					for(size_t i = size_; i < newsize; i++)
						allocator_.construct(array_ + i, val);
					size_ = newsize;
				}
			};

			// returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
			size_type capacity() const
			{
				return capacity_;
			};

			// Returns whether the vector is empty (i.e. whether its size is 0).
			bool empty() const
			{
				return (size_ == 0 ? true : false);
			};

	//		ELEMENT ACCESS --------------------------------------------------------------------------------------
			
			reference	operator[](size_type index)
			{
				return (array_[index]);
			};

			reference	operator[](size_type index) const
			{
				return (array_[index]);
			};
			
			const_reference at(size_type index) const
			{
				if (index >= size_)
					throw (std::out_of_range("Error! You are trying to access an element outside our range."));
				return (array_[index]);
			};

			reference at(size_type index)
			{
				if (index >= size_)
					throw (std::out_of_range("Error! You are trying to access an element outside our range."));
				return (array_[index]);
			};

			reference front()
			{
				return array_[0];
			};

			const_reference front() const
			{
				return array_[0];
			};

			reference back()
			{
				return array_[size_ - 1];
			};

			const_reference back() const
			{
				return array_[size_ - 1];
			};


//			MODIFIERS --------------------------------------------------------------------------------------------------------------------

			// Removes the last element in the vector, effectively reducing the container size by one.

			// Adds a new element at the end of the vector, after its current 
			// last element. The content of new_elt is copied (or moved) to the new element.
			void	push_back(const T& new_element)
			{
				if (capacity_ * 2 > max_size())
					throw (std::length_error("Cannot allocate anymore. Maximum size reached"));
				else if (capacity_ <= size_)
				{
					capacity_ = capacity_ == 0 ? 1 : capacity_ * 2;
					reserve(capacity_);
				}
				size_++;
				allocator_.construct(array_ + size_ - 1, new_element);
			};

		
			void	pop_back()
			{
				allocator_.destroy(array_ + size_ - 1);
        		size_--;
			};

			// Inserts element of value new_guy at the specified location in the container. 
			iterator	insert(iterator position, const T & new_guy)
			{
				size_type where_to_insert = std::distance(begin(), position);

				if (size_ + 1 > capacity_)
					reserve(size_ + 1);
				// step 2 : translate position from iterator to integer so we can
				// add it to our pointer array_ and place our new guy
				position = begin() + where_to_insert;
				if (position == end())
					allocator_.construct(array_ + size_, new_guy);
				else
				{
					// step 3 : we just construct one more object at the end()
					// and place our last element.
					allocator_.construct(array_ + size_, array_[size_ - 1]);
					// step 4 : we replace every value by the one before until
					// we reach where we want to add our new guy.
					size_++; // we update size_ because end() depends on it
					for (iterator itEnd = end() - 2; itEnd > position; itEnd--)
						*itEnd = *(itEnd - 1);
					// step 5 : we copy the value of our new_guy at index position
					*position = new_guy;
				}
				capacity_ = size_;
				return position;
			};

			// Inserts n elements of value new_guy at the specified location (position) in the container. 
			void	insert(iterator position, size_type n, const T & new_guy)
			{
				size_type where_to_insert = std::distance(begin(), position);

				// step 1 : allocation
				if (size_ + n >= capacity_)
					reserve(size_ + n);

				// step 2 : insertion
				if (size_ == 0)
					for (size_type i = 0; i < n; i++)
						allocator_.construct(array_ + i, new_guy);
				else
				{
					if (position == end())
					{
						for (size_type i = size_; i < size_ + n; i++)
							allocator_.construct(array_ + i, new_guy);
					}
					else
					{
						// place the last element at the new end
						size_type new_last_index = size_ + n - 1;
						allocator_.construct(array_ + new_last_index, array_[size_ - 1]);
	
						// shift all the other elements before index 'where_to_insert' n times to the right
						new_last_index--;
						for (size_type i = where_to_insert; i < size_ - 1; i++)
						{
							if (new_last_index < size_)
								allocator_.destroy(array_ + new_last_index);
							allocator_.construct(array_ + new_last_index, array_[new_last_index - n]);
							new_last_index--;
						}
	
						// insert new_guys
						for (size_type i = 0; i < n; i++)
						{
							allocator_.destroy(array_ + where_to_insert);
							allocator_.construct(array_ + where_to_insert, new_guy);
							where_to_insert++;
						}
					}
				}
				//updates
				size_ += n;
				capacity_ = size_;
			};

			// Inserts elements from range [first, last) before posisition. 
			template <class InputIterator>
				void	insert(iterator position, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
				{
					// n is the number of elements to insert
					size_type n = std::distance(first, last); 
					size_type where_to_insert = std::distance(begin(), position);
				
					// step 1 : allocation
					if (size_ + n >= capacity_)
						reserve(size_ + n);

					// step 2 : insertion
					if (size_ == 0)
					{
						for (size_type i = 0; i < n; i++)
						{
							allocator_.construct(array_ + i, *first);
							first++;
						}
					}
					else 
					{
						if (position == end())
						{
							for (; first != last; first++)
							{
								allocator_.construct(array_ + where_to_insert, *first);
								where_to_insert++;
							}
						}
						else
						{
							size_type new_last_index = size_ + n - 1;
	
							// shift element at last index to new last index
							allocator_.construct(array_ + (size_ + n - 1), array_[size_ - 1]);

							// shift all the other elements
							new_last_index--;
							for (size_type i = where_to_insert; i < size_ - 1; i++)
							{
								if (new_last_index < size_)
									allocator_.destroy(array_ + new_last_index);
								allocator_.construct(array_ + new_last_index, array_[new_last_index - n]);
								new_last_index--;
							}
	
							// insert new_guys
							for (; first != last; first++)
							{
								allocator_.destroy(array_ + where_to_insert);
								allocator_.construct(array_ + where_to_insert, *first);
								where_to_insert++;
							}
						}
					}

					// updates
					size_ += n;
					capacity_ = size_;
				};
			
			// Removes from the vector a single element at position.
			// An invalid position or range causes undefined behavior.
			iterator	erase(iterator position)
			{
				if (position == end())
				{
					allocator_.destroy(array_ + (size_ - 1));
					size_--;
					return position;
				}
				
				// shift all elements to the left
			    for (iterator i = position; i != end() - 1; i++)
    			    *i = *(i + 1);
				
				allocator_.destroy(array_ + size_ - 1);

				size_--;
				return position;
			};
// 
			// Removes fromt the vector a range of elements ([first,last))
			// An invalid position or range causes undefined behavior.
			iterator	erase(iterator first, iterator last)
			{
				if (first == last)
					return first;
				size_t n = std::distance(first, last);
				// size_t where_to_erase = std::distance(begin(), last) - 1;
				// for (; where_to_erase < n; where_to_erase++)
				// 	allocator_.destroy(array_+ where_to_erase);
				iterator remember_first = first;
				// shift all elements n times to the left
				for (; first != end() - n; first++)
					*first = *(first + n);
				for (size_type i = size_ - n; i < size_ ; i++)
				{
					allocator_.destroy(array_ + i);
				}
				size_ -= n;
				return remember_first;
			};

//			Exchanges the content of the container by the content of swapMe,
//			which is another vector object of the same type. Sizes may differ.
			void    swap(vector<T, Allocator> & swapMe)
			{
				pointer  	tmp;
				size_type   tmp_size;

				// step 1 : swap arrays (aka pointer to the array of elements of type T)
				if (array_ != swapMe.array_)
				{
					tmp = array_;
					array_ = swapMe.array_;
					swapMe.array_ = tmp;
				}

				// step 2 : swap sizes
				if (size_ != swapMe.size_)
				{
					tmp_size = size_;
					size_ = swapMe.size_;
					swapMe.size_ = tmp_size;
				}

				// step 3 : swap capacities
				if (capacity_ != swapMe.capacity_)
				{
					tmp_size = capacity_;
					capacity_ = swapMe.capacity_;
					swapMe.capacity_ = tmp_size;
				}
			};

			// Removes all elements from the vector (which are destroyed), leaving 
			// the container with a size of 0.
			void    clear()
			{
				while (!empty())
					pop_back();
			};

		private:
			// number of elements in the vector.
			size_type		size_;
			// size of the storage space currently allocated for the vector, 
			// expressed in terms of elements.
			// capacity_ is not necessarily equal to the size_.
			// It can be equal or greater, with the extra space
			// allowing to accommodate for growth without the
			// need to reallocate on each insertion.
			size_type		capacity_;
			// pointer to the array of the elements of type T
			pointer			array_;
			// the tool used to allocate memory
			Allocator		allocator_;
	};


// NON_MEMBER FUNCTION OVERLOADS -------------------------------------------------------------------------------------------------------

	//	COMPARATORS --------------------------------------------------------------------------------------------------------------------
			
		template <typename T, typename Allocator>
			bool	operator==(const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
			{
				if (lhs.size() == rhs.size())
					return (equal(lhs.begin(), lhs.end(), rhs.begin()));
				return (false);
			};

		template <typename T, typename Allocator>
			bool	operator< (const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
			{
				return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			};

		template <typename T, typename Allocator>
			bool	operator!=(const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
			{
				return (!(lhs == rhs));
			};

		template <typename T, typename Allocator>
			bool	operator> (const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
			{
				return (rhs < lhs);
			};

		template <typename T, typename Allocator>
			bool	operator>=(const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
			{
				return (!(lhs < rhs));
			};

		template <typename T, typename Allocator>
			bool	operator<=(const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
			{
				return (!(rhs < lhs));
			};

	//	SPECIALIZED ALGORITHM --------------------------------------------------------------------------------------------------------------------
		
		template <typename T, typename Allocator>
			void	swap(vector<T, Allocator>& x, vector<T, Allocator>& y)
			{
				x.swap(y);
			};
	
	// FOR DEBUG ----------------------------------------------------------------------------------------------------------------------------------

		template <typename T, typename Allocator>
			std::ostream&	operator<<(std::ostream& o, vector<T, Allocator> const & rhs)
			{
				std::cout << DARKTURQUOISE << "Printing content of vector of size(" << rhs.size() << ") : " << std::endl;
				for (size_t i = 0; i < rhs.size(); i++)
					o << rhs.get_array()[i] << " | ";
				std::cout << RESET << std::endl;
				return o;
			}
}