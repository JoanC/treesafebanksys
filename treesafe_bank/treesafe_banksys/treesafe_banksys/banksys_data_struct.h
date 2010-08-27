#ifndef _BANKSYS_DATA_STRUCT_H_
#define _BANKSYS_DATA_STRUCT_H_

//存放了所有数据结构体
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
//	net_recieved_info rec;//接受到的数据
//	net_send_info send;//发送的数据
//   net_Server banksys_server;
//};

/////////////////////////////////////////////////////////
//数据库模块
//将请求数据发送给数据库
//数据中包括了请求与请求的相关数据
enum  en_require_type{
	CUST_INFO = 1 ,
	ACCOUNT_INFO = 2 ,
	LOAN_INFO = 3 ,
}  ;
struct bankDB_request_info{
	en_require_type		type ;
	char								id[19] ;
};

//结果数据
//输出的数据都存入其中
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
	bool		type ;						// true for 活期 ， 否则死期
	double	balance ;					// balance
	int		month_remain ;		// if 死期 ...
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
	bankDB_request_info		req;//数据库DB的请求数据
	bankDB_result_info			rlt;//DB结果信息
	//...
};

/////////////////////////////////////////////////////////
//mid 模块
struct banksys_mid{
	bool isDbComplete;//将发送的
	net_recieved_info rec;//从网络接口中接受到的数据
	net_send_info send;//转化后，将要发送的数据
	bankDB_request_info req;//发送给数据库DB的请求数据
	bankDB_result_info rlt;//从数据库接受的DB结果信息
};

////////////////////////////////////////////////////////
//frame模块
//主流程的指针
struct banksys_frame{
	sys_Server* sys_net;//指向网络模块
	banksys_mid* sys_mid;//指向中继器
	banksys_db* sys_db;//指向数据库模块
};

#endif
