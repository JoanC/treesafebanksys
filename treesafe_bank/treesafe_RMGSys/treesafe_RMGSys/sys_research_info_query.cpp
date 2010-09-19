
#include "stdafx.h"
#include "sys_research_info_query.h"

//模块18的实现文件
extern _ConnectionPtr *treesafe_db_connection ; 

//18.1
void init_research_query_input_info(research_query_input_info* _init){
DEBUG_RESEARCH_QUERY_PRINT("init_research_query_input_info\n");
    //初始化输入信息模块	
	//字符串的初始化为空
	strcpy(_init->app_id,"");
}

void init_research_query_info(research_query_info* _init){
DEBUG_RESEARCH_QUERY_PRINT("init_research_query_info\n");
	//初始化结果模块
	//初始化申请信息
	//初始化用户基本信息
	apply_init_apply_custmor_info(&_init->query_info.input_basic_info);
	//初始化用户资产信息
	apply_init_apply_custmor_assets_info(&_init->query_info.input_asset_info);
	//初始化用户家庭信息
	apply_init_apply_custmor_family_info(&_init->query_info.input_fammily_info);
	//初始化贷款信息
	apply_init_apply_loan_info(&_init->query_info.input_loan_info); 
	//初始化错误信息
	init_sys_err(&_init->err_info);
}

research_query_modle* init_research_query_modle(){
DEBUG_RESEARCH_QUERY_PRINT("init_research_query_modle\n");
	//初始并产生主模块
	research_query_modle* _new_modle
		= (research_query_modle*)malloc(sizeof(research_query_modle));
	//初始化输入模块
	init_research_query_input_info(&_new_modle->input_info);
	//初始化查询信息
	init_research_query_info(&_new_modle->rlt_info);
	return _new_modle;
}

void release_research_query_modle(research_query_modle* _release){
DEBUG_RESEARCH_QUERY_PRINT("release_research_query_modle\n");
	//释放模块
	free(_release);
}


//18.2
void research_query_copy_cmd(const char* _cmd
	,char* _dest , int _cmd_len){
DEBUG_RESEARCH_QUERY_PRINT("research_query_copy_cmd\n");
		//命令信息的复制
		memcpy(_dest,_cmd,_cmd_len);
}

research_query_input_info* research_query_convert_cmd(char* _info){
	//转化并解码输入的信息
DEBUG_RESEARCH_QUERY_PRINT("research_query_convert_cmd\n");
	return (research_query_input_info*)_info;
}

research_query_input_info* research_query_get_cmd(const char* _cmd,int _cmd_len){
DEBUG_RESEARCH_QUERY_PRINT("research_query_get_cmd\n");
	//获取指令的主函式
	char _info[sizeof(research_query_input_info)];
	//复制指令
	research_query_copy_cmd(_cmd,_info,_cmd_len);
	//转化指令
	return research_query_convert_cmd(_info);
}

//模块18.3
void research_query_get_data(const char* _app_id,research_query_data* _data,bool* _rlt)
{
	DEBUG_RESEARCH_QUERY_PRINT("research_query_get_data\n");
	strcpy(_data->input_asset_info.app_id,_app_id) ;
	strcpy(_data->input_basic_info.app_id,_app_id) ;
	strcpy(_data->input_fammily_info.app_id,_app_id) ;
	strcpy(_data->input_loan_info.app_id,_app_id) ;

	*_rlt = Get_app_cust_info(treesafe_db_connection,_data) 
				&& Get_app_asset_info(treesafe_db_connection,_data)
				&& Get_app_cust_fami_info(treesafe_db_connection,_data) 
				&& Get_app_cust_loan_info(treesafe_db_connection,_data) ;
}

//模块18.4
void research_query_convert_rlt(research_query_info* _info
	,char* _rlt , int* _rlt_len){
DEBUG_RESEARCH_QUERY_PRINT("init_research_query_info\n");
	//将查询的数据整合到结果数据中
	*_rlt_len = sizeof(research_query_info);
	//复制指令
	memcpy(_rlt,_info,*_rlt_len);
}

void research_query_frame(const char* _cmd,int _cmd_len
	,char* _rlt,int* _rlt_len){
DEBUG_RESEARCH_QUERY_PRINT("research_query_frame\n");
		//模块18的主函式
		//初始化模块
		research_query_modle* _modle
			= init_research_query_modle();
		//调用18.2
		_modle->input_info = *research_query_get_cmd(_cmd,_cmd_len);
		//调用18.3
		/*(模块18.3尚未完成)*/
		bool _get_data_corr;
		research_query_get_data(_modle->input_info.app_id
			,&_modle->rlt_info.query_info,&_get_data_corr);
			
		//调用18.4
		//整理结果模块
		research_query_convert_rlt(&_modle->rlt_info
			,_rlt,_rlt_len);
		//释放模块
		release_research_query_modle(_modle);
}