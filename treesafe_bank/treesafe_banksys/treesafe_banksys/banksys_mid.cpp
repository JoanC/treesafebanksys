#include "stdafx.h"
#include "banksys_mid.h"
#include "banksys_macro.h"

//��������л�ȡ����
void mid_get_data_from_net(banksys_mid* _mid ,banksys_net* _net){
	ARRSERT_POINTER_NULL(_mid && _net)//�м�ת������Ч��_net��Ϊ��
#ifdef DEBUG_MID_INFO
	printf("get recieved data from net\n");
#endif
	_mid->rec = _net->rec;//�������
#ifdef DEBUG_MID_INFO
	printf("recieve done\n");
#endif
#ifdef DEBUG_MID_INFO
	printf("check recieved data , success\n");
#endif
}

//�����ݿ��н�������
void mid_get_data_from_db(banksys_mid* _mid ,banksys_db* _db){
	ARRSERT_POINTER_NULL(_mid && _db)//�м�ת������Ч�����ݿ���Ч
#ifdef DEBUG_MID_INFO
	printf("get reslut data from db\n");
#endif
	_mid->rlt = _db->rlt;//�������
#ifdef DEBUG_MID_INFO
	printf("recieve done\n"); 
#endif
#ifdef DEBUG_MID_INFO
	printf("check recieved data , success\n");
#endif
}

//�����ݿ��з�������
void mid_send_data_to_db(banksys_mid* _mid ,banksys_db* _db){
	ARRSERT_POINTER_NULL(_mid && _db)//�м�ת������Ч�����ݿ���Ч
#ifdef DEBUG_MID_INFO
	printf("check send data , success\n");
#endif
#ifdef DEBUG_MID_INFO
	printf("send request data to db\n");
#endif
	_db->req = _mid->req;//��������
#ifdef DEBUG_MID_INFO
	printf("send done\n");
#endif
}

//�������з�������
void mid_send_data_to_net(banksys_mid* _mid ,banksys_net* _net){
	ARRSERT_POINTER_NULL(_mid && _net)//�м�ת������Ч��_net��Ϊ��
#ifdef DEBUG_MID_INFO
	printf("check send data , success\n");
#endif
#ifdef DEBUG_MID_INFO
	printf("send result data to net\n");
#endif
	_net->send = _mid->send;//��������
#ifdef DEBUG_MID_INFO
	printf("send done\n");
#endif
}

//���������н��ܵ�����ת��Ϊ�����ݿ������
void mid_convert_rec_to_req(net_recieved_info* _rec , bankDB_request_info* _req){
   ARRSERT_POINTER_NULL(_rec) //��������Ϊ��
#ifdef DEBUG_MID_INFO
	printf("convert from net_recieved_info to bankDB_request_info...\n");
#endif
	memcpy(_req,_rec->cRecieveInfo,strlen(_rec->cRecieveInfo));//���ݸ���
}
//�������ݿ���ܵ����н������ת��Ϊ����
void mid_convert_rlt_to_send(bankDB_result_info* _rlt , net_send_info* _send){
    ARRSERT_POINTER_NULL(_rlt)//�������Ϊ��
#ifdef DEBUG_MID_INFO
	printf("convert from bankDB_result_info to net_send_info...\n");
#endif
	memcpy(_send->cSendInfo,_rlt,strlen((char*)_rlt));//���ݸ���
}

//һ�δ�net�н�������,�������ݴ���db�Ĺ���
void mid_recieve_frame(banksys_net* _net, 
	banksys_mid* _mid , banksys_db* _db){
	ARRSERT_POINTER_NULL(_mid && _net && _db)//������һ��Ϊ��
	//��ʼ��net����һ������
	mid_get_data_from_net(_mid , _net);
	//ת������
	mid_convert_rec_to_req(&_mid->rec , &_mid->req);
	//���������ݷ���db
	mid_send_data_to_db(_mid,_db);
}

//һ�δ�db�н�������,�������ݴ���net�Ĺ���
void mid_send_frame(banksys_net* _net,
	banksys_mid* _mid ,banksys_db* _db){
	if(!(_mid && _net && _db)) return;
	//��ʼ�����ݿ��н���һ������
	mid_get_data_from_db(_mid,_db);
	//ת������
	mid_convert_rlt_to_send(&_mid->rlt,&_mid->send);
	//�����󷢸�net
	mid_send_data_to_net(_mid,_net);
}