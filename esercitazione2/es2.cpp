#include <iostream>
#include <cmath>  //include sqrt 
#include <algorithm>   //include min e max

int main()
{
	static const int N = 6;
	double arr[N] = {12.4, 5.3, 6.1, 9.8, 2.5, 4.9};
	
	double min = arr[0];
	double max = arr[0];
	double sum = 0.0;
	double sum_squares = 0.0;
	
	for (int i = 0; i < N; i++) {
		min = std::min(min, arr[i]);
		max = std::max(max, arr[i]);
		sum = sum + arr[i];
	}
	
	double media = sum / N;
	
	for (int i = 0; i < N; i++) {
		double diff = arr[i] - media;
		sum_squares = sum_squares + (diff * diff);
	}
	double varianza = sum_squares / N;
	double deviazione_standard = std::sqrt(varianza);
	
	//Stampa
	std::cout << "Minimo: " << min << "\n";
	std::cout << "Massimo: " << max << "\n";
	std::cout << "Media: " << media << "\n";
	std::cout << "Deviazione standard " << deviazione_standard << "\n";
	
	return 0;
}