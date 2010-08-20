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
#ifdef TEST_REG_MODLE
	//���ǲ��Դ����
	_db_rlt->nCount = 0;
	//strcpy((char*)_db_rlt->pRlt,"");
#endif
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
	//��Ϣ����,��������Ϣ
	//��������Ľṹ�����������û�����Ļ�����Ϣ���бȶԵ�
	//��Ҫ�ȶԵ���Ϣ��������,����,�Ա�
	//����
	strcpy(_cust_info->reg_basic_user_name,_cust->name);
	//���֤����
	strcpy(_cust_info->reg_id , _cust->id);
	//����
	_cust_info->reg_age = _cust->age;
	//�Ա�
	_cust_info->reg_gender = _cust->gend ? male : female;
	//��ͥסַ
	//...��ͥסַ���ñȽ�
	//strcpy(_cust_info->reg_home_addr,_cust->home_addr);
}

void reg_query_user(char* _query_id,reg_basic_info* _rlt_cust_info){
	//ģ��6.3������ʽ
	//����Ϊ����ͽ���Ľṹ�������ڴ�
	bankDB_request_info* _req = 
		(bankDB_request_info*)malloc(sizeof(bankDB_request_info));
	bankDB_result_info* _rlt = 
		(bankDB_result_info*)malloc(sizeof(bankDB_result_info));
	//������Ӧ��������Ϣ
	reg_query_user_generate_req(_query_id,_req);
	//��ѯ
	reg_query_user_get_rlt(_req,_rlt);
	//ת��
	reg_query_user_convert_rlt(_rlt,_rlt_cust_info);
	//�ͷ��ڴ�
	free(_req);
	free(_rlt);
}

bool reg_info_cmp(reg_basic_info* _input,reg_basic_info* _bank_data){
	//��Ϣ��֤
	//�ȶ�����,����,�Ա�
	if(_input->reg_age != _bank_data->reg_age) return false;
	if(strcmp(_input->reg_basic_user_name,_bank_data->reg_basic_user_name) != 0)
		return false;
	if(_input->reg_gender != _bank_data->reg_gender) return false;
	return true;
}

//ģ��6.5
void reg_add_user_to_db(reg_input_info* _info){
	//����basic��Ϣ,�Ѹ��û��������ݿ���
	//...��sunniʵ��
}

//6.6
//ע�������,�������Ϣת���ɽ�Ҫ���͵���Ϣ
void reg_generate_result(reg_modle* _mld , char* _rlt , int* _rlt_len){
	if(_mld->info.reg_err.type == err_no_err)
		reg_summery_rlt_data(_mld);//����ģ���е�����
	//���ƽ��,ģ���ͷź�,��������������紫���
	memcpy(_rlt,&_mld->info,sizeof(reg_info));
	//�����Ϣ
	*_rlt_len = sizeof(reg_info);
}
void reg_summery_rlt_data(reg_modle* _mld){
	//����Ҫ���͸���ҳ�˵�����
	//������Ϣ�Ѿ�����������������
	strcpy(_mld->info.user_name,_mld->input_info.basic_info.reg_id);
	//...����(�����)
}

//6.7
void reg_error_compute(sys_err_type _type , reg_modle* _modle){
	_modle->reg_succ = false;
	//���Ҵ�����Ϣ
	_modle->info.reg_err.type = _type;
	sys_err_search(&_modle->info.reg_err);
}

void reg_frame(char* _command , int _arg_len , char* _rlt , int* _rlt_len){
	//���´���������ģ��6�������ӿ�
	
	//6.1
	//��ʼ��ע��ģ��
	reg_modle* _reg_frame_modle = reg_init();
	
	//6.2 ��ȡ������Ϣ
	_reg_frame_modle->input_info = *reg_get_info(_command,_arg_len);
	if(!_reg_frame_modle->input_info.is_pwd_vry_crr){
		//����������֤����ȷ
		reg_error_compute(err_reg_vry_pwd_err,_reg_frame_modle);
	}
	
	//6.3 ������ϵͳ�Ĳ�ѯ
	reg_query_user(_reg_frame_modle->input_info.basic_info.reg_id,
		&_reg_frame_modle->db_query_from_bank);
	
	//6.4 �Ա�
	if(!reg_info_cmp(&_reg_frame_modle->input_info.basic_info
		,&_reg_frame_modle->db_query_from_bank)){
		//��Ϣ�Ա��д���
		reg_error_compute(err_reg_info_check_wrong,_reg_frame_modle);
	}
	
	//6.5 ���û�д���,����Ϣ��ӵ����ݿ�
	if(_reg_frame_modle->info.reg_err.type == err_no_err) 
		reg_add_user_to_db(&_reg_frame_modle->input_info);
	
	//6.6ת����Ϣ,������
	reg_generate_result(_reg_frame_modle,_rlt,_rlt_len);
	
	//�ͷ�ģ��
	reg_release(_reg_frame_modle);
}