#pragma once
#include <vector>
#include <map>


namespace TianCore {
	template<class T>
	class Array : public std::vector<T> {
	};

	template<class K, class V>
	class HashMap : public std::map<K, V> {
	};
}