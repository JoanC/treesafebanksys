#ifndef _BANKSYS_MACRO_H_
#define _BANKSYS_MACRO_H_

extern "C"{
	//������һЩ���׵ĺ�ģ��
#define DEBUG_MID_INFO_TEST true

	//��ָ��__p_nameΪNULL,�򷵻�void
#define ARRSERT_POINTER_NULL(__p_name) \
	if( (__p_name) == NULL)  \
	return; \

	//��������Ϊ__type���ڴ�,�����ָ��__p_malloc��
	//ʵ����һ������Ϊn������
	//n = 1ʱ������һ��һ����ڴ�����
	//�����ڴ�ȫ����ʼ��Ϊ0
#define MALLOC_POINTER(__p_malloc , _type , _len) \
	(__p_malloc) = (_type*)calloc(_len,sizeof(_type) ); \

	//mid�������Ϣ
#if defined DEBUG_MID_INFO
#define DEBUG_MID_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_MID_PRINT(x) {};
#endif
}

//����type�Ĳ�ͬ,���ݲ�ͬ�Ľṹ���Сֵ
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