#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"card.h"
using namespace std;

#define CARD_FIV_New  "┏━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━┓\n┃%s┃┃%s┃┃%s┃┃%s┃┃%s┃\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n┃%s┃┃%s┃┃%s┃┃%s┃┃%s┃\n┗━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━┛\n"

typedef struct  TypePrint{
		string row[7];
}TP;

class Print{
	TP  typePrint[4];
public:

	Print(){
		typePrint[0].row[0] = "┃       *        ┃";
		typePrint[0].row[1] = "┃      ***       ┃";
		typePrint[0].row[2] = "┃     *****      ┃";
		typePrint[0].row[3] = "┃    *******     ┃";
		typePrint[0].row[4] = "┃   *********    ┃";
		typePrint[0].row[5] = "┃   *** * ***    ┃";
		typePrint[0].row[6] = "┃      ***       ┃";

		typePrint[1].row[0] = "┃       *        ┃";
		typePrint[1].row[1] = "┃      ***       ┃";
		typePrint[1].row[2] = "┃     *****      ┃";
		typePrint[1].row[3] = "┃    *******     ┃";
		typePrint[1].row[4] = "┃     *****      ┃";
		typePrint[1].row[5] = "┃      ***       ┃";
		typePrint[1].row[6] = "┃       *        ┃";

		typePrint[2].row[0] = "┃      ***       ┃";
		typePrint[2].row[1] = "┃     *****      ┃";
		typePrint[2].row[2] = "┃     *****      ┃";
		typePrint[2].row[3] = "┃  ***  *  ***   ┃";
		typePrint[2].row[4] = "┃ *************  ┃";
		typePrint[2].row[5] = "┃  ***  *  ***   ┃";
		typePrint[2].row[6] = "┃      ***       ┃";

		typePrint[3].row[0] = "┃   ***   ***    ┃";
		typePrint[3].row[1] = "┃  ***** *****   ┃";
		typePrint[3].row[2] = "┃   *********    ┃";
		typePrint[3].row[3] = "┃    *******     ┃";
		typePrint[3].row[4] = "┃     *****      ┃";
		typePrint[3].row[5] = "┃      ***       ┃";
		typePrint[3].row[6] = "┃       *        ┃";
	}

	/*	
	カードの空白を調整する。
	引数の文字数を差し引いた空白を入れる。
	返値　：　char　*　型　
	引数　：　ss 空白いり文字列ポインター、　s 加える文字列、　ForB 左詰め（'f'）右詰め（'b'）指定	
	*/
	char * Copy(char * ss,  char * srt, char ForB ){
		int Scount;
		int Ncount = 10;

		Scount = strlen(srt);

		switch(ForB){

			case 'f':
				strncpy(ss,srt,Scount);
				break;
			case 'b':				
				strncpy(ss + ( Ncount - Scount ) ,srt,Scount);
				break;
			default:
				strcpy(ss,"");
				break;
		}
		return ss;
	}

	/*	
	カードの空白を調整する。
	引数の文字数を差し引いた空白を入れる。
	返値　：　char　*　型　
	引数　：　ss 空白いり文字列ポインター、　s 加える文字列、　ForB 左詰め（'f'）右詰め（'b'）指定	
	*/
	char * Copy2(char * ss,  string srt, char ForB ){
		int Scount;
		int Ncount = 16;

		Scount = srt.length();

		switch(ForB){

			case 'f':
				strncpy(ss,srt.c_str(),Scount);
				break;
			case 'b':				
				strncpy(ss + ( Ncount - Scount ) ,srt.c_str(),Scount);
				break;
			default:
				strcpy(ss,"");
				break;
		}

		return ss;
	}
	
	//引数 Card * 型
	//返値 string 型 
	//カードの種類に見合った文字列を返す。
	//( 0:スペード 1:ダイヤ 2:クラブ 3:ハート)
	string charOfType( Card * c ,char num ){
		return typePrint[ c->getTypeFlag() ].row[ num - 1 ];
	}

	//カード五枚の表示
	void printCardFivNew(Card *c1,Card *c2,Card *c3,Card *c4,Card *c5){
		char ssf1[16+1] = "                ";
		char ssb1[16+1] = "                ";
		char ssf2[16+1] = "                ";
		char ssb2[16+1] = "                ";
		char ssf3[16+1] = "                ";
		char ssb3[16+1] = "                ";
		char ssf4[16+1] = "                ";
		char ssb4[16+1] = "                ";
		char ssf5[16+1] = "                ";
		char ssb5[16+1] = "                ";

		printf( CARD_FIV_New	,Copy2(ssf1,c1->getNo(),'f') ,Copy2(ssf2,c2->getNo(),'f'),Copy2(ssf3,c3->getNo(),'f')  ,Copy2(ssf4,c4->getNo(),'f') ,Copy2(ssf5,c5->getNo(),'f')
								,charOfType(c1, 1 ).c_str()  		 ,charOfType(c2, 1).c_str()			,charOfType(c3, 1).c_str()		,charOfType(c4, 1).c_str() 		,charOfType(c5, 1).c_str()
								,charOfType(c1, 2 ).c_str()			 ,charOfType(c2, 2).c_str()			,charOfType(c3, 2).c_str()		,charOfType(c4, 2).c_str()		,charOfType(c5, 2).c_str()
								,charOfType(c1, 3 ).c_str()			 ,charOfType(c2, 3).c_str()			,charOfType(c3, 3).c_str()		,charOfType(c4, 3).c_str()		,charOfType(c5, 3).c_str()
								,charOfType(c1, 4 ).c_str()			 ,charOfType(c2, 4).c_str()			,charOfType(c3, 4).c_str()		,charOfType(c4, 4).c_str()		,charOfType(c5, 4).c_str()
								,charOfType(c1, 5 ).c_str()			 ,charOfType(c2, 5).c_str()			,charOfType(c3, 5).c_str()		,charOfType(c4, 5).c_str()		,charOfType(c5, 5).c_str()
								,charOfType(c1, 6 ).c_str()			 ,charOfType(c2, 6).c_str()			,charOfType(c3, 6).c_str()		,charOfType(c4, 6).c_str()		,charOfType(c5, 6).c_str()
								,charOfType(c1, 7 ).c_str() 		 ,charOfType(c2, 7).c_str()			,charOfType(c3, 7).c_str()		,charOfType(c4, 7).c_str()		,charOfType(c5, 7).c_str()
								,Copy2(ssb1,c1->getNo(),'b') ,Copy2(ssb2,c2->getNo(),'b'),Copy2(ssb3,c3->getNo(),'b'),Copy2(ssb4,c4->getNo(),'b'),Copy2(ssb5,c5->getNo(),'b') );
	}

	//ジャッジの表示
	//( 0:ハイカード	1:ワンペア		2:ツーペア		3:スリー・オブ・ア・カインド
	//	4:ストレート	5:フラッシュ	6:フルハウス	7:フォー・オブ・ア・カインド 
	//	8:ストレートフラッシュ		9:ロイヤルストレートフラッシュ )
	void printJudge(char judge){
		
		switch( judge ){
			case 0 :
				printf("ハイカード");
				break;
			case 1 :
				printf("ワンペア");
				break;
			case 2 :
				printf("ツーペア");
				break;
			case 3 :
				printf("スリー・オブ・ア・カインド");
				break;
			case 4 :
				printf("ストレート");
				break;
			case 5 :
				printf("フラッシュ");
				break;
			case 6 :
				printf("フルハウス");
				break;
			case 7 :
				printf("フォー・オブ・ア・カインド");
				break;
			case 8 :
				printf("ストレートフラッシュ");
				break;
			case 9 :
				printf("ロイヤルストレートフラッシュ");
				break;
			default:
				break;
		}

	}

	//初期表示
	void pronpt(){
		printf("ようこそ。\n");
		printf("ポーカーゲームを始めます。\n");
	}

	//金額の入力
	//引数 なし
	//返値 int型 掛け金
	int moneyInput(){
		int money ;
		
		printf("掛け金を入力してください：");
		while( scanf("%d",&money) == EOF ){
			printf("掛け金を入力してください：");
		}
		return money;
	}

	//所持金の表示
	//引数 int型 所持金
	//返値 なし
	void moneyPrint(int money){
		printf("所持金 : %d\n" ,money);
	}

	void printErr(){
		printf(" エラーです。\n");
	}


	void printErr(char *s){
		printf("%s エラーです。\n",s);
	}
};