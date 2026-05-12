#pragma once
#include <list>
#include <set>
#include <map>
#include <vector>
#include <ostream>
#include <algorithm>


//unidirected_edge
//from_int e to_int sono gli interi dei nodi, from e to i metodi
class unidirected_edge {
public: 
	unidirected_edge(int e1, int e2) {
	from_int = std::min(e1, e2);
	to_int = std::max(e1, e2);
	}
	int from() const {
		return from_int; 
	}
	int to() const {
		return to_int;
	}
	
	//metodi per rendere gli archi ordinabili
	//operator<
	bool operator<(const unidirected_edge& other) const {
		if (from_int != other.from_int) {
			return from_int < other.from_int;
		}
		return to_int < other.to_int;
	}
	
	//operator==
	bool operator==(const unidirected_edge& other) const {
			return from_int == other.from_int && to_int == other.to_int;
	}
	
private: 
	int from_int;
	int to_int;
};

//operator<< 
std::ostream& operator<<(std::ostream& os, const unidirected_edge& e) {
	os << "(" << e.from() << ", " << e.to() << ")";
	return os;
}


class unidirected_graph {
public:
	//costruttore di default
	unidirected_graph() = default;
	//costruttore di copia
	unidirected_graph(const unidirected_graph&) = default;
	//metodo neighours()
	std::set<int> neighbours(int nodo) const {
		auto iteratore = adiacenza.find(nodo);
		if ( iteratore == adiacenza.end())
			return {};
		return (*iteratore).second;
	}
	//metodo add_edge()
	void add_edge(const unidirected_edge& e) {
		if (edge_index.find(e) != edge_index.end()) 
			return; //non fa niente se l'arco esiste già
		size_t ind = ordina_per_indice.size(); //size_t per avere lo stesso tipo
		ordina_per_indice.push_back(e); //aggiunge l'arco al vettore
		edge_index[e] = ind;
		adiacenza[e.from()].insert(e.to());
		adiacenza[e.to()].insert(e.from());
	}
	//metodo all_edges()
	std::list<unidirected_edge> all_edges() const {
		return std::list<unidirected_edge>(ordina_per_indice.begin(), ordina_per_indice.end());
	}
	//metodo all_nodes()
	//set ignora i duplicati
	std::set<int> all_nodes() const {
		std::set<int> nodi;
		for (const auto& coppia : adiacenza) //coppia nodo e insieme dei vicini
			nodi.insert(coppia.first);
		return nodi;
	}
	//metodo edge_number()
	bool edge_number(const unidirected_edge& e, int& posizione_arco) const {
    int index = 0;
	for (const auto& arco : ordina_per_indice) {
		if(arco == e) {
			posizione_arco = index;
			return true;
		}
		index++;
	}
	return false; //se non trova l'arco, quindi se non esiste
}
	//metodo edge_at()
	bool edge_at(int ind, unidirected_edge& arco_trovato) const {
    int index = 0;
    for (const auto& arco : ordina_per_indice) {
        if (index == ind) {
            arco_trovato = arco;
            return true;
        }
        index++; 
    }
    return false; //non trova nessun arco associato a nessun indice iterato
}
	//operator-()
	unidirected_graph operator-(const unidirected_graph& grafo2) const {
		unidirected_graph grafo_differenza;
		for (const auto& arco : ordina_per_indice) {
			if (grafo2.edge_index.find(arco) == grafo2.edge_index.end()) {
				grafo_differenza.add_edge(arco);
			}
		}
		return grafo_differenza;
	}
	
private:
    // Archi in ordine di inserimento (per edge_at / edge_number)
    std::vector<unidirected_edge> ordina_per_indice;
    // Mappa arco -> indice
    std::map<unidirected_edge, int> edge_index;
    // Lista di adiacenza: nodo -> insieme di vicini
    std::map<int, std::set<int>> adiacenza;
};
	