//�������ݿ�������˵ĺ�������
//��Ϊ��̨���ݿ�ĵ��ú����紫�봫��

//���ݿ�ģ�������ģ����԰������,�м����һ��ͨ�õ����ݽӿ�

//request_type : ��������,����չ
struct net_request_info{
	int request_type;//...
	void* _info;
};

//packet�ṹ��,��һ��ͨ�ýṹ
struct net_packet{
	void* _data;
	//...
};
//���ܵ���Ϣ
//������δ���������,���м�Ĺ���ģ���п��Ա������һ�����ݿ����õ�����
struct net_recieved_info{
	void* _data;
};

//���緢�͵���Ϣ
struct net_send_info{
	void* _data;
};

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
//--------------------------------------------------------------------------
//����ӿڴ�����
//�������Ӻ��ͷ�����
void net_add_connection();
void net_release_connection();
//��������ģ��ȴ�����
void net_wait_for_request(net_request_info _request);

//����ģ��������ݰ�
void net_recieve_paket();//��������һ�����ݰ�

void net_recieve_data();//��������һ������,��ʵ�ǽ����ݰ�����

//��������
void net_send_data(net_send_info* _send);

//--------------------------------------------------------------------------
//����ģ�鴦����

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
//--------------------------------------------------------------------------
//���ݿ⴦����

//ͨ����_data�Ľ���,Ӧ�ö�֮���в�ͬ�Ĳ���
//������Щ��������һ�������н���
void bankDB_Operate(bankDB_request_info* _req , bankDB_result_info* _rlt, 
	 bankDB_result_info* (*operate_func) (bankDB_request_info* _req));

//...�����Ǹ������ݿ�Ĺ��ߺ���
//...


