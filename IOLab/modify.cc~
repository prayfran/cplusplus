#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	
	fstream in(argv[1], ios_base::in | ios_base::out);
	if (!in) {
		cerr << argv[0] << ": can't open " << argv[1] << endl;
		return 1;
	}
	
	string s;
	int p = 0;
	while (getline(in, s)) {
		size_t n;
		while ( (n=s.find("Bush")) != string::npos )
			s.replace(n, 4, "Gore");
		in.seekp(p, std::ios_base::beg);
		in.write((s+'\n').c_str(), s.length()+1);
	p += s.length() + 1;
	}

	return 0;
}
