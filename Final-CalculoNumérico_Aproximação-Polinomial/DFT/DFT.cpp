#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <cerrno>
#include <cfenv>

double funcaoY(double);
double (*func1) (double) = funcaoY; //Ponteiro para a função

double funcaoX(int, int);
double(*func2) (int, int) = funcaoX;

double calcAk(int , int , double (*func1)(double), double (*func2)(int, int));
double calcBk(int , int , double (*func1)(double), double (*func2)(int, int));

int main()
{
	int n;
	int m;
	
	std::cout << "N: ";	
	std::cin >> n; 
	std::cout << std::endl;

	std::cout << "M: "; 
	std::cin >> m;
	std::cout << std::endl;
	
	double valoresA[n+1];	
	double valoresB[n-1];
	
	valoresA[0] = calcAk(0, m, func1, func2);
	valoresA[n] = calcAk(0, m, func1, func2);
	for(int i = 0; i < n-1; i++)
	{
		valoresB[i] = calcBk(i+1, m, func1, func2);
		valoresA[i+1] = calcAk(i+1, m, func1, func2);
	}
	
	for(int i = 0; i < n+1; i++)
	{
		std::cout << "a" << i << "= "<< valoresA[i] << std::endl;
	}
	
	for(int i = 0; i < n-1; i++)
	{
		std::cout << "b" << i + 1 << "= "<< valoresB[i] << std::endl;
	}
    
    //Para Plotar:
    
    std::cout << valoresA[0] << "/2 ";
    for(int i = 1; i < n+1; i++)
    {
        std::cout << valoresA[i] << " * cos(x*" << i << ") +"; 
    }
    
    for(int i = 0; i < n-1; i++)
    {
        std::cout << valoresB[i] << " * sin(x*" << i+1 << ") +";
    }
    	
	return 0;
}

double funcaoY(double x)
{
	return ((x * x) + (3 * x) - 4);
}

double funcaoX(int m, int j)
{
	return ((M_PI * -1) + ((j * M_PI)/m));
}

double calcAk(int k, int m, double (*func)(double), double (*func2)(int, int))
{
	double aux = 0;

	for(int i = 0; i <= 2*m-1; ++i)
	{
		aux += func(func2(m,i)) * std::cos(k*func2(m,i));
	}

	return aux * (1.0/m);
}

double calcBk(int k, int m, double (*func)(double), double (*func2)(int, int))
{	
	double aux = 0;
	
	for(int i = 0; i <= 2*m-1; ++i)
	{			
		aux += func(func2(m,i)) * std::sin(k * func2(m,i));		
	}
	return aux * (1.0/m);
}
