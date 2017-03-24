#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sintatico.h"

#define PROGRAM 39
#define PONTO_E_VIRGULA 1
#define PONTO 2
#define VAR 3
#define VIRGULA 4
#define DOIS_PONTOS 5
#define PROCEDURE 6
#define FUNCTION 7
#define BEGIN 8
#define END 9
#define PONTO_PONTO 10
#define MAIS 11
#define MENOS 12
#define ARRAY 13
#define ABRE_COLCHETES 14
#define FECHA_COLCHETES 15
#define OF 16
#define ABRE_PARENTESES 17
#define FECHA_PARENTESES 18
#define DOIS_PONTOS_IGUAL 19
#define IF 20
#define THEN 21
#define ELSE 22
#define WHILE 23
#define DO 24
#define IGUAL 25
#define MENOR_MAIOR 26
#define MENOR 27
#define MENOR_IGUAL 28
#define MAIOR_IGUAL 29
#define MAIOR 30
#define OR 31
#define MULT 32
#define DIV 33
#define AND 34
#define DOLAR 35
#define IDENTIFICADOR 36
#define NUMERO 37
#define NOT 38

#define max 1000000

void S(int tokens[max], int *cont, int *erro);
void PROGRAMA(int tokens[max], int *cont, int *erro);
void BLOCO(int tokens[max], int *cont, int *erro);
void B1(int tokens[max], int *cont, int *erro);
void B1LINHA(int tokens[max], int *cont, int *erro);
void B1DUASLINHA(int tokens[max], int *cont, int *erro);
void BLOCO1(int tokens[max], int *cont, int *erro);
void B2(int tokens[max], int *cont, int *erro);
void B2LINHA(int tokens[max], int *cont, int *erro);
void TIPO(int tokens[max], int *cont, int *erro);
void TIPOLINHA(int tokens[max], int *cont, int *erro);
void T1(int tokens[max], int *cont, int *erro);
void T1LINHA(int tokens[max], int *cont, int *erro);
void PF(int tokens[max], int *cont, int *erro);
void PF1(int tokens[max], int *cont, int *erro);
void PF2(int tokens[max], int *cont, int *erro);
void PF2LINHA(int tokens[max], int *cont, int *erro);
void PF2DUASLINHA(int tokens[max], int *cont, int *erro);
void VARIAVEL(int tokens[max], int *cont, int *erro);
void VARIAVEL1(int tokens[max], int *cont, int *erro);
void V1(int tokens[max], int *cont, int *erro);
void V2(int tokens[max], int *cont, int *erro);
void V2LINHA(int tokens[max], int *cont, int *erro);
void V2DUASLINHA(int tokens[max], int *cont, int *erro);
void COMANDO(int tokens[max], int *cont, int *erro);
void COMANDOLINHA(int tokens[max], int *cont, int *erro);
void C1(int tokens[max], int *cont, int *erro);
void C2(int tokens[max], int *cont, int *erro);
void C2LINHA(int tokens[max], int *cont, int *erro);
void C3(int tokens[max], int *cont, int *erro);
void C3LINHA(int tokens[max], int *cont, int *erro);
void C4(int tokens[max], int *cont, int *erro);
void EXPRESSAO(int tokens[max], int *cont, int *erro);
void E1(int tokens[max], int *cont, int *erro);
void ES(int tokens[max], int *cont, int *erro);
void ES1(int tokens[max], int *cont, int *erro);
void TERMO(int tokens[max], int *cont, int *erro);
void TERMO1(int tokens[max], int *cont, int *erro);
void FATOR(int tokens[max], int *cont, int *erro);
void FATORLINHA(int tokens[max], int *cont, int *erro);
void F1(int tokens[max], int *cont, int *erro);
void F2(int tokens[max], int *cont, int *erro);
void F2LINHA(int tokens[max], int *cont, int *erro);
void CONSTANTE(int tokens[max], int *cont, int *erro); 

struct aux2{

	char str[500];
};
typedef struct aux2 aux2;
aux2 strings[max];

int vet2[max];

char* converte2(int num){

	if(num == PROGRAM)
		return("program");
	else if(num == PONTO_E_VIRGULA)
		return(";");
	else if(num == PONTO)
		return(".");
	else if(num == VAR)
		return("var");
	else if(num == VIRGULA)
		return(",");
	else if(num == DOIS_PONTOS)
		return(":");
	else if(num == PROCEDURE)
		return("procedure");
	else if(num == FUNCTION)
		return("function");
	else if(num == BEGIN)
		return("begin");
	else if(num == END)
		return("end");
	else if(num == PONTO_PONTO)
		return("..");
	else if(num == MAIS)
		return("+");
	else if(num == MENOS)
		return("-");
	else if(num == ARRAY)
		return("array");
	else if(num == ABRE_COLCHETES)
		return("[");
	else if(num == FECHA_COLCHETES)
		return("]");
	else if(num == OF)
		return("of");
	else if(num == ABRE_PARENTESES)
		return("(");
	else if(num == FECHA_PARENTESES)
		return(")");
	else if(num == DOIS_PONTOS_IGUAL)
		return(":=");
	else if(num == IF)
		return("if");
	else if(num == THEN)
		return("then");
	else if(num == ELSE)
		return("else");
	else if(num == WHILE)
		return("while");
	else if(num == DO)
		return("do");
	else if(num == IGUAL)
		return("=");
	else if(num == MENOR_MAIOR)
		return("<>");
	else if(num == MENOR)
		return("<");
	else if(num == MENOR_IGUAL)
		return("<=");
	else if(num == MAIOR_IGUAL)
		return(">=");
	else if(num == MAIOR)
		return(">");
	else if(num == OR)
		return("or");
	else if(num == MULT)
		return("*");
	else if(num == DIV)
		return("div");
	else if(num == AND)
		return("and");
	else if(num == DOLAR)
		return("$");
	else
		return("");
}

void eat(int token, int vt, int *cont, int *erro){

	if(*erro == 1)
		return;
	if(token == vt)
		*cont = *cont + 1;
	else{

		*erro = 1;
		printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
	}
}

void sintatico(int tokens[max]){

	int cont = 0, erro = 0;
	S(tokens, &cont, &erro);
	if(erro == 0)
			printf("CADEIA ACEITA");
}

void S(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PROGRAM :

			PROGRAMA(tokens, cont, erro);
			eat(tokens[*cont], DOLAR, cont, erro);
			break;
		default :

			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void PROGRAMA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PROGRAM :

			eat(tokens[*cont], PROGRAM, cont, erro);
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			eat(tokens[*cont], PONTO_E_VIRGULA, cont, erro);
			BLOCO(tokens, cont, erro);
			eat(tokens[*cont], PONTO, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void BLOCO(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case VAR :
			eat(tokens[*cont], VAR, cont, erro);
			B1(tokens, cont, erro);
			break;
		case PROCEDURE :
			BLOCO1(tokens, cont, erro);
			break;
		case FUNCTION :
			BLOCO1(tokens, cont, erro);
			break;
		case BEGIN :
			BLOCO1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void B1(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :

			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			B1LINHA(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void B1LINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case VIRGULA :
			eat(tokens[*cont], VIRGULA, cont, erro);
			B1(tokens, cont, erro);
			break;
		case DOIS_PONTOS :
			eat(tokens[*cont], DOIS_PONTOS, cont, erro);
			TIPO(tokens, cont, erro);
			eat(tokens[*cont], PONTO_E_VIRGULA, cont, erro);
			B1DUASLINHA(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void B1DUASLINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			B1(tokens, cont, erro);
			break;
		case PROCEDURE :
			BLOCO1(tokens, cont, erro);
			break;
		case FUNCTION :
			BLOCO1(tokens, cont, erro);
			break;
		case BEGIN :
			BLOCO1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void BLOCO1(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PROCEDURE :
			eat(tokens[*cont], PROCEDURE, cont, erro);
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			PF(tokens, cont, erro);
			eat(tokens[*cont], PONTO_E_VIRGULA, cont, erro);
			BLOCO(tokens, cont, erro);
			eat(tokens[*cont], PONTO_E_VIRGULA, cont, erro);
			BLOCO1(tokens, cont, erro);
			break;
		case FUNCTION :
			eat(tokens[*cont], FUNCTION, cont, erro);
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			PF(tokens, cont, erro);
			eat(tokens[*cont], DOIS_PONTOS, cont, erro);
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			eat(tokens[*cont], PONTO_E_VIRGULA, cont, erro);
			BLOCO(tokens, cont, erro);
			eat(tokens[*cont], PONTO_E_VIRGULA, cont, erro);
			BLOCO1(tokens, cont, erro);
			break;
		case BEGIN :
			eat(tokens[*cont], BEGIN, cont, erro);
			B2(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void B2(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			COMANDO(tokens, cont, erro);
			B2LINHA(tokens, cont, erro);
			break;
		case PONTO_E_VIRGULA :
			COMANDO(tokens, cont, erro);
			B2LINHA(tokens, cont, erro);
			break;
		case PONTO :
			COMANDO(tokens, cont, erro);
			B2LINHA(tokens, cont, erro);
			break;
		case BEGIN :
			COMANDO(tokens, cont, erro);
			B2LINHA(tokens, cont, erro);
			break;
		case END :
			COMANDO(tokens, cont, erro);
			B2LINHA(tokens, cont, erro);
			break;
		case IF :
			COMANDO(tokens, cont, erro);
			B2LINHA(tokens, cont, erro);
			break;
		case WHILE :
			COMANDO(tokens, cont, erro);
			B2LINHA(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void B2LINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PONTO_E_VIRGULA :
			eat(tokens[*cont], PONTO_E_VIRGULA, cont, erro);
			B2(tokens, cont, erro);
			break;
		case END :
			eat(tokens[*cont], END, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void TIPO(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			TIPOLINHA(tokens, cont, erro);
			break;
		case NUMERO :
			eat(tokens[*cont], NUMERO, cont, erro);
			eat(tokens[*cont], PONTO_PONTO, cont, erro);
			CONSTANTE(tokens, cont, erro);
			break;
		case MAIS :
			eat(tokens[*cont], MAIS, cont, erro);
			eat(tokens[*cont], NUMERO, cont, erro);
			eat(tokens[*cont], PONTO_PONTO, cont, erro);
			CONSTANTE(tokens, cont, erro);
			break;
		case MENOS :
			eat(tokens[*cont], MENOS, cont, erro);
			eat(tokens[*cont], NUMERO, cont, erro);
			eat(tokens[*cont], PONTO_PONTO, cont, erro);
			CONSTANTE(tokens, cont, erro);
			break;
		case ARRAY :
			eat(tokens[*cont], ARRAY, cont, erro);
			eat(tokens[*cont], FECHA_COLCHETES, cont, erro);
			T1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void TIPOLINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PONTO_E_VIRGULA :
		case VIRGULA :
		case FECHA_COLCHETES :
			break;
		case PONTO_PONTO :
			eat(tokens[*cont], PONTO_PONTO, cont, erro);
			CONSTANTE(tokens, cont, erro);
			break;
		
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void T1(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			TIPO(tokens, cont, erro);
			T1LINHA(tokens, cont, erro);
			break;
		case NUMERO :
			TIPO(tokens, cont, erro);
			T1LINHA(tokens, cont, erro);
			break;
		case MAIS :
			TIPO(tokens, cont, erro);
			T1LINHA(tokens, cont, erro);
			break;
		case MENOS :
			TIPO(tokens, cont, erro);
			T1LINHA(tokens, cont, erro);
			break;
		case ARRAY :
			TIPO(tokens, cont, erro);
			T1LINHA(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void T1LINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case VIRGULA :
			eat(tokens[*cont], VIRGULA, cont, erro);
			T1(tokens, cont, erro);
			break;
		case FECHA_COLCHETES :
			eat(tokens[*cont], FECHA_COLCHETES, cont, erro);
			eat(tokens[*cont], OF, cont, erro);
			TIPO(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void PF(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case ABRE_PARENTESES :
			eat(tokens[*cont], ABRE_PARENTESES, cont, erro);
			PF1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void PF1(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			PF2(tokens, cont, erro);
			break;
		case VAR :
			eat(tokens[*cont], VAR, cont, erro);
			PF2(tokens, cont, erro);
			break;
		case FECHA_PARENTESES :
			eat(tokens[*cont], FECHA_PARENTESES, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void PF2(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			PF2LINHA(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void PF2LINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			eat(tokens[*cont], DOIS_PONTOS, cont, erro);
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			PF2DUASLINHA(tokens, cont, erro);
			break; 
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void PF2DUASLINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PONTO_E_VIRGULA :
			eat(tokens[*cont], PONTO_E_VIRGULA, cont, erro);
			PF2(tokens, cont, erro);
			break; 
		case FECHA_PARENTESES :
			eat(tokens[*cont], FECHA_PARENTESES, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void VARIAVEL(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			VARIAVEL1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void VARIAVEL1(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PONTO_E_VIRGULA :
		case VIRGULA :
		case END :
		case MAIS :
		case MENOS :
		case FECHA_COLCHETES :
		case FECHA_PARENTESES :
		case DOIS_PONTOS_IGUAL :
		case THEN :
		case DO :
		case IGUAL :
		case MENOR_MAIOR :
		case MENOR :
		case MENOR_IGUAL :
		case MAIOR_IGUAL :
		case MAIOR :
		case OR :
		case MULT :
		case DIV :
		case AND :
			break;
		case ABRE_COLCHETES :
			V1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void V1(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case ABRE_COLCHETES :
			eat(tokens[*cont], ABRE_COLCHETES, cont, erro);
			V2(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void V2(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			EXPRESSAO(tokens, cont, erro);
			V2LINHA(tokens, cont, erro);
			break;
		case NUMERO :
			EXPRESSAO(tokens, cont, erro);
			V2LINHA(tokens, cont, erro);
			break;
		case MAIS :
			EXPRESSAO(tokens, cont, erro);
			V2LINHA(tokens, cont, erro);
			break;
		case MENOS :
			EXPRESSAO(tokens, cont, erro);
			V2LINHA(tokens, cont, erro);
			break;
		case ABRE_PARENTESES :
			EXPRESSAO(tokens, cont, erro);
			V2LINHA(tokens, cont, erro);
			break;
		case NOT :
			EXPRESSAO(tokens, cont, erro);
			V2LINHA(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void V2LINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case VIRGULA :
			eat(tokens[*cont], VIRGULA, cont, erro);
			V2(tokens, cont, erro);
			break;
		case FECHA_COLCHETES :
			eat(tokens[*cont], FECHA_COLCHETES, cont, erro);
			V2DUASLINHA(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void V2DUASLINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case VIRGULA :
		case PONTO_E_VIRGULA :
		case END :
		case MAIS :
		case MENOS :
		case FECHA_COLCHETES :
		case FECHA_PARENTESES :
		case DOIS_PONTOS_IGUAL :
		case THEN :
		case DO :
		case IGUAL :
		case MENOR_MAIOR :
		case MENOR :
		case MENOR_IGUAL :
		case MAIOR_IGUAL :
		case MAIOR :
		case OR :
		case MULT :
		case DIV :
		case AND :
			break;
		case ABRE_COLCHETES :
			V1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void COMANDO(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			COMANDOLINHA(tokens, cont, erro);
			break;
		case PONTO_E_VIRGULA :
		case END :	
			break;
		case BEGIN :
			eat(tokens[*cont], BEGIN, cont, erro);
			C3LINHA(tokens, cont, erro);
			break;
		case IF :
			eat(tokens[*cont], IF, cont, erro);
			EXPRESSAO(tokens, cont, erro);
			eat(tokens[*cont], THEN, cont, erro);
			eat(tokens[*cont], BEGIN, cont, erro);
			COMANDO(tokens, cont, erro);
			eat(tokens[*cont], END, cont, erro);
			C4(tokens, cont, erro);
			break;
		case WHILE :
			eat(tokens[*cont], WHILE, cont, erro);
			EXPRESSAO(tokens, cont, erro);
			eat(tokens[*cont], DO, cont, erro);
			COMANDO(tokens, cont, erro);
			break; 
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void COMANDOLINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PONTO_E_VIRGULA :
			VARIAVEL1(tokens, cont, erro);
			eat(tokens[*cont], DOIS_PONTOS_IGUAL, cont, erro);
			EXPRESSAO(tokens, cont, erro);
			break;
		case END :
			VARIAVEL1(tokens, cont, erro);
			eat(tokens[*cont], DOIS_PONTOS_IGUAL, cont, erro);
			EXPRESSAO(tokens, cont, erro);
			break;
		case ABRE_COLCHETES :
			VARIAVEL1(tokens, cont, erro);
			eat(tokens[*cont], DOIS_PONTOS_IGUAL, cont, erro);
			EXPRESSAO(tokens, cont, erro);
			break;
		case ABRE_PARENTESES :
			eat(tokens[*cont], ABRE_PARENTESES, cont, erro);
			C1(tokens, cont, erro);
			break;
		case DOIS_PONTOS_IGUAL :
			VARIAVEL1(tokens, cont, erro);
			eat(tokens[*cont], DOIS_PONTOS_IGUAL, cont, erro);
			EXPRESSAO(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void C1(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			C2(tokens, cont, erro);
			break;
		case NUMERO :
			C2(tokens, cont, erro);
			break;
		case MAIS :
			C2(tokens, cont, erro);
			break;
		case MENOS :
			C2(tokens, cont, erro);
			break;
		case ABRE_PARENTESES :
			C2(tokens, cont, erro);
			break;
		case FECHA_PARENTESES :
			eat(tokens[*cont], FECHA_PARENTESES, cont, erro);
			break;
		case NOT :
			C2(tokens, cont, erro);
			break;		
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void C2(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			EXPRESSAO(tokens, cont, erro);
			C2LINHA(tokens, cont, erro);
			break;
		case NUMERO :
			EXPRESSAO(tokens, cont, erro);
			C2LINHA(tokens, cont, erro);
			break;	
		case MAIS :
			EXPRESSAO(tokens, cont, erro);
			C2LINHA(tokens, cont, erro);
			break;	
		case MENOS :
			EXPRESSAO(tokens, cont, erro);
			C2LINHA(tokens, cont, erro);
			break;
		case ABRE_PARENTESES :
			EXPRESSAO(tokens, cont, erro);
			C2LINHA(tokens, cont, erro);
			break;
		case NOT :
			EXPRESSAO(tokens, cont, erro);
			C2LINHA(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void C2LINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case VIRGULA :
			eat(tokens[*cont], VIRGULA, cont, erro);
			C2(tokens, cont, erro);
			break;
		case FECHA_PARENTESES :
			eat(tokens[*cont], FECHA_PARENTESES, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void C3(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			COMANDO(tokens, cont, erro);
			C3LINHA(tokens, cont, erro);
			break;
		case PONTO_E_VIRGULA :
			COMANDO(tokens, cont, erro);
			C3LINHA(tokens, cont, erro);
			break;
		case BEGIN :
			COMANDO(tokens, cont, erro);
			C3LINHA(tokens, cont, erro);
			break;	
		case END :
			COMANDO(tokens, cont, erro);
			C3LINHA(tokens, cont, erro);	
			break;
		case IF :
			COMANDO(tokens, cont, erro);
			C3LINHA(tokens, cont, erro);
			break;
		case WHILE :
			COMANDO(tokens, cont, erro);
			C3LINHA(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void C3LINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PONTO_E_VIRGULA :
			eat(tokens[*cont], PONTO_E_VIRGULA, cont, erro);
			C3(tokens, cont, erro);
			break;
		case END :
			eat(tokens[*cont], END, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void C4(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PONTO_E_VIRGULA :
		case END :
			break;
		case ELSE :
			eat(tokens[*cont], ELSE, cont, erro);
			eat(tokens[*cont], BEGIN, cont, erro);
			COMANDO(tokens, cont, erro);
			eat(tokens[*cont], END, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void EXPRESSAO(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			ES(tokens, cont, erro);
			E1(tokens, cont, erro);
			break;
		case NUMERO :
			ES(tokens, cont, erro);
			E1(tokens, cont, erro);
			break;
		case MAIS :
			ES(tokens, cont, erro);
			E1(tokens, cont, erro);
			break;
		case MENOS :
			ES(tokens, cont, erro);
			E1(tokens, cont, erro);
			break;
		case ABRE_PARENTESES :
			ES(tokens, cont, erro);
			E1(tokens, cont, erro);
			break;
		case NOT :
			ES(tokens, cont, erro);
			E1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void E1(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PONTO_E_VIRGULA :
		case VIRGULA :
		case END :
		case FECHA_COLCHETES :
		case FECHA_PARENTESES :
		case THEN :
		case DO :
			break;
		case IGUAL :
			eat(tokens[*cont], IGUAL, cont, erro);
			ES(tokens, cont, erro);
			break;
		case MENOR_MAIOR :
			eat(tokens[*cont], MENOR_MAIOR, cont, erro);
			ES(tokens, cont, erro);
			break;
		case MENOR :
			eat(tokens[*cont], MENOR, cont, erro);
			ES(tokens, cont, erro);
			break;
		case MENOR_IGUAL :
			eat(tokens[*cont], MENOR_IGUAL, cont, erro);
			ES(tokens, cont, erro);
			break;
		case MAIOR_IGUAL :
			eat(tokens[*cont], MAIOR_IGUAL, cont, erro);
			ES(tokens, cont, erro);
			break;
		case MAIOR :
			eat(tokens[*cont], MAIOR, cont, erro);
			ES(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void ES(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			TERMO(tokens, cont, erro);
			ES1(tokens, cont, erro);
			break;
		case NUMERO :
			TERMO(tokens, cont, erro);
			ES1(tokens, cont, erro);
			break;
		case MAIS :
			eat(tokens[*cont], MAIS, cont, erro);
			TERMO(tokens, cont, erro);
			ES1(tokens, cont, erro);
			break;
		case MENOS :
			eat(tokens[*cont], MENOS, cont, erro);
			TERMO(tokens, cont, erro);
			ES1(tokens, cont, erro);
			break;
		case ABRE_PARENTESES :
			TERMO(tokens, cont, erro);
			ES1(tokens, cont, erro);
			break;
		case NOT :
			TERMO(tokens, cont, erro);
			ES1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void ES1(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PONTO_E_VIRGULA :
		case VIRGULA :
		case END :
		case FECHA_COLCHETES :
		case FECHA_PARENTESES :
		case THEN :
		case DO :
		case IGUAL :
		case MENOR_MAIOR :
		case MENOR :
		case MENOR_IGUAL :
		case MAIOR_IGUAL :
		case MAIOR :
			break;
		case MAIS :
			eat(tokens[*cont], MAIS, cont, erro);
			TERMO(tokens, cont, erro);
			ES1(tokens, cont, erro);
			break;
		case MENOS :
			eat(tokens[*cont], MENOS, cont, erro);
			TERMO(tokens, cont, erro);
			ES1(tokens, cont, erro);
			break;
		case OR :
			eat(tokens[*cont], OR, cont, erro);
			TERMO(tokens, cont, erro);
			ES1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void TERMO(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			FATOR(tokens, cont, erro);
			TERMO1(tokens, cont, erro);
			break;
		case NUMERO :
			FATOR(tokens, cont, erro);
			TERMO1(tokens, cont, erro);
			break; 
		case ABRE_PARENTESES :
			FATOR(tokens, cont, erro);
			TERMO1(tokens, cont, erro);
			break;
		case NOT :
			FATOR(tokens, cont, erro);
			TERMO1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void TERMO1(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PONTO_E_VIRGULA :
		case VIRGULA :
		case END :
		case MAIS :
		case MENOS :
		case FECHA_COLCHETES :
		case FECHA_PARENTESES :
		case THEN :
		case IGUAL :
		case MENOR_MAIOR :
		case MENOR :
		case MENOR_IGUAL :
		case MAIOR_IGUAL :
		case MAIOR :
		case OR :
		case DO :
			break;
		case MULT :
			eat(tokens[*cont], MULT, cont, erro);
			FATOR(tokens, cont, erro);
			TERMO1(tokens, cont, erro);
			break;	
		case DIV :
			eat(tokens[*cont], DIV, cont, erro);
			FATOR(tokens, cont, erro);
			TERMO1(tokens, cont, erro);
			break;
		case AND :
			eat(tokens[*cont], AND, cont, erro);
			FATOR(tokens, cont, erro);
			TERMO1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void FATOR(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			FATORLINHA(tokens, cont, erro);
			break;
		case NUMERO :
			eat(tokens[*cont], NUMERO, cont, erro);
			break;
		case ABRE_PARENTESES :
			eat(tokens[*cont], ABRE_PARENTESES, cont, erro);
			EXPRESSAO(tokens, cont, erro);
			eat(tokens[*cont], FECHA_PARENTESES, cont, erro);
			break;
		case NOT :
			eat(tokens[*cont], NOT, cont, erro);
			FATOR(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void FATORLINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case PONTO_E_VIRGULA :
			VARIAVEL1(tokens, cont, erro);
			break;
		case VIRGULA :
			VARIAVEL1(tokens, cont, erro);
			break;
		case END :
			VARIAVEL1(tokens, cont, erro);
			break;
		case MAIS :
			VARIAVEL1(tokens, cont, erro);
			break;
		case MENOS :
			VARIAVEL1(tokens, cont, erro);
			break;
		case ABRE_COLCHETES :
			VARIAVEL1(tokens, cont, erro);
			break;
		case FECHA_COLCHETES :
			VARIAVEL1(tokens, cont, erro);
			break;
		case ABRE_PARENTESES :
			eat(tokens[*cont], ABRE_PARENTESES, cont, erro);
			F1(tokens, cont, erro);
			break;
		case FECHA_PARENTESES :
			VARIAVEL1(tokens, cont, erro);
			break;
		case THEN :
			VARIAVEL1(tokens, cont, erro);
			break;
		case DO :
			VARIAVEL1(tokens, cont, erro);
			break;
		case IGUAL :
			VARIAVEL1(tokens, cont, erro);
			break;
		case MENOR_MAIOR :
			VARIAVEL1(tokens, cont, erro);
			break;
		case MENOR :
			VARIAVEL1(tokens, cont, erro);
			break;
		case MENOR_IGUAL :
			VARIAVEL1(tokens, cont, erro);
			break;
		case MAIOR_IGUAL :
			VARIAVEL1(tokens, cont, erro);
			break;
		case MAIOR :
			VARIAVEL1(tokens, cont, erro);
			break;
		case OR :
			VARIAVEL1(tokens, cont, erro);
			break;
		case MULT :
			VARIAVEL1(tokens, cont, erro);
			break;
		case DIV :
			VARIAVEL1(tokens, cont, erro);
			break;
		case AND :
			VARIAVEL1(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void F1(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			F2(tokens, cont, erro);
			break;
		case NUMERO :
			F2(tokens, cont, erro);
			break;
		case MAIS :
			F2(tokens, cont, erro);
			break;
		case MENOS :
			F2(tokens, cont, erro);
			break;
		case ABRE_PARENTESES :
			F2(tokens, cont, erro);
			break;
		case FECHA_PARENTESES :
			eat(tokens[*cont], FECHA_PARENTESES, cont, erro);
			break;
		case NOT :
			F2(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void F2(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			EXPRESSAO(tokens, cont, erro);
			F2LINHA(tokens, cont, erro);
			break;
		case NUMERO :
			EXPRESSAO(tokens, cont, erro);
			F2LINHA(tokens, cont, erro);
			break;
		case MAIS :
			EXPRESSAO(tokens, cont, erro);
			F2LINHA(tokens, cont, erro);
			break;
		case MENOS :
			EXPRESSAO(tokens, cont, erro);
			F2LINHA(tokens, cont, erro);
			break;
		case ABRE_PARENTESES :
			EXPRESSAO(tokens, cont, erro);
			F2LINHA(tokens, cont, erro);
			break;
		case NOT :
			EXPRESSAO(tokens, cont, erro);
			F2LINHA(tokens, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void F2LINHA(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case VIRGULA :
			eat(tokens[*cont], VIRGULA, cont, erro);
			F2(tokens, cont, erro);
			break;
		case FECHA_PARENTESES :
			eat(tokens[*cont], FECHA_PARENTESES, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

void CONSTANTE(int tokens[max], int *cont, int *erro){

	if(*erro == 1)
		return;
	switch(tokens[*cont]){

		case IDENTIFICADOR :
			eat(tokens[*cont], IDENTIFICADOR, cont, erro);
			break;
		case NUMERO :
			eat(tokens[*cont], NUMERO, cont, erro);
			break;
		case MAIS :
			eat(tokens[*cont], MAIS, cont, erro);
			eat(tokens[*cont], NUMERO, cont, erro);
			break;
		case MENOS :
			eat(tokens[*cont], MENOS, cont, erro);
			eat(tokens[*cont], NUMERO, cont, erro);
			break;
		default :
			printf("Erro de Sintaxe. Linha %d Token ""%s", vet2[*cont], strings[*cont].str);
			*erro = 1;
	}
}

int main(){

	extern int yylex();
	int vet[max];
	int i = 0, a = yylex();
	
	while(a != 0){

		vet[i] = a;
		strcpy(strings[i].str, aux);
		vet2[i] = linha;
		i++;
		if(a == 89)
			break;
		a = yylex();
	}	
	vet[i] = 35;
	if(a != 89)
		sintatico(vet);

	return 0;
}
