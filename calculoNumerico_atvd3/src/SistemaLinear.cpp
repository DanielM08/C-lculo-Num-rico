/*
 * @file SistemaLinear.cpp
 * @brief Universidade Federal do Rio Grande Do Norte (UFRN)
 * @brief DIM0404 - Calculo Numerico
 * @brief Tarefa: Resolver sistemas lineares com a solução mais aproximada possível dos valores reais
 * @date 27/03/2018
 * @author Jhonattan Cabral e Daniel Marx.
 */

#include "../include/SistemaLinear.h"

using matriz = std::vector<std::vector<double>>;

/*
 * Construtor
 */
SistemaLinear::SistemaLinear(std::string nome_arquivo)
{
	sistema_m = lerMatriz(nome_arquivo);
	
	//instancia A_m, b_m e resultados_m
	matriz A_m(sistema_m.size(), std::vector<double>(sistema_m.size()));
	std::vector<double> b_m(sistema_m.size());
	std::vector<double> resultados_m(0);
	
	//Inicializar A_m e b_m
	for(int i = 0; i < sistema_m.size(); i++)
	{
		for(int j = 0; j < sistema_m.size(); j++)
		{
			A_m[i][j] = sistema_m[i][j];
		}
		//b recebe a ultima coluna da matriz lida
		b_m[i] = sistema_m[i][sistema_m.size()];
	} 
}

/*
 *@brief Método responsavel por ler a matriz de um determinado arquivo
 *@param nome_arquivo - nome do arquivo no qual sera lido
 *@return A - matriz lida do arquivo
 */
matriz SistemaLinear::lerMatriz(std::string nome_arquivo)
{
	std::ifstream file(nome_arquivo); 
    unsigned size;
 
    file >> size; //Lê a primeira linha e pega o tamanho da matriz
 
	if(!file){ std::cout << "Erro"; }
 
    matriz A;
    double value;
    for(auto i = 0u; i < size; i++)
    {
	    std::vector<double> temp;
        for(auto j = 0u; j < size+1; j++)
        {
	        file >> value;
            temp.push_back(value);
        }
        A.push_back(temp);
	}
	return A;				   
}

/*
 *@brief Método responsavel por triangular a matriz atraves da eliminacao de Gauss
 *@param A matriz que será 'triangularizada'
 *@return A - matriz triangularizada
 */
matriz SistemaLinear::gerarMatrizTriangular(matriz A)
{
	for(size_t k = 0u; k <= A.size(); k++) //Número de pivôs 
    {
		A = pivotacao(k, A); //Faz a pivotação parcial da coluna k
 		
		for(size_t i = 1 + k; i < A.size(); i++) //Número de linhas a baixo da primeira
        {
			//imprimeMatriz(A);
   	     	double fatorM = A[i][k]/A[k][k];
			for(size_t j = 0 + k ; j < A.size() + 1; j++) //Número de colunas
	        {   
	  	    	A[i][j] = A[i][j] - A[k][j]*(fatorM);
	        }
	     }
	}

	return A;
}

/*
 *@brief Faz a pivotação parcial de uma coluna passada de certa matriz, 
 	para ser candidato a pivô, o número deve estar na diagonal principal ou nas linhas abaixo deste. Pode-se haver troca de linhas.
 *@param col coluna em que ocorrerá a pivotação
 *@param A matriz onde será realizada a pivotação
 *@return A - matriz com melhor valor de pivô para a coluna
 */
matriz SistemaLinear::pivotacao(int col, matriz A)
{
	int maior = col; //Linha em que está o maior valor daquela coluna
	
	for(size_t i = col+1; i < A.size(); i++)
	{
		if(abs(A[i][col]) > abs(A[maior][col]))
			maior = i;
	}

	//Se o pivô já não está na diagonal, trocam se as linhas
	if(maior != col)
	{	
		std::vector<float> aux(A.size()+1);
		for(size_t i = 0; i < A.size() + 1; i++)
			aux[i] = A[col][i];

		for(size_t i = 0; i < A.size() + 1; i++)
			A[col][i] = A[maior][i];

		for(size_t i = 0; i < A.size() + 1; i++)
			A[maior][i] = aux[i];	
	}

	return A;
}

/*
 *@brief Método público que será chamado pelo usuário da classe. Faz multiplos refinamentos no resultado.
 *@return retorna vetor de resultados da classe.
*/
std::vector<double> SistemaLinear::solucoesSistema()
{	
	int i = 0;
	while(i < 1)
	{
		refinamento();
		i++;
	}
	return resultados_m;
}

/*
 *@brief Método responsavel por resolver o sistema linear a partir de uma matriz triangular 
 */
std::vector<double> SistemaLinear::metodoGauss(matriz X)
{ 
	matriz A = gerarMatrizTriangular(X); 
  	std::vector<double> resultados;
   
   	for(int i = A.size() - 1; i >= 0; i = i - 1) // Calcula-se de baixo para cima.
    {
		//Valor da diagonal principal, que multiplica a incógnita.
		double X = A[i][i]; 
	            
		//Armazenará o valor da incógnita que está sendo buscada 
		double Y = 0;
 
        //Cálculo do Y considera os valores posteriores ao da diagonal principal
        for(size_t j = i+1, k = 0; j < A.size() + 1; j++, k++)
        {
	        //Enquanto j não chegar na posição da ultima coluna
	        if(j < A.size())
		        Y = Y + resultados[k] * A[i][j]; //Soma valores depois dos pivores, e os multiplica pelas incógnitas já achadas
		    else
			    Y = (A[i][j] - Y)/X; //Calcula o valor da incógnita da linha i + 1 da matriz
		}
		 
		//Insere o valor procurado no início do vetor de resultados.
		resultados.insert(resultados.begin(),Y);
	}
	
	return resultados;
}

/*
 *@brief Método faz o refinamento do sistema linear se chamado mais de uma vez, 
 o refinamento visa aproximar mais a solução gerada pelo método de Gauss da solução real. 
 O vetor de resultados da classe é modificado.
*/
void SistemaLinear::refinamento()
{
	if(resultados_m.size() != 0)
	{
		/*
		std::vector<double> residuo(resultados_m.size());				
		//std::cout << sistema_m.size() << "xxxx";
		//Preenche residuo -> r = b - Ax', onde x' é o vetor solução encontrado.
		for(int i = 0; i < A_m.size(); i++)
		{
			std::cout << "FOOOOOOOOOOOOOOOOOOOON";
			int soma = 0;
			for(int j = 0; j < A_m.size(); j++)
			{
				soma += A_m[i][j] * resultados_m[j];
				std::cout << "x" << soma;
			}	
			residuo[i] = b_m[i] - soma;
		}

		for(size_t i = 0; i < residuo.size(); i++)
		{
			std::cout << "*"<< residuo[i];
		}

		//Resolver Ay = r e somar y ao vetor de resultados já existente
		matriz A(A_m.size(), std::vector<double>(A_m.size()+1)); //A é uma matriz completa
		
		//Preenche a parte dos coeficientes
		for(int i = 0; i < A.size(); i++)
		{
			for(int j = 0; j < A.size(); j++)
			{
				A[i][j] = A_m[i][j];		
			}
		}	
		//Preenche a ultima coluna, contendo as constantes
		for(int i = 0; i < A.size();i++)
			A[i][A.size()] = residuo[i];

		std::vector<double> y_resultados = metodoGauss(A);

		//Faz a soma dos valores de y com o x', amenizando o erro.
		for(int i = 0; i < resultados_m.size(); i++)
		{
			resultados_m[i] += y_resultados[i];
		}
		*/
	}
	else
	{
		resultados_m = metodoGauss(sistema_m);
	}
}


/*
 *@brief Método que imprime a matriz
 */
void SistemaLinear::imprimeMatrizSistema()
{
	 for(matriz::iterator it = sistema_m.begin(); it != sistema_m.end(); ++it)
 	 {
   	 	for(std::vector<double>::iterator jt = it->begin(); jt != it->end(); ++jt)
    	{
	 		std::cout << *jt << " ";
	 	}
	 	std::cout << std::endl;
	 }
	 std::cout << std::endl;
}
