#include "stdafx.h"
#include "sys_apply.h"

//7.1
//初始化
void apply_init_apply_custmor_info(apply_custmor_info* _init){
	_init->cust_age = 18;
	_init->cust_gender = male;
	strcpy(_init->cust_id,"000000000000000000");
	strcpy(_init->cust_name,"");
}

void apply_init_apply_loan_info(apply_loan_info* _init){
	//初始化各个数据
}

void apply_init_apply_input_info(apply_input_info* _init){
	apply_init_apply_custmor_info(&_init->input_basic_info);
	apply_init_apply_loan_info(&_init->input_loan_info);
}

void apply_init_apply_info(apply_info* _init){
	//初始化错误信息
	init_sys_err(&_init->errInfo);
	//初始化其他信息...
}

//7.2
//获取输入信息
void apply_get_copy_command(char* _dest , char* _command,int _len){
	//信息复制
	memcpy(_dest,_command,_len);
}

apply_input_info* apply_get_convert_input(char* _data){
	return (apply_input_info*)_data;
}

apply_input_info* apply_get_input_info(char* _command , int _len){
	//信息复制
	char _info[sizeof(apply_input_info)];
	apply_get_copy_command(_info,_command,_len);
	return apply_get_convert_input(_info);
}

//7.3
void apply_query_cust_info(apply_custmor_info* _rlt){
	//查询结果
}

//7.4
bool apply_check_cust_info(apply_custmor_info* _input 
	, apply_custmor_info* _db_query){
		//数据检测
		if(strcmp(_input->cust_id,_db_query->cust_id) != 0)
			return false;
		if(strcmp(_input->cust_name,_db_query->cust_name) != 0){
			return false;
		}
		//性别检测
		if(_input->cust_gender != _db_query->cust_gender)
			return false;
		if(_input->cust_age == _db_query->cust_age){
			//检测年龄
			return false;
		}
		return true;
}

//7.5


//7.6
void apply_err_compute(sys_err_type _type , apply_modle* _modle){
	_modle->rlt_info.errInfo.type = _type;
}

//申请处理的主函式
void apply_frame(char* _command , int _len , char* _rlt , int _rlt_len){
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
	if(apply_check_cust_info(&_apply_frame->input_info.input_basic_info,
		&_apply_frame->db_cust_info)){

	}

}
