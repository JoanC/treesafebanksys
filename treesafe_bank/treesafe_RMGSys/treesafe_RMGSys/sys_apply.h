#include "error_type.h"

//申请处理流程

//操作员输入的信息结构
struct apply_input_info{
	void* user_info;
	void* data;
};

//经整合后,系统可读的信息
struct apply_sys_info{
	void* data;
};

//申请处理的所有信息结构
struct apply_info{
	apply_input_info input;//输入的信息
	apply_sys_info sys;//待调查的信息
	
	//下面是错误,日志,和报表信息
	err_apply errInfo;//申请处理中的错误信息
	void* logInfo;//日志信息
	void* reportInfo;//报表信息
};

//得到界面上输入的申请信息
//将_input信息加载到_apply_info中
//这是一个整体函数
//具体的要看申请处理信息中有多少项
//中间可能会有很多小函数
void apply_get_input_info(apply_info* _apply_info,
	apply_input_info* _input);

//信息整合
//将调查员输入的信息转化为调查系统可识别的申请调查信息
void apply_convert_info(apply_input_info* _org
	,apply_sys_info);