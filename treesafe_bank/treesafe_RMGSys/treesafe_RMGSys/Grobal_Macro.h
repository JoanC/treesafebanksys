#pragma once

//全局宏
//由Jiraiya完成

//debug 调试代码
//与银行端进行网络测试的代码段
//#define TEST_BANK_SYS_CONNECTION


//reg测试的代码段
//#define TEST_REG_MODLE

//research_exact 的测试代码段
//#define TEST_RESEARCH_EXACT_MODLE



//模块1：网络模块
#define DEBUG_NET
#if defined DEBUG_NET
#define DEBUG_NET_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_NET(x) {};
#endif

//模块2: 命令模块
#define DEBUG_COMMAND
#if defined DEBUG_COMMAND
#define DEBUG_COMMAND_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_COMMAND(x) {};
#endif


//模块3：登录模块
#define DEBUG_LOGIN_INFO
#if defined DEBUG_LOGIN_INFO
#define DEBUG_LOGIN_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_LOGIN_INFO(x) {};
#endif

//模块4: 错误模块
#define DEBUG_ERR_INFO
#if defined DEBUG_ERR_INFO
#define DEBUG_ERR_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_ERR_PRINT(x){};
#endif

//模块6：注册模块
#define DEBUG_REG_INFO
#if defined DEBUG_REG_INFO
#define DEBUG_REG_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_ERR_PRINT(x){};
#endif

//模块7：申请模块
#define DEBUG_APPLY
#if defined DEBUG_APPLY
#define DEBUG_APPLY_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_APPLY_PRINT(x){};
#endif

//模块8 ：审核模块
#define DEBUG_RESEARCH
#if defined DEBUG_RESEARCH
#define DEBUG_RESEARCH_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_RESEARCH_PRINT(x){};
#endif

//模块9：审核信息结果提交模块
#define DEBUG_RESEARCH_COMMIT
#if defined DEBUG_RESEARCH_COMMIT
#define DEBUG_RESEARCH_COMMIT_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_RESEARCH_COMMITs_PRINT(x){};
#endif

//模块11：打分模块
#define DEBUG_GET_SCORE
#if defined DEBUG_GET_SCORE
#define DEBUG_GET_SCORE_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_GET_SOCRE_PRINT(x){};
#endif

//模块15：管理员添加雇员模块
#define DEBUG_ADMIN_ADD_EMLOYEE
#if defined DEBUG_ADMIN_ADD_EMLOYEE
#define DEBUG_ADMIN_ADD_EMLOYEE_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_ADMIN_ADD_EMLOYEE(x){};
#endif

//模块16：删除雇员信息模块
#define DEBUG_ADMIN_DEL_EMLOYEE
#if defined DEBUG_ADMIN_DEL_EMLOYEE
#define DEBUG_ADMIN_DEL_EMLOYEE_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_ADMIN_DEL_EMLOYEE(x){};
#endif

//模块18 ：调查结果查询模块
#define DEBUG_RESEARCH_QUERY
#if defined DEBUG_RESEARCH_QUERY
#define DEBUG_RESEARCH_QUERY_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_RESEARCH_QUERY(x){};
#endif

//模块19：雇员信息查询
#define DEBUG_EMPLOYEE_QUERY
#if defined DEBUG_EMPLOYEE_QUERY
#define DEBUG_EMPLOYEE_QUERY_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_EMPLOYEE_QUERY(x){};
#endif

//模块20：查找用户信息数组
#define DEBUG_USER_QUERY
#if defined DEBUG_USER_QUERY
#define DEBUG_USER_QUERY_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_USER_QUERY(x){};
#endif

//模块21：风险评估结果查询
#define DEBUG_SCORE_QUERY
#if defined DEBUG_SCORE_QUERY
#define DEBUG_SCORE_QUERY_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_SCORE_QUERY(x){};
#endif

//模块22：查询单个用户信息
#define DEBUG_ONE_USER_INFO
#if defined DEBUG_ONE_USER_INFO
#define DEBUG_ONE_USER_INFO_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_ONE_USER_INFO(x){};
#endif

//模块23：查询雇员数组信息
#define DEBUG_QUERY_ARRAY
#if defined DEBUG_QUERY_ARRAY
#define DEBUG_QUERY_ARRAY_PRINT(__debug_info) printf(__debug_info);
#else
#define DEBUG_QUERY_ARRAY(x){};
#endif



//utf-7的编码转换
//将一个adsc读入,将其解码
#define DECODE_UTF7_TO_ASC(__src_code)\
{\
	WCHAR* _temp = (WCHAR*)calloc(strlen(__src_code),sizeof(wchar_t)); \
    MultiByteToWideChar(CP_UTF7,0,__src_code,-1,_temp,strlen(__src_code));\
	WideCharToMultiByte(CP_ACP,0,_temp,strlen(__src_code),__src_code,strlen(__src_code),NULL,0);\
}
