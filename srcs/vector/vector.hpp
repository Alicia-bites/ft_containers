#pragma once

#include <iostream>
#include "../../cool_tools/type_traits.hpp"
#include <stdlib.h>
#include <iterator>

#include "../../cool_tools/colors/colors.hpp"

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

// std::size_t can store the maximum size of a theoretically 
// possible object of any type (including array)

namespace ft 
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			// HOMEMADE TYPE DEFINITION
			typedef typename Allocator::pointer		pointer;
			typedef typename Allocator::reference	reference;

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
				std::cout << SPRINGGREEN5 << "Calling default constructor." 
					<< std::endl << RESET;
			};

			// constructor with a given number of elements
			explicit vector(std::size_t size, const Allocator & allocator = Allocator())
			: size_(size)
			, capacity_(0)
			, array_(0)
			, allocator_(allocator)
			{
				std::cout << SPRINGGREEN5 << "Calling empty conainter constructor." 
					<< std::endl << RESET;
				// step 1 : allocate memory
				if (size_ != 0)
				{
					array_ = allocator_.allocate(size_);
					capacity_ = size_;
				}
				// step 2 : initialisation
				for (std::size_t i = 0; i < size_; i++)
				{
					// std::allocator::construct -- > Constructs an element object on the location pointed by p.
					allocator_.construct(array_ + i, T());
				}
			};

			// constructor with a given number of elements and a value to initialize the elements
			explicit vector(std::size_t size, const T & value, const Allocator & allocator = Allocator())
			: size_(size)
			, capacity_(0)
			, array_(0)
			, allocator_(allocator)
			{
				std::cout << SPRINGGREEN5 << "Calling fill constructor." 
					<< std::endl << RESET;
				// step 1 : allocate memory
				if (size_ != 0)
				{
					array_ = allocator_.allocate(size_);
					capacity_ = size_;
				}
				// step 2 : initialisation
				for (std::size_t i = 0; i < size_; i++)
				{
					// std::allocator::construct -- > Constructs an element object on the location pointed by p.
					allocator_.construct(array_ + i, value);
				}
			};

//			range constructor : Constructs a container with as many elements as
//				the range [first,last), with each element constructed 
//				from its corresponding element in that range, in the same order.
			template <typename InputIt>
				vector(typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last, const Allocator & allocator = Allocator())
				: size_(0)
				, capacity_(0)
				, array_(0)
				, allocator_(allocator)
				{
					std::ptrdiff_t diff = abs(first - last);
					size_ = diff;
					if (size_)
					{
						array_ = allocator_.allocate(size_);
						capacity_ = size_;
					}
					for (std::size_t i = 0; i < size_; i++)
					{
						// std::cout << RED1 << *first << RESET << std::endl;
						allocator_.construct(array_ + i, *first);
						first++;
					}
				};

	//		DESTRUCTORS ----------------------------------------------------------------------------
			~vector(){};

			// GETTERS ---------------------------------------------------------------------------------------
			std::size_t size()
			{
				return size_;
			}

	//		ACCESSORS ----------------------------------------------------------------------------
			typename vector<T, Allocator>::reference	operator[](std::size_t index)
			{
				return (array_[index]);
			}

		private:
			// number of elements in tab
			std::size_t		size_;
			// size of tab (how much we need to malloc)
			std::size_t		capacity_;
			// pointer to the array of elements of type T
			pointer			array_;
			// the tool used to allocate memory
			Allocator		allocator_;
	};
}