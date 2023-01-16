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
				std::cout << OLIVE << "Calling default constructor." 
					<< std::endl << RESET;
			};

			// constructor with a given number of elements
			explicit vector(size_type size, const Allocator & allocator = Allocator())
			: size_(size)
			, capacity_(0)
			, array_(0)
			, allocator_(allocator)
			{
				std::cout << OLIVE << "Calling empty conainter constructor." 
					<< std::endl << RESET;
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
				std::cout << OLIVE << "Calling fill constructor." 
					<< std::endl << RESET;
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
						std::cout << OLIVE << "Calling range constructor." 
							<< std::endl << RESET;
						InputIt remember_first = first;
						for (; first != last; first++)
						{
							size_++;
						}
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
					std::cout << OLIVE << "Calling copy constructor." 
						<< std::endl << RESET;
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
				std::cout << OLIVE << "Calling destructor." 
					<< std::endl << RESET;
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

			size_type size() const;
			size_type max_size() const;
			void
			resize(size_type sz, T c = T());
			size_type capacity() const;
			bool
			empty() const;
			void
			reserve(size_type n);

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
			size_type size()
			{
				return size_;
			};

	//		ACCESSORS ----------------------------------------------------------------------------------------
			typename vector<T, Allocator>::reference	operator[](size_type index)
			{
				return (array_[index]);
			};

			typename vector<T, Allocator>::reference	operator[](size_type index) const
			{
				return (array_[index]);
			};

//			MEMBER FUNCTIONS ---------------------------------------------------------------------------------
//			Exchanges the content of the container by the content of swapMe,
//			which is another vector object of the same type. Sizes may differ.
			void    swap(vector<T, Allocator>& swapMe)
			{
				pointer  tmp;
				size_type   tmp_size;

				std::cout << MAGENTA5 << "Swap member function called."
					<< std::endl << RESET;
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
			// number of elements to add in tab
			size_type		size_;
			// size of tab (total number of elements at instant t)
			size_type		capacity_;
			// pointer to the array of elements of type T
			pointer			array_;
			// the tool used to allocate memory
			Allocator		allocator_;
	};
}