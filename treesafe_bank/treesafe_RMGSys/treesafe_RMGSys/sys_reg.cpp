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
#ifdef TEST_REG_MODLE
	//这是测试代码段
	_db_rlt->nCount = 0;
	//strcpy((char*)_db_rlt->pRlt,"");
#endif
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
	//信息传输,填充基本信息
	//这个被填充的结构体是用于与用户输入的基本信息进行比对的
	//需要比对的信息包括姓名,年龄,性别
	//姓名
	strcpy(_cust_info->reg_basic_user_name,_cust->name);
	//身份证号码
	strcpy(_cust_info->reg_id , _cust->id);
	//年龄
	_cust_info->reg_age = _cust->age;
	//性别
	_cust_info->reg_gender = _cust->gend ? male : female;
	//家庭住址
	//...家庭住址不用比较
	//strcpy(_cust_info->reg_home_addr,_cust->home_addr);
}

void reg_query_user(char* _query_id,reg_basic_info* _rlt_cust_info){
	//模块6.3的主函式
	//首先为请求和结果的结构体申请内存
	bankDB_request_info* _req = 
		(bankDB_request_info*)malloc(sizeof(bankDB_request_info));
	bankDB_result_info* _rlt = 
		(bankDB_result_info*)malloc(sizeof(bankDB_result_info));
	//生成相应的请求信息
	reg_query_user_generate_req(_query_id,_req);
	//查询
	reg_query_user_get_rlt(_req,_rlt);
	//转化
	reg_query_user_convert_rlt(_rlt,_rlt_cust_info);
	//释放内存
	free(_req);
	free(_rlt);
}

bool reg_info_cmp(reg_basic_info* _input,reg_basic_info* _bank_data){
	//信息验证
	//比对姓名,年龄,性别
	if(_input->reg_age != _bank_data->reg_age) return false;
	if(strcmp(_input->reg_basic_user_name,_bank_data->reg_basic_user_name) != 0)
		return false;
	if(_input->reg_gender != _bank_data->reg_gender) return false;
	return true;
}

//模块6.5
void reg_add_user_to_db(reg_input_info* _info){
	//根据basic信息,把该用户加入数据库中
	//...待sunni实现
}

//6.6
//注册结束后,将结果信息转化成将要发送的信息
void reg_generate_result(reg_modle* _mld , char* _rlt , int* _rlt_len){
	if(_mld->info.reg_err.type == err_no_err)
		reg_summery_rlt_data(_mld);//整理模块中的数据
	//复制结果,模块释放后,结果将被发到网络传输层
	memcpy(_rlt,&_mld->info,sizeof(reg_info));
	//结果信息
	*_rlt_len = sizeof(reg_info);
}
void reg_summery_rlt_data(reg_modle* _mld){
	//整理要发送给网页端的数据
	//错误信息已经在主流程中填充完毕
	strcpy(_mld->info.user_name,_mld->input_info.basic_info.reg_id);
	//...其它(可添加)
}

//6.7
void reg_error_compute(sys_err_type _type , reg_modle* _modle){
	_modle->reg_succ = false;
	//查找错误信息
	_modle->info.reg_err.type = _type;
	sys_err_search(&_modle->info.reg_err);
}

void reg_frame(char* _command , int _arg_len , char* _rlt , int* _rlt_len){
	//以下代码整合了模块6的所有子块
	
	//6.1
	//初始化注册模块
	reg_modle* _reg_frame_modle = reg_init();
	
	//6.2 获取输入信息
	_reg_frame_modle->input_info = *reg_get_info(_command,_arg_len);
	if(!_reg_frame_modle->input_info.is_pwd_vry_crr){
		//两次密码验证不正确
		reg_error_compute(err_reg_vry_pwd_err,_reg_frame_modle);
	}
	
	//6.3 银行子系统的查询
	reg_query_user(_reg_frame_modle->input_info.basic_info.reg_id,
		&_reg_frame_modle->db_query_from_bank);
	
	//6.4 对比
	if(!reg_info_cmp(&_reg_frame_modle->input_info.basic_info
		,&_reg_frame_modle->db_query_from_bank)){
		//信息对比有错误
		reg_error_compute(err_reg_info_check_wrong,_reg_frame_modle);
	}
	
	//6.5 如果没有错误,则将信息添加到数据库
	if(_reg_frame_modle->info.reg_err.type == err_no_err) 
		reg_add_user_to_db(&_reg_frame_modle->input_info);
	
	//6.6转化信息,输出结果
	reg_generate_result(_reg_frame_modle,_rlt,_rlt_len);
	
	//释放模块
	reg_release(_reg_frame_modle);
}