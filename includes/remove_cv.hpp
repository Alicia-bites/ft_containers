#pragma once

// Provides a member type alias called type, which is the same as the type T,
// but with any top-level const or volatile qualifications removed.
// In other words, if you have a type T that has const or volatile qualifications,
// std::remove_cv<T>::type will give you the same type without those qualifications.
// This can be useful in generic programming when you need to operate on a type,
// but you don't want to take into account any const or volatile qualifications.
namespace ft 
{
	template <typename T> 
		struct remove_cv                   
		{
			typedef T type;
		};

	template <typename T> 
		struct remove_cv<const T>          
		{
			typedef T type;
		};

	template <typename T> 
		struct remove_cv<volatile T>       
		{
			typedef T type;
		};

	template <typename T> 
		struct remove_cv<const volatile T> 
		{
			typedef T type;
		};

	template <typename T> 
		struct remove_const
		{
			typedef T type;
		};

	template <typename T> 
		struct remove_const<const T>       
		{
			typedef T type;
		};

	
	template <typename T> 
		struct remove_volatile             
		{
			typedef T type;
		};

	template <typename T> 
		struct remove_volatile<volatile T> 
		{
			typedef T type;
		};

};