#ifndef _BANKSYS_DATA_STRUCT_H_
#define _BANKSYS_DATA_STRUCT_H_

//������������ݽṹ�� 
#include <winsock2.h>
//server socket struct

struct net_Server
{
	SOCKET sServer;   //server socket
	BOOL bServerRunning;   //whether server is working
};

//recieve info
struct net_recieved_info
{
	size_t stRecPackSize;
	char* cRecieveInfo;
};

//send info
struct net_send_info{
	size_t stSendPackSize;
	char* cSendInfo;
};

struct banksys_net{
	net_recieved_info rec;//���ܵ�������
	net_send_info send;//���͵�����
	net_Server banksys_server;
};



/////////////////////////////////////////////////////////
//���ݿ�ģ��
//���������ݷ��͸����ݿ�
//�����а�����������������������
struct bankDB_request_info{
	int type;
	int index;
};

//�������
//��������ݶ���������
struct bankDB_result_info{
	void* data;
};

struct banksys_db{
	bankDB_request_info req;//���ݿ�DB����������
	bankDB_result_info rlt;//DB�����Ϣ
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

#endif