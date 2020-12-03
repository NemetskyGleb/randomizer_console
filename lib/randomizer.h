#ifndef RANDOMIZER_H
#define RANDOMIZER_H
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <tuple>

typedef std::vector<std::string> vstring;
typedef std::unordered_set<int> uset;
typedef std::tuple<std::string, std::vector<int> > tuple; 


/**
 * @brief 
 * Класс для рандома случайных чисел диапозона от 1 до number_of_numbers
 * Распределение происходит по объектам, кол-во чисел на объект задаётся 
 * переменной numbers_per_object 
 */
class Randomizer {
private:
    uint number_of_objects;
    uint number_of_numbers;
    uint numbers_per_object;
    tuple *tuple_array = nullptr;
    std::vector<int> *vector_array = nullptr;
public:
    Randomizer() : number_of_objects(0), number_of_numbers(0), numbers_per_object(0) {}
    Randomizer(vstring& obj, uint num_obj = 0, uint num_numb = 0, uint numb_per_obj = 1);
    // Randomizer(const Randomizer& r);
    // Randomizer& operator=(const Randomizer& r);
    void Print();
    ~Randomizer();
};


#endif