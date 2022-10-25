#include <stdio.h>

// PROJETO FINAL MEGA-SENA

int main(){
	
	int i, j, num, acertos = 0, parar, gabarito[6], digitado[10];
	int repetido;
	
	for ( i = 0; i < 6; i++ ){ // define os valores do gabarito como 0, inicialmente 
		gabarito[i] = 0;
	}
	
	printf("Digite o gabarito da megasena: \n"); 
	
	for ( i = 0; i < 6; i++ ){ // recebe o gabarito e substitui os valores repetidos do gabarito
		scanf("%i", &num);
		for ( j = 0; j < 6; j++ ){
			if (num == gabarito[j] || (num < 1 || num > 60)){
				repetido = 1;
				break;
			}
		}
		
		if ( repetido == 1 ){
			printf("\nO numero %i e invalido, digite novamente: \n", num);
			repetido = 0;
			
			i -= 1;
		}
		else{
			gabarito[i] = num;
		}
		
	}
	
	for ( i = 0; i < 10; i++ ){ // define os valores dos valores digitados como 0, inicialmente 
		digitado[i] = 0;
	}
	
	printf("\n");
	printf("OBS: Voce pode encerrar o palpite ao digitar 0, apos ter feito, pelo menos, 6 palpites.\n");
	printf("Digite os numeros do seu palpite: \n");
	
	for ( i = 0; i < 10; i++ ){ // recebe o palpite e substitui os valores repetidos
		scanf("%i", &num);
		
		if ( i >= 6 && num == 0 ){
			parar = 1;
			break;
		}
		for ( j = 0; j < 10; j++ ){
			if (num == digitado[j] || (num < 1 || num > 60)){
				repetido = 1;
				break;
			}
		}
		
		if ( repetido == 1 ){
			printf("\nO numero %i ja foi sorteado, digite novamente: \n", num);
			repetido = 0;
			
			i -= 1;
		}
		else{
			digitado[i] = num;
		}
		
	}
	
	for ( i = 0; i < 10; i++ ){ // verifica quantidade de acertos
		for ( j = 0; j < 6; j++){
			if ( digitado[i] == gabarito[j] ){
				acertos++;
			}
		}
	}
	
	printf("\n");
	for ( i = 0; i < 6; i++ ){ // print gabarito
		printf("Gabarito: [%i] %i\n", i, gabarito[i]);
	}
	
	printf("\n");
	if ( acertos == 6 ){
		printf("Parabens voce teve uma sena (6 acertos)! \n");
	}
	else if ( acertos == 5 ){
		printf("Parabens voce teve uma quina (5 acertos)! \n");
	}
	else if ( acertos == 4){
		printf("Parabens voce teve uma quadra (4 acertos)! \n");
	}
	else {
		printf("Nao foi dessa vez! Tente novamente!");
	}
	
	return 0;
}
