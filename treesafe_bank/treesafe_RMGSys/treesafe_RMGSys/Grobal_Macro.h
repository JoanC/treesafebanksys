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


//login�������Ϣ

#define DEBUG_LOGIN_INFO

#if defined DEBUG_LOGIN_INFO
#define DEBUG_LOGIN_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_LOGIN_INFO(x) {};
#endif


#ifndef DEBUG_NET_INFO
#define DEBUG_NET_INFO
#endif


//utf-7�ı���ת��
//��һ��adsc����,�������
#define DECODE_UTF7_TO_ASC(__src_code)\
{\
	WCHAR* _temp = (WCHAR*)calloc(strlen(__src_code),sizeof(wchar_t)); \
    MultiByteToWideChar(CP_UTF7,0,__src_code,-1,_temp,strlen(__src_code));\
	WideCharToMultiByte(CP_ACP,0,_temp,strlen(__src_code),__src_code,strlen(__src_code),NULL,0);\
}
