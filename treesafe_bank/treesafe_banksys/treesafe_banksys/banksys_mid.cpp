#include "stdafx.h"
#include "banksys_mid.h"

//��������л�ȡ����
void mid_get_data_from_net(banksys_mid* _mid ,net_recieved_info* _rec){
	if(_mid == NULL) return;//�м�ת������Ч
#ifdef DEBUG_INFO
	printf("get recieved data from net\n");
#endif
	_mid->rec = *_rec;//�������
#ifdef DEBUG_INFO
	printf("recieve done\n");
#endif
#ifdef DEBUG_INFO
	printf("check recieved data , success\n");
#endif
}

//�����ݿ��н�������
void mid_get_data_from_db(banksys_mid* _mid ,bankDB_result_info* _rlt){
	if(_mid == NULL) return;//�м�ת������Ч
#ifdef DEBUG_INFO
	printf("get reslut data from db\n");
#endif
	_mid->rlt = *_rlt;//�������
#ifdef DEBUG_INFO
	printf("recieve done\n");
#endif
#ifdef DEBUG_INFO
	printf("check recieved data , success\n");
#endif
}

//�����ݿ��з�������
void mid_send_data_to_db(banksys_mid* _mid ,bankDB_request_info* _req){
		if(_mid == NULL) return;//�м�ת������Ч
#ifdef DEBUG_INFO
	printf("check send data , success\n");
#endif
#ifdef DEBUG_INFO
	printf("send request data to db\n");
#endif
	*_req = _mid->req;//��������
#ifdef DEBUG_INFO
	printf("send done\n");
#endif
}

//�������з�������
void mid_send_data_to_net(banksys_mid* _mid , net_send_info* _send){
	if(_mid == NULL) return;//�м�ת������Ч
#ifdef DEBUG_INFO
	printf("check send data , success\n");
#endif
#ifdef DEBUG_INFO
	printf("send result data to net\n");
#endif
	*_send = _mid->send;//��������
#ifdef DEBUG_INFO
	printf("send done\n");
#endif
}

//���������н��ܵ�����ת��Ϊ�����ݿ������
void mid_convert_rec_to_req(net_recieved_info* _rec , bankDB_request_info* _req){
#ifdef DEBUG_INFO
	printf("convert from net_recieved_info to bankDB_request_info...\n");
#endif
}
//�������ݿ���ܵ����н������ת��Ϊ����
void mid_convert_rlt_to_send(bankDB_result_info* _rlt , net_send_info* _send){
#ifdef DEBUG_INFO
	printf("convert from bankDB_result_info to bankDB_send_info...\n");
#endif
}