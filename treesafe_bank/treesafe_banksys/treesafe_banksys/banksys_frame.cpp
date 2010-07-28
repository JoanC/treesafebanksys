#include "stdafx.h"
#include "banksys_frame.h"
#include "banksys_macro.h"

banksys_frame* banksys_frame_allocate(){
	banksys_frame* _frame;
	//Ϊ����ģ�������ڴ�
	MALLOC_POINTER(_frame,banksys_frame,1);
	MALLOC_POINTER(_frame->sys_net,banksys_net,1);
	MALLOC_POINTER(_frame->sys_mid,banksys_mid,1);
	MALLOC_POINTER(_frame->sys_db,banksys_db,1);
	return _frame;
}

void banksys_frame_recieve(banksys_frame* _frame){
	//������������ʽ
	ARRSERT_POINTER_NULL(_frame)
}

void banksys_frame_send(banksys_frame* _frame){
	//��������ʽ
	ARRSERT_POINTER_NULL(_frame)
}

void banksys_frame_deallocate(banksys_frame* _frame){
	//�ͷ�ģ��
	ARRSERT_POINTER_NULL(_frame)
	free(_frame->sys_net);
	free(_frame->sys_mid);
	free(_frame->sys_db);
	free(_frame);
}