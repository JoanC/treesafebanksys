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
	printf("check data , success\n");
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
	printf("check data , success\n");
#endif
}

//�����ݿ��з�������
void mid_send_data_to_db(banksys_mid* _mid ,bankDB_request_info* _req){
		if(_mid == NULL) return;//�м�ת������Ч
#ifdef DEBUG_INFO
	printf("get reslut data from db\n");
#endif
	_mid->rlt = *_rlt;//�������
#ifdef DEBUG_INFO
	printf("check data , success\n");
#endif
}