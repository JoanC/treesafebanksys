#include "database_mgr.h"
#include "sys_error_compute.h"
#include "sys_group_info.h"//������Ϣ

//ģ��12
//��ʼ����
//��������(����)

//����һ�����鷿������Ҫ����Ϣ

#define GROUP_MAKER_ID_LEN 19//�����˵�id����
#define GROUP_MAKER_NAME 51//�����˵���������
#define GROUP_MAKER_APPLY_ID 19//�����˵Ĵ�������ĳ���

//����һ����������Ҫ��������Ϣ
struct group_start_info{
	//���������鳤
	//��������Ϣ
	char goup_maker_id[GROUP_MAKER_ID_LEN];//������id����
	char group_maker_name[GROUP_MAKER_NAME];//����������
	//������Ϊ���������������
	char group_maker_apply[GROUP_MAKER_APPLY_ID];
	//һ������Ļ�����Ϣ
};
