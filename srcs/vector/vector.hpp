#pragma once

#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <cstddef>

#include "../../cool_tools/colors/colors.hpp"
#include "../../cool_tools/iterator.hpp"
#include "../../cool_tools/type_traits.hpp"

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

//				range constructor : Constructs a container with as many elements as
//					the range [first,last), with each element constructed 
//					from its corresponding element in that range, in the same order.
//				type of the first argument will only be defined as input iterator if 
//					this argument is not an integer (iow scalars --> native types with 
//					a simple value, like int, char, long, bool...).
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
	//			the elements in x, in the same order.
				vector(const vector<T,Allocator> & original)
				: size_(original.size_)
				, capacity_(original.capacity_)
				, array_(0)
				, allocator_(original.allocator_)
				{
					// std::cout << OLIVE << "Calling copy constructor." 
					// 	<< std::endl << RESET;

					if (original.capacity_)
					{
						array_ = allocator_.allocate(original.capacity_);
					}
					for (size_type i = 0; i < original.size_; i++)
					{
						allocator_.construct(array_ + i, original[i]);
					}
				};

	//		DESTRUCTORS --------------------------------------------------------------------------------------
			~vector()
			{
				// std::cout << OLIVE << "Calling destructor." 
				// 	<< std::endl << RESET;

				if (capacity_ == 0)
					return ;
				for (size_type i = 0; i < size_; i++)
				{
					allocator_.destroy(array_ + i);
				}
				allocator_.deallocate(array_, capacity_);
			};

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
			void reserve(size_type new_capacity)
			{
				if (new_capacity < capacity_)
					return ;
				if (new_capacity > max_size())
					throw (std::length_error("Can´t reserve more space than max_size() allows. Try with a number smaller than max_size()"));
				// step 1, we create a new pointer and allocate as much space as new_capacity indicates
				pointer new_array;
				new_array = allocator_.allocate(new_capacity);
				// step 2, we copy each element of the old array in new_array
				for (size_t i = 0; i < size_; i++)
					allocator_.construct(new_array + i, array_[i]);
				// step 3, we destroy old array
				for (size_t i = 0; i < capacity_; i++)
					allocator_.destroy(array_ + i);
				allocator_.deallocate(array_, capacity_);
				capacity_ = new_capacity;
				array_ = new_array;
			};


			// resizes the container so that it contains n elements.
			void resize(size_type newsize, T val = T())
			{
				if (newsize <= size_)
				{
					for (size_t i = newsize; i < capacity_; i++)
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
				else if (capacity_ > size_)
					allocator_.construct(array_ + size_, new_element);
				else
				{
					capacity_ = capacity_ == 0 ? 1 : capacity_ * 2;
					try
					{
						allocator_.allocate(capacity_);
					}
					catch(const std::exception& e)
					{
						std::cerr << e.what() << '\n';
						return ;
					}
					allocator_.construct(array_ + size_, new_element);
				}
				size_++;
			};

			void	pop_back()
			{
				allocator_.destroy(array_ + size_ - 1);
        		size_--;
			};

			// Inserts element at the specified location in the container. 
			iterator	insert(iterator position, const T & new_guy)
			{
				// step 1 : allocate. If size_ is stritcly inferior to capacity_,
				// it's cool, nothing to allocate. But if size_ is equal to capacity_,
				// we need to allocate one more block for our new guy.
				if (size_ == capacity_)
					allocator_.allocate(size_ + 1);

				// step 2 : translate position from iterator to integer so we can
				// add it to our pointer array_ and place our new guy
				size_type where_to_insert = std::distance(begin(), position);
				position = begin() + where_to_insert;
				if (position == end())
					allocator_.construct(array_ + size_, new_guy);
				else
				{
					// step 3 : we just construct one more object at the end()
					// and place their our last element.
					allocator_.construct(array_ + size_, array_[size_ - 1]);
					// step 4 : we replace every value by the one before until
					// we reach where we want to add our new guy.
					for (iterator itEnd = end() - 2; itEnd > position; itEnd--)
						*itEnd = *(itEnd - 1);
					// step 5 : we copy the value of our new_guy at index position
					*position = new_guy;
				}
				size_++;
				capacity_ = size_;
				return position;
			};

			void	insert(iterator position, size_type n, const T & new_guy)
			{
				size_type where_to_insert = std::distance(begin(), position);
				
				// step 1 : allocation
				if (size_ + n >= capacity_)
					reserve(size_ + n);

				// step 2 : insertion
				if (position == end())
				{
					for (size_type i = size_; i < size_ + n; i++)
						allocator_.construct(array_ + i, new_guy);
				}
				else
				{
					// every elements after 'position' must be shifted 'n' times
					// step 1 : place the last element at the end
					allocator_.construct(array_ + size_, array_[size_ - 1]);
					
					// shift all the other elements
					position = begin() + where_to_insert;
					std::cout << "before for loop = " << *(end() - 6) << std::endl;
					for (iterator itEnd = end() - 2; itEnd > position; itEnd--)
					{
						std::cout << *itEnd << std::endl;
						std::cout << *(itEnd - n) << std::endl;
						*itEnd = *(itEnd - n);
					}
					// insert new_guys
					std::cout << "where_to_insert = " << *(array_ + where_to_insert - 1) << std::endl;
					for (size_type i = 0; i < n; i++)
					{
						allocator_.construct(array_ + where_to_insert, new_guy);
						where_to_insert++;
					}

					// updates
					size_ += n;
					capacity_ = size_;
				}
			};

			// template <class InputIterator>
			// 	void	insert(iterator position, InputIterator first, InputIterator last)
			// 	{

			// 	};
				
			// iterator	erase(iterator position)
			// {

			// };

			// iterator	erase(iterator first, iterator last)
			// {

			// };

			// void	swap(vector<T,Allocator>&)
			// {

			// };

			// void	clear()
			// {

			// };


//			ASSIGNEMENT
			vector<T,Allocator>& operator=(const vector<T,Allocator>& src)
			{
				std::cout << MAGENTA3 << "Calling assignment operator." 
					<< std::endl << RESET;
				if (this != &src)
				{
					ft::vector<int> unconst_src(src);
					swap(unconst_src);
					if (capacity_ > src.capacity_)
					{
						for (size_type i = size_; i != src.size_; i--)
						{
							std::cout << array_[i] << std::endl;
							allocator_.destroy(array_ + i);
						}
					}
				}
				return *this;
			};

			// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
			// template <class InputIt>
			// 	void assign(InputIt first, InputIt last)
			// 	{
					
			// 	};

			// GETTERS ---------------------------------------------------------------------------------------

//			MEMBER FUNCTIONS ---------------------------------------------------------------------------------
//			Exchanges the content of the container by the content of swapMe,
//			which is another vector object of the same type. Sizes may differ.
			void    swap(vector<T, Allocator>& swapMe)
			{
				pointer  tmp;
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

			// void    clear()
			// {
			// 	while (!empty())
			// 		pop_back();
			// };

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
			// pointer to the array of elements of type T
			pointer			array_;
			// the tool used to allocate memory
			Allocator		allocator_;
	};
}