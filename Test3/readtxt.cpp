#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int main()
{

    ifstream fin("asdtext.txt");  
    double s;  
    while( fin >> s ) 
    {    
        cout << "Read from file: " << s << endl;  
    }
return 0;
}
