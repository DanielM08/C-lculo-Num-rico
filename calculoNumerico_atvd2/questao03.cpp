/*
 * @file questao03.cpp
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

double funcao03(double t);
double (*func03) (double) = funcao03; //Ponteiro para a funcao03.
double funcaoBissecao(double t1, double t2, double (*func)(double));

int main(void)
{
    std::cout << "Tempo decorrido até certo objeto alcançar o solo, seguindo a fórmula da questão" << std::endl;
    
    //>>Primeira raíz
    double r1 = funcaoBissecao(0, 1000, func03);
    std::cout << "Tempo aproximado para chegada ao solo, foi de: " << r1 << std::endl;
	return 0;
}

/*
 *@brief Função da questão 03
 *@param x - Valor de entrada para o tempo de queda
 *@return Resultado da função
 */
double funcao03(double t)
{
	double g = 32.17;
	double s0 = 300;
	double m = 0.25;
	double k = 0.1;
	
	return s0 - ((m*g)/k)*t + ((pow(m,2)*g)/pow(k,2))*(1 - pow(M_E,((-1*k)*t)/m)); //M_E - constante do C++ para número de Euler
}

/*
 * @brief Método iterativo da bisseção
 * @param t1 - Inicio do intervalo
 * @param t2 -  Fim do intervalo
 * @param *func - Ponteiro pra funcao na qual se deseja
 * encontrar as raizes
 * @return p - Valor aproximado do tempo decorrido até o objeto chegar ao solo
 */
double funcaoBissecao(double t1, double t2, double (*func)(double))
{
    double fa, fp, p;

    for(int i = 0; i < 10000; i++)
    {
        fa = func(t1);
        p = (t1 + t2)/2;
        fp = func(p);
                
        if(fp == 0 or ((t2 - t1)/2) < 0.00001)
        {
            return p;
        }
        else
        {   
            //Verifica se possui o mesmo sinal
            if(fa*fp > 0)
                t1 = p;
            else
                t2 = p;
        }
    }
    return p;
}

