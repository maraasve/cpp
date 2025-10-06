#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <Data.hpp>

class Serializer {
	public:
		Serializer() = delete;
		Serializer(const Serializer& src) = delete;
		Serializer& operator=(const Serializer& src) = delete;
		~Serializer() = delete;

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
