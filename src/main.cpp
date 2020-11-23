#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_set>

const int NUMBER_OF_STUDENTS = 10;
const int NUMBER_OF_TICKETS = 20;
const int DIVIDER = 2;
typedef std::vector<std::string> vstring;
typedef std::unordered_set<int> uset;

void Create_Students(std::vector<std::string>& s, const int NUMBER_OF_STUDENTS);
void RandomizeTickets(uset& tk, const int NUMBER_OF_TICKETS);
std::tuple<vstring, uset>* MakeTuples(vstring& s, uset& tk, const int DIVIDER = 1);

int main() {
	using namespace std;
	vector<string> students = {"Vasya", "Petya", "Zhenya"};
	unordered_set<int> tickets;
	RandomizeTickets(tickets, NUMBER_OF_TICKETS);
	for (auto&& x : tickets) {
		cout << x << ' ' ;
	}
	
	tuple<vstring, uset> tp[NUMBER_OF_STUDENTS] = MakeTuples(students, tickets);

	cout << get<0>(tp[i]) << ' '
	<< get<1>(tp[i]) << endl;

	return 0;
}


// void Create_Students(vstring& s, int NUMBER_OF_STUDENTS) {
// 	for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
		
// 	}
// }
void RandomizeTickets(uset& tk, int NUMBER_OF_TICKETS) {
	while (tk.size() <= NUMBER_OF_TICKETS)
		tk.insert(rand() % (NUMBER_OF_TICKETS + 1));
}

/**
 * @brief 
 *	This function returns tuple of two components STUDENT <----> TICKET 
 *	ticket could be more than one
 * @param s 
 * @param tk 
 * @param DIVIDER 
 * @return std::tuple<vstring, uset> 
 */
std::tuple<vstring, uset>* MakeTuple(vstring& s, uset& tk, const int DIVIDER) {
	if (DIVIDER == 0)
		exit(-1);
	return std::make_tuple(s, tk);
}
