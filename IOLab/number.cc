#include <iostream>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <cctype>
#include <map>
using namespace std;

class Number {
    public:
	Number() : value(0) {}
	Number(int v) : value(v) {}
	Number &operator=(int n) { value = n; return *this; }
	operator int() const { return value; }
    private:
    	int value;
};
bool is_digits(const std::string &str){
return str.find_first_not_of("0123456789") == std::string::npos;

}

std::map<std::string, int> m;
istream &operator>>(istream &is, Number &rhs) {
	string n2;
	is >>n2;
	if(is_digits(n2)){
	istringstream buf(n2);
	int value;
	buf >> value;
	rhs = value;
	}
	else if (m.count(n2)){
	rhs = m[n2];
}
	return is;
}


int main() {
	Number n = 666;
	istringstream ss("12 34 three 789 five");
	m["three"] = 3;
	m["five"] = 5;
	while (ss >> n)
		cout << n << ' ';
	cout << endl;
}
