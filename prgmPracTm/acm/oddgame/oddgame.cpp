#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

int main() {
	int n;
	int i, j;
	int * sign;
	int king_pos;
	std::string line;
	int lineno = 0;
	std::cin >> n;

	while ( getline( std::cin, line ) && std::cin.get() != std::cin.eof() ) {
		std::istringstream is( line );
		if (lineno==0){
			lineno++;
			continue;
		}
		std::vector<int> groups((std::istream_iterator<int>(is)), std::istream_iterator<int>());
		//std::cout << groups.size() << "\t" <<groups.front() << "\t" <<groups.back() << std::endl;

		sign = new int[groups.size()-1];

		for (j=0; j<groups.size()-1; j++) {
			sign[j] = (groups[j+1] - groups[j]) > 0? 1:0;
		}

		for (j=0; j<groups.size()-4; j++) {
			if (sign[j] == 0) {				
				if (sign[j+1] == 0)
					//000
					if (sign[j+2] == 0)	continue;
					//001
					else{king_pos = j+3;break;}
					//010
				else if (sign[j+2] == 0) {king_pos = j+2;break;}
					//011
					else{king_pos = j+1;break;}
			}
			else{
				if (sign[j+1] == 0)
					//100
					if (sign[j+2] == 0)	{king_pos = j+1;break;}
					//101
					else{king_pos = j+2;break;}
				    //110
				else if (sign[j+2] == 0) {king_pos = j+3;break;}
					//111
					else continue;
			}
		}
		std::cout << king_pos << std::endl;
	}

}
