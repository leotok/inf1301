/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTBAR.C
*  Letras identificadoras:      TBAR
*
*  Autores: 
*			eg - Eric Grinstein
*			jm - Jordana Mecler
*			lw - Leonardo Wajnsztok
*
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo baralho de cartas. � poss�vel testar com esse m�dulo a 
*     cria��o de 10 baralhos de cartas (que ser�o armazenados internamente
*     em um vetor.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo baralho de cartas:
*
*     =criar  <int> - chama a fun��o BAR_CriarBaralho, criando um baralho
*					  no slot dado pelo par�metro fornecido.
*					  O baralho pode ser criada do slot 0 ao slot 9. 
*					  Qualquer n�mero fornecido fora deste intervalo � tratado como par�metro incorreto.
*					  O mesmo vale para os outros comandos de teste.
*     =preencher <int> <int> 
*                   - chama a fun��o BAR_PreencherBaralho,
*					onde o primeiro par�metro � o n�mero da baralho
*					a ser alterado, o segundo � o n�mero de naipes que
*					o baralho ter�.
*     =pop <int>
*					- chama a fun��o BAR_PopCarta,
*					onde o par�metro se refere ao n�mero da baralho a ser removido
*					seu topo. 
*     
*     =embaralhar <int> 
*                   - chama a fun��o BAR_Embaralhar, onde o primeiro par�metro
*                     se refere ao n�mero da baralho a ser embaralhado.
*
*     =destroi <int>  - chama a fun��o BAR_DestruirBaralho, onde o inteiro dado se refere ao
*                     n�mero da baralho a ser destru�do.
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "CARTA.H"
#include    "BARALHO.H"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_BAR_CMD       "=criar"
#define     PREENCHER_CMD       "=preencher"
#define     POP_CMD				"=pop"
#define     EMBARALHAR_CMD		"=embaralhar"
#define     DESTROI_CMD         "=destruir"

/* M�ximo de baralhos a serem testadas simult�neamente */

#define     MAX_BARS            10

BAR_tppBaralho vBaralhos[10];

/*****  C�digo das func�es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TBAR Efetuar opera��es de teste espec�ficas para baralho de cartas
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     baralho sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

         BAR_tpCondRet CondRetObtido   = BAR_CondRetOK ;
         BAR_tpCondRet CondRetEsperada = BAR_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */
		 BAR_tpCondRet CondRetEsperadaCarta = BAR_CondRetOK ;

         

         char NaipeEsperado = '?'  ;
         char NaipeObtido   = '!'  ;  
         char NaipeDado     = '\0' ;

         int ValorEsperado = -1  ;
         int ValorObtido   = -2  ;  
         int ValorDado     = 0 ;

         int PosicaoBaralho = -1 ;
         int NumBaralho = -1 ;
         int NumLidos = -1 ;

         CAR_tppCarta CartaObtida ;
         CAR_tppCarta CartaDada ;

         TST_tpCondRet Ret ;

         /* Testar BAR Criar Baralho de Cartas */

         if ( strcmp( ComandoTeste , CRIAR_BAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" , &NumBaralho  , 
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 || NumBaralho >= MAX_BARS || NumBaralho < 0 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = BAR_CriarBaralho( &vBaralhos[NumBaralho] ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar baralho." );

         } /* fim ativa: Testar BAR Criar Baralho de cartas*/

         /* Testar BAR Preencher baralho */

         else if ( strcmp( ComandoTeste , PREENCHER_CMD ) == 0 )
         {
			
            NumLidos = LER_LerParametros( "iii" ,
                               &NumBaralho , &ValorDado ,  &CondRetEsperada ) ;
            if ( NumLidos != 3 || NumBaralho >= MAX_BARS || NumBaralho < 0 )
            {
               return TST_CondRetParm ;
            } /* if */
		
			CondRetObtido = BAR_PreencherBaralho( vBaralhos[NumBaralho] , ValorDado );
			
   
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao preencher baralho" );

         } /* fim ativa: Testar BAR Preencher baralho */

      /* Testar BAR Pop Carta da Baralho */

         else if ( strcmp( ComandoTeste , POP_CMD ) == 0 )
         {			
            NumLidos = LER_LerParametros( "ii" ,
                               &NumBaralho , &CondRetEsperada ) ;
            if ( NumLidos != 2 || NumBaralho >= MAX_BARS || NumBaralho < 0 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = BAR_PopCarta( vBaralhos[NumBaralho] , &CartaObtida ) ;

			
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                            "Retorno errado ao operar 'pop' no baralho") ;

         } /* fim ativa: Testar BAR Pop Carta da Baralho */


        /* Testar BAR Embaralhar Baralho de cartas */

         else if ( strcmp( ComandoTeste , EMBARALHAR_CMD ) == 0 )
         {
			
            NumLidos = LER_LerParametros( "ii" ,
                               &NumBaralho , &CondRetEsperada ) ;
            if ( NumLidos != 2 || NumBaralho >= MAX_BARS || NumBaralho < 0 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = BAR_Embaralhar( vBaralhos[NumBaralho] ) ;
            return TST_CompararInt( CondRetEsperada , CondRetObtido,
												"Retorno errado ao embaralhar") ;
	

         } /* Fim ativa: Testar BAR Embaralhar Baralho de cartas*/

      /* Testar BAR Destruir baralho de cartas */

         else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" , &NumBaralho , 
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 || NumBaralho >= MAX_BARS || NumBaralho < 0 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = BAR_DestruirBaralho( vBaralhos[NumBaralho] ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado destruir baralho." );

         } /* fim ativa: Testar BAR Destruir Baralho de Cartas */

      /* Testar BAR Destruir Baralho */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TBAR Efetuar opera��es de teste espec�ficas para baralho de cartas */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/
