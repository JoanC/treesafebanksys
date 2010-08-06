#ifndef _BANKSYS_MACRO_H_
#define _BANKSYS_MACRO_H_

extern "C"{
	//定义了一些简易的宏模板
#define DEBUG_MID_INFO_TEST true

	//若指针__p_name为NULL,则返回void
#define ARRSERT_POINTER_NULL(__p_name) \
	if( (__p_name) == NULL)  \
	return; \

	//申请类型为__type的内存,存放在指针__p_malloc中
	//实际是一个长度为n的数组
	//n = 1时，就是一个一般的内存申请
	//并将内存全部初始化为0
#define MALLOC_POINTER(__p_malloc , _type , _len) \
	(__p_malloc) = (_type*)calloc(_len,sizeof(_type) ); \

	//mid的输出信息
#if defined DEBUG_MID_INFO
#define DEBUG_MID_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_MID_PRINT(x) {};
#endif
}

//根据type的不同,传递不同的结构体大小值
//
#define DB_INFO_SIZE(__db_type,__rlt_size){ \
	switch (__db_type) { \
	case(CUST_INFO): __rlt_size = sizeof(bankDB_result_cust_info);break;\
	case(ACCOUNT_INFO):__rlt_size = sizeof(bankDB_result_account_info);break;\
	case(LOAN_INFO):__rlt_size = sizeof(bankDB_result_loan_info);break;\
	default:__rlt_size = -1;\
};\
}\

#endif