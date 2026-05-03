#include <iostream>
#include <vector>
#include <algorithm>

#include "sorting.hpp"
#include "randfiller.h"
#include "timecounter.h"
 
int main()
{
    randfiller rf; 
	timecounter tc;
    const int N_vettori = 100;
    for (int size = 4; size <= 8192; size *= 2) {
		std::vector<std::vector<int>> vettori(N_vettori, std::vector<int>(size));
        for (int i = 0; i < N_vettori; i++) {
			rf.fill(vettori[i], -1000, 1000);
		}
		
		std::vector<std::vector<int>> vec_bubble    = vettori;
		std::vector<std::vector<int>> vec_insertion = vettori;
		std::vector<std::vector<int>> vec_selection = vettori;
		std::vector<std::vector<int>> vec_merge     = vettori;
		std::vector<std::vector<int>> vec_quick     = vettori;
		std::vector<std::vector<int>> vec_quick_ott = vettori;
		std::vector<std::vector<int>> vec_std       = vettori;
		
		//Misura Bubble sort
        tc.tic();
		for (int i = 0; i < N_vettori; i++) {
			bubble_sort(vec_bubble[i]);
		}
        double tempo_bubble = tc.toc()/N_vettori;
		std::cout << "Tempo impiegato da Bubble sort: " << tempo_bubble << "\n";
		
		//Misura Insertion sort
        tc.tic();
		for (int i = 0; i < N_vettori; i++) {
			insertion_sort(vec_insertion[i]);
		}
        double tempo_insertion = tc.toc()/N_vettori;
		std::cout << "Tempo impiegato da Insertion sort: " << tempo_insertion << "\n";

        //Misura Selection sort
        tc.tic();
		for (int i = 0; i < N_vettori; i++) {
			selection_sort(vec_selection[i]);
		}
        double tempo_selection = tc.toc()/N_vettori;
		std::cout << "Tempo impiegato da Selection sort: " << tempo_selection << "\n";
		
		//Misura Merge sort
        tc.tic();
		for (int i = 0; i < N_vettori; i++) {
			merge_sort(vec_merge[i], 0, (int)vec_merge[i].size() - 1);
		}
        double tempo_merge = tc.toc()/N_vettori;
		std::cout << "Tempo impiegato da Merge sort: " << tempo_merge << "\n";
		
		//Misura Quicksort
        tc.tic();
		for (int i = 0; i < N_vettori; i++) {
			quicksort(vec_quick[i], 0, (int)vec_quick[i].size() - 1);
		}
        double tempo_quick = tc.toc()/N_vettori;
		std::cout << "Tempo impiegato da Quicksort: " << tempo_quick << "\n";
		
		//Misura Quicksort
        tc.tic();
		for (int i = 0; i < N_vettori; i++) {
			quicksort_ottimale(vec_quick_ott[i], 0, (int)vec_quick_ott[i].size() - 1);
		}
        double tempo_quick_ott = tc.toc()/N_vettori;
		std::cout << "Tempo impiegato da Quicksort ottimale: " << tempo_quick_ott << "\n";

        //Misura il tempo con std::sort()
        tc.tic();
		for (int i = 0; i < N_vettori; i++) {
			std::sort(vec_std[i].begin(), vec_std[i].end());
		}
        double tempo_sort = tc.toc()/N_vettori;
		std::cout << "Tempo impiegato da std::sort(): " << tempo_sort << "\n";

    }

    return EXIT_SUCCESS;
}


