#pragma once

//ȫ�ֺ�
//��Jiraiya���

//debug ���Դ���
//�����ж˽���������ԵĴ����
//#define TEST_BANK_SYS_CONNECTION


//reg���ԵĴ����
//#define TEST_REG_MODLE

//research_exact �Ĳ��Դ����
//#define TEST_RESEARCH_EXACT_MODLE



//ģ��1������ģ��
#define DEBUG_NET
#if defined DEBUG_NET
#define DEBUG_NET_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_NET(x) {};
#endif

//ģ��2: ����ģ��
#define DEBUG_COMMAND
#if defined DEBUG_COMMAND
#define DEBUG_COMMAND_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_COMMAND(x) {};
#endif


//ģ��3����¼ģ��
#define DEBUG_LOGIN_INFO
#if defined DEBUG_LOGIN_INFO
#define DEBUG_LOGIN_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_LOGIN_INFO(x) {};
#endif

//ģ��4: ����ģ��
#define DEBUG_ERR_INFO
#if defined DEBUG_ERR_INFO
#define DEBUG_ERR_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_ERR_PRINT(x){};
#endif

//ģ��6��ע��ģ��
#define DEBUG_REG_INFO
#if defined DEBUG_REG_INFO
#define DEBUG_REG_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_ERR_PRINT(x){};
#endif

//ģ��7������ģ��
#define DEBUG_APPLY
#if defined DEBUG_APPLY
#define DEBUG_APPLY_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_APPLY_PRINT(x){};
#endif

//ģ��8 �����ģ��
#define DEBUG_RESEARCH
#if defined DEBUG_RESEARCH
#define DEBUG_RESEARCH_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_APPLY_PRINT(x){};
#endif

//ģ��9�������Ϣ����ύģ��
#define DEBUG_RESEARCH_COMMIT
#if defined DEBUG_RESEARCH_COMMIT
#define DEBUG_RESEARCH_COMMIT_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_APPLY_PRINT(x){};
#endif

//ģ��11�����ģ��
#define DEBUG_GET_SCORE
#if defined DEBUG_GET_SCORE
#define DEBUG_GET_SCORE_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_APPLY_PRINT(x){};
#endif

//utf-7�ı���ת��
//��һ��adsc����,�������
#define DECODE_UTF7_TO_ASC(__src_code)\
{\
	WCHAR* _temp = (WCHAR*)calloc(strlen(__src_code),sizeof(wchar_t)); \
    MultiByteToWideChar(CP_UTF7,0,__src_code,-1,_temp,strlen(__src_code));\
	WideCharToMultiByte(CP_ACP,0,_temp,strlen(__src_code),__src_code,strlen(__src_code),NULL,0);\
}
