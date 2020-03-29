#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

double somatorio1( std::vector<double> A, int p )
{
    double resultado = 0;
    for(auto i = A.begin(); i != A.end(); i++)
    {
	resultado += std::pow((*i),p);	
    }

    return resultado;
}

//vetores de mesmo tamanho
double somatorio2 (std::vector<double> A, std::vector<double> B, int p)
{
    double resultado = 0;
    for(size_t i = 0; i != A.size(); i++)
    {
	resultado += A[i] * std::pow((B[i]),p);
    }

    return resultado;
}

int main()
{
   int n = 1;
   int m = 0;
   
   std::vector<double> x; 
   std::vector<double> y;  

   double i, j;

   while(std::cin >> i >> j)
   {
	x.push_back(i);
        y.push_back(j);
  	
	m++;
   }

   double mCoeficientes[n+1][n+2];

   for(int i = 0; i < n + 1; i++)
   {
	mCoeficientes[i][n+1] = somatorio2(y, x, i);
 	for(int j = 0; j < n + 1; j++)
	{
	    mCoeficientes[i][j] = somatorio1(x, j + i);
	}
   }

   for(int i = 0; i < n+1; i++)
   {
    for(int j = 0; j < n+2; j++)
	{
	  std::cout << mCoeficientes[i][j] << "        ";
	}
	std::cout << std::endl;
   }
   return 0;
}