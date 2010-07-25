#include "banksys_data_struct.h"

//�м����ģ��
struct banksys_mid{
	bool isOver;//����м����Ƿ��Ѿ�ʹ�����
	net_recieved_info rec;//������ӿ��н��ܵ�������
	net_send_info send;//ת���󣬽�Ҫ���͵�����
	bankDB_request_info req;//���͸����ݿ�DB����������
	bankDB_result_info rlt;//�����ݿ���ܵ�DB�����Ϣ
};

//�������н�������
void mid_get_data_from_net(banksys_mid* _mid , net_recieved_info* _rec);
//�����ݿ��н�������
void mid_get_data_from_db(banksys_mid* _mid ,bankDB_result_info* _rlt);
//�����ݿ��з�������
void mid_send_data_to_db(banksys_mid* _mid ,bankDB_request_info* _req);
//�������з�������
void mid_send_data_to_net(banksys_mid* _mid , net_send_info* _send);
//���������н��ܵ�����ת��Ϊ�����ݿ������
void mid_convert_rec_to_req(banksys_mid* _mid ,net_recieved_info* _rec , bankDB_request_info* _req);
//�������ݿ���ܵ����н������ת��Ϊ����
void mid_convert_rlt_to_send(banksys_mid* _mid ,bankDB_result_info* _rlt , net_send_info* _send);