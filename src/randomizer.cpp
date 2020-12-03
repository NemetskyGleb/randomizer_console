#include "../lib/randomizer.h"
#include <ctime>

Randomizer::Randomizer(vstring& obj, uint num_obj, 
            uint num_numb, uint numb_per_obj)
            : number_of_objects(num_obj), number_of_numbers(num_numb),
            numbers_per_object(numb_per_obj) {
    vstring objects = obj;
    srand(time(0));

    // Randoming numbers and adding it in set
    uset numbers;   
    while (numbers.size() < number_of_numbers)
        numbers.insert(rand() % number_of_numbers + 1);

    tuple_array = new tuple[number_of_objects];
    vector_array = new std::vector<int>[number_of_objects];
    
    // Filling vectors and making tuples
    int j = 0;	
    for (uint i = 0; i < number_of_objects; i++) {	
        for (uint k = 0; k < numbers_per_object; k++, j++) {
            vector_array[i].push_back(*std::next(numbers.begin(), j));
        }
        tuple_array[i] = make_tuple(objects[i], vector_array[i]);  
    }
}

void Randomizer::Print() {
    for (uint i = 0; i < number_of_objects; i++) {
            std::cout << std::get<0>(tuple_array[i]) << " - ";
            for (auto&& x : std::get<1>(tuple_array[i])) {
                std::cout << x << ' ';
            }
            std::cout << std::endl;
        }
}


Randomizer::~Randomizer() {
    if (vector_array != nullptr) {
        delete[] vector_array;
    }
	if (tuple_array != nullptr) {
        delete[] tuple_array;
    }
}

