#include <Serializer.hpp>

int main(void){
	Data *dataPtr = new Data(42, 84);
	std::cout << "Data address: " << dataPtr << std::endl;
	uintptr_t raw = Serializer::serialize(dataPtr);
	std::cout << "Serialized data (as uintptr_t): " << raw << std::endl;
	Data *deserializedPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address: " << deserializedPtr << std::endl;
	std::cout << "Data num1: " << deserializedPtr->getNum1() << ", num2: " << deserializedPtr->getNum2() << std::endl;
	delete dataPtr;
}