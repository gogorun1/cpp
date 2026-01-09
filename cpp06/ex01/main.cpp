#include "Serializer.hpp"

int main() {
    Data myData;
    myData.id = 42;
    myData.name = "Paris";
    myData.value = 3.14;

    uintptr_t raw = Serializer::serialize(&myData);

    Data* result = Serializer::deserialize(raw);

    if (result == &myData) {
        PRINT("Address Match!");
        if (result->id == 42 && result->name == "Paris") {
            PRINT("Data Integrity Confirmed: " << result->name);
        }
    } else {
        std::cerr << "Pointer Mismatch!" << std::endl;
    }
    return 0;
}
