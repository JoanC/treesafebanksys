#include "stdafx.h"
#include "sys_error_compute.h"

char err_info[10] [MAX_ERR_INFO];

void init_sys_err(sys_err* _err){
	//��ʼ���ṹ��
DEBUG_ERR_PRINT("initialize system error!\n");
	_err->type = err_no_err;
	memset(_err->info,'\0',MAX_ERR_INFO);

	
	strcpy(&err_info[0][0],"�޴���") ;
	strcpy(&err_info[1][0],"�û��������벻��") ;
	strcpy(&err_info[2][0],"��֤�벻ƥ��") ;
	strcpy(&err_info[3][0],"���ݿ���ʴ���") ;
	strcpy(&err_info[4][0],"����ȷ�ϳ���") ;
	strcpy(&err_info[5][0],"�������е����ݱȶ�ʱ����") ; 
	strcpy(&err_info[6][0],"���ݿ����ʧ��") ;
	strcpy(&err_info[7][0],"�����봦��ʱ�������Ĵ���") ;
	strcpy(&err_info[8][0],"������Ϣ�˶��д�") ;
	strcpy(&err_info[9][0],"�޴��û�") ;

}

void sys_err_search(sys_err* _err){
	//ͨ�����ݿ�,���err�ṹ��
DEBUG_ERR_PRINT("search error!\n");
	strcpy(_err->info,&err_info[_err->type][0]) ;

}