#pragma once

#include "error_type.h"

//���봦������

//����Ա�������Ϣ�ṹ
struct apply_input_info{
	void* user_info;
	void* data;
};

//�����Ϻ�,ϵͳ�ɶ�����Ϣ
struct apply_sys_info{
	void* data;
};

//���봦���������Ϣ�ṹ
struct apply_info{
	int apply_id;//������
	void* date;//���뷢��������

	apply_input_info input;//�������Ϣ
	apply_sys_info sys;//���������Ϣ
	
	//�����Ǵ���,��־,�ͱ�����Ϣ
	err_type errInfo;//���봦���еĴ�����Ϣ
	void* logInfo;//��־��Ϣ
	void* reportInfo;//������Ϣ
};

//�õ������������������Ϣ
//��_input��Ϣ���ص�_apply_info��
//����һ�����庯��
//�����Ҫ�����봦����Ϣ���ж�����
//�м���ܻ��кܶ�С����
void apply_get_input_info(apply_info* _apply_info,
	apply_input_info* _input);

//���������Ϣ�ĺϷ���
//�����Ƿ�����Ϣȱ©,�Ƿ�����Ϣ���﷨�ϴ��������ȱ©
void apply_check_input(apply_info* _apply_info);

//�������,�Ѵ�����Ϣ���͵�apply������
void apply_send_err(err_type* _errInfo);

//��Ϣ����
//������Ա�������Ϣת��Ϊ����ϵͳ��ʶ������������Ϣ
void apply_convert_info(apply_input_info* _org
	,apply_sys_info* _rlt);

//�����������Ϣ���͸�������Ϣ����ģ��
//�����뷢�͵�����ģ��,������һ������,�����δ��˵�����
//������Ϣģ�黹�����
void apply_send_info_to_survey(apply_sys_info* _info,void* survey);

//�������֪ͨ��Ϣ
//�ӵ����֪ͨ��Ϣ��,�ж��Ƿ�ͨ��
//���û��ͨ��,����д�����
//���ͨ��,����д洢
void apply_get_access_info(apply_sys_info* _info, void* _access);

//������
//���������¼,����
void apply_err_mgr(apply_sys_info* _info);

//�洢������
//���������,������ɹ���,������ô�����Ľ�������ݿ���
//���ݿⲿ�ֻ�Ӧ���
void apply_save(apply_info* _info, void* _db_table);

//�洢������Ϣ
//��������Ϣ���͸�����ϵͳ
//����ģ�黹Ӧ���
void apply_send_report(apply_info* _info, void* _report);

//��������
//��������Ĵ�����,�����Ի�������!!
void apply_undo(apply_info* _info);