/*
 * @file SistemaLinear.h
 * @brief Universidade Federal do Rio Grande Do Norte (UFRN)
 * @brief DIM0404 - Calculo Numerico
 * @brief Tarefa: Resolver sistemas lineares com a solução mais aproximada possível dos valores reais
 * @date  27/03/2018
 * @author Jhonattan Cabral e Daniel Marx.
 */
#ifndef _SISTEMALINEAR_H_
#define _SISTEMALINEAR_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class SistemaLinear
{

	using matriz = std::vector<std::vector<double>>;

	private:
	
		matriz sistema_m;
		std::vector<double> resultados_m;
		matriz A_m;
		std::vector<double> b_m;

	public:

		SistemaLinear(std::string nome_arquivo);

		~SistemaLinear() = default;
		
		std::vector<double> solucoesSistema();
		
		void imprimeMatrizSistema();

	private:
		
		std::vector<double> metodoGauss(matriz A);
		matriz gerarMatrizTriangular(matriz A);
		matriz lerMatriz(std::string nome_arquivo);
		matriz pivotacao(int col, matriz A);
		void refinamento();
}; 
#endif
