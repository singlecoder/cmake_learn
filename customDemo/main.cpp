#include <iostream>

#include "config.h"

#ifdef USE_MYTEST
  	#include "test/test.h"
#else
  	// #include 
#endif

using namespace std;

int main ()
{
	#ifdef USE_MYTEST
	  	Test* t = new Test();
		t->print();
	#else
	  	cout << "multiDirs test from default" << endl;
	#endif
	
	return 0;
}