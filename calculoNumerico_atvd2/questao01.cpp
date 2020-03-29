/*
 * @file questao01.cpp
 * @brief Universidade Federal do Rio Grande Do Norte (UFRN)
 * @brief DIM0404 - Cálculo Numérico
 * @brief Tarefa: Encontrar raízes de equações
 * @date 27/02/2018
 * @author Jhonattan Cabral e Daniel Marx.
 */

#include <iostream>
#include <math.h>
#include <stdlib.h>



double funcao01(double x);
double (*func01) (double) = funcao01; //Ponteiro para a funcao01.
bool funcaoBissecao(double a, double b, double (*func)(double), double *p);  

int main()
{
    double p = 0;
    std::cout << ">>Consultando o grafico percebemos que a funcao possui 3 raizes" << std::endl;     
    //>>Primeira raíz
    bool r1 = funcaoBissecao(-1,2, func01, &p);
    if(r1)
        std::cout << "Para o intervalo de -1 ate 2, temos a raiz(aproximada): " <<
p << std::endl;
    else
        std::cout << "O método falhou" << std::endl;
 
    p = 0;   
    //>>Segunda raíz
    bool r2 = funcaoBissecao(-3, -1, func01, &p);
    if(r2)
        std::cout << "Para o intervalo de -3 até -1, temos a raiz(aproximada): " <<
p << std::endl;
    else
        std::cout << "O método falhou" << std::endl; 
    
    p = 0;   
    //>>Terceira raíz
    bool r3 = funcaoBissecao(-5, -3, func01, &p);
    if(r3)
        std::cout << "Para o intervalo de -5 ate -3, temos a raiz(aproximada): " <<
p << std::endl;
    else
        std::cout << "O método falhou" << std::endl;

	return 0;
}

/*
 *@brief Função da questão 01
 *@param x - Valor de entrada para a função
 *@return Resultado da função
 */
double funcao01(double x)
{
    return pow(x,3) + 4.6*pow(x,2) + 1.6*x - 7.2;
}

/*
 * @brief Método iterativo da bisseção
 * @param a - Inicio do intervalo
 * @param b -  Fim do intervalo
 * @param *p - ponteiro para a variavel que irá receber o valor da raíz
 * @param *func - Ponteiro pra funcao na qual se deseja
 * encontrar as raizes
 * @return true - Se o método conseguir encontrar a raíz(aproximada)
 * @return false - Caso o método falhe e não consiga encontrar a raíz
 */
bool funcaoBissecao(double a, double b, double (*func)(double), double *p)
{
    double fa, fp;

    for(int i = 0; i < 1000; i++)
    {
        fa = func(a);
        *p = (a + b)/2;
        fp = func(*p);
        
        
        if(fp == 0 or ((b - a)/2) < 0.000001)
        {
            return true;
        }
        else
        {   
            //Verifica se possui o mesmo sinal
            if(fa*fp > 0)
                a = *p;
            else
                b = *p;
        }
    }
    return false;
}

