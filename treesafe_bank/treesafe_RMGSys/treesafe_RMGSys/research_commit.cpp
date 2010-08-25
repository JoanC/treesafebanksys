#include "stdafx.h"
#include "research_commit.h"

//模块9 -- 审核信息结果提交模块的实现代码

//9.1 初始化与释放模块

void research_commit_init_research_commit_input_info(research_commit_input_info* _init){
	//初始化审核提交的输入信息
	//审核员的id,初始为空
	strcpy(_init->researcher_id,"");
	//审核员的姓名,初始为空
	strcpy(_init->researcher_name,"");
	//被提交的审核申请编号,初始为空
	strcpy(_init->research_apply_id,"");
	//审核员的联系电话号,初始为空
	strcpy(_init->research_tel,"");
	
	//各种信息的审核结果(true/false)
	//细节待定

	//审核的最终结果,初始值为false
	_init->is_research_approved = false;
}

void research_commit_init_research_commit_info(research_commit_info* _init){
	//初始化结果记录信息
	//初始化错误信息
	init_sys_err(&_init->err_info);
	//提交是否成功,初始为true,(中间出问题后,会改为false)...
	_init->is_commit_succ = true;
}

research_commit_modle* research_commit_init_research_commoit_modle(){
	//初始化(并生成)主模块
	//分配内存
	research_commit_modle* _new_modle = 
		(research_commit_modle*)malloc(sizeof(research_commit_modle));
	//初始化内部细节
	//初始化输入信息
	research_commit_init_research_commit_input_info(&_new_modle->input_info);
	//初始化结果信息
	research_commit_init_research_commit_info(&_new_modle->rlt_info);
	//返回指针值
	return _new_modle;
}

void release_research_commit_modle(research_commit_modle* _release){
	//释放模块
	free(_release);
}

//9.2
//...
research_commit_input_info* research_commit_get_cmd(const char* _cmd
	,int _cmd_len){
	//为新的信息分配内存
		char* _info = (char*)malloc(_cmd_len);
		research_commit_copy_cmd(_cmd,_info,_cmd_len);
		return research_commit_convert_input(_info);
}

void research_commit_copy_cmd(const char* _cmd,char* _dest,int _cmd_len){
	//复制命令信息
	memcpy(_dest,_cmd,_cmd_len);
}

research_commit_input_info* research_commit_convert_input(char* _info){
	//对字符串进行强制类型的转化(反序列化)的过程
	return (research_commit_input_info*)_info;
}


//9.3
//...待sunni完成


//9.4
//...待sunni完成


//9.5
//结果信息的转换
void research_commit_convert_rlt(research_commit_info* _info
	,char* _rlt , int* _rlt_len){
		memcpy(_rlt,_info,sizeof(research_commit_info));
		*_rlt_len = sizeof(research_commit_info);
}

//模块9的主函式
void research_commit_frame(const char* _cmd , int _cmd_len
	,char* _rlt , int* _rlt_len){
		//9.1
		//初始化模块
		research_commit_modle* _research_commit_frame
			= (research_commit_modle*)malloc(sizeof(research_commit_modle));
		//9.2
		//解析指令,获取输入信息
		_research_commit_frame->input_info
			= *research_commit_get_cmd(_cmd,_cmd_len);
		//9.3
		//...

		//9.4
		//...

		//9.5
		//生成结果信息
		research_commit_convert_rlt(&_research_commit_frame->rlt_info
			,_rlt,_rlt_len);
		
		//释放模块
		release_research_commit_modle(_research_commit_frame);
}