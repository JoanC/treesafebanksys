#include "stdafx.h"
#include "banksys_mid.h"

//��������л�ȡ����
void mid_get_data_from_net(banksys_mid* _mid ,net_recieved_info* _rec){
	if(_mid == NULL) return;//�м�ת������Ч
	printf("get data/n");
	_mid->rec = *_rec;//�������
	printf("check data , success/n");
}