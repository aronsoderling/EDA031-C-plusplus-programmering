#ifndef CODING_LIST
#define CODING_LIST

/*
 * List is a list of integers
 */
class Coding {
public:
	/* For any character c, encode(c) is a character different from c */
	static unsigned char encode(unsigned char c){
	  return c+1;
	}
	/* For any character c, decode(encode(c)) == c */
	static unsigned char decode(unsigned char c){
	  return c-1;
	}
private:
	
};

#endif
