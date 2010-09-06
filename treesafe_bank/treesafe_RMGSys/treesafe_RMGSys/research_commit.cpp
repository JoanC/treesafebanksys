#include "stdafx.h"
#include "research_commit.h"

//ģ��9 -- �����Ϣ����ύģ���ʵ�ִ���
extern _ConnectionPtr* treesafe_db_connection ; 
//9.1 ��ʼ�����ͷ�ģ��

void research_commit_init_research_commit_input_info(research_commit_input_info* _init){
DEBUG_RESEARCH_COMMIT_PRINT("commit research input info\n");
	//��ʼ������ύ��������Ϣ
	//���Ա��id,��ʼΪ��
	strcpy(_init->researcher_id,"");
	//���ύ�����������,��ʼΪ��
	strcpy(_init->research_apply_id,"");
	//���������Ϣ�����
	//��˵����ս��,��ʼֵΪfalse
	_init->is_research_approved = true;
	strcpy(_init->cust_research_info_comment,"");
	strcpy(_init->family_research_info_comment,"");
	strcpy(_init->asset_research_info_comment,"");
	strcpy(_init->loan_research_info_comment,"");
}
 
void research_commit_init_research_commit_info(research_commit_info* _init){
DEBUG_RESEARCH_COMMIT_PRINT("research commit:initialize research commit info\n");
	//��ʼ�������¼��Ϣ
	//��ʼ��������Ϣ
	init_sys_err(&_init->err_info);
	//�ύ�Ƿ�ɹ�,��ʼΪtrue,(�м�������,���Ϊfalse)...
	_init->is_commit_succ = true;
}

research_commit_modle* research_commit_init_research_commoit_modle(){
DEBUG_RESEARCH_COMMIT_PRINT("research commit:initialize research commit modle\n");
	//��ʼ��(������)��ģ��
	//�����ڴ�
	research_commit_modle* _new_modle = 
		(research_commit_modle*)malloc(sizeof(research_commit_modle));
	//��ʼ���ڲ�ϸ��
	//��ʼ��������Ϣ
	research_commit_init_research_commit_input_info(&_new_modle->input_info);
	//��ʼ�������Ϣ
	research_commit_init_research_commit_info(&_new_modle->rlt_info);
	//����ָ��ֵ
	return _new_modle;
}

void release_research_commit_modle(research_commit_modle* _release){
DEBUG_RESEARCH_COMMIT_PRINT("research commit:release research commit info\n");
	//�ͷ�ģ��
	free(_release);
}

//9.2
//...
research_commit_input_info* research_commit_get_cmd(const char* _cmd
	,int _cmd_len){
	DEBUG_RESEARCH_COMMIT_PRINT("research commit:get command!\n");
	//Ϊ�µ���Ϣ�����ڴ�
		char* _info = (char*)malloc(_cmd_len);
		research_commit_copy_cmd(_cmd,_info,_cmd_len);
		return research_commit_convert_input(_info);
}

void research_commit_copy_cmd(const char* _cmd,char* _dest,int _cmd_len){
	//����������Ϣ
	DEBUG_RESEARCH_COMMIT_PRINT("research commit:copy command!\n");
	memcpy(_dest,_cmd,_cmd_len);
}

research_commit_input_info* research_commit_convert_input(char* _info){
	//���ַ�������ǿ�����͵�ת��(�����л�)�Ĺ���
	/*���Ľ���*/
DEBUG_RESEARCH_COMMIT_PRINT("research commit:convert input!\n");
	research_commit_input_info* _new_info = (research_commit_input_info*)_info;
	DECODE_UTF7_TO_ASC(_new_info->asset_research_info_comment);
	DECODE_UTF7_TO_ASC(_new_info->cust_research_info_comment);
	DECODE_UTF7_TO_ASC(_new_info->family_research_info_comment);
	DECODE_UTF7_TO_ASC(_new_info->loan_research_info_comment);
	return _new_info;
}


//9.3
//...��sunni���
bool research_commit_save_apply(research_commit_input_info* _apply_info)
{
	DEBUG_RESEARCH_COMMIT_PRINT("research commit:save apply!\n");
	return Update_app_id_set(treesafe_db_connection,_apply_info) && Update_app_pass_and_comment(treesafe_db_connection,_apply_info) ;
}

//9.4
//...��sunni���


//9.5
//�����Ϣ��ת��
void research_commit_convert_rlt(research_commit_info* _info
	,char* _rlt , int* _rlt_len){
	DEBUG_RESEARCH_COMMIT_PRINT("research commit:convert result!\n");
		memcpy(_rlt,_info,sizeof(research_commit_info));
		*_rlt_len = sizeof(research_commit_info);
}

//ģ��9������ʽ
void research_commit_frame(const char* _cmd , int _cmd_len
	,char* _rlt , int* _rlt_len){
	DEBUG_RESEARCH_COMMIT_PRINT("research commit:commit frame!\n");
		//9.1
		//��ʼ��ģ��
		research_commit_modle* _research_commit_frame
			= (research_commit_modle*)malloc(sizeof(research_commit_modle));
		//9.2
		//����ָ��,��ȡ������Ϣ
		_research_commit_frame->input_info
			= *research_commit_get_cmd(_cmd,_cmd_len);
		//9.3
		//...
		research_commit_save_apply(&_research_commit_frame->input_info);

		//9.5
		//���ɽ����Ϣ
		research_commit_convert_rlt(&_research_commit_frame->rlt_info
			,_rlt,_rlt_len);
		
		//�ͷ�ģ��
		release_research_commit_modle(_research_commit_frame);
}