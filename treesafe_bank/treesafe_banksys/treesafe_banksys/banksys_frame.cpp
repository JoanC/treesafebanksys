#include "stdafx.h"
#include "banksys_frame.h"
#include "banksys_macro.h"

banksys_frame* banksys_frame_allocate(){
	banksys_frame* _frame;
	//为三个模块申请内存
	MALLOC_POINTER(_frame,banksys_frame,1);
	MALLOC_POINTER(_frame->sys_net,banksys_net,1);
	//_frame->sys_net = (banksys_net*)malloc(sizeof(banksys_net));
	MALLOC_POINTER(_frame->sys_mid,banksys_mid,1);
	MALLOC_POINTER(_frame->sys_db,banksys_db,1);
	return _frame;
}

void banksys_frame_recieve(banksys_frame* _frame){
	//接受数据主函式
	ARRSERT_POINTER_NULL(_frame)
	net_recieve_frame(_frame->sys_net);
	mid_recieve_frame(_frame->sys_net,_frame->sys_mid,_frame->sys_db);
	//db ... 
}

void banksys_frame_db(banksys_frame* _frame){
	_ConnectionPtr* _pConn = NULL;//数据库连接指针
	ARRSERT_POINTER_NULL(_pConn)
	MALLOC_POINTER(_pConn,_ConnectionPtr,1);
	Loan_info_inquiry(_frame->sys_db,_pConn);//请求数据
	InquiryResult(_frame->sys_db,_pConn);//返回数据
}

void banksys_frame_send(banksys_frame* _frame){
	//发送主函式
	ARRSERT_POINTER_NULL(_frame)
	//db...
	mid_send_frame(_frame->sys_net,_frame->sys_mid,_frame->sys_db);
	net_send_frame(_frame->sys_net);
}

void banksys_frame_deallocate(banksys_frame* _frame){
	//释放模块
	ARRSERT_POINTER_NULL(_frame)
	free(_frame->sys_net);
	free(_frame->sys_mid);
	free(_frame->sys_db);
	free(_frame);
}