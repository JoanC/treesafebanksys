#pragma once 
#include "database_mgr.h"

//S1.1
//��ʼ������
void init_add_group(group_member_info *_Outcome) ;


//S1.2
//��char *_Data �ж�ȡ���ݵ�group_member_info *_Outcome
void decode_group_member_info(const char *_Data,int _NumOfMembers,group_member_info *_Outcome) ;

//S1.3
//���ݿ������
bool add_group_to_db(group_member_info *_info) ;

//S
void add_group_frame(const char *_Data,int _NumOfMember,int *_LenOfOutcome) ;