#include "banksys_db.h"
#include "banksys_mid.h"
#include "banksys_net.h"
#include "banksys_data_struct.h"

//������ϵͳ������ʽ�ֽ�

//��������ģ��
//�����ڴ�ķ���ͳ�ʼ��
//����һ��frame�ṹ���ָ��
void banksys_frame_allocate(banksys_frame* _frame);

//������������ʽ
void banksys_frame_recieve(banksys_frame* _frame);

//��������ʽ
void banksys_frame_send(banksys_frame* _frame);

//�ͷ�ģ��
void banksys_frame_deallocate(banksys_frame* _frame);