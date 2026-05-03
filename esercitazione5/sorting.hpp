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

//Merge 
template<typename T>
void merge(std::vector<T>& A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector <T> L(n1);
	std::vector <T> R(n2);
	for(int i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}
	for(int j = 0; j < n2; j++) {
		R[j] = A[q + j + 1];
	}
	int i = 0;
	int j = 0;
	int k = p;
	//L[n1] = +inf, R[n2] = +inf
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}
	//Si copiano gli eventuali elementi rimasti in L in A
	while(i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}
	//Si copiano gli eventuali elementi rimasti in R in A
	while(j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}
}

//Merge Sort
template<typename T>
void merge_sort(std::vector<T>& A, int p, int r) {
	if(p < r) {
		int q = (p + r)/2;
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
}

//Partition 
template<typename T>
int partition(std::vector<T>& A, int p, int r) {
	T x = A[r];
	int i = p - 1;
	for(int j = p; j < r; j++) {
		if(A[j] <= x) {
			i++;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i+1], A[r]);
	return i+1; //Restituisce l'indice del pivot
}

//Quicksort
template<typename T>
void quicksort(std::vector<T>& A, int p, int r) {
	if(p < r) {
		int q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

//Inserction Sort per versione nuova di quicksort
template<typename T>
void insertion_sort_nuovo(std::vector<T>& A, int p, int r) {
	if (p >= r) {
		return;
	}
    for (int j = p + 1; j <= r; ++j) {   
        T key = A[j];
        int i = j - 1;
        while (i >= p && A[i] > key) {
			// Sposta gli elementi più grandi di key un posto verso destra, finché non trova il posto giusto per key
            A[i + 1] = A[i];
            --i;
        }
        A[i + 1] = key;
    }
}

const int SOGLIA = 128; //size da cui quicksort vince su insertionsort

//Quicksort ottimale
template<typename T>
void quicksort_ottimale(std::vector<T>& A, int p, int r) {
	if (r - p + 1 <= SOGLIA) {
		insertion_sort_nuovo(A, p, r);
		return;
	}
	if (p < r) {
		int q = partition(A, p, r);
		quicksort_ottimale(A, p, q-1);
		quicksort_ottimale(A, q+1, r);
	}
}