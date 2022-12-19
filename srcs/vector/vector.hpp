#pragma once

#include <iostream>

// Remarque :
// Dans la definition d'un patron, on utilise le mot 'class'
// pour indiquer en fait un type quelconque, classe ou non.
// (comme ca --> 'template <class T> T' qui veut dire : le
// type T peut etre n'importe quel type.)
// Nonobstant, la norme a introduit le mot cle 'typename'
// pour remplacer le mot 'class' qui fait quand meme plus
// sens.


template <typename T, typename Allocator = std::allocator<T> >
class vector
{
	private:
		// number of elements in tab
		int	size;
		// size of tab (how much we need to malloc)
		int	capacity;
	public:
		vector();
		~vector();
};