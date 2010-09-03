#include "stdafx.h"
#include "sys_research_exact.h"


void init_research_exact_input_info(research_exact_input_info* _init){
	//初始化输入结构
	strcpy(_init->research_work_id,"");
}


void init_research_exact_info(research_exact_info* _init){
	//初始化结果结构
	strcpy(_init->app_id,"");
	//初始化错误信息
	init_sys_err(&_init->err_info);
}


research_exact_modle* init_research_exact_modle(){
	//初始化整体模块
	//内存分配
	research_exact_modle* _new_modle
		= (research_exact_modle*)malloc(sizeof(research_exact_modle));
	//初始化各个数据块
	init_research_exact_input_info(&_new_modle->input_info);
	init_research_exact_info(&_new_modle->rlt_info);
	return _new_modle;
}

//释放模块
void release_research_exact_info(research_exact_info* _release){
	free(_release);
}

void research_copy_cmd_data(const char* _cmd,char* _dest,int _cmd_len){
	//复制命令
	memcpy(_dest,_cmd,_cmd_len);
}

research_exact_input_info* research_convert_cmd(char* _info){
	//转化指令
	return (research_exact_input_info*)_info;
}


research_exact_input_info* research_get_cmd(const char* _cmd,
	int _cmd_len){
		//8.2主函式
		//分配新的内存
		char* _new_info = 
			(char*)malloc(_cmd_len);
		//复制指令
		research_copy_cmd_data(_cmd,_new_info,_cmd_len);
		//转化并返回输入信息
		return research_convert_cmd(_new_info);
}
