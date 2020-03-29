/*
 * @file questao02.cpp
 * @brief Universidade Federal do Rio Grande Do Norte (UFRN)
 * @brief DIM0404 - Cálculo NuméRico
 * @brief Tarefa: Encontrar raízes de equações
 * @date 27/02/2018
 * @author Jhonattan Cabral e Daniel Marx.
 */

#include <iostream>
#include <math.h>
#include <cmath>
#include <stdlib.h>

double funcao02(double x);
double func02Derivada(double x);
double (*func02) (double) = funcao02; //Ponteiro para a funcao02.
double (*funcDerivate)(double) = func02Derivada; //Ponteiro para a derivada.
bool funcaoNewton(double p0, double (*func)(double), double (*funcDerivate)(double), double *p);  

int main()
{
	double p = 0;
    std::cout << ">>Consultando o grafico percebemos que a funcao possui 3 raizes" << std::endl;     
    
    //>>Primeira raíz
    bool r1 = funcaoNewton(-4, func02, funcDerivate, &p);
   	if(r1)
	    std::cout << "Para o ponto inicial -4, temos a raiz(aproximada): " << p << std::endl;
	else
	    std::cout << "O método falhou" << std::endl;
   
    p = 0;
    //>>Segunda raíz     
    bool r2 = funcaoNewton(2, func02, funcDerivate, &p);
    if(r2)
	    std::cout << "Para o ponto inicial 2, temos a raiz(aproximada): " << p << std::endl;
	else
	    std::cout << "O método falhou" << std::endl;
    
    p = 0;
    //>>Terceira raíz
    bool r3 = funcaoNewton(9, func02, funcDerivate, &p);
    if(r3)
	    std::cout << "Para o ponto inicial 9, temos a raiz(aproximada): " << p << std::endl;
	 else
	    std::cout << "O método falhou" << std::endl;
	
	return 0;
}

/*
 *@brief Função da questão 02
 *@param x - Valor de entrada para a função
 *@return Resultado da função
 */
double funcao02(double x)
{
    return pow(x,3) - 1.7 * pow(x,2) - 12.78 * x - 10.08;
}

/*
 *@brief Derivada da função da questão 02
 *@param x - Valor de entrada da função
 *@return Resultado da função
 */
double func02Derivada(double x)
{
	return 3*pow(x,2) - 3.4*x - 12.78;
}

/*
 * @brief Método iterativo de Newton
 * @param p0 - Ponto de início para a estimativa
 * @param *p - Ponteiro para uma variavel que irá receber a raiz(se houver)
 * @param *func - Ponteiro pra funcao na qual se deseja
 * encontrar as raizes.
 * @param *funcDerivate - Ponteiro pra derivada da funcao da questao 02
 * @return true - Caso o método seja eficiente e retorne a raiz(aproximada)
 * @return false - Caso o método falhe e não consiga encontrar a raiz.
 */
bool funcaoNewton(double p0, double (*func)(double), double(*funcDerivate)(double), double *p)
{
	for(int i = 0; i < 1000; i++)
	{	
		*p = p0 - func(*p)/funcDerivate(*p);
		if(std::abs(*p - p0) < 0.000001)
		{
			return true;
		}
		p0 = *p;
	}
	return false;
}

