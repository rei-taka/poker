#include <stdlib.h>
#include <time.h>
#include "card.h"

class Trump{

	Card * s[13] ;
	Card * c[13] ;
	Card * h[13] ;
	Card * d[13] ;

public:

	Trump(){
		for(char i = 1 ; i <= 13 ; i++ ){
			 s[i-1] = new Card(i , 'S') ;
			 c[i-1] = new Card(i , 'C') ;
			 h[i-1] = new Card(i , 'H') ;
			 d[i-1] = new Card(i , 'D') ;
		}
	}

	//引数 char型　ntype : カードタイプ
	//返値　Card型 配列
	//引数で指定されたtypeのカードを返す。
	//カードのアクセスに使用
	Card * getCard( char  type , char num ){
		switch( type ){
			case 'S':
				return s[num];
				break;
			case 'C':
				return c[num];
				break;
			case 'H':
				return h[num];
				break;
			case 'D':
				return d[num];
				break;
		}
		return 0;
	}

	//引数 char型　ntype : カードタイプ
	//返値　Card型 配列
	//引数で指定されたtypeのカードを返す。
	//カードのアクセスに使用
	//(0：スペード,1：ダイヤ,2：クラブ,3：ハート)
	Card * getCardFT( char  type , char num ){
		switch( type ){
			case 0 :
				return s[num];
				break;
			case 1:
				return d[num];
				break;
			case 2:
				return c[num];
				break;
			case 3:
				return h[num];
				break;
		}
		return 0;
	}

};