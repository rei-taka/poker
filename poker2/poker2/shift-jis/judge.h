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
		
		//�����l�ݒ�
		for(int i = 0 ; i < 13 ; i++ ){
			cardCount[ i ] = 0 ;
		}
		for(int i = 0 ; i < 4 ; i++ ){
			typeCount[ i ] = 0 ;
		}
		//���������̃J�[�h�A�����^�C�v�̃J�[�h�̖����𐔂���B
		for(int i = 0 ; i < 5  ; i++){
			cardCounter( card[ i ].getNum( ) );
			typeCounter( card[ i ].getTypeFlag( ) );
		}
		Search();
		//�W���b�W����
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

	//���̕\��
	//( 0:�n�C�J�[�h	1:�����y�A		2:�c�[�y�A		3:�X���[�E�I�u�E�A�E�J�C���h
	//	4:�X�g���[�g	5:�t���b�V��	6:�t���n�E�X	7:�t�H�[�E�I�u�E�A�E�J�C���h 
	//	8:�X�g���[�g�t���b�V��		9:���C�����X�g���[�g�t���b�V�� )
	char Status(void){
		return jd.f.judgeType;
	}

	//���� �Ȃ�
	//�Ԓl int�^
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

	//���� �Ȃ�
	//�Ԓl int�^ 
	//
	bool pair( void ){	
		if( cardCount[ pairId[ 0 ] ] == 2 && cardCount[ pairId[ 1 ] ] < 2 ){
			return true;
		}
		return false ;
	}

	//���� �Ȃ�
	//�Ԓl bool�^ 
	//�c�[�y�A���ۂ�
	bool twoPairIs( void ){	
		return   cardCount[ pairId[ 0 ] ] == 2 && cardCount[ pairId[ 1 ] ] == 2 ? true : false ;
	}
	char * debagPairId(){
		return pairId;
	}
	char * debagCardCount(){
		return cardCount;
	}
	//���� �Ȃ�
	//�Ԓl bool�^ 
	//�X���[�J�[�h���ۂ�
	bool thrOfCardIs( void ){	
		return cardCount[ pairId[ 0 ] ] == 3 &&  cardCount[ pairId[ 1 ] ] != 2 ? true : false; 
	}

	//���� �Ȃ�
	//�Ԓl bool�^ 
	//�t�H�[�I�u�A�J�C���h���ۂ�
	bool forOfCardIs( void ){	
		return cardCount[ pairId[ 0 ] ] == 4 ? true : false; 
	}
	//���� �Ȃ�
	//�Ԓl bool�^
	//�t���n�E�X���ǂ�����Ԃ��B( true : �t���n�E�X false : �t���n�E�X�ł͂Ȃ� )
	bool fullHouseIs( void ){	
		if(cardCount[ pairId[ 0 ] ] == 2 && cardCount[ pairId[ 1 ] ] == 3){
			return true;
		}
			return cardCount[ pairId[ 0 ] ] == 3 && cardCount[ pairId[ 1 ] ] == 2 ? true : false;
	}
	//���� �Ȃ�
	//�Ԓl bool�^
	//�t���b�V�����ǂ�����Ԃ��B( true : �t���b�V�� false : �t���b�V���ł͂Ȃ� )
	bool flushIs( void ){
		for(int i = 0 ; i < 4 ; i++){
			if(typeCount[ i ] == 5)return true;
		}
		return false;
	}

	//���� �Ȃ�
	//�Ԓl bool�^
	//�X�g���[�g���ǂ�����Ԃ��B( true : �X�g���[�g false : �X�g���[�g�ł͂Ȃ� )
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
	//���� �Ȃ�
	//�Ԓl bool�^
	//�X�g���[�g���ǂ�����Ԃ��B( true : �X�g���[�g false : �X�g���[�g�ł͂Ȃ� )
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