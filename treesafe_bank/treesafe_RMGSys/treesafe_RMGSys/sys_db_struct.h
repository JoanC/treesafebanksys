#pragma once

//��½ģ�����Ϣ��ѯ
//��½Ȩ��
//����Ա,һ���û�...
enum login_competence{
	compe_err	= -1 ,	
	compe_cust = 0 ,
	compe_operater = 1 ,
	compe_admin = 3,
	//...other competence
};


const size_t idLen			= 19 ;
const size_t pwdLen		= 16 ;
struct sys_db_login{
	char								user_id[idLen] ;
	char								login_pwd[pwdLen] ;
	login_competence		cmpt ;
};

//���µĽṹ��
//��Jiraiya���
//��;�ڸ�������ǰ����ϸ˵��

//ģ��7,8Ҫ�õ�
//��˱�
//��������Ϣ�Ӹ�����Ϣ�Ƿ���ȷ(bit)��һ��ע��
//�����������
struct sys_db_research{
	//�������ı��
	//����Ϣ��ԭʼ����(������id��)

	//����Ϣ���Ƿ���ȷ
	//...

	//ע����Ϣ(1������)
	//...
};

//ģ��9ʹ�õ�
//��ʽ��������Ϣ
struct sys_db_apply{
	//��ʽ����ı��
	//����Ϣ����������(������id��)
	//...
};