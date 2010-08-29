#include "database_mgr.h"
#include "sys_error_compute.h"
#include "sys_group_info.h"//分组信息

//模块12
//开始分组
//建立分组(房间)

//建立一个分组房间所需要的信息

#define GROUP_MAKER_ID_LEN 19//申请人的id长度
#define GROUP_MAKER_NAME 51//申请人的姓名长度
#define GROUP_MAKER_APPLY_ID 19//申请人的贷款申请的长度

//建立一个分组所需要的输入信息
struct group_start_info{
	//建立人是组长
	//建组人信息
	char goup_maker_id[GROUP_MAKER_ID_LEN];//建组人id长度
	char group_maker_name[GROUP_MAKER_NAME];//建组人姓名
	//建组人为建组而申请的申请号
	char group_maker_apply[GROUP_MAKER_APPLY_ID];
	//一个分组的基本信息
};
