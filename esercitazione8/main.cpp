#include "grafi.hpp"
#include <iostream>
#include <cstdlib>

int main() {
	unidirected_edge e1(4, 7);
	std::cout << "test from_to applicato a " << e1 << ":" << "\n";
	if (e1.from() == 4) {
		std::cout << "test from_to passato, from = 4" << "\n";
	}
	else {
		std::cout << "test from_to non passato, from != 4" << "\n";
	}
	if (e1.to() == 7) {
		std::cout << "test from_to passato, to = 7" << "\n";
	}
	else {
		std::cout << "test from_to non passato, to != 7" << "\n";
	}
	unidirected_edge e_1(6, 3);
	std::cout << "test from_to applicato a " << e_1 << ":" << "\n";
	if (e_1.from() == 3) {
		std::cout << "test from_to passato, from = 3" << "\n";
	}
	else {
		std::cout << "test from_to non passato, from != 3" << "\n";
	}
	if (e_1.to() == 6) {
		std::cout << "test from_to passato, to = 6" << "\n";
	}
	else {
		std::cout << "test from_to non passato, to != 6" << "\n";
	}
 
	unidirected_edge e2(3, 7);
	unidirected_edge e3(7, 3);
	unidirected_edge e4(4, 9);
	std::cout << "test operator< applicato a " << e2 << ", " << e3 << ", " << e4 << ":" << "\n";
	if (e2 < e4) {
		std::cout << "test operator< " << e2 << " < " << e4 << " passato" << "\n";
	}
	else {
		std::cout << "test operator< " << e2 << " < " << e4 << " non passato" << "\n";
	}
	
	
	std::cout << "test operator== applicato a " << e2 << ", " << e3 << ", " << e4 << ":" << "\n";
	if (e2 == e3) {
		std::cout << "test operator== " << e2 << " = " << e3 << " passato" << "\n";
	}
	else {
		std::cout << "test operator== " << e2 << " = " << e3 << " non passato" << "\n";
	}
	if (e2 == e4) {
		std::cout << "test operator== " << e2 << " != " << e4 << " non passato" << "\n";
	}
	else {
		std::cout << "test operator== " << e2 << " != " << e4 << " passato" << "\n";
	}
	
	
	unidirected_graph g0;
	unidirected_edge e5(0, 1);
	unidirected_edge e6(0, 2);
	unidirected_edge e7(3, 2);
	g0.add_edge(e5);
	g0.add_edge(e6);
	g0.add_edge(e7);
	std::cout << "test neighbours applicato a " << e5 << ", " << e6 << ", " << e7 << ":" << "\n";
	auto vicini0 = g0.neighbours(0);
	if (vicini0.size() == 2) {
		std::cout << "test neighbours passato, il nodo 0 ha correttamente " << vicini0.size() << " vicini" << "\n";
	}
	else {
		std::cout << "test neighbours non passato, il nodo 0 deve avere " << vicini0.size() << " vicini" << "\n";
	}
	if (vicini0.count(1) == 0 || vicini0.count(2) == 0) {
		std::cout << "test neighbours non passato, i vicini di 0 devono essere 1 e 2" << "\n";
	}
	else {
		std::cout << "test neighbours passato, i vicini di 0 sono correttamente 1 e 2" << "\n";
	}
	auto vicini1 = g0.neighbours(1);
	if (vicini1.size() == 1) {
		std::cout << "test neighbours passato, il nodo 1 ha correttamente " << vicini1.size() << " vicini" << "\n";
	}
	else {
		std::cout << "test neighbours non passato, il nodo 1 deve avere " << vicini1.size() << " vicini" << "\n";
	}
	if (vicini1.count(0) == 0) {
		std::cout << "test neighbours non passato, i vicini di 1 devono essere 0" << "\n";
	}
	else {
		std::cout << "test neighbours passato, i vicini di 1 sono correttamente 0" << "\n";
	}
	auto vicini2 = g0.neighbours(2);
	if (vicini2.size() == 2) {
		std::cout << "test neighbours passato, il nodo 2 ha correttamente " << vicini2.size() << " vicini" << "\n";
	}
	else {
		std::cout << "test neighbours non passato, il nodo 2 deve avere " << vicini2.size() << " vicini" << "\n";
	}
	if (vicini2.count(0) == 0 || vicini2.count(3) == 0) {
		std::cout << "test neighbours non passato, i vicini di 2 devono essere 0 e 3" << "\n";
	}
	else {
		std::cout << "test neighbours passato, i vicini di 2 sono correttamente 0 e 3" << "\n";
	}
	auto vicini3 = g0.neighbours(3);
	if (vicini3.size() == 1) {
		std::cout << "test neighbours passato, il nodo 3 ha correttamente " << vicini3.size() << " vicini" << "\n";
	}
	else {
		std::cout << "test neighbours non passato, il nodo 3 deve avere " << vicini3.size() << " vicini" << "\n";
	}
	if (vicini3.count(2) == 0) {
		std::cout << "test neighbours non passato, i vicini di 3 devono essere 2" << "\n";
	}
	else {
		std::cout << "test neighbours passato, i vicini di 3 sono correttamente 2" << "\n";
	}
	
	unidirected_graph g2;
	unidirected_edge e8(0, 1);
	unidirected_edge e9(1, 2);
	unidirected_edge e10(0, 2);
	g2.add_edge(e8);
	g2.add_edge(e9);
	g2.add_edge(e10);
	std::cout << "test all_nodes applicato a " << e8 << ", " << e9 << ", " << e10 << ":" << "\n";
	auto nodi = g2.all_nodes();
	if (nodi.size() == 3) {
		std::cout << "metodo all_nodes passato, il grafo ha correttamente " << nodi.size() << " nodi" << "\n";
	}
	else {
		std::cout << "metodo all_nodes non passato, il grafo deve avere " << nodi.size() << " nodi" << "\n";
	}
	if (nodi.count(0) == 0 || nodi.count(1) == 0 || nodi.count(2) == 0) {
		std::cout << "metodo all_nodes non passato, il grafo deve contenere i nodi 0, 1, 2" << "\n";
	}
	else {
		std::cout << "metodo all_nodes passato, il grafo contiene correttamente i nodi 0, 1, 2" << "\n";
	}
	std::cout << "test all_edges applicato a " << e8 << ", " << e9 << ", " << e10 << ":" << "\n";;
	auto archi = g2.all_edges();
	if (archi.size() == 3) {
		std::cout << "metodo all_edges passato, il grafo ha correttamente " << archi.size() << " archi" << "\n";
	}
	else {
		std::cout << "metodo all_edges non passato, il grafo deve avere " << archi.size() << " archi" << "\n";
	}
	
	unidirected_graph g1;
	g1.add_edge(unidirected_edge (2, 3));
	g1.add_edge(unidirected_edge (3, 2));
	std::cout << "test archi duplicati:" << "\n";
	if (g1.all_edges().size() == 1) {
		std::cout << "non ci sono archi duplicati" << "\n";
	}
	else {
		std::cout << "errore: è stato duplicato un arco" << "\n";
	}
	
	unidirected_graph g00;
	g00.add_edge(unidirected_edge(2, 3));
	g00.add_edge(unidirected_edge(4, 5));
	unidirected_graph g_copia(g00);
	std::cout << "test costruttore di copia:" << "\n";
	if (g_copia.all_edges().size() == g00.all_edges().size()) {
		std::cout << "test costruttore di copia passato, il numero di archi dei due grafi è lo stesso" << "\n";
	}
	else {
		std::cout << "test costruttore di copia non passato, il numero di archi dei due grafi è diverso" << "\n";
	}
	
	unidirected_graph g3;
	unidirected_edge e11(2, 3);
	unidirected_edge e12(4, 7);
	g3.add_edge(e11);
	g3.add_edge(e12);
	std::cout << "test edge_number applicato a " << e11 << " e a " << e12 << ":" << "\n";
	int posizione_arco1 = 0;
	g3.edge_number(unidirected_edge(2, 3), posizione_arco1);
	if (posizione_arco1 == 0) {
		std::cout << "test edge_number passato, la posizione dell'arco 1 è correttamente " << posizione_arco1 << "\n";
	} 
	else {
		std::cout << "test edge_number non passato, la posizione dell'arco 1 deve essere" << posizione_arco1 << "\n";
	}
	std::cout << "test edge_at applicato a " << e11 << ":" << "\n";
	unidirected_edge arco_trovato(0, 0);
	g3.edge_at(0, arco_trovato);
	if (arco_trovato == unidirected_edge(2,3)) {
		std::cout << "test edge_at passato, l'arco in posizione 0 è correttamente " <<  unidirected_edge(2,3) << "\n";
	}
	else {
		std::cout << "test edge_at non passato, l'arco in posizione 0 deve essere " <<  unidirected_edge(2,3) << "\n";
	}
	
	unidirected_graph g4;
	unidirected_graph g4_1;
	g4.add_edge(unidirected_edge(3, 5));
	g4.add_edge(unidirected_edge(2, 6));
	g4.add_edge(unidirected_edge(7, 9));
	g4_1.add_edge(unidirected_edge(2, 6));
	unidirected_graph g4_differenza = g4 - g4_1;
	std::cout << "test operator-: " << "\n";
	auto differenza_archi = g4_differenza.all_edges();
	if (differenza_archi.size() == 2) {
		std::cout << "test operator- passato, il numero di archi del grafo differenza è corretto" << "\n";
	}
	else {
		std::cout << "test operator- non passato, il numero di archi del grafo differenza non è corretto" << "\n";
	}
	bool arco_non_in_diff = false;
	for (auto& arco : differenza_archi) {
		if (arco == unidirected_edge(2, 6)) {
			arco_non_in_diff = true;
		}
	}
	if (arco_non_in_diff) {
		std::cout << "test operator- non passato, un arco è erroneamente presente nel grafo differenza" << "\n"; 
	}
	else {
		std::cout << "test operator- passato, il grafo differenza è riempito correttamente" << "\n"; 
	}
}
