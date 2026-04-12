#pragma once
#include <vector> // per usare std::vector
#include <algorithm> // per usare std::swap

// Ordinamento
// Scorre il vettore dal 2° elemento in poi e lo confronta con il precedente
template<typename T>
int is_sorted(const std::vector<T>& vec)
{
	if (vec.size() == 0) {
		return 1;
		// Vettore nullo
	}
    for (int i = 1; i < (int)vec.size(); i++) { // Si parte da i=1 perchè dopo si fa i-1
        if (vec[i] < vec[i - 1])
            return 0;
		// Se trova un elemento più piccolo del precedente restituisce 0
    }
    return 1;
	// Vettore ordinato
}
 
 // Bubble sort
 template<typename T>
 void bubble_sort(std::vector<T>& A) {
	int n = (int)A.size();
    if (n <= 1) 
		return;
		// Un vettore di 0 o 1 elementi non viene ordinato
    for (int i = 0; i <= n - 2; ++i) {           
        for (int j = n - 1; j >= i + 1; --j) { 
		// // Scorre il vettore da destra (A.size - 1) a sinistra (i+1) (j-- decrementa l'indice man mano)
            if (A[j] < A[j - 1])
                std::swap(A[j], A[j - 1]);
			// Scambia ogni coppia di elementi adiacenti se sono nell'ordine sbagliato
        }
    }
}

// Insertion Sort
template<typename T>
void insertion_sort(std::vector<T>& A) {
	int n = (int)A.size();
    for (int j = 1; j <= n - 1; ++j) {   
        T key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
			// Sposta gli elementi più grandi di key un posto verso destra, finché non trova il posto giusto per key
            A[i + 1] = A[i];
            --i;
        }
        A[i + 1] = key;
    }
}

// Selection Sort 
template<typename T>
void selection_sort(std::vector<T>& A){
	int n = (int)A.size();
    if (n < 2) 
		return;
    for (int i = 0; i <= n - 2; ++i) {   
        int min_idx = i;
        for (int j = i + 1; j <= n - 1; ++j) {
            if (A[j] < A[min_idx])
                min_idx = j;
        }
        std::swap(A[i], A[min_idx]);
		// Si cerca il minimo nella parte non ancora ordinata e lo si porta in testa
    }
}