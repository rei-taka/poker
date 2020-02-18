
class Money{
	//所持金
	int money;
public :

	Money(){
		money = 1000;
	}

	//マネーゲッター
	int getMoney(){
		return this->money;
	}

	//配当
	//引数　：掛け金		int型
	//返値　：入力の成功	bool型 ( true false)
	bool moneyChenge(int money , char judge ){
		if( this->money >= money ){
			this->money -= money;
			switch( judge ){
				case 0 :
					money *= 0;
					break;
				case 1 ://ワンペア
					money *= 1;
					break;
				case 2 ://ツーペア
					money *= 5;
					break;
				case 3 ://スリー・オブ・ア・カインド
					money *= 7;
					break;
				case 4 ://ストレート
					money *= 10;
					break;
				case 5 ://フラッシュ
					money *= 200;
					break;
				case 6 ://フルハウス
					money *= 1000;
					break;
				case 7 ://フォー・オブ・ア・カインド
					money *= 2000;
					break;
				case 8 ://ストレートフラッシュ
					money *= 10000;

					break;
				case 9 ://ロイヤルストレートフラッシュ
					money *= 1000000;
					break;
				default:
					break;
			}
			this->money += money;
			return true;
		}else{
			return false;
		}
	}

};