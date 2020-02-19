#ifndef CARD_H
#define CARD_H

#include<stdio.h>
#include<string.h>
#include<string>

using namespace std;

//�t���O�^�C�v
typedef struct {
	unsigned int Num  : 4;
	unsigned int Type : 2;
	unsigned int Used : 1;
} flag ;

//�t���O�t���J�[�h���p�́@1�o�C�g�\��
typedef union {
		flag f;
		int data;
} CardFlag ;

/*
�g�����v�J�[�h�̒�`
�f�[�^��1�o�C�g�̗e�ʂɎ��܂�B
*/
class Card{
	CardFlag tranp;
	char NoStr[2];//�����̎��̂ݎg�p�B
public:

	//�R���X�g���N�^�[
	//���� char�^
	Card(){
		setNum(1);
		NoStr[1] = '\0';
	}

	//�R���X�g���N�^�[
	//���� char�^
	Card(char num){
		setNum(num);
		NoStr[1] = '\0';
	}

	//�R���X�g���N�^�[
	//���� char�^ �J�[�hNo,�J�[�h�^�C�v�i'S','C','D','H'�j
	Card(char num , char Type){
		setNum(num);
		NoStr[1] = '\0';
		setType(Type);
	}

	//���� �Ȃ�
	//�Ԓl char�@*�@�^
	//�������������܂߂�������i�J�[�h�̕����i A,J,Q,K �j�����2�P�^�j�Ƃ��ĕԂ��B
	string getNo(){
		
		if( 1 < tranp.f.Num && tranp.f.Num < 10 ){
			NoStr[0] = tranp.f.Num + 48;
			return NoStr;
		}else{
			return getCharNo(tranp.f.Num);
		}
		return 0;
	}

	//����  char 
	//�Ԓl�@char *�^
	//�J�[�h�̕����i A,J,Q,K �j�����2�P�^���������܂߂ĕԂ��B
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
	
	//���� �Ȃ�
	//�Ԓl char�^
	//�v�Z���Ɏg�p�z��
	char getNum(){
		return  tranp.f.Num;
	}

	//���� char�^
	//�Ԓl �Ȃ�
	//No�̃Z�b�^�[
	void setNum(char num ){
		tranp.f.Num = num  ;
	}

	//���� �Ȃ�
	//�Ԓl char�^ �f�[�^�i�����A�^�C�v�A�g�p�j
	//data�̃Q�b�^�[
	char getData(){
		return tranp.data;
	}

	//�����@�Ȃ�
	//�Ԓl�@char�^(0�F�X�y�[�h,1�F�_�C��,2�F�N���u,3�F�n�[�g)
	//Type�̃Q�b�^�[
	short getTypeFlag(){
		return tranp.f.Type;
	}
	//�����@�Ȃ�
	//�Ԓl�@char�^ (0�F���g�p,1�F�g�p��)
	//TypeAndUsed�̃Q�b�^�[
	char getUsedFlag(){
		return tranp.f.Used;
	}
	//���� �Ȃ�
	//�Ԓl char *
	//��������o��
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
	//���� char�^
	//�Ԓl �Ȃ�
	//�J�[�h�^�C�v�Z�b�^�[
	//�w��͔��p�p�啶�� 'S' 'D' 'C' 'H'�@�Ŏw��B
	//�f�t�H���g��'S'
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
	//���� char�^
	//�Ԓl �Ȃ�
	//�J�[�h�^�C�v�Z�b�^�[
	//�w��͐���( S : 0 D : 1 C : 2 H : 3 )�Ŏw��B
	//�f�t�H���g��'S'
	void setTypeBit(char type){
		tranp.f.Type =  type;
	}
	//�����@�Ȃ�
	//�Ԓl�@char�^ (0�F���g�p,1�F�g�p��)
	//TypeAndUsed�̃Q�b�^�[
	void setUsedFlag(){
		tranp.f.Used = tranp.f.Used == 1 ? 0 : 1 ;
	}
};

#endif