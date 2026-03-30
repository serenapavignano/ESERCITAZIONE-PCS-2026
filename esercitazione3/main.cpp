#include <iostream>
#include "razionali.hpp"

int main(void)
{
	razionali<int> z(0, 5);
    std::cout << "0/5 = " << z << "\n";
    razionali<int> a(1, 2);           // 
	std::cout << "1/2 = " << a << "\n";
    razionali<int> b(4, 8);     //       
	std::cout << "4/8 -> ridotta:" << b << "\n";       
    razionali<int> c(4, 1);            
	std::cout << "4/1 -> intero: " << c << "\n"; 
    razionali<int> neg(-1, 2);         
	std::cout << "-1/2 = " << neg << "\n";
	razionali<int> neg2(1, -2);        
	std::cout << "1/-2 = " << neg2 << "\n";
	//Denominatore =0
    razionali<int> inf_pos(1, 0);       //
	std::cout << "1/0 = " << inf_pos << "\n";
    razionali<int> inf_neg(-1, 0);     //
	std::cout << "-1/0 = " << inf_neg << "\n";
    razionali<int> NaN(0, 0);          //
	std::cout << "0/0 = " << NaN << "\n";

    //Somma
    razionali<int> d(1, 3), e(1, 2);
    std::cout << d << " + " << e << " = " << (d + e) << "\n";  
	//+=
	razionali<int> d1 = d; //d1 serve a non modificare definitivamente d
	std::cout << d << " += " << e << " = " << (d1 += e) << "\n";
    //Sottrazione
    std::cout << d << " - " << e << " = " << (d - e) << "\n";
	//-=
	d1 = d;
	std::cout << d << " -= " << e << " = " << (d1 -= e) << "\n";
    //Moltiplicazione
    razionali<int> f(2, 3), g(3, 4);
    std::cout << f << " * " << g << " = " << (f * g) << "\n";
	//*=
	razionali <int> f1 = f;
	std::cout << f << " *= " << g << " = " << (f1 *= g) << "\n";
    //Divisione
    std::cout << f << " / " << g << " = " << (f / g) << "\n"; 
	// /=
	f1 = f;
	std::cout << f << " /= " << g << " = " << (f1 /= g) << "\n";

    //Casi con Inf
    razionali<int> x(2, 3);
    std::cout << x  << " + Inf  = " << (x + inf_pos) << "\n"; 
    std::cout << x  << " * Inf  = " << (x * inf_pos) << "\n"; 
	std::cout << x << " - Inf  = " << (x - inf_pos) << "\n"; 
	std::cout << x << " / Inf  = " << (x / inf_pos) << "\n"; 
	
	razionali<int> x1 = x;
	std::cout << x  << " += Inf  = " << (x1 += inf_pos) << "\n"; 
	x1 = x;
	std::cout << x  << " *= Inf  = " << (x1 *= inf_pos) << "\n";
	x1 = x;
	std::cout << x << " -= Inf  = " << (x1 -= inf_pos) << "\n";
	x1 = x;
	std::cout << x << " /= Inf  = " << (x1 /= inf_pos) << "\n";
	
	std::cout << "Inf - " << x << " = " << inf_pos - x << "\n";
	std::cout << "Inf / " << x << " = " << inf_pos / x << "\n";
	std::cout << x  << " + (-Inf)  = " << (x + inf_neg) << "\n"; 
    std::cout << x  << " * (-Inf)  = " << (x * inf_neg) << "\n"; 
	std::cout << x << " - (-Inf)  = " << (x - inf_neg) << "\n"; 
	std::cout << x << " / (-Inf)  = " << (x / inf_neg) << "\n"; 
    std::cout << "Inf + Inf = " << (inf_pos + inf_pos) << "\n";
    std::cout << "Inf - Inf = " << (inf_pos - inf_pos) << "\n";
    std::cout << "Inf * Inf = " << (inf_pos * inf_pos) << "\n";
    std::cout << "Inf / Inf = " << (inf_pos / inf_pos) << "\n";  
	std::cout << "Inf + (-Inf) = " << (inf_pos + inf_neg) << "\n";
	std::cout << "Inf - (-Inf) = " << (inf_pos - inf_neg) << "\n";
    std::cout << "Inf * (-Inf) = " << (inf_pos * inf_neg) << "\n";
	std::cout << "Inf / (-Inf) = " << (inf_pos / inf_neg) << "\n";
	std::cout << "-Inf - Inf = " << (inf_neg - inf_pos) << "\n";
	std::cout << "-Inf / Inf = " << (inf_neg / inf_pos) << "\n";
	std::cout << "(-Inf) + (-Inf) = " << (inf_neg + inf_neg) << "\n"; 
	std::cout << "(-Inf) - (-Inf) = " << (inf_neg - inf_neg) << "\n";
	std::cout << "(-Inf) * (-Inf) = " << (inf_neg * inf_neg) << "\n";
	std::cout << "(-Inf) / (-Inf) = " << (inf_neg / inf_neg) << "\n";
	
	//Casi Inf e NaN
	std::cout << "Inf + NaN = " << (inf_pos + NaN) << "\n";
	std::cout << "Inf - NaN = " << (inf_pos - NaN) << "\n";
	std::cout << "Inf * NaN = " << (inf_pos * NaN) << "\n";
	std::cout << "Inf / NaN = " << (inf_pos / NaN) << "\n";
	std::cout << "NaN - Inf = " << (NaN - inf_pos) << "\n";
	std::cout << "NaN / Inf = " << (NaN / inf_pos) << "\n";
	std::cout << "-Inf + NaN = " << (inf_neg + NaN) << "\n";
	std::cout << "-Inf - NaN = " << (inf_neg - NaN) << "\n";
	std::cout << "-Inf * NaN = " << (inf_neg * NaN) << "\n";
	std::cout << "-Inf / NaN = " << (inf_neg / NaN) << "\n";
	std::cout << "NaN - (-Inf) = " << (NaN - inf_neg) << "\n";
	std::cout << "NaN / (-Inf) = " << (NaN / inf_neg) << "\n";
	
    //Casi con NaN
    std::cout << x << " + NaN = " << (x + NaN)   << "\n"; 
	std::cout << x << " - NaN = " << (x - NaN)   << "\n"; 
    std::cout << x << " * NaN = " << (x * NaN)   << "\n"; 
	std::cout << x << " / NaN = " << (x / NaN)   << "\n"; 
	
	x1 = x;
	std::cout << x << " += NaN = " << (x1 += NaN) <<"\n";
	x1 = x;
	std::cout << x << " -= NaN = " << (x1 -= NaN) <<"\n";
	x1 = x;
	std::cout << x << " *= NaN = " << (x1 *= NaN) <<"\n";
	x1 = x;
	std::cout << x << " /= NaN = " << (x1 /= NaN) <<"\n";
	
	std::cout << "NaN - " << x << "=" << (NaN - x) << "\n";
	std::cout << "NaN / " << x << "=" << (NaN / x) << "\n";
    std::cout << "Inf + NaN = " << (inf_pos + NaN) << "\n"; 
	std::cout << "NaN + NaN = " << (NaN + NaN) << "\n";
    std::cout << "NaN - NaN = " << (NaN - NaN) << "\n";
	std::cout << "NaN * NaN = " << (NaN * NaN) << "\n";
    std::cout << "NaN / NaN = " << (NaN / NaN) << "\n";
	//Casi con 0
    std::cout << "0 * Inf = " << (z * inf_pos) << "\n";
    std::cout << "0 / Inf = " << (z / inf_pos) << "\n";
    std::cout << "Inf / 0 = " << (inf_pos / z) << "\n";
	std::cout << "0 * (-Inf) = " << (z * inf_neg) << "\n";
    std::cout << "0 / (-Inf) = " << (z / inf_neg) << "\n";
    std::cout << "-Inf / 0 = " << (inf_neg / z) << "\n";
	std::cout << "0 * (NaN) = " << (z * NaN) << "\n";
    std::cout << "0 / (NaN) = " << (z / NaN) << "\n";
    std::cout << "NaN / 0 = " << (NaN / z) << "\n";
    std::cout << x << " / 0 = " << (x / z) << "\n";
    std::cout << "0 / 0 = " << (z / z) << "\n";
    
    return 0;
}