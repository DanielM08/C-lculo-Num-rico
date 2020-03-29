#include "../include/SistemaLinear.h"


int main(int argc, char* argv[])
{
	if(argc < 2)
		exit(EXIT_FAILURE);
	
	for(int i = 1; i < argc; i++)
	{
		std::cout << "Matriz " << i << std::endl;
		SistemaLinear s(argv[i]);
		s.imprimeMatrizSistema();
		
		std::vector<double> resultados = s.solucoesSistema();

		std::cout << "Soluções do sistema: " << std::endl;
		for(size_t i = 0; i < resultados.size(); i++)
		{
			std::cout <<"X" << i << " = "<< resultados[i] << std::endl;
		}
		std::cout << std::endl;
	}
	
	/*
	SistemaLinear s1("/home/danielmarx/Documentos/TI/5ºSemestre/CN/calculoNumerico_atvd2/data/m1.in");
	s1.imprimeMatrizSistema();	
	s1.solucoesSistema();
	*/
	return 0;
}

