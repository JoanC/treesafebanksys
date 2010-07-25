#ifndef _BANKSYS_MID_H_
#define _BANKSYS_MID_H_


#include "banksys_data_struct.h"
#include "banksys_net.h"
#include "banksys_db.h"

//�м����ģ��
struct banksys_mid{
	bool isDbComplete;//�����͵�
	net_recieved_info rec;//������ӿ��н��ܵ�������
	net_send_info send;//ת���󣬽�Ҫ���͵�����
	bankDB_request_info req;//���͸����ݿ�DB����������
	bankDB_result_info rlt;//�����ݿ���ܵ�DB�����Ϣ
};

//�������н�������
void mid_get_data_from_net(banksys_mid* _mid , banksys_net* _net);
//�����ݿ��н�������
void mid_get_data_from_db(banksys_mid* _mid , banksys_db* _db);
//�����ݿ��з�������
void mid_send_data_to_db(banksys_mid* _mid ,banksys_db* _db);
//�������з�������
void mid_send_data_to_net(banksys_mid* _mid , banksys_net* _net);
//���������н��ܵ�����ת��Ϊ�����ݿ������
void mid_convert_rec_to_req(net_recieved_info* _rec , bankDB_request_info* _req);
//�������ݿ���ܵ����н������ת��Ϊ����
void mid_convert_rlt_to_send(bankDB_result_info* _rlt , net_send_info* _send);

//һ�δ�net�н�������,�������ݴ���db�Ĺ���
void mid_recieve_frame(banksys_net* _net, banksys_db* _db);

#endif