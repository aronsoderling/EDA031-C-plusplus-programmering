#include <string>
#include <iostream>

using namespace std;

int main() {
	string s;
	s.assign(100001, 'P');
	s.replace(0, 2, "CC");

	for(int i=2; i <= 100000; ++i){
		if(s[i] == 'P'){
			for(int j=i*2; j<=100000; j += i){
				s.replace(j, 1, "C");
			}
		}
	}
	
	cout << s.substr(0,201) << endl;
	
	int pos = s.rfind("P");	

	cout << "Largest prime smaller than 100 000 is " << pos << endl;
}
