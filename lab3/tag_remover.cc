#include <iostream>
#include <string>
#include <sstream>
#include "tag_remover.h"
using namespace std;

TagRemover::TagRemover(istream& is){
	string line;
	bool in_tag = false;
	while(is.good()){
		getline(is, line);
		/*if(c == '<'){
			isTag = true;
		}else if(c == '>'){
			isTag = false;
		}*/
		bool more_tags = true;
		while(more_tags){
			auto i1 = line.find("<");
			auto i2 = line.find(">");

			if(in_tag){
				if(i2 != string::npos){
					line.erase(0,i2+1);
					in_tag = false;
				}else{
					line.erase(0, line.size());
					more_tags = false;
				}
			}else if(i1 != string::npos && i2 != string::npos && i1 < i2){
				line.erase(i1, i2-i1+1);			
			}else if(i1 != string::npos && i2 == string::npos){
				line.erase(i1, line.size()-i1);
				in_tag = true;
			}else{
				more_tags = false;
			}
		}
	
		size_t pos1, pos2, pos3, pos4;
	
		do{
			pos1 = line.find("&lt;");
			pos2 = line.find("&gt;");
			pos3 = line.find("&nbsp;");
			pos4 = line.find("&amp;");

			if(pos1 != string::npos){
				line.replace(pos1, 4, "<");
			}else if(pos2 != string::npos){
				line.replace(pos2, 4, ">");
			}else if(pos3 != string::npos){
				line.replace(pos3, 6, " ");
			}else if(pos4 != string::npos){
				line.replace(pos4, 5, "&");
			}
		}while(pos1 != string::npos || 
			pos2 != string::npos || 
			pos3 != string::npos || 
			pos4 != string::npos); 

		str += line;
		str.push_back('\n');		
	}
}
void TagRemover::print(ostream& os){
	os << str << endl;
}
