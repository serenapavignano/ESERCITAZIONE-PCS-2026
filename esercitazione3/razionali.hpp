#pragma once
#include <concepts>
#include <iostream>
#include <numeric>  //serve per usare std::gcd

template<typename I> requires std::integral<I>
class razionali
{
	I num_;
	I den_;

	void semplificazioni()
	{
		//Gestione caso denominatore =0
		if (den_ == 0) {
			if (num_ > 0) num_ = 1;  //restituisce +inf
			else if (num_ < 0) num_ = -1;   //restituisce +inf
			else num_ = 0;   //restituisce NaN (gestisce il caso 0/0)
			return;
		}
		
		if (num_ == 0) {
			den_ = 1;
			return;
			//Rappresenta in modo univoco 0/numero_qualsiasi come 0/1
		}
		
		if (den_ < 0) {
			num_ = -num_;
			den_ = -den_;
			//Serve a porre il meno solo a numeratore in modo che, ad esempio, -1/2 e 1/-2 non siano considerati numeri diversi
		}
		
		//Semplificazioni
		I mcd = std::gcd(num_, den_);
		if (mcd > 1) {   //esclude il caso numeratore e denominatore primi tra loro
			num_ = num_/mcd;
			den_ = den_/mcd;
		}
	}
public:
	//Costuttore di default
	razionali()
		: num_(I{0}), den_(I{1})
	{}
	
	//Costruttore user-defined
	razionali(const I& numeratore, const I& denominatore)
		: num_(numeratore), den_(denominatore) 
		{
			semplificazioni();
		}
	
	//Restituisce i valori di numeratore e denominatore
	I num() const {return num_;}
	I den() const {return den_;}
	
	//Implementazione canonica dell'incremento
	razionali& operator+=(const razionali& other) {
		if (den_ == 0 || other.den_ == 0) {
			//Gestisce NaN
			if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)){
				num_ = 0;
				den_ = 0;
				return *this;
			}
		}
		//Gestisce 2 Inf
		if (den_ == 0 && other.den_ == 0) {
			if (num_ == other.num_){  // Inf + Inf = Inf
				return *this;
			}
			else {  //Inf + (-Inf) = NaN
				num_ = 0;
				return *this;
			}
		}
		//Un solo Inf
		if (den_ == 0)
			return *this;
		if (other.den_ == 0) {
			num_ = other. num_;
			den_ = other.den_;
			return *this;
		}
		//Somma standard
		num_ = num_ * other.den_ + other.num_ * den_;
		den_ = den_ * other.den_;
		semplificazioni();
		return *this;
	}
	
	//Implementazione canonica della somma
	razionali operator+(const razionali& other) const {
		razionali ret = *this;
		ret += other;
		return ret;
	}
	
	//Implementazione canonica del decremento
	razionali& operator-=(const razionali& other) {
		//Gestisce NaN
		if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		//Gestisce 2 Inf
		if (den_ == 0 && other.den_ == 0) {
			if (num_ != other.num_) {  // Inf - (-Inf) = Inf
				return *this;
			} 
			else {   // Inf - Inf = NaN
				num_ = 0;
				return *this;
			}
		}
		//Un solo Inf
		if (den_ == 0) 
			return *this;
		if (other.den_ == 0) {
			num_ = -other.num_;        
			den_ = other.den_;
			return *this;
		}
		//Sottrazione standard
		num_ = num_ * other.den_ - other.num_ * den_;
		den_ = den_ * other.den_;
		semplificazioni();
		return *this;
	}
	
	//Implementazione canonica della sottrazione
	razionali operator-(const razionali& other) const {
		razionali ret = *this;
		ret -= other;
		return ret;
	}
	
	//Implementazione canonica di *= 
	razionali& operator*=(const razionali& other) {
		num_*= other.num_;
		den_*= other.den_;
		semplificazioni();
		return *this;
	}
	
	//Implementazione canonica della moltiplicazione
	razionali operator*(const razionali& other) const {
		razionali ret = *this;
		ret *= other;
		return ret;
	}
		
	//Implementazione canonica di /=
	razionali& operator/=(const razionali& other) {
		num_*= other.den_;
		den_*= other.num_;
		semplificazioni();
		return *this;
	}
	
	//Implementazione canonica della divisione
	razionali operator/(const razionali& other) const {
		razionali ret = *this;
		ret /= other;
		return ret;
	}
};

template<typename I>
std::ostream&
operator<<(std::ostream& os, const razionali<I>& r)
{
	if (r.den() == 0) {
		//Casi speciali
		if (r.num() > 0) os << "+Inf";
		else if (r.num() < 0) os << "-Inf";
		else os <<"NaN";
	}
	else if (r.den() == 1) {
		os << r.num();      //Se il denominatore è 1 stampa solo il numeratore
	}
	else {
		os << r.num() << "/" << r.den();   //Caso standard
	}
	return os;
}