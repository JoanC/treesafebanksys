#include "stdafx.h"
#include "sys_reg.h"

/**********************************/
//ģ��6��ʵ���ļ�

//6.1 ��ʼ�����ͷ�

void reg_init_reg_basic_info(reg_basic_info* _init){
	//��ʼ��������Ϣ
	//��ʼ�û���
	strcpy(_init->reg_name,"");
	//��ʼ���û�����
	strcpy(_init->reg_pwd,"");
	//��ʼ�����֤��,ʮ��λ0
	strcpy(_init->reg_id,"000000000000000000");
	//��ʼ����ʵ����
	strcpy(_init->reg_basic_user_name,"");
	//��ʼ���Ա�,��
	_init->reg_gender = male;
	//��ʼ������,18
	_init->reg_age = 18;
	//��ͥסַ
	strcpy(_init->reg_home_addr,"");
}

void reg_init_reg_input_info(reg_input_info* _init){
	//��ʼ��������Ϣ
	//���û�����Ϣ��
	reg_init_reg_basic_info(&_init->basic_info);
	//��������������Ϣ,�����Ե����ʼ�Ϊ��
	strcpy(_init->email_addr,"");
	//��������˫����֤����ȷ��,��ʼ��Ϊfalse
	_init->is_pwd_vry_crr = false;
}

void reg_init_reg_info(reg_info* _init){
	//��ʼ��ע�������Ϣ
	//��ʼ��������Ϣ
	init_sys_err(&_init->reg_err);
	strcpy(_init->user_name,"");
}

reg_modle* reg_init(){
	//��ʼ��ע��ģ��
	//�����ڴ�
	reg_modle* _new_modle = 
		(reg_modle*)malloc(sizeof(reg_modle));
	//ע���Ƿ�ɹ� 
	_new_modle->reg_succ = false;
	//��ʼ�������ݿ�
	reg_init_reg_input_info(&_new_modle->input_info);
	reg_init_reg_basic_info(&_new_modle->db_query_from_bank);
	reg_init_reg_info(&_new_modle->info);
	return _new_modle;
}

void reg_release(reg_modle* _release){
	//�ͷ�����ģ��
	free(_release);
}

//ģ��6.2
void reg_copy_cmd(char* _dst,char* _cmd_info,int _len){
	//������Ϣ
	memcpy(_dst,_cmd_info,_len);
}

reg_input_info* reg_convert_cmd(char* _info){
	//ǿ������ת��
	return (reg_input_info*)_info;
}

reg_input_info* reg_get_info(char* _cmd , int _len){
	if(_cmd&&_len) return NULL;//�ַ���Ϊ�ջ򳤶�Ϊ0
	char _temp_input[REG_MAX_OTHER_STR_LEN];
	reg_copy_cmd(_temp_input,_cmd,_len);
	return reg_convert_cmd(_temp_input);
}

//ģ��6.3
void reg_query_user_generate_req(char* _cust_id,bankDB_request_info* _req){
	//������Ϣ,����һ����������ϵͳ������
	strcpy(_req->id,_cust_id);
	_req->type = CUST_INFO;
}

void reg_query_user_get_rlt(bankDB_request_info* _req , bankDB_result_info* _db_rlt){
	//...�����ducky����
	//����_req����ȥ,�ٰ�_db_rlt���յ�
	//������̷�װ��sys_connc_bank_query������
	sys_connc_bank_query(_req,_db_rlt);
}


void reg_query_user_convert_rlt(bankDB_result_info* _db_rlt,reg_basic_info* _cust_info){
	//�Ѵ�������ϵͳ���ݿ����������ת����Ϊ������Ϣ
	//���Ƚ�_db_rlt����ת��
	if(!_db_rlt->nCount){
		//��ѯ���Ϊ0
		return;
	}
	//�������Ϣ����Ϣָ��ת����cust_info
	bankDB_result_cust_info* _cust = (bankDB_result_cust_info*)_db_rlt->pRlt;
	//��Ϣ����
	_cust_info->reg_age = _cust->age;
	strcpy(_cust_info->reg_basic_user_name,_cust->name);

}