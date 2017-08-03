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

    ifstream fin("segauto.txt");  
    double s;  
int sum=0;
    while( fin >> s ) 
    {    
	sum++;
        cout << "Read from file: " << s << endl;  
    }
	cout<<sum<<endl;
return 0;
}
