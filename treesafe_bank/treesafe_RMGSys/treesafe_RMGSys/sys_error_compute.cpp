#include "stdafx.h"
#include "sys_error_compute.h"

void init_sys_err(sys_err* _err){
	//��ʼ���ṹ��
	_err->type = err_no_err;
	memset(_err->info,'\0',MAX_ERR_INFO);
}

void sys_err_search(sys_err* _err){
	//ͨ�����ݿ�,���err�ṹ��
}