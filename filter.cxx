/*
Author: b1e9n9e0
Date: 24.11.15

Task:
Write a filter for noise reduction.
1	Read from File 
		Ĉheck Filesize
		allocate sufficient memory
		read to array
2	apply the filter to the array without creating a new array, thus overwriting the old array
3	write the content of the array to a text file
4	Plot the result
*/


#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;



void write(double* input, const int N){

	ofstream filtered("filtered.txt");
	for(int i = 0; i < N; i++){
		filtered << input[i] << endl;
		//cout << (*input)[i] << endl;
	}
	filtered.close();


}


void read(double** input, const int N){
	ifstream noise("noisy.txt");
	*input = new double[N];
	for(int i = 0; i < N; i++){
		noise >> (*input)[i];
		//cout << (*input)[i] << endl;
	}
	noise.close();

}


void filter(double* input, const int N, int runs){
	double plus1,minus1,temp,temp0;
	plus1 = input[1];
	temp = input[0];
	minus1 = input[N-1];
	temp0 = input[0];
	for(int j = 0; j < runs; j++){
		for(int i = 1; i < N-1; i++){
			temp = input[i];
			input[i] = (minus1+temp+plus1)/3;
			minus1 = temp;
			plus1 = input[(i+2)%N];
		}
	}
	input[N-1] = (minus1 + input[N-1] + temp0)/3;

}


int main(void){
	const int N = 237;
	double* input;
	int runs;

	cout << "Please enter number of filter rounds"<< endl;
	cin >> runs;

	read(&input, N);
	//cout << input[N-1];
	filter(input,N,runs);
	write(input,N);



delete[] input;
//delete input;
return 0;
}