#include "stdafx.h"
#include "banksys_mid.h"

//从网络层中获取数据
void mid_get_data_from_net(banksys_mid* _mid ,net_recieved_info* _rec){
	if(_mid == NULL) return;//中间转换器无效
	printf("get data/n");
	_mid->rec = *_rec;//获得数据
	printf("check data , success/n");
}