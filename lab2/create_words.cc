#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream is;
	ofstream os;
	is.open("/usr/share/dict/words");
	os.open("./words.txt");

	do{
		string line;
		getline(is, line);
		
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		
		os << line;
		if(line.size() >= 3){
			vector<string> trigrams;
			os << " " << line.size() - 2;
			for(size_t i=0; i<=line.size()-3; i++){
				trigrams.push_back(line.substr(i,3));
			}
			
			sort(trigrams.begin(), trigrams.end());

			for(size_t i=0; i<trigrams.size(); i++){
				os << " " << trigrams[i];
			}
		}else{
			os << " 0";
		}
		os << endl;
		//cout << line << endl;
	}while(is.good());

	is.close();
	os.close();
	return 0;	
}
