#include "query_user_info.h"
#include "database_mgr.h"
//20.1
//jiraiya 完成
//初始化结构体


//20.3
//sunni完成
//得到所有农民的人数,这些人的条件是有被审核通过的申请
//结果保存在一个数字中
void user_query_arr_count(int* _count);

//20.4
//sunni完成
//得到一个数组
//数组中存放这些农民的信息
//结果存入一个指针中
void user_query_arr(user_query_info* user_array,int* _arr_size);