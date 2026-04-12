#include <iostream>
#include <vector>
#include <algorithm>

#include "sort.hpp"
#include "randfiller.h"
#include "timecounter.h"
 
int main()
{
    randfiller rf; 
	timecounter tc;
    std::vector<int> vec; //Creazione vettore da riempire
    for (int size = 4; size <= 8192; size *= 2) {
        vec.resize(size); // Ora il vettore ha dimensione = size
		rf.fill(vec, -1000, 1000);
		
		std::vector<int> vec_bubble = vec;
		std::vector<int> vec_insertion = vec;
		std::vector<int> vec_selection = vec;
		std::vector<int> vec_std = vec;
		
		//Misura Bubble sort
        tc.tic();
        bubble_sort(vec_bubble);
        double tempo_bubble = tc.toc();
		std::cout << "Tempo impiegato da Bubble sort: " << tempo_bubble << "\n";
		
		//Misura Insertion sort
        tc.tic();
        insertion_sort(vec_insertion);
        double tempo_insertion = tc.toc();
		std::cout << "Tempo impiegato da Insertion sort: " << tempo_insertion << "\n";

        //Misura Selection sort
        tc.tic();
        selection_sort(vec_selection);
        double tempo_selection = tc.toc();
		std::cout << "Tempo impiegato da Selection sort: " << tempo_selection << "\n";

        //Misura il tempo con std::sort()
        tc.tic();
        std::sort(vec_std.begin(), vec_std.end());
        double tempo_sort = tc.toc();
		std::cout << "Tempo impiegato da std::sort(): " << tempo_sort << "\n";

    }

    return EXIT_SUCCESS;
}