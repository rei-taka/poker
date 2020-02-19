#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"card.h"
using namespace std;

#define CARD_FIV_New  "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n��%s����%s����%s����%s����%s��\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n��%s����%s����%s����%s����%s��\n������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"

typedef struct  TypePrint{
		string row[7];
}TP;

class Print{
	TP  typePrint[4];
public:

	Print(){
		typePrint[0].row[0] = "��       *        ��";
		typePrint[0].row[1] = "��      ***       ��";
		typePrint[0].row[2] = "��     *****      ��";
		typePrint[0].row[3] = "��    *******     ��";
		typePrint[0].row[4] = "��   *********    ��";
		typePrint[0].row[5] = "��   *** * ***    ��";
		typePrint[0].row[6] = "��      ***       ��";

		typePrint[1].row[0] = "��       *        ��";
		typePrint[1].row[1] = "��      ***       ��";
		typePrint[1].row[2] = "��     *****      ��";
		typePrint[1].row[3] = "��    *******     ��";
		typePrint[1].row[4] = "��     *****      ��";
		typePrint[1].row[5] = "��      ***       ��";
		typePrint[1].row[6] = "��       *        ��";

		typePrint[2].row[0] = "��      ***       ��";
		typePrint[2].row[1] = "��     *****      ��";
		typePrint[2].row[2] = "��     *****      ��";
		typePrint[2].row[3] = "��  ***  *  ***   ��";
		typePrint[2].row[4] = "�� *************  ��";
		typePrint[2].row[5] = "��  ***  *  ***   ��";
		typePrint[2].row[6] = "��      ***       ��";

		typePrint[3].row[0] = "��   ***   ***    ��";
		typePrint[3].row[1] = "��  ***** *****   ��";
		typePrint[3].row[2] = "��   *********    ��";
		typePrint[3].row[3] = "��    *******     ��";
		typePrint[3].row[4] = "��     *****      ��";
		typePrint[3].row[5] = "��      ***       ��";
		typePrint[3].row[6] = "��       *        ��";
	}

	/*	
	�J�[�h�̋󔒂𒲐�����B
	�����̕������������������󔒂�����B
	�Ԓl�@�F�@char�@*�@�^�@
	�����@�F�@ss �󔒂��蕶����|�C���^�[�A�@s �����镶����A�@ForB ���l�߁i'f'�j�E�l�߁i'b'�j�w��	
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
	�J�[�h�̋󔒂𒲐�����B
	�����̕������������������󔒂�����B
	�Ԓl�@�F�@char�@*�@�^�@
	�����@�F�@ss �󔒂��蕶����|�C���^�[�A�@s �����镶����A�@ForB ���l�߁i'f'�j�E�l�߁i'b'�j�w��	
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
	
	//���� Card * �^
	//�Ԓl string �^ 
	//�J�[�h�̎�ނɌ��������������Ԃ��B
	//( 0:�X�y�[�h 1:�_�C�� 2:�N���u 3:�n�[�g)
	string charOfType( Card * c ,char num ){
		return typePrint[ c->getTypeFlag() ].row[ num - 1 ];
	}

	//�J�[�h�ܖ��̕\��
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

	//�W���b�W�̕\��
	//( 0:�n�C�J�[�h	1:�����y�A		2:�c�[�y�A		3:�X���[�E�I�u�E�A�E�J�C���h
	//	4:�X�g���[�g	5:�t���b�V��	6:�t���n�E�X	7:�t�H�[�E�I�u�E�A�E�J�C���h 
	//	8:�X�g���[�g�t���b�V��		9:���C�����X�g���[�g�t���b�V�� )
	void printJudge(char judge){
		
		switch( judge ){
			case 0 :
				printf("�n�C�J�[�h");
				break;
			case 1 :
				printf("�����y�A");
				break;
			case 2 :
				printf("�c�[�y�A");
				break;
			case 3 :
				printf("�X���[�E�I�u�E�A�E�J�C���h");
				break;
			case 4 :
				printf("�X�g���[�g");
				break;
			case 5 :
				printf("�t���b�V��");
				break;
			case 6 :
				printf("�t���n�E�X");
				break;
			case 7 :
				printf("�t�H�[�E�I�u�E�A�E�J�C���h");
				break;
			case 8 :
				printf("�X�g���[�g�t���b�V��");
				break;
			case 9 :
				printf("���C�����X�g���[�g�t���b�V��");
				break;
			default:
				break;
		}

	}

	//�����\��
	void pronpt(){
		printf("�悤�����B\n");
		printf("�|�[�J�[�Q�[�����n�߂܂��B\n");
	}

	//���z�̓���
	//���� �Ȃ�
	//�Ԓl int�^ �|����
	int moneyInput(){
		int money ;
		
		printf("�|��������͂��Ă��������F");
		while( scanf("%d",&money) == EOF ){
			printf("�|��������͂��Ă��������F");
		}
		return money;
	}

	//�������̕\��
	//���� int�^ ������
	//�Ԓl �Ȃ�
	void moneyPrint(int money){
		printf("������ : %d\n" ,money);
	}

	void printErr(){
		printf(" �G���[�ł��B\n");
	}


	void printErr(char *s){
		printf("%s �G���[�ł��B\n",s);
	}
};