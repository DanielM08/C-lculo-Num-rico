/*
* @file questao03.cpp
* @brief Universidade Federal do Rio Grande Do Norte (UFRN)
* @brief DIM0404 - C�lculo Num�Rico
* @brief Tarefa: Encontrar ra�zes de equa��es
* @date 27/02/2018
* @author Jhonattan Cabral e Daniel Marx.
*/

#include <iostream>
#include <math.h>
#include <cmath>
#include <stdlib.h>

double funcao04(double L);
double(*func04) (double) = funcao04; //Ponteiro para a funcao03.
double funcaoBissecao(double t1, double t2, double(*func)(double));

int main(void)
{
	std::cout << "C�lculo da largura do beco, por meio do m�todo da bisse��o" << std::endl;

	double r1 = funcaoBissecao(0, 1000, func04);
	std::cout << "Largura aproximada do beco �: " << r1 << std::endl;
	return 0;
}

/*
*@brief Fun��o da quest�o 04; Desrita por: 1/A = 1/(x1^2 - L^2) + 1/(x2^2 - L^2)
*@param L -> Valor que se espera ser igual � largura do beco
*@return Resultado da fun��o
*/
double funcao04(double L)
{
	double x1 = 20;
	double x2 = 30;
	double A = 8;

	return 1 - (A/(sqrt(pow(x1, 2) - pow(L, 2))) + A/(sqrt(pow(x2, 2) - pow(L, 2))));
}

/*
* @brief M�todo iterativo da bisse��o; Retorna a largura de um beco no problema da quest�o 04
* @param l1 - Inicio do intervalo
* @param l2 -  Fim do intervalo
* @param *func - Ponteiro pra funcao na qual se deseja
* encontrar as raizes
* @return p - Valor aproximado do tempo decorrido at� o objeto chegar ao solo
*/
double funcaoBissecao(double l1, double l2, double(*func)(double))
{
	double fa, fp, L;

	for (int i = 0; i < 10000; i++)
	{
		fa = func(l1);
		L = (l1 + l2) / 2; //Valor da largura do beco
		fp = func(L);

		if (fp == 0 or ((l2 - l1) / 2) < 0.000001) //Diferentemente das outras quest�es, o valor da fun��o dever� ser igual a 1 para encontrar o tamanho do beco
		{
			return L;
		}
		else
		{
			//Verifica se possui o mesmo sinal
			if (fa*fp > 0)
				l1 = L;
			else
				l2 = L;
		}
	}
	return -1; //Algum erro ocorreu
}
