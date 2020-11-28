#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <ctime>
#include <tuple>


const int NUMBER_OF_STUDENTS = 4;
const int NUMBER_OF_TICKETS = 20;
const int TICKETS_PER_STUDENT = 5;
typedef std::vector<std::string> vstring;
typedef std::unordered_set<int> uset;

void Create_Students(std::vector<std::string>& s, const int NUMBER_OF_STUDENTS);
void RandomizeTickets(uset& tk, const int NUMBER_OF_TICKETS);

int main() {
	using namespace std;
	vstring students = {"Vasya", "Petya", "Zhenya", "Gleb"};
	unordered_set<int> tickets;
	srand(time(0));

	RandomizeTickets(tickets, NUMBER_OF_TICKETS);
		
	// for (auto it = tickets.begin(); it != tickets.end(); it++)
	// 	cout << *it << ' ';
	// std::cout << std::endl;

	tuple<string, vector<int> > *tuple_array = new tuple<string, vector<int> >[NUMBER_OF_STUDENTS]; // Allocate memory
	std::vector<int> *vector_array = new vector<int>[NUMBER_OF_STUDENTS];
	int j = 0;	
	for (int i = 0; i < students.size(); i++) {	
		for (int k = 0; k < TICKETS_PER_STUDENT; k++, j++) {
			vector_array[i].push_back(*std::next(tickets.begin(), j));
		}
		tuple_array[i] = make_tuple(students[i], vector_array[i]);  
	}

	

	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
		cout << get<0>(tuple_array[i]) << " - ";
		for (auto&& x : get<1>(tuple_array[i])) {
			cout << x << ' ';
		}
		std::cout << std::endl;
	}

	delete[] vector_array;
	delete[] tuple_array;
	return 0;
}


// void Create_Students(vstring& s, int NUMBER_OF_STUDENTS) {
// 	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
		
// 	}
// }
void RandomizeTickets(uset& tk, int NUMBER_OF_TICKETS) {
	while (tk.size() < NUMBER_OF_TICKETS)
		tk.insert(rand() % NUMBER_OF_TICKETS + 1);
}

/**
 * @brief 
 *	This function returns tuple of two components STUDENT <----> TICKET 
 *	ticket could be more than one
 * @param s 
 * @param tk 
 * @param TICKETS_PER_STUDENT 
 * @return std::tuple<vstring, uset> 
 */
// std::tuple<vstring, std::vector<int> > MakeTuple(vstring& s, uset& tk, const int TICKETS_PER_STUDENT) {
// 	if (TICKETS_PER_STUDENT == 0)
// 		exit(-1);
// 	return std::make_tuple(s, tk);
// }
