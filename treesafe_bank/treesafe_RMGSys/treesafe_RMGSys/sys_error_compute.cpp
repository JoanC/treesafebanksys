#include "stdafx.h"
#include "sys_error_compute.h"

void init_sys_err(sys_err* _err){
	//��ʼ���ṹ��
	_err->type = err_no_err;
	memset(_err->info,'\0',MAX_ERR_INFO);
}

void sys_err_search(sys_err* _err){
	//ͨ�����ݿ�,���err�ṹ��
	char err_info[10][MAX_ERR_INFO] ;
	strcpy(err_info[0],"�޴���") ;
	strcpy(err_info[1],"�û��������벻��") ;
	strcpy(err_info[2],"��֤�벻ƥ��") ;
	strcpy(err_info[3],"���ݿ���ʴ���") ;
	strcpy(err_info[4],"����ȷ�ϳ���") ;
	strcpy(err_info[5],"�������е����ݱȶ�ʱ����") ;
	strcpy(err_info[6],"���ݿ����ʧ��") ;
	strcpy(err_info[7],"�����봦��ʱ�������Ĵ���") ;
	strcpy(err_info[8],"������Ϣ�˶��д�") ;
	strcpy(err_info[9],"�޴��û�") ;


	strcpy(_err->info,err_info[_err->type]) ;

}