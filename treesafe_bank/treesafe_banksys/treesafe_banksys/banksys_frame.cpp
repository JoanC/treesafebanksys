#include "stdafx.h"
#include "banksys_frame.h"

banksys_frame* banksys_frame_allocate(){
	banksys_frame* _frame;
	//为三个模块申请内存
	_frame = (banksys_frame*)malloc(sizeof(banksys_frame));
	_frame->sys_net = (banksys_net*)malloc(sizeof(banksys_net));
	_frame->sys_mid = (banksys_mid*)malloc(sizeof(banksys_mid));
	_frame->sys_db = (banksys_db*)malloc(sizeof(banksys_db));
	return _frame;
}

void banksys_frame_recieve(banksys_frame* _frame){
	//接受数据主函式
	if(!_frame) return;
}

void banksys_frame_send(banksys_frame* _frame){
	//发送主函式
	if(!_frame) return;
}

void banksys_frame_deallocate(banksys_frame* _frame){
	//释放模块
	if(!_frame) return;//已经为空
	free(_frame->sys_net);
	free(_frame->sys_mid);
	free(_frame->sys_db);
	free(_frame);
}