
class Money{
	//������
	int money;
public :

	Money(){
		money = 1000;
	}

	//�}�l�[�Q�b�^�[
	int getMoney(){
		return this->money;
	}

	//�z��
	//�����@�F�|����		int�^
	//�Ԓl�@�F���͂̐���	bool�^ ( true false)
	bool moneyChenge(int money , char judge ){
		if( this->money >= money ){
			this->money -= money;
			switch( judge ){
				case 0 :
					money *= 0;
					break;
				case 1 ://�����y�A
					money *= 1;
					break;
				case 2 ://�c�[�y�A
					money *= 5;
					break;
				case 3 ://�X���[�E�I�u�E�A�E�J�C���h
					money *= 7;
					break;
				case 4 ://�X�g���[�g
					money *= 10;
					break;
				case 5 ://�t���b�V��
					money *= 200;
					break;
				case 6 ://�t���n�E�X
					money *= 1000;
					break;
				case 7 ://�t�H�[�E�I�u�E�A�E�J�C���h
					money *= 2000;
					break;
				case 8 ://�X�g���[�g�t���b�V��
					money *= 10000;

					break;
				case 9 ://���C�����X�g���[�g�t���b�V��
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