#ifndef CARD_H
#define CARD_H

#include<stdio.h>
#include<string.h>
#include<string>

using namespace std;

//フラグタイプ
typedef struct {
	unsigned int Num  : 4;
	unsigned int Type : 2;
	unsigned int Used : 1;
} flag ;

//フラグ付きカード共用体　1バイト構成
typedef union {
		flag f;
		int data;
} CardFlag ;

/*
トランプカードの定義
データは1バイトの容量に収まる。
*/
class Card{
	CardFlag tranp;
	char NoStr[2];//数字の時のみ使用。
public:

	//コンストラクター
	//引数 char型
	Card(){
		setNum(1);
		NoStr[1] = '\0';
	}

	//コンストラクター
	//引数 char型
	Card(char num){
		setNum(num);
		NoStr[1] = '\0';
	}

	//コンストラクター
	//引数 char型 カードNo,カードタイプ（'S','C','D','H'）
	Card(char num , char Type){
		setNum(num);
		NoStr[1] = '\0';
		setType(Type);
	}

	//引数 なし
	//返値 char　*　型
	//数字を￥ｎを含めた文字列（カードの文字（ A,J,Q,K ）および2ケタ）として返す。
	string getNo(){
		
		if( 1 < tranp.f.Num && tranp.f.Num < 10 ){
			NoStr[0] = tranp.f.Num + 48;
			return NoStr;
		}else{
			return getCharNo(tranp.f.Num);
		}
		return 0;
	}

	//引数  char 
	//返値　char *型
	//カードの文字（ A,J,Q,K ）および2ケタを￥ｎを含めて返す。
	string getCharNo(char num){
		switch(num){
			case 1:
				return "A";
				break;
			case 10:
				return "10";
				break;
			case 11 :
				return "J";
				break;
			case 12 :
				return "Q";
				break;
			case 13:
				return "K";
				break;
			default:break;
		}
		return 0;
	}
	
	//引数 なし
	//返値 char型
	//計算時に使用想定
	char getNum(){
		return  tranp.f.Num;
	}

	//引数 char型
	//返値 なし
	//Noのセッター
	void setNum(char num ){
		tranp.f.Num = num  ;
	}

	//引数 なし
	//返値 char型 データ（数字、タイプ、使用可）
	//dataのゲッター
	char getData(){
		return tranp.data;
	}

	//引数　なし
	//返値　char型(0：スペード,1：ダイヤ,2：クラブ,3：ハート)
	//Typeのゲッター
	short getTypeFlag(){
		return tranp.f.Type;
	}
	//引数　なし
	//返値　char型 (0：未使用,1：使用中)
	//TypeAndUsedのゲッター
	char getUsedFlag(){
		return tranp.f.Used;
	}
	//引数 なし
	//返値 char *
	//文字列を出力
	string getType(){
		char type = tranp.f.Type;
		switch(type){
			case 0:
				return "S";
				break;
			case 1: 
				return "D";
				break;
			case 2:
				return "C";
				break;
			case 3:
				return "H";
				break;
			default:
				return "NoType";
				break;
		}
		return "NoType";
	}
	//引数 char型
	//返値 なし
	//カードタイプセッター
	//指定は半角英大文字 'S' 'D' 'C' 'H'　で指定。
	//デフォルトは'S'
	void setType(char type){
		switch(type){
			case 'S':
				tranp.f.Type =  0x00;
				break;
			case 'D': 
				tranp.f.Type =  0x01;
				break;
			case 'C':
				tranp.f.Type =  0x02;
				break;
			case 'H':
				tranp.f.Type =  0x03;
				break;
			default:
				tranp.f.Type =  0x01;
				break;
		}

	}
	//引数 char型
	//返値 なし
	//カードタイプセッター
	//指定は数字( S : 0 D : 1 C : 2 H : 3 )で指定。
	//デフォルトは'S'
	void setTypeBit(char type){
		tranp.f.Type =  type;
	}
	//引数　なし
	//返値　char型 (0：未使用,1：使用中)
	//TypeAndUsedのゲッター
	void setUsedFlag(){
		tranp.f.Used = tranp.f.Used == 1 ? 0 : 1 ;
	}
};

#endif