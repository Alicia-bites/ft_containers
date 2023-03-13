#pragma once

#include <utility>

namespace ft
{
	// provides a way to choose between two types based on a boolean flag at compile-time.
	template <bool flag, typename IsTrueType, typename IsFalseType>
		struct choose;


 	// If the value of the flag is "true", the "choose" struct contains a nested type "type" 
	// that is equal to "IsTrueType". 
	// If the value of the flag is "false", the "choose" struct 
	// contains a nested type "type" that is equal to "IsFalseType".

	template <typename IsTrueType, typename IsFalseType>
		struct choose<true, IsTrueType, IsFalseType>
		{
			typedef IsTrueType type;
		};

	template <typename IsTrueType, typename IsFalseType>
		struct choose<false, IsTrueType, IsFalseType>
		{
			typedef IsFalseType type;
		};
}