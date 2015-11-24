/*
*minmaxrand
*Author: b1e9n9e0
*date: 18.11.2015
*task 1 of hw4 computational
*/


//task: Generate a static array of N random numbers. Fill in the numbers within an extra function of your code, similar to the last homework. Write a second function which finds the maximum and the minimum number stored in that array. Print the two values from inside the main() function.

#include <iostream>
#include <cstdlib>

using namespace std;

//function: fillarray
void fillarray(const int N , int* p){
	srand(time(NULL));
	for (int i = 0; i < N; i++){
		p[i]=rand();
	}
}
//function: find min max

void find(const int N , int* p, int* minmax){
	minmax[0] = p[0];
	minmax[1] = p[0];
	for(int i = 1; i < N; i++){
		if(p[i] < minmax[0]) minmax[0] = p[i];
		if(p[i] > minmax[1]) minmax[1] = p[i];
	}
}

//main: 

int main(){
	int minmax[2];
	const int N = 1000;
	int p[N];

	fillarray(N,p);
	find(N,p,minmax);

	cout << "min" << "\t" << minmax[0] << endl;
	cout << "max" << "\t" << minmax[1] << endl;
}
