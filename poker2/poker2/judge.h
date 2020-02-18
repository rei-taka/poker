#pragma once
#include"card.h"

typedef struct JudgeFlug{
	unsigned char judgeType : 4;
	unsigned char HighNum: 4;

} jf;

typedef union JudgeData{
	char data ;
	jf f;
}JudgeData;
/*
enum Status { 

	HIGH_C,
	ONE_P,
	TWO_P,
	THR_C,
	STRAIGHT,
	FLUSH,
	FULLHOUSE,
	FOR_C,
	STR_FLUSH,
	L_STR_FLUSH,

} Status ;
*/
class Judge {
	Card  card[ 5 ];
	char cardCount[13];
	char pairId[2];
	char typeCount[4];
	JudgeData jd;

public :

	Judge( Card * c1 ,Card * c2 ,Card * c3 ,Card * c4 ,Card * c5 ){
		card[ 0 ] = * c1;
		card[ 1 ] = * c2;
		card[ 2 ] = * c3;
		card[ 3 ] = * c4;
		card[ 4 ] = * c5;
		
		//初期値設定
		for(int i = 0 ; i < 13 ; i++ ){
			cardCount[ i ] = 0 ;
		}
		for(int i = 0 ; i < 4 ; i++ ){
			typeCount[ i ] = 0 ;
		}
		//同じ数字のカード、同じタイプのカードの枚数を数える。
		for(int i = 0 ; i < 5  ; i++){
			cardCounter( card[ i ].getNum( ) );
			typeCounter( card[ i ].getTypeFlag( ) );
		}
		Search();
		//ジャッジする
		if( straightFlushIs() ){
			jd.f.judgeType = 8;
		}else if( forOfCardIs() ){
			jd.f.judgeType = 7;
		}else if( fullHouseIs() ){
			jd.f.judgeType = 6;
		}else if( flushIs() ){
			jd.f.judgeType = 5;
		}else if( straightIs() ){
			jd.f.judgeType = 4;
		}else if( thrOfCardIs() ){
			jd.f.judgeType = 3;
		}else if( twoPairIs() ){
			jd.f.judgeType = 2;
		}else if( pair() ){
			jd.f.judgeType = 1;
		}else{
			jd.f.judgeType = 0;
		}
	}

	//役の表示
	//( 0:ハイカード	1:ワンペア		2:ツーペア		3:スリー・オブ・ア・カインド
	//	4:ストレート	5:フラッシュ	6:フルハウス	7:フォー・オブ・ア・カインド 
	//	8:ストレートフラッシュ		9:ロイヤルストレートフラッシュ )
	char Status(void){
		return jd.f.judgeType;
	}

	//引数 なし
	//返値 int型
	void Search( void ){	
		char num = 0;

		for( char i = 0 ; i < 2 ; i++ ){
			pairId[ i ] = -1 ;
		}

		for( char i = 0 ; i < 13 ; i++){
			if(  2 <= cardCount[ i ] ){
				pairId[ num ] =  i ;
				num++;				
			}
		}
	}

	//引数 なし
	//返値 int型 
	//
	bool pair( void ){	
		if( cardCount[ pairId[ 0 ] ] == 2 && cardCount[ pairId[ 1 ] ] < 2 ){
			return true;
		}
		return false ;
	}

	//引数 なし
	//返値 bool型 
	//ツーペアか否か
	bool twoPairIs( void ){	
		return   cardCount[ pairId[ 0 ] ] == 2 && cardCount[ pairId[ 1 ] ] == 2 ? true : false ;
	}
	char * debagPairId(){
		return pairId;
	}
	char * debagCardCount(){
		return cardCount;
	}
	//引数 なし
	//返値 bool型 
	//スリーカードか否か
	bool thrOfCardIs( void ){	
		return cardCount[ pairId[ 0 ] ] == 3 &&  cardCount[ pairId[ 1 ] ] != 2 ? true : false; 
	}

	//引数 なし
	//返値 bool型 
	//フォーオブアカインドか否か
	bool forOfCardIs( void ){	
		return cardCount[ pairId[ 0 ] ] == 4 ? true : false; 
	}
	//引数 なし
	//返値 bool型
	//フルハウスかどうかを返す。( true : フルハウス false : フルハウスではない )
	bool fullHouseIs( void ){	
		if(cardCount[ pairId[ 0 ] ] == 2 && cardCount[ pairId[ 1 ] ] == 3){
			return true;
		}
			return cardCount[ pairId[ 0 ] ] == 3 && cardCount[ pairId[ 1 ] ] == 2 ? true : false;
	}
	//引数 なし
	//返値 bool型
	//フラッシュかどうかを返す。( true : フラッシュ false : フラッシュではない )
	bool flushIs( void ){
		for(int i = 0 ; i < 4 ; i++){
			if(typeCount[ i ] == 5)return true;
		}
		return false;
	}

	//引数 なし
	//返値 bool型
	//ストレートかどうかを返す。( true : ストレート false : ストレートではない )
	bool straightIs(){
		char count = 0;
		for( int i = 0 ; i < 12 ; i++ ){
			if( cardCount[ i ] == cardCount[ i + 1 ] && cardCount[ i ] == 1  ){
				count++;
			}	
		}
		if( count == 4 ){
			return true;
		}
		return false;
	}
	//引数 なし
	//返値 bool型
	//ストレートかどうかを返す。( true : ストレート false : ストレートではない )
	bool straightFlushIs(){
		return straightIs() && flushIs() ?  true : false;
	}

	void cardCounter(char num){
		if( 0 < num){
			cardCount[ num - 1 ]++;
		}
	}

	char  cardCounter2(char num){
		return cardCount[num];
	}

	void typeCounter(char num){
		typeCount[ num ]++;
	}

};