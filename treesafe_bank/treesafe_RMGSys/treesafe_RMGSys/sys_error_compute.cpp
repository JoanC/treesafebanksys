#include "stdafx.h"
#include "sys_error_compute.h"

char err_info[MAX_ERR_INFO][10] ;

void init_sys_err(sys_err* _err){
	//��ʼ���ṹ��
	_err->type = err_no_err;
	memset(_err->info,'\0',MAX_ERR_INFO);

	
	strcpy(&err_info[0][0],"�޴���") ;
	strcpy(&err_info[0][1],"�û��������벻��") ;
	strcpy(&err_info[0][2],"��֤�벻ƥ��") ;
	strcpy(&err_info[0][3],"���ݿ���ʴ���") ;
	strcpy(&err_info[0][4],"����ȷ�ϳ���") ;
	strcpy(&err_info[0][5],"�������е����ݱȶ�ʱ����") ;
	strcpy(&err_info[0][6],"���ݿ����ʧ��") ;
	strcpy(&err_info[0][7],"�����봦��ʱ�������Ĵ���") ;
	strcpy(&err_info[0][8],"������Ϣ�˶��д�") ;
	strcpy(&err_info[0][9],"�޴��û�") ;
	
}

void sys_err_search(sys_err* _err){
	//ͨ�����ݿ�,���err�ṹ��

	strcpy(_err->info,&err_info[0][_err->type]) ;

}