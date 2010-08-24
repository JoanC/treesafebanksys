#include "stdafx.h"
#include "sys_research_exact.h"

extern _ConnectionPtr* database_connection;

//模块8的实现


//8.1
void research_exact_init_research_exact_input_info(research_exact_input_info* _init){
	strcpy(_init->investigator_id,"");
}

void research_exact_init_research_exact_investigator_prop(research_exact_investigator_prop* _init){
	_init->statu = false;
	strcpy(_init->research_apply_id,"");
}

void research_exact_init_research_exact_info(research_exact_info* _init){
	//初始化错误信息
	init_sys_err(&_init->err_info);
	strcpy(_init->research_apply_id,"");
}

research_exact_modle* research_exact_init_research_exact_modle(){
	//分配内存
	research_exact_modle* _new_modle
		= (research_exact_modle*)malloc(sizeof(research_exact_modle));
	//初始化输入信息
	research_exact_init_research_exact_input_info(&_new_modle->input_info);
	//初始化审核员信息
	research_exact_init_research_exact_investigator_prop(&_new_modle->investigator_prop);
	//初始化结果记录信息
	research_exact_init_research_exact_info(&_new_modle->rlt_info);
	//返回这个新建的指针
	return _new_modle;
}

void release_research_exact_modle(research_exact_modle* _release){
	free(_release);
}


//8.2
void research_exact_copy_cmd(const char* _cmd , char* _dest , int _cmd_len){
	//复制命令信息
	memcpy(_dest,_cmd,_cmd_len);
}

research_exact_input_info* reasearch_exact_convert_cmd(char* _info){
	//转化命令
	return (research_exact_input_info*)_info;
}

research_exact_input_info* research_exact_get_cmd(const char* _cmd , int _cmd_len){
	//为新的命令信息划分内存
	char* _cmd_info = 
		(char*)malloc(_cmd_len);
	//首先复制命令
	research_exact_copy_cmd(_cmd,_cmd_info,_cmd_len);
	//转化指针格式
	return reasearch_exact_convert_cmd(_cmd_info);
}

//8.3
//...
//有待sunni完成


//8.4
//...
//有待sunni完成

//8.5
//...
//有待sunni完成
//...


//8.6
void research_exact_convert_rlt(research_exact_info* _info
	,char* _rlt , int* _len){
	//确定长度
	*_len = sizeof(research_exact_info);
	//复制
	memcpy(_rlt,_info,*_len);
}


//模块8的主函式
void research_exact_frame(const char* _cmd
	,int _cmd_len,char* _rlt , int* _rlt_len){
		//8.1
		//初始化模块
		research_exact_modle* _research_exact_frame
			= research_exact_init_research_exact_modle();
		//8.2
		//将命令信息转化为用户输入的数据
		_research_exact_frame->input_info
			= *research_exact_get_cmd(_cmd,_cmd_len);

		//8.3
		//...

		if(_research_exact_frame->investigator_prop.statu
			== true){
				//如果审核员处于空闲状态
				//则抽取一个申请,并改变状态
		//8.4
		//...

		//8.5
		//...
		}
		//8.6
		//将结果转化到_rlt中,准备交付
		research_exact_convert_rlt(&_research_exact_frame->rlt_info
			,_rlt,_rlt_len);
		//8.7
		//释放审核抽取模块
		release_research_exact_modle(_research_exact_frame);
}