#pragma once

//��½ģ�����Ϣ��ѯ
const size_t idLen = 19 ;
const size_t pwdLen = 16 ;


//��½Ȩ��
//����Ա,һ���û�...
enum login_competence{
	compe_admin,
	compe_user
	//...other competence
};

struct sys_db_login{
	char cust_id[idLen] ;
	char login_pwd[pwdLen] ;
	bool is_employee ;
	char employee_id[idLen] ;
};