#include "Serializer.hpp"

int	main( void) {

	Data		data;
	Data		*deserializedData = NULL;
	uintptr_t	raw;

	std::cout << "---------Initializing Data---------\n";
	data.name = "John";
	data.age = 42;
	std::cout << data;

	std::cout << "\n---------Serializing Data---------\n";
	raw = Serializer::serialize(&data);
	std::cout << "Adress:" << raw << "\n";

	std::cout << "\n---------Deserialized Data---------\n";
	deserializedData = Serializer::deserialize(raw);
	std::cout << *deserializedData << "\n";

	return 0;
}