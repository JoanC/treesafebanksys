#include "stdafx.h"
//�������н�������
void mid_get_data_from_net(net_recieved_info* _rec);
//�����ݿ��н�������
void mid_get_data_from_db(bankDB_result_info* _rlt);
//�����ݿ��з�������
void mid_send_data_to_db(bankDB_request_info* _req);
//�������з�������
void mid_send_data_to_net( net_send_info* _send);
//���������н��ܵ�����ת��Ϊ�����ݿ������
void mid_convert_rec_to_req(net_recieved_info* _rec , bankDB_request_info* _req);
//�������ݿ���ܵ����н������ת��Ϊ����
void mid_convert_rlt_to_send(bankDB_result_info* _rlt , net_send_info* _send);