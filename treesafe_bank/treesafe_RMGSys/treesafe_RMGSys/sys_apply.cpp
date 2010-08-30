#include "stdafx.h"
#include "sys_apply.h"

extern _ConnectionPtr* treesafe_db_connection ; 
//7.1
void apply_init_apply_info(apply_info* _init){
	//初始化结果信息
	//初始化错误信息
	_init->is_succ = true;
	init_sys_err(&_init->errInfo);
	//初始化其他信息...
}

void apply_init_apply_modle(apply_modle* _init){
	//初始化各个指针
	apply_init_apply_input_info(&_init->input_info);
	apply_init_apply_custmor_info(&_init->db_cust_info);
	apply_init_apply_info(&_init->rlt_info);
}

void apply_release(apply_modle* _mld){
	free(_mld);
}

//7.2
//获取输入信息
void apply_get_copy_command(char* _dest , const char* _command,int _len){
	//信息复制
	memcpy(_dest,_command,_len);
}

apply_input_info* apply_get_convert_input(char* _data){
	return (apply_input_info*)_data;
}

apply_input_info* apply_get_input_info(const char* _command , int _len){
	//信息复制
	char _info[sizeof(apply_input_info)];
	apply_get_copy_command(_info,_command,_len);
	return apply_get_convert_input(_info);
}

//7.3
void apply_query_cust_info(apply_custmor_info* _rlt,bool *_isSucceeded)
{
	*_isSucceeded = Apply_cust_info_query(treesafe_db_connection,_rlt) ;
}

//7.4
bool apply_check_cust_info(apply_custmor_info* _input 
	, apply_custmor_info* _db_query){
		//基础数据的检测
		//用户的姓名检测
		if(strcmp(_input->cust_name,_db_query->cust_name) != 0) return false;
		//用户的性别检测
		if(_input->cust_gender != _db_query->cust_gender) return false;
		//年龄检测
		if(_input->cust_age != _db_query->cust_age) return false;
				//用户的卡号检测
		if(strcmp(_input->cust_id,_db_query->cust_id) != 0) return false;
		//客户省份卡的类型检测
		if(_input->cust_card_type != _db_query->cust_card_type) return false;
		//客户的教育程度检测
		if(_input->cust_edu != _db_query->cust_edu) return false;
		return true;
}

//7.5
void apply_save_generate_id(char *_outcome) 
{}


//7.6
void apply_err_compute(sys_err_type _type , apply_modle* _modle){
	_modle->rlt_info.errInfo.type = _type;
	//从数据库中调出这个错误的相关信息
	sys_err_search(&_modle->rlt_info.errInfo);
}

void apply_convert_rlt(apply_info* _info , char* _rlt , int* _rlt_len){
	//数据复制
	//将数据复制到结果信息
	memcpy(_rlt,_info,sizeof(apply_info));
	*_rlt_len = sizeof(apply_info);
}

//申请处理的主函式
void apply_frame(const char* _command , int _len , char* _rlt , int* _rlt_len){
	//7.1
	//初始化模块
	apply_modle* _apply_frame = 
		(apply_modle*)malloc(sizeof(apply_modle));
	apply_init_apply_modle(_apply_frame);
	
	//7.2
	//接收输入信息
	_apply_frame->input_info = 
		*apply_get_input_info(_command,_len);
	
	//7.3
	//调出数据
	//apply_query_cust_info(&_apply_frame->rlt_info);

	//7.4
	//比对数据
	if(!apply_check_cust_info(&_apply_frame->input_info.input_basic_info,
		&_apply_frame->db_cust_info)){
			apply_err_compute(err_apply_info_chech_wrong
				, _apply_frame);
	}

	//7.5
	//apply_save_to_research_table(apply_save_generate_id()
	//,&_apply_frame->input_info);

	//7.6
	//整理结果
	apply_convert_rlt(&_apply_frame->rlt_info
		,_rlt, _rlt_len);

	//7.7
	//释放模块
	apply_release(_apply_frame);
}
