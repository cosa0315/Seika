#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int point=10;//�D���x
int k=1;//�N�C�Y�̖�萔
char s[20];//�G���^�[�L�[�Ői�ނ��
char name[20];	//�v���C���[�̖��O

/*�֐��錾*/
int c_jannkenn();//C���Y�̂���񂯂�
int p_jannkenn();//�v���C���[�̂���񂯂�
void end();//�G���f�B���O
void kuizu();//�N�C�Y
void namae();//���O�ݒ�

int main(void)
{
	srand((unsigned)time(NULL));
	int a,j,p,c,mozi,ans;//���ⓚ����悤�A�����Y����񂯂�p�A�v���C���[����񂯂�p�A�����T���A�����T����
	//C���Y�����ȏЉ��
	printf("-----------------------------------------------------------\n");
	printf("                C���Y�ƗF�B�ɂȂ낤�I�̐�����\n");
	printf("�V�ѕ�\n");
	printf("    C���Y�Ƃ�����ׂ肵����A�V�񂾂肵�Ē��ǂ��Ȃ邾��\n");
	printf("    �悢�Ǝv���I������I��ōD���x���グ�悤�B\n");
	printf("C���Y�̐���\n");
	printf("    C���Y�͔���������A�r�[�����o���肵�܂��B\n");
	printf("    ����L���ŋ�������{�������񂾂肵�܂��B\n");
	printf("-----------------------------------------------------------\n");
	printf("�G���^�[�L�[�ŕ���͐i�݂܂��B\n");gets(s);
	printf(" ------------------------------\n");
	printf("| |--------------------------| |\n");
	printf("| |                          | |\n");
	printf("| |     ��           ��      | |\n");
	printf("| |     ��           ��      | |\n");
	printf("| |            ��            | |\n");
	printf("| |                          | |\n");
	printf("| ---------------------------  |\n");
	printf(" ------------------------------\n");
	
	printf("C���Y�F�ڂ�C���Y�I�����͖l�ƗF�B�ɂȂ��Ăق�����\n");gets(s);
	printf("C���Y�F�N�̖��O�͂Ȃ�Ă����́H\n���ɓ��͂����܂�\n");gets(s);
	printf("���͂��Ă��������B\n");
	//�v���C���[���O����
	//�������Œʂ�Ȃ��悤�ɂ���
	namae();
	//����1
	printf("C���Y�F���Ⴀ���ǂ��Ȃ邽�߂�%s�̂��Ƃ�m�肽����\n",name);gets(s);
	printf("C���Y�F�ڂ��̎���ɓ����Ă�\n");gets(s);
	printf("C���Y�F�Q�[���͍D���H(�P�`�R����͂��Ă�)\n�P�D�D��\n�Q�D����\n�R�D����\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("%s�F�D��\n",name);gets(s);
			printf("C���Y�F�ڂ����D���Ȃ񂾁I�I�ꏏ����\n");gets(s);//C���Y����
			point=point+1;//�D���x�̕ω�
			break;
		case 2:
			printf("%s�F����\n",name);gets(s);
			printf("C���Y�F���Ⴀ�ꏏ�ɗV��ōD���ɂȂ��Ă��炢������\n");gets(s);//C���Y����
			break;
		case 3:
			printf("%s�F����\n",name);gets(s);
			printf("C���Y�F������...\n");gets(s);//C���Y����
			printf("C���Y�F���Ⴀ�D���ɂȂ��Ă��炦��悤�ɂ܂���\n");gets(s);
			point=point-1;//�D���x�̕ω�
			break;
		
		default:
			printf("C���Y�F�P�`�R����Ȃ��I�I�I\n");gets(s);
			//�����Y�{���ăo�b�h�G���h
			point=0;
			end();
	}
	//����񂯂�1��ڂ�2���
	printf("C���Y�F�ڂ��Ƃ���񂯂񂵂悤��I\n");gets(s);
	for(j=0;j<=1;j++){
	printf("C���Y�F����[�񂯁[��\n");
	printf("�o�����I��ł��������B\n");
	printf("1.�O�[\n2.�`���L\n3.�p�[\n");
	p=p_jannkenn();
	c=c_jannkenn();
	//����񂯂񔻒�
	if(p>=4){
		printf("C���Y�F����͂₩��������\n");gets(s);
		printf("C���Y�F���߂�˂������\n");gets(s);
		j--;
	}
	else if(p==c-1 || p==c+2){
		printf("����\n");gets(s);
		printf("C���Y�F�������I�I\n");gets(s);
	}
	else if(p==c){
		printf("������\n");gets(s);
		printf("C���Y�F�����������[\n");gets(s);
	}
	
	else{
		printf("����\n");gets(s);
		printf("C���Y�F�킟\n");gets(s);
		//�����Y��т����ăo�b�h�G���h
		point=1;
		end();
	}
	}
	//����񂯂�3��ځi�K��������j
	printf("C���Y�F���Ⴀ����ōŌゾ��I\n");gets(s);
	printf("C���Y�F����[�񂯁[��\n");gets(s);
	printf("�o�����I��ł��������B�P�`�R�őI�΂Ȃ������ꍇ�����ɂȂ�܂��B\n");
	printf("1.�O�[\n2.�`���L\n3.�p�[\n");
	p_jannkenn();
	printf("C���Y\n");
	printf("        ---  ---\n");
	printf("       |   ||   |\n");
	printf("       |   ||   |\n");
	printf("       |   ||   |\n");
	printf("       |   ||   |------\n");
	printf("       |        |   |  |\n");
	printf("       |        |   |  |\n");
	printf(" -------         ------|\n");
	printf("|                      |\n");
	printf("-----------------------\n");
	printf("C���Y�F������[���Ă��[\n");gets(s);
	printf("............\n");gets(s);
	printf("C���Y�F�ǂ������́H\n");gets(s);
	printf("�P�D���≽��\n�Q�D���邵����ˁH\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("%s�F���≽��\n",name);gets(s);
			printf("C���Y�F�Ȃ�悩�����I\n");gets(s);//C���Y����
			break;
		case 2:
			printf("%s�F���邵����ˁH\n",name);gets(s);
			printf("C���Y�F���ĂȂ�����I�I\n");gets(s);//C���Y����
			//�����Y�{���ăo�b�h�G���h
			point=2;
			end();
			break;
		default:
			printf("%s�F\n",name);
			printf("C���Y�F�܂�������\n");gets(s);
	}
	//����2
	printf("C���Y�F���[�y���������B\n");gets(s);
	printf("C���Y�F�̂ǂ������Ă���������ڂ������Ȃ��������Ă��Ă���Ȃ�����\n");gets(s);
	printf("���̎O��������Ă���\n�P�D�I�����W�W���[�X\n�Q�D��\n�R�D��\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("%s�F�ǂ���\n",name);gets(s);
			printf("C���Y�F���肪�Ƃ��I�I�ڂ�����D���Ȃ񂾁I\n");gets(s);//C���Y����
			point=point+1;//�D���x�̕ω�
			break;
		case 2:
			printf("%s�F�ǂ���\n",name);gets(s);
			printf("C���Y�F���肪�Ƃ��I\n");gets(s);//C���Y����
			point=-1;//�D���x�̕ω�
			end();
			break;
		case 3:
			printf("%s�F�ǂ���\n",name);gets(s);
			printf("C���Y�F���肪�Ƃ��I\n");gets(s);//C���Y����
			
			break;
		default:
			printf("C���Y�F�P�`�R����Ȃ��I�I�I\n");gets(s);
			//�����Y�{���ăo�b�h�G���h
			point=0;
			end();
	}
	//�����T��
	printf("C���Y�F���Ⴀ���͂ڂ����������o�����炻�̒�����Ⴄ������T���Q�[������\n");gets(s);
	printf("C���Y�F���Ⴀ������I\n");gets(s);
	printf("C���Y�F����\n");gets(s);
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSS5SSSSSSSSSSSSSSSS\n");
	printf("�Ⴄ���̂���͂��Ă��������B\n");
	scanf("%d",&mozi);
	ans = 5;
	if(mozi==ans){
		printf("C���Y�F��������I\n");gets(s);
	}
	else{
		printf("C���Y�F�Ⴄ��\n");gets(s);
		point=3;
		end();
	}
	printf("C���Y�F����\n");gets(s);
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("lllllllllllllllll1ll\n");
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("llllllllllllllllllll\n");
	printf("�Ⴄ���̂���͂��Ă��������B\n");
	scanf("%d",&mozi);
	ans = 1;
	if(mozi==ans){
		printf("C���Y�F��������I\n");gets(s);
	}
	else{
		printf("C���Y�F�Ⴄ��\n");gets(s);
		point=3;
		end();
	}
	printf("0���Y�F����\n");gets(s);
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("SSSSSSSSSSSSSSSSSSSS\n");
	printf("�Ⴄ���̂���͂��Ă��������B\n");
	scanf("%d",&mozi);
	ans = 0;
	if(mozi==ans){
		printf("C���Y�F��������I\n");gets(s);
	}
	else{
		printf("C���Y�F�Ⴄ��\n");gets(s);
		point=3;
		end();
	}
	//����R
	printf("C���Y�F������y���������ˁ[\n");gets(s);
	printf("C���Y�F����������\n");
	printf("C���Y�F�ق��ɗV�ԓ������͂�������ǂꂩ�I��łق�����(�P�`�R����͂��Ă�)\n�P�D�h��Ȕ�\n�Q�D���ʂ̔�\n�R�D�n���Ȕ�\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("%s�F�����Ă�����\n",name);gets(s);
			printf("C���Y�F�J���Ă݂ā[\n");gets(s);//C���Y����
			point=-2;//�D���x�̕ω�
			end();
			break;
		case 2:
			printf("%s�F�����Ă�����\n",name);gets(s);
			printf("C���Y�F�J���Ă݂ā[\n");gets(s);//C���Y����
			printf("C���Y�F�������ۂ�������\n");gets(s);
			printf("C���Y�F����ˁ[��\n");gets(s);
			break;
		case 3:
			printf("%s�F�����Ă�����\n",name);gets(s);
			printf("C���Y�F�J���Ă݂ā[\n");gets(s);//C���Y����
			point=-3;//�D���x�̕ω�
			end();
			break;
		default:
			printf("C���Y�F�P�`�R����Ȃ��I�I�I\n");gets(s);
			//�����Y�{���ăo�b�h�G���h
			point=0;
			end();
	}
	//�N�C�Y
	printf("C���Y�F���Ⴀ���̓N�C�Y����I�I\n");gets(s);
	printf("����\n");gets(s);
	kuizu();
	printf("����\n");gets(s);
	kuizu();
	printf("��O��\n");gets(s);
	kuizu();
	//����4
	printf("C���Y�F�ڂ��ƗV�Ԃ̊y���������H�i�P�`�R�œ��͂��Ăˁj\n�P�D�y�����Ȃ�����\n");
	printf("�Q�D�y��������\n");
	printf("�R�D����\n\n");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("%s�F�y�����Ȃ�����\n",name);gets(s);
			printf("C���Y�F����Ȃ�\n");gets(s);//C���Y����
			point=point-4;//�D���x�̕ω�
			end();
			break;
		case 2:
			printf("%s�F�y��������\n",name);gets(s);
			printf("C���Y�F�悩�����I\n");gets(s);//C���Y����
			point=point+1;//�D���x�̕ω�
			break;
		case 3:
			printf("%s�F����\n",name);gets(s);
			printf("C���Y�F���[�y�����Ȃ������́[\n");gets(s);//C���Y����
			
			break;
		default:
			printf("%s�F\n",name);
			printf("C���Y�F�P�`�R����Ȃ��I�I�I\n");gets(s);
			//�����Y�{���ăo�b�h�G���h
			point=0;
			end();
	}

	//�G���f�B���O
	end();
}
//���O����
void namae()
{
	int x;
	char ctaro[20];
	strcpy(ctaro,"C���Y");
	while(x != 1){
	gets(name);
	printf("C���Y�F%s�ł����Ă��邩�ȁH\n",name);gets(s);
	printf("1.������\n");
	printf("2.�Ⴄ��\n");
	scanf("%d",&x);
	if(x==1){
		printf("C���Y�F%s��낵���ˁI\n",name);gets(s);
	}
	else{
		printf("���Ⴀ���������͂��Ă�\n");
		gets(name);
	}
	}
	if(strcmp(ctaro,name)==0){
		printf("C���Y�F�ڂ��Ɩ��O���ꏏ���ˁI\n");gets(s);
		strcpy(name,"C");
		printf("C���Y�F���������R���ˁI\n");gets(s);
		printf("C���Y�F�����ǋ�ʂ����ɂ�������N�̂��Ƃ�%s���ČĂԂ�\n",name);gets(s);
	}
}
//�v���C���[����񂯂�ŉ����o�������߂�֐�
int p_jannkenn()
{
	int you;
	scanf("%d",&you);
	printf("C���Y�F�|���I�I\n");
	printf("\n");
	printf("\n");
	printf("%s\n",name);
	if(you==1){
			printf("----------------\n");
			printf("|   |   |   |   |\n");
			printf("|   |   |   |   |\n");
			printf("----------------|\n");
			printf("|         |     |\n");
			printf("----------------\n");
			you=1;
	}
	else if(you==2){
			printf(" ---  ---\n");
			printf("|   ||   |\n");
			printf("|   ||   |\n");
			printf("|   ||   |\n");
			printf("|   ||   |------\n");
			printf("|        |   |  |\n");
			printf("|        |   |  |\n");
			printf("----------------|\n");
			printf("|         |     |\n");
			printf("----------------\n");
			you=2;
	}
	else if(you==3){
			printf("        ---  ---  ---  ---\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |                  |\n");
			printf("       |                  |\n");
			printf(" -------                  |\n");
			printf("|                         |\n");
			printf("--------------------------\n");
			you=3;
	}
	else{
		printf("�o���Ȃ�\n");
	}
	return you;
}
//c���Y����񂯂�ŉ����o���������߂�֐�
int c_jannkenn()
{
	int taro;
	taro=rand()%3;
	printf("\n");
	printf("\n");
	printf("C���Y\n");
	if(taro==1){
			printf("----------------\n");
			printf("|   |   |   |   |\n");
			printf("|   |   |   |   |\n");
			printf("----------------|\n");
			printf("|         |     |\n");
			printf("----------------\n");
			taro=1;
	}
	else if(taro==2){
			printf(" ---  ---\n");
			printf("|   ||   |\n");
			printf("|   ||   |\n");
			printf("|   ||   |\n");
			printf("|   ||   |------\n");
			printf("|        |   |  |\n");
			printf("|        |   |  |\n");
			printf("----------------|\n");
			printf("|         |     |\n");
			printf("----------------\n");
			taro=2;
	}
	else{
			printf("        ---  ---  ---  ---\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |   ||   ||   ||   |\n");
			printf("       |                  |\n");
			printf("       |                  |\n");
			printf(" -------                  |\n");
			printf("|                         |\n");
			printf("--------------------------\n");
			taro=3;
	}
	return taro;
}
//�N�C�Y�̊֐�
void kuizu()
{
	int a;
	char b[20];
	if(k==1){
		printf("C���Y�F�������|�ɂ���Ƃǂ��Ȃ�ł��傤�B�i�P�`�R�œ��͂��Ăˁj\n�P�D�����ɂȂ�\n�Q�D�ł��Ȃ�\n�R�D���̂悤�ɉ��ł��ʂ��悤�ɂȂ�\n");//�G�w
		scanf("%d",&a);//�P������
		switch(a){
		case 1:
			printf("C���Y�F��������I�I\n");gets(s);//C���Y����
			break;
		case 2:
			printf("C���Y�F�Ⴄ��\n");gets(s);//C���Y����
			point=4;//�D���x�̕ω�
			end();
			break;
		case 3:
			printf("C���Y�F�Ⴄ��\n");gets(s);//C���Y����
			point=4;//�D���x�̕ω�
			end();
			break;
		default:
			printf("C���Y�F�P�`�R����Ȃ��I�I�I\n");gets(s);
			//�����Y�{���ăo�b�h�G���h
			point=0;
			end();
	}
	k++;
	}
	else if(k==2){
		printf("C���Y�F�ʕ�����������悹���g���b�N���Ȃ���Ƃ��ɗ��Ƃ������͉̂��ł��傤�B�i�P�`�R�œ��͂��Ăˁj\n�P�D�A�{�J�h\n�Q�D�ʕ�\n�R�D�X�s�[�h\n");//�Ђ�߂�
		scanf("%d",&a);//�R������
		switch(a){
		case 1:
			printf("C���Y�F�Ⴄ��\n");gets(s);//C���Y����
			point=4;//�D���x�̕ω�
			end();
			break;
		case 2:
			printf("C���Y�F�Ⴄ��\n");gets(s);//C���Y����
			point=4;//�D���x�̕ω�
			end();
			break;
		case 3:
			printf("C���Y�F��������I�I\n");gets(s);//C���Y����
			break;
		default:
			printf("C���Y�F�P�`�R����Ȃ��I�I�I\n");gets(s);
			//�����Y�{���ăo�b�h�G���h
			point=0;
			end();
	}
	k++;
	}
	else{
		gets(b);
		system("cls");
		printf("C���Y�F�ڂ��͂ǂ�ł��傤�i�P�`�R�œ��͂��Ăˁj\n");//C���Y
			printf("   1\n");
			printf(" ------------------------------\n");
			printf("| |--------------------------| |\n");
			printf("| |                          | |\n");
			printf("| |     ��           ��      | |\n");
			printf("| |     ��           ��      | |\n");
			printf("| |            ��            | |\n");
			printf("| |                          | |\n");
			printf("| ---------------------------  |\n");
			printf(" ------------------------------\n");
			printf("   2\n");
			printf(" ------------------------------\n");
			printf("| |--------------------------| |\n");
			printf("| |                          | |\n");
			printf("| |     ��           ��      | |\n");
			printf("| |     ��           ��      | |\n");
			printf("| |            ��            | |\n");
			printf("| |                          | |\n");
			printf("| ---------------------------  |\n");
			printf(" ------------------------------\n");
			printf("   3\n");
			printf(" ------------------------------\n");
			printf("| |--------------------------| |\n");
			printf("| |                          | |\n");
			printf("| |     ��           ��      | |\n");
			printf("| |     ��           ��      | |\n");
			printf("| |            ��            | |\n");
			printf("| |                          | |\n");
			printf("| ---------------------------  |\n");
			printf(" ------------------------------\n");
			printf("C���Y�F��ɖ�肪�����\n");
			scanf("%d",&a);//�P������
		switch(a){
		case 1:
			printf("C���Y�F��������I�I\n");gets(s);//C���Y����
			break;
		case 2:
			printf("C���Y�F�Ⴄ��\n");gets(s);//C���Y����
			point=4;//�D���x�̕ω�
			end();
			break;
		case 3:
			printf("C���Y�F�Ⴄ��\n");gets(s);//C���Y����
			point=4;//�D���x�̕ω�
			end();
			break;
		default:
			printf("C���Y�F�P�`�R����Ȃ��I�I�I\n");gets(s);
			//�����Y�{���ăo�b�h�G���h
			point=0;
			end();
	}
	k++;
	}
}
//�G���f�B���O���ǂ�ɂȂ邩�𔻒f����֐�
void end()
{
	printf("*-------------------�W�v������---------------------*\n");
	printf("�D���x�F%d\n",point);
	if(point==13){
		printf("C���Y�F�Ƃ��Ă��y����������\n���ꂩ������ǂ����Ă�\n");gets(s);
		printf("�e�Fend\n");
	}
	else if(point>5){
		printf("C���Y�F�b���̊y����������[\n");gets(s);
		printf("�F�Bend\n");
	}
	else{
		switch(point){
		case 0://���͊ԈႢ
			printf("C���Y�F�G���[���������܂����B�G���[���������܂���\n");gets(s);//C���Y����
			printf("C���Y�͍������Ĕ������܂����B\n");gets(s);
			break;
		
		case 1://����񂯂񕉂�
			printf("C���Y�F����������������������[�[�[\n");gets(s);//C���Y����
			printf("C���Y�͊��ł��܂��B\n");gets(s);
			printf("��т����Ĕ������܂����B\n");gets(s);
			break;
		case -1://����~�X
			printf("C���Y�F�S�N�S�N�S�N.....\n");gets(s);//C���Y����
			printf("C���Y�F����H\n");gets(s);
			printf("C���Y�͔������܂���\n");gets(s);
			break;
		case 2://����񂯂񕉂�
			printf("C���Y�F�ڂ�����������I�I\n");gets(s);//C���Y����
			printf("C���Y���Ђ���n�߂܂���\n");gets(s);
			printf("C���Y���������܂����B\n");gets(s);
			break;
		case 3://�����T���~�X
			printf("C���Y�F�����������悤�ɂ��Ă������I�I\n");gets(s);//C���Y����
			printf("C���Y�ɉ�������܂����B\n");gets(s);
			break;
		case -2://����~�X
			printf("���ɂ͒��������Ă��܂����B");gets(s);//C���Y����
			printf("C���Y�F�킠��������\n");gets(s);
			printf("C���Y�͂т����肵�Ĕ������܂����B\n");gets(s);
			break;
		case -3://����~�X
			printf("�ق��肪��������܂��܂���\n");gets(s);//C���Y����
			printf("C���Y�F�N�V����\n");gets(s);
			printf("C���Y�͂�����݂����Ĕ����Ńr�[�����o���܂����B\n");gets(s);
			break;
		case 4://�N�C�Y�~�X
			printf("C���Y�F�ڂ��������Ă������I�I\n");gets(s);
			printf("�R���Ԃ����ƃN�C�Y��@�����܂�܂����B\n");gets(s);
			break;
		case -4://����~�X
			printf("C���Y�F���[��\n");gets(s);
			printf("C���Y�͋����~�݂܂���\n�����̒��ɐ������܂��Ă��܂���\n");gets(s);
			printf("���Ȃ��͓M��Ă��܂��܂����B\n");gets(s);
			break;
		default:
			printf("�H\n");
	}

		printf("���Send\n");
	}
	exit(1);
}