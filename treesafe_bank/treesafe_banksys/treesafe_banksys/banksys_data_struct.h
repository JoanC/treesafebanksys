//������������ݽṹ��

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