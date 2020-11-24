#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>

const int NUMBER_OF_STUDENTS = 10;
const int NUMBER_OF_TICKETS = 20;
const int TICKETS_PER_STUDENT = 2;
typedef std::vector<std::string> vstring;
typedef std::unordered_set<int> uset;

void Create_Students(std::vector<std::string>& s, const int NUMBER_OF_STUDENTS);
void RandomizeTickets(uset& tk, const int NUMBER_OF_TICKETS);
std::map<vstring, std::vector<int> > MakeTuples(vstring& s, uset& tk, const int TICKETS_PER_STUDENT = 1);

int main() {
	using namespace std;
	vstring students = {"Vasya", "Petya", "Zhenya"};
	unordered_set<int> tickets;
	RandomizeTickets(tickets, NUMBER_OF_TICKETS);
	
	cout << *std::next(tickets.begin(), 0);

	std::multimap<vstring, std::vector<int> > mp;
	int j = 0;	
	for (int i = 0; i < students.size(); i++) {
		std::vector<int> tks_per_st;
		for (; j < TICKETS_PER_STUDENT; j++) {
			tks_per_st.push_back(*std::next(tickets.begin(), j));
			mp.insert(students[i], tks_per_st[j]);  
		}
	}

	// for (auto pos = mp.begin(); pos != mp.end(); ++pos)
    //     std::cout << pos->first << ' ' << pos->second << '\n';


	
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
 * @param TICKETS_PER_STUDENT 
 * @return std::tuple<vstring, uset> 
 */
// std::tuple<vstring, std::vector<int> > MakeTuple(vstring& s, uset& tk, const int TICKETS_PER_STUDENT) {
// 	if (TICKETS_PER_STUDENT == 0)
// 		exit(-1);
// 	return std::make_tuple(s, tk);
// }
