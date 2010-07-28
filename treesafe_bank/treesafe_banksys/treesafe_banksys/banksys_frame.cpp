#include "stdafx.h"
#include "banksys_frame.h"

void bank_frame_allocate(banksys_frame* _frame){
	//为三个模块申请内存
	_frame->sys_net = (banksys_net*)malloc(sizeof(banksys_net));
	_frame->sys_mid = (banksys_mid*)malloc(sizeof(banksys_mid));
	_frame->sys_db = (banksys_db*)malloc(sizeof(banksys_db));
}


void banksys_frame_deallocate(banksys_frame* _frame){
	//释放模块
	if(!_frame) return;//已经为空
	free(_frame->sys_net);
	free(_frame->sys_mid);
	free(_frame->sys_db);
}