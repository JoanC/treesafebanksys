#pragma once

//ȫ�ֺ�
//��Jiraiya���

//debug ���Դ���
//�����ж˽���������ԵĴ����
//#define TEST_BANK_SYS_CONNECTION


//reg���ԵĴ����
//#define TEST_REG_MODLE

//research_exact �Ĳ��Դ����
#define TEST_RESEARCH_EXACT_MODLE


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