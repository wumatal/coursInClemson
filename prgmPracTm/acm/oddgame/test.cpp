#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

int main() {
	int n;
	int i, j;
	int gnome;
	int a,b,c;
	int * sign;
	int * king_pos;
	std::string line;
	int lineno = 0;
	std::cin >> n;

	while ( getline( std::cin, line ) && std::cin.get() != std::cin.eof() ) {
		std::istringstream is( line );
		if (lineno==0){
			is >> n;
			lineno++;

			continue;
		}
		std::vector<int> groups((std::istream_iterator<int>(is)), std::istream_iterator<int>());
		std::cout << groups.size() << "\t" <<groups.front() << "\t" <<groups.back() << std::endl;

		/*if ( !groups.empty()) {

			sign = new int[groups.size()-1];

			for (j=0; j<groups.size()-1; j++) {
				sign[j] = (groups[j+1] - groups[j]) > 0? 1:0;
			}

			for (j=0; j<groups.size()-4; j++) {
				switch(sign[j] + sign[j+1] + sign[j+2]) {
					case 1 : 
					case 6 : king_pos[i] = j+2;break;
					case 3 : 
					case 4 : king_pos[i] = j;break;
					case 2 : 
					case 5 : king_pos[i] = j+1;break;
					default : continue;
				}
			}
		}*/
	}

	for(i=0; i<n; std::cout << king_pos[i++] << std::endl);
}
