#include <iostream>
#include <cstdlib> //Serve per EXIT_SUCCESS e EXIT_FAILURE
#include <vector> // Serve per std::vector
#include <string> // Serve per std::string
#include <random>
 
#include "sorting.hpp"
#include "randfiller.h"
 
int main(void)
{
	std::random_device rd; // Genera una variabile rd random;
    std::mt19937 gen(rd()); // Costruisce il generatore con seme rd
    std::uniform_int_distribution<int> dist(0, 1000); // Crea una distribuzione uniforme di numeri interi tra 0 e 1000
 
    randfiller rf;
    // Ripete il test 100 volte
    for (int t = 0; t < 100; ++t) {
        int size = dist(gen); // Estrae una dimensione casuale tra 0 e 1000
        std::vector<int> vec(size);
        rf.fill(vec, -1000, 1000); // Riempie il vettore con valori casuali tra -1000 e 1000
		
		quicksort(vec, 0, (int)vec.size() - 1);
		
		if (!is_sorted(vec)) {
            std::cerr << "Errore: il vettore non è ordinato \n";
            return EXIT_FAILURE;
        }
    }
 
    // Test su vettore di std::string
    std::vector<std::string> stringa = {
        "sedia", "tavolo", "soffitto", "lampada", "pavimento",
        "quadro", "cielo", "finestra", "orologio", "muro"
    };
    quicksort(stringa, 0, (int)stringa.size() - 1);
    if (!is_sorted(stringa)) {
        std::cerr << "Errore: la stringa non è ordinata \n";
        return EXIT_FAILURE;
    }
 
    std::cout << "Il metodo bubble sort ha correttamente ordinato il vettore \n";
    return EXIT_SUCCESS;
}