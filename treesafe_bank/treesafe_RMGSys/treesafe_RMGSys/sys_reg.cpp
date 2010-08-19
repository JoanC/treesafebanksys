#include "stdafx.h"
#include "sys_reg.h"

/**********************************/
//模块6的实现文件

//6.1 初始化与释放

void reg_init_reg_basic_info(reg_basic_info* _init){
	//初始化基本信息
	//初始用户名
	strcpy(_init->reg_name,"");
	//初始化用户密码
	strcpy(_init->reg_pwd,"");
	//初始化身份证号,十八位0
	strcpy(_init->reg_id,"000000000000000000");
	//初始化真实姓名
	strcpy(_init->reg_basic_user_name,"");
	//初始化性别,男
	_init->reg_gender = male;
	//初始化年龄,18
	_init->reg_age = 18;
	//家庭住址
	strcpy(_init->reg_home_addr,"");
}

void reg_init_reg_input_info(reg_input_info* _init){
	//初始化输入信息
	//设置基本信息块
	reg_init_reg_basic_info(&_init->basic_info);
	//设置其它附加信息,这里以电子邮件为例
	strcpy(_init->email_addr,"");
	//设置密码双次验证的正确性,初始置为false
	_init->is_pwd_vry_crr = false;
}

void reg_init_reg_info(reg_info* _init){
	//初始化注册过程信息
	//初始化错误信息
	init_sys_err(&_init->reg_err);
	strcpy(_init->user_name,"");
}

reg_modle* reg_init(){
	//初始化注册模块
	//分配内存
	reg_modle* _new_modle = 
		(reg_modle*)malloc(sizeof(reg_modle));
	//注册是否成功 
	_new_modle->reg_succ = false;
	//初始化各数据块
	reg_init_reg_input_info(&_new_modle->input_info);
	reg_init_reg_basic_info(&_new_modle->db_query_from_bank);
	reg_init_reg_info(&_new_modle->info);
	return _new_modle;
}

void reg_release(reg_modle* _release){
	//释放整体模块
	free(_release);
}

//模块6.2
void reg_copy_cmd(char* _dst,char* _cmd_info,int _len){
	//复制信息
	memcpy(_dst,_cmd_info,_len);
}

reg_input_info* reg_convert_cmd(char* _info){
	//强制类型转化
	return (reg_input_info*)_info;
}

reg_input_info* reg_get_info(char* _cmd , int _len){
	if(_cmd&&_len) return NULL;//字符串为空或长度为0
	char _temp_input[REG_MAX_OTHER_STR_LEN];
	reg_copy_cmd(_temp_input,_cmd,_len);
	return reg_convert_cmd(_temp_input);
}

//模块6.3
void reg_query_user_generate_req(char* _cust_id,bankDB_request_info* _req){
	//根据信息,产生一个给银行子系统的请求
	strcpy(_req->id,_cust_id);
	_req->type = CUST_INFO;
}

void reg_query_user_get_rlt(bankDB_request_info* _req , bankDB_result_info* _db_rlt){
	//...这个得ducky做啦
	//即把_req传出去,再把_db_rlt接收到
	//这个过程封装在sys_connc_bank_query过程中
	sys_connc_bank_query(_req,_db_rlt);
}


void reg_query_user_convert_rlt(bankDB_result_info* _db_rlt,reg_basic_info* _cust_info){
	//把从银行子系统数据库调来的数据转化成为基础信息
	//首先将_db_rlt进行转化
	if(!_db_rlt->nCount){
		//查询结果为0
		return;
	}
	//将结果信息的信息指针转化成cust_info
	bankDB_result_cust_info* _cust = (bankDB_result_cust_info*)_db_rlt->pRlt;
	//信息传输
	_cust_info->reg_age = _cust->age;
	strcpy(_cust_info->reg_basic_user_name,_cust->name);

}