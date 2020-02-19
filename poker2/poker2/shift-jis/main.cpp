#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"trump.h"
#include"judge.h"
#include"money.h"
#include"print.h"

int main(void){
	Trump t;
	Card * c[5];
	Print p;
	Money m;

	srand( ( unsigned int ) time( NULL ) );

	for(int i = 0 ; i < 5 ; i++ ){
		c[ i ] = t.getCardFT( rand( ) % 4 , rand( ) % 13  );
		while( c[ i ]->getUsedFlag() == 0 ){
			c[ i ] = t.getCardFT( rand( ) % 4 , rand( ) % 13  );
		}
		c[ i ]->setUsedFlag();
	}
	
	Judge j( c[0] ,c[1] ,c[2] ,c[3] ,c[4] );

	p.pronpt();
	p.moneyPrint( m.getMoney() );
	
	m.moneyChenge( p.moneyInput() , j.Status() );

	p.printJudge( j.Status());
	printf("\n");
	p.printCardFivNew( c[0] ,c[1] ,c[2] ,c[3] ,c[4] );
	printf("\n");


	for(int i = 0 ; i < 5 ; i++ ){
			c[i]->setUsedFlag();
	}
	
	while( m.getMoney() != 0 ){
		for(int i = 0 ; i < 5 ; i++ ){
			c[ i ] = t.getCardFT( rand( ) % 4 , rand( ) % 13  );
			while( c[ i ]->getUsedFlag() == 0 ){
				c[ i ] = t.getCardFT( rand( ) % 4 , rand( ) % 13  );
			}
			c[ i ]->setUsedFlag();
		}

		Judge j ( c[0] ,c[1] ,c[2] ,c[3] ,c[4] ) ;
		p.moneyPrint( m.getMoney() );
		m.moneyChenge( p.moneyInput() , j.Status() );

		p.printJudge( j.Status());
		printf("\n");
		p.printCardFivNew( c[0] ,c[1] ,c[2] ,c[3] ,c[4] );
		printf("\n");

		for(int i = 0 ; i < 5 ; i++ ){
			c[i]->setUsedFlag();
		}
	}
	return 0;
}