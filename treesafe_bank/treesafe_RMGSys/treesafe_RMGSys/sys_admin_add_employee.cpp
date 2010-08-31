#include "stdafx.h"
#include "sys_admin_add_employee.h"



//ģ��15 -- ����Ա��ӹ�Աģ���ʵ��

//15.1
//��ʼ��ģ��

void init_add_employee_input(add_employee_input* _init){
	//��ʼ��������Ϣ
	init_admin_employee_info(&_init->employ_basic_info);
	strcpy(_init->comment,"");//��ʼ��ע����Ϣ
}

void init_add_employee_info(add_employee_info* _init){
	//��ʼ����ӹ�Ա�Ľ����¼��Ϣ
	//��ʼ���ѳɹ�
	//��������ʱ�ŻὫ���ֵ��Ϊtrue
	_init->is_succ = true;
	//��ʼ��������Ϣ
	init_sys_err(&_init->err_info);
}

add_employee_modle* init_add_employee_modle(){
	//��ʼ����ӹ�Ա����ģ��
	//�����ڴ�..
	add_employee_modle* _new_modle = 
		(add_employee_modle*)malloc(sizeof(add_employee_modle));
	//��ʼ��ģ��
	//������Ϣ��ʼ��
	init_add_employee_input(&_new_modle->input_info);
	//�����¼��Ϣ
	init_add_employee_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_add_employee_modle(add_employee_modle* _release){
	free(_release);
}
//15.2

void add_employee_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
	//����������Ϣ
	memcpy(_dest,_cmd,_cmd_len);
}

add_employee_input* add_employee_convert_cmd(char* _info){
	//ת�������Ϊ��������
	add_employee_input* _new_info = (add_employee_input*)_info;

	//�������Ľ���utf7����
	DECODE_UTF7_TO_ASC(_new_info->comment);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_addr);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_email);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_id);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_name);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_tel);
	DECODE_UTF7_TO_ASC(_new_info->employ_basic_info.employee_work_id);
	return _new_info;
}

add_employee_input* add_employee_get_cmd(const char* _cmd,int _cmd_len){
	//ת�����Ҹ���ָ��
	char* _info = (char*)malloc(_cmd_len);
	//��������
	add_employee_copy_cmd(_cmd,_info,_cmd_len);
	//ת��ָ��
	return add_employee_convert_cmd(_info);
}

//15.3
void add_employee_to_db(add_employee_input* _input_info, bool *_rlt)
{
	*_rlt = add_new_employee(treesafe_db_connection,&(_input_info->employ_basic_info),_input_info->comment) ;
//	reg_basic_info _info_add_to_login ;
//	_info_add_to_login.reg_id = _input_info->employ_basic_info.employee_id ;

}

//15.4
void add_employee_covert_result(add_employee_info* _info
	,char* _rlt , int* _rlt_len){
	memcpy(_rlt,_info,sizeof(add_employee_info));
	*_rlt_len = sizeof(add_employee_info);
}


//ģ��15������ʽ
void add_employee_frame(const char* _cmd , int _cmd_len
	,char* _rlt , int* _rlt_len){
	//15.1
	//��ʼ��ģ��
	add_employee_modle* _new_frame = init_add_employee_modle();
	//15.2
	//����ָ����Ϣ
	_new_frame->input_info = *add_employee_get_cmd(_cmd,_cmd_len);
	//15.3
	//...
	bool _db_rlt = false;
	add_employee_to_db(&_new_frame->input_info,&_db_rlt);

	//15.4
	add_employee_covert_result(&_new_frame->rlt_info,_rlt,_rlt_len);

	//�ͷ�ģ��
	release_add_employee_modle(_new_frame);
}