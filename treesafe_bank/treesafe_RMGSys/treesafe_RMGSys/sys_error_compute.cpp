#include "stdafx.h"
#include "sys_error_compute.h"

void init_sys_err(sys_err* _err){
	//初始化结构体
	_err->type = err_no_err;
	memset(_err->info,'\0',MAX_ERR_INFO);
}

void sys_err_search(sys_err* _err){
	//通过数据库,填充err结构体
	char err_info[10][MAX_ERR_INFO] ;
	strcpy(err_info[0],"无错误") ;
	strcpy(err_info[1],"用户名或密码不对") ;
	strcpy(err_info[2],"验证码不匹配") ;
	strcpy(err_info[3],"数据库访问错误") ;
	strcpy(err_info[4],"密码确认出错") ;
	strcpy(err_info[5],"与银行中的数据比对时出错") ;
	strcpy(err_info[6],"数据库操作失败") ;
	strcpy(err_info[7],"在申请处理时会遇到的错误") ;
	strcpy(err_info[8],"基础信息核对有错") ;
	strcpy(err_info[9],"无此用户") ;


	strcpy(_err->info,err_info[_err->type]) ;

}