%option noyywrap
%option caseless

%x COMMENT
%x COMMENT2

%{
#include<string.h>
#include"sintatico.h"

int chars = 0;
int words = 0;
int lines = 1;
int lines2;

%}

%%

"program"    {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (39);}
";"      {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (1);}
"."		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (2);}
"var"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (3);}
","		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (4);}
":"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (5);}
"procedure"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (6);}
"function"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (7);}
"begin"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (8);}
"end"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (9);}
".."		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (10);}
"+"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (11);}
"-"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (12);}
"array"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (13);}
"["		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (14);}
"]"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (15);}
"of"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (16);}
"("		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (17);}
")"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (18);}
":="		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (19);}
"if"       {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (20);}
"then"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (21);}
"else"     {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (22);}
"while"        {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (23);}
"do"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (24);}
"="		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (25);}
"<>"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (26);}
"<"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (27);}
"<="		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (28);}
">="		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (29);}
">"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (30);}
"or"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (31);}
"*"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (32);}
"div"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (33);}
"and"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (34);}
"NOT"		 {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (38);}

[0-9]+ {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (37);}
[a-zA-Z][a-zA-Z0-9]* {linha = lines;strcpy(aux, yytext);chars+=strlen(yytext);return (36);}
[ \t]      {chars++;}
[\n]       {lines++;chars = 1;}

<INITIAL>{
     "(*"  {lines2 = lines;}  BEGIN(COMMENT2);
     }

<COMMENT2>{
     <<EOF>>   { printf("ERRO LEXICO, LINHA:%d, COMENTARIO NAO TERMINADO",lines2); exit(0);} BEGIN(INITIAL);
     "*)"      { } BEGIN(INITIAL);
     [^*\n]+   { }
     "*"/[^/]  { } 
     \n        yylineno++;lines++;
     }
     
<INITIAL>{
     "{"  {lines2 = lines; }  BEGIN(COMMENT);
     }

<COMMENT>{
     <<EOF>>   { printf("ERRO LEXICO, LINHA:%d, COMENTARIO NAO TERMINADO",lines2);exit(0);} BEGIN(INITIAL);
     "}"       {  } BEGIN(INITIAL);
     [^}\n]+   { }
     "*"/[^/]  { } 
     \n        yylineno++;lines++;
     }
\/\/([^\n])*   { }

.          { printf("ERRO(%s) LINHA: (%d) COLUNA(%d)",yytext, lines, chars);return(89);}

%%
