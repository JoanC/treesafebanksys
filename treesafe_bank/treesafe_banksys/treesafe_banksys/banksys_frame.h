#include "banksys_db.h"
#include "banksys_mid.h"
#include "banksys_net.h"
#include "banksys_data_struct.h"

//银行子系统的主函式分解

//建立所有模块
//包括内存的分配和初始化
//返回一个frame结构体的指针
void banksys_frame_allocate(banksys_frame* _frame);

//接受数据主函式
void banksys_frame_recieve(banksys_frame* _frame);

//发送主函式
void banksys_frame_send(banksys_frame* _frame);

//释放模块
void banksys_frame_deallocate(banksys_frame* _frame);