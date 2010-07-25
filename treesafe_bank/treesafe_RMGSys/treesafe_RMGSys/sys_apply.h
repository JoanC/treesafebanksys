//申请处理流程

//操作员输入的信息结构
struct apply_input_info{
	void* data;
};

//经整合后,系统可读的信息
struct apply_sys_info{
	void* data;
};

//申请处理的所有信息结构


//得到界面上输入的申请信息
void apply_get_input_info();