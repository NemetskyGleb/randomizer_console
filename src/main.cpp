#include <iostream>
#include "../lib/randomizer.h"
const int NUMBER_OF_STUDENTS = 5;
const int NUMBER_OF_TICKETS = 23;
const int TICKETS_PER_STUDENT = 4;

int main() {
	using namespace std;
	vstring students = {"Vasya", "Petya", "Zhenya", "Gleb", "Helen"};
	/**
	 * TO DO
	 * Продумать исключения
	 * когда число билетов на студента не хватает
	 * выводить оставшиеся билеты 
	 * 
	 * 
	 */
	
	Randomizer a(students, NUMBER_OF_STUDENTS, NUMBER_OF_TICKETS, TICKETS_PER_STUDENT);
	a.Print();
	
	return 0;
}
