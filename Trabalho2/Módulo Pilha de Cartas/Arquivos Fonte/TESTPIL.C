/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTPIL.C
*  Letras identificadoras:      TPIL
*
*  Autores: 
*			eg - Eric Grinstein
*			jm - Jordana Mecler
*			lw - Leonardo Wajnsztok
*
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo pilha de cartas. � poss�vel testar com esse m�dulo a 
*     cria��o de 10 pilhas de cartas (que ser�o armazenadas internamente
*     em um vetor.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo pilha de cartas:
*
*     =criar  <int> - chama a fun��o PIL_CriarPilhaVazia, criando 
*					  criando-a no slot de pilhas dado pelo par�metro fornecido.
*					  A pilha pode ser criada do slot 0 ao slot 9. Qualquer n�mero 
*                     fornecido fora deste intervalo � tratado como par�metro incorreto.
*					  O mesmo vale para os outros comandos de teste.
*     =push <int> <Char> <int>
*                   - chama a fun��o PIL_PushCarta,
*					onde o primeiro par�metro � o n�mero da pilha
*					a ser alterada, o segundo � o naipe da carta a ser
*					inserida e o �ltimo seu valor.
*     =pop <int>
*					- chama a fun��o PIL_PopCarta,
*					onde o par�metro se refere ao n�mero da pilha a ser removido
*					seu topo. 
*     
*     =ver <int> <int>
*                   - chama a fun��o PIL_VerCarta, onde o primeiro par�metro
*                   se refere ao n�mero da pilha a ser vista e o segundo a posi��o da
*					pilha em rela��o ao topo a ser vista.
*					
*
*     =destroi <int>  - chama a fun��o PIL_DestruirPilha, onde o inteiro dado se refere ao
*                     n�mero da pilha a ser destru�da
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "CARTA.H"
#include    "PILHA_DE_CARTAS.H"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_PIL_CMD       "=criar"
#define     PUSH_CMD            "=push"
#define     POP_CMD				"=pop"
#define     VER_CMD				"=ver"
#define     DESTROI_CMD         "=destruir"

/* M�ximo de pilhas a serem testadas simult�neamente */

#define     MAX_PILS            10

PIL_tppPilha vPilhas[ MAX_PILS ];

/*****  C�digo das func�es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TPIL Efetuar opera��es de teste espec�ficas para pilha de cartas
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     pilha sendo testado.
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

      PIL_tpCondRet CondRetObtido   = PIL_CondRetOK ;
      PIL_tpCondRet CondRetEsperada = PIL_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

	 

      char NaipeEsperado = '?'  ;
      char NaipeObtido   = '!'  ;  
      char NaipeDado     = '\0' ;

      int ValorEsperado = -1  ;
      int ValorObtido   = -2  ;  
      int ValorDado     = 0 ;

      int PosicaoPilha = -1 ;
      int NumPilha = -1 ;
      int  NumLidos = -1 ;

      CAR_tppCarta CartaObtida ;
      CAR_tppCarta CartaDada ;

      TST_tpCondRet Ret ;

      /* Testar PIL Criar Pilha de Cartas */

         if ( strcmp( ComandoTeste , CRIAR_PIL_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" , &NumPilha ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 || NumPilha >= MAX_PILS || NumPilha < 0 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PIL_CriarPilhaVazia( &vPilhas[NumPilha] ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar pilha." );

         } /* fim ativa: Testar PIL Criar Pilha de cartas*/

      /* Testar PIL Push Carta na pilha */

         else if ( strcmp( ComandoTeste , PUSH_CMD ) == 0 )
         {
			
            NumLidos = LER_LerParametros( "icii" ,
                               &NumPilha, &NaipeDado , &ValorDado, &CondRetEsperada ) ;
            if ( NumLidos != 4 || NumPilha >= MAX_PILS || NumPilha < 0 )
            {
               return TST_CondRetParm ;
            } /* if */
			
			CAR_CriarCarta( &CartaDada ) ;
            CAR_PreencheCarta( CartaDada, NaipeDado , ValorDado );
			
            CondRetObtido = PIL_PushCarta( vPilhas[NumPilha] , CartaDada ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao operar 'push' na pilha" );

         } /* fim ativa: Testar PIL Push Carta na pilha */

      /* Testar PIL Pop Carta da Pilha */

         else if ( strcmp( ComandoTeste , POP_CMD ) == 0 )
         {			
            NumLidos = LER_LerParametros( "ii" ,
                               &NumPilha , &CondRetEsperada ) ;
            if ( NumLidos != 2 || NumPilha >= MAX_PILS || NumPilha < 0 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PIL_PopCarta( vPilhas[NumPilha] , &CartaObtida ) ;

			
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao operar 'pop' na pilha") ;


            } /* Testar PIL Ver Carta da Pilha */

		else if ( strcmp( ComandoTeste , VER_CMD ) == 0 )
         {
			
            NumLidos = LER_LerParametros( "iii" ,
                            &NumPilha , &PosicaoPilha , &CondRetEsperada ) ;
            if ( NumLidos != 3 || NumPilha >= MAX_PILS || NumPilha < 0 )
            {
                return TST_CondRetParm ;
            } /* if */

			 CondRetObtido = PIL_VerCarta( vPilhas[NumPilha] , &CartaObtida , PosicaoPilha ) ;
				
				
			 return TST_CompararInt( CondRetEsperada , CondRetObtido ,
						"Retorno errado ao ver carta da pilha") ;


            } /* Testar PIL Ver Carta da Pilha */

            /* Testar PIL Destruir pilha de cartas */
            else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
            {

		    NumLidos = LER_LerParametros( "ii" , &NumPilha ,  
		                       &CondRetEsperada ) ;
		    if ( NumLidos != 2 || NumPilha >= MAX_PILS || NumPilha < 0 )
		    {
		       return TST_CondRetParm ;
		    } /* if */

		    CondRetObtido = PIL_DestruirPilha( vPilhas[NumPilha] ) ;

		    return TST_CompararInt( CondRetEsperada , CondRetObtido ,
		                            "Retorno errado destruir pilha." );

	    } /* fim ativa: Testar PIL Destruir Pilha de Cartas */

	    /* Testar PIL Destruir Pilha */

        return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TPIL Efetuar opera��es de teste espec�ficas para pilha de cartas */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/
