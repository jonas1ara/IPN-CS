int aux;

	for(int j=0;j<NUMS_TO_GENERATE;j++)
	{
		for(int k=0;k<NUMS_TO_GENERATE;k++)
		{
			if(numeros[k] > numeros [k+1])
			{
				aux = numeros [k+1];
				numeros[k+1] = numeros[k];
				numeros[k] = aux;
			}
		}
	}
	for(int j=0;j<NUMS_TO_GENERATE;j++)
	{
		printf("%d\t", numeros[j]);	
	}