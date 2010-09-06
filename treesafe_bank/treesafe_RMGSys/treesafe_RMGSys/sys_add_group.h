#pragma once 
#include "database_mgr.h"

//S1.1
//初始化数据
void init_add_group(group_member_info *_Outcome) ;


//S1.2
//从char *_Data 中读取数据到group_member_info *_Outcome
void decode_group_member_info(const char *_Data,int _NumOfMembers,group_member_info *_Outcome) ;

//S1.3
//数据库添加组
bool add_group_to_db(group_member_info *_info) ;

//S
void add_group_frame(const char *_Data,int _NumOfMember,int *_LenOfOutcome) ;