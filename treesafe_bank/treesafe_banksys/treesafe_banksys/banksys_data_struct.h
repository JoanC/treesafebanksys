#ifndef _BANKSYS_DATA_STRUCT_H_
#define _BANKSYS_DATA_STRUCT_H_

//������������ݽṹ��
#include <winsock2.h>
#include "banksys_net.h"
//server socket struct

//const int PackageSize = 80;
//
//struct net_Server
//{
//	WSADATA		wsd;
//	SOCKET sServer;   //server socket
//	SOCKET sClient;
//	SOCKADDR_IN	addrServ;
//	sockaddr_in addrClient;
//	BOOL bServerRunning;   //whether server is working
//};
//
////recieve info
//struct net_recieved_info
//{
//	size_t stRecPackSize;
//	char* cRecieveInfo;
//};
//
////send info
//struct net_send_info{
//	size_t stSendPackSize;
//	char* cNetDataInfo;
//};

//struct sys_Server{
//	net_recieved_info rec;//���ܵ�������
//	net_send_info send;//���͵�����
//   net_Server banksys_server;
//};

/////////////////////////////////////////////////////////
//���ݿ�ģ��
//���������ݷ��͸����ݿ�
//�����а�����������������������
enum  en_require_type{
	CUST_INFO = 1 ,
	ACCOUNT_INFO = 2 ,
	LOAN_INFO = 3 ,
}  ;
struct bankDB_request_info{
	en_require_type		type ;
	char								id[19] ;
};

//�������
//��������ݶ���������
struct bankDB_result_cust_info{
	char		id[19] ;			//id
	char		name[51] ;		//name
	bool		gend ;						// "true" for boy...
	int		age ;						//age
	char		phone_num[12] ;	//...
	char		home_addr[51] ;	//...
} ;
struct	bankDB_result_account_info{
	char		account_num[19] ;	// account number , length:18
	char		open_branch[51] ;	// opened in which branch
	char		open_date[11] ;		// when opened
	bool		type ;						// true for ���� �� ��������
	double	balance ;					// balance
	int		month_remain ;		// if ���� ...
};
struct bankDB_result_loan_info{
	char		loan_num[19] ; 			//loan number , length:18 
	char		open_branch[51] ;		//opened in which branch
	char		open_date[11] ;			//when opened
	double	amount ;						//how much
	int		month_remain ;			//how many months remain
	double	monthly_return ;		//how much monthly return
};
struct bankDB_result_info
{
	int		nCount ;	//an counter that shows how many results in the array(*pRlt). 
	void		*pRlt ;		//pointer to the result struct , such as bankDB_result_account_info...
};
struct banksys_db{
	bankDB_request_info		req;//���ݿ�DB����������
	bankDB_result_info			rlt;//DB�����Ϣ
	//...
};

/////////////////////////////////////////////////////////
//mid ģ��
struct banksys_mid{
	bool isDbComplete;//�����͵�
	net_recieved_info rec;//������ӿ��н��ܵ�������
	net_send_info send;//ת���󣬽�Ҫ���͵�����
	bankDB_request_info req;//���͸����ݿ�DB����������
	bankDB_result_info rlt;//�����ݿ���ܵ�DB�����Ϣ
};

////////////////////////////////////////////////////////
//frameģ��
//�����̵�ָ��
struct banksys_frame{
	sys_Server* sys_net;//ָ������ģ��
	banksys_mid* sys_mid;//ָ���м���
	banksys_db* sys_db;//ָ�����ݿ�ģ��
};

#endif
