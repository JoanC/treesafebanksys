#include "stdafx.h"
#include "sys_employee_query.h"

//ģ��19��ʵ���ļ�
extern _ConnectionPtr* treesafe_db_connection ; 

//19.1
//����������Ϣ
void init_employee_query_input_info(employee_query_input_info* _init){
DEBUG_EMPLOYEE_QUERY_PRINT("init_employee_query_input_info\n");
	strcpy(_init->work_id,"");
}


void init_employee_query_info(employee_query_info* _init){
DEBUG_EMPLOYEE_QUERY_PRINT("init_employee_query_info\n");
	//��ʼ����Ա��Ϣ
	init_admin_employee_info(&_init->query_data);
	//��ʼ��������Ϣ
	init_sys_err(&_init->err_info);
}

employee_query_modle* init_employee_query_modle(){ 
DEBUG_EMPLOYEE_QUERY_PRINT("init_employee_query_modle\n");
	//���ٲ���ʼ��ģ��
	employee_query_modle* _new_modle
		= (employee_query_modle*)malloc(sizeof(employee_query_modle));
	//��ʼ����������ģ��
	//��ʼ������ģ��
	init_employee_query_input_info(&_new_modle->input_info);
	//��ʼ�������Ϣ
	init_employee_query_info(&_new_modle->rlt_info);
	//���ؽ��ָ��
	return _new_modle;
}

void release_employee_query_modle(employee_query_modle* _release){
DEBUG_EMPLOYEE_QUERY_PRINT("release_employee_query_modle\n");
	free(_release);
}

//19.2

void employee_query_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
DEBUG_EMPLOYEE_QUERY_PRINT("employee_query_copy_cmd\n");
		//��������
		memcpy(_dest,_cmd,_cmd_len);
}

employee_query_input_info* employee_query_convert_cmd(char* _info){
DEBUG_EMPLOYEE_QUERY_PRINT("employee_query_convert_cmd\n");
	//������ת��Ϊ������Ϣ
	return (employee_query_input_info*)_info;
}

employee_query_input_info* employee_query_get_cmd(const char* _cmd
	,int _cmd_len){
DEBUG_EMPLOYEE_QUERY_PRINT("employee_query_get_cmd\n");
		//19.2����ʽ
		//���ٿռ�
		char* _new_info = 
			(char*)malloc(_cmd_len);
		//����
		employee_query_copy_cmd(_cmd,_new_info,_cmd_len);
		//ת��
		return employee_query_convert_cmd(_new_info);
}

//19.3
void employee_query_get_data(const char* _work_id
	,employee_query_data* _info,bool* _rlt)
{
DEBUG_EMPLOYEE_QUERY_PRINT("employee_query_get_data\n");
	//�ַ����ĸ���
	strcpy(_info->employee_id,_work_id);
	*_rlt = Get_emplo_info_by_card_id(treesafe_db_connection,_info) ;
}

//19.4
void employee_query_convert_rlt(employee_query_info* _info,
	char* _rlt , int* _rlt_len){
DEBUG_EMPLOYEE_QUERY_PRINT("employee_query_convert_rlt\n");
	   //ת�����
	   *_rlt_len = sizeof(employee_query_info);
	   //���ƽ����Ϣ
	   memcpy(_rlt,_info,*_rlt_len);
}

//ģ��19������ʽ
void employee_query_frame(const char* _cmd , int _cmd_len
	,char* _rlt,int* _rlt_len){
DEBUG_EMPLOYEE_QUERY_PRINT("employee_query_frame\n");
		//�½�����ʼ��ģ��
		//19.1
		employee_query_modle* _frame_modle
			= init_employee_query_modle();
		//19.2
		_frame_modle->input_info = *employee_query_get_cmd(_cmd,_cmd_len);
		//19.3...
		bool _is_db_corr = false;
		employee_query_get_data(_frame_modle->input_info.work_id,
			&_frame_modle->rlt_info.query_data,&_is_db_corr);
		//19.4
		employee_query_convert_rlt(&_frame_modle->rlt_info,_rlt,_rlt_len);
		//�ͷ�ģ��
		release_employee_query_modle(_frame_modle);
}