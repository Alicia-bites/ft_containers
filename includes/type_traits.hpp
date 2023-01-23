#pragma once

// If B is true, std::enable_if has a public member typedef type.
// equal to T; otherwise, there is no member typedef.

namespace ft
{
    template <typename T, T v>
        struct integral_constant
        {
			static const T					value = v;
			typedef T						value_type;
			typedef integral_constant<T,v>	type;
			operator T() const				
			{ 
				return v; 
			}
        };

    typedef integral_constant<bool,true>	true_type;
    typedef integral_constant<bool,false>	false_type;
    
    template<typename T>
	struct is_integral : public false_type {};
    
    template<>	struct is_integral<unsigned char>			: public true_type {};
    template<>	struct is_integral<unsigned short int>		: public true_type {};
    template<>	struct is_integral<unsigned int>	  		: public true_type {};
    template<>	struct is_integral<unsigned long int>       : public true_type {};
    template<>	struct is_integral<unsigned long long int>  : public true_type {};
    template<>	struct is_integral<signed char>	   			: public true_type {};
    template<>	struct is_integral<short int>	     		: public true_type {};
    template<>	struct is_integral<int>	 					: public true_type {};
    template<>	struct is_integral<long int>	      		: public true_type {};
    template<>	struct is_integral<long long int>	 		: public true_type {};
    template<>	struct is_integral<char>					: public true_type {};
    template<>	struct is_integral<wchar_t>					: public true_type {};
    template<>	struct is_integral<bool>					: public true_type {};


    // The template parameter "T" is only enabled (= validayy) if the boolean
    // template parameter "B" is true. The second parameter T is set to void by default.
    template<bool B, typename T = void>
        struct enable_if
		{};
 
    // Member typedef called "type" will be set to "T" when 
    // the template parameter "true" is passed as the first 
    // template parameter to "enable_if".
    template<typename T>
        struct enable_if<true, T>
		{ 
			typedef T type;
		};
}