#pragma once

//���ݿ��ܹ�����
//Ϊ����ģ���ṩ�ӿ�
//�Ա�(table)Ϊ�������struct�Ľṹ
#include "sys_db_struct.h"
#include<stdio.h>
#include<conio.h>

#import "C:\\Program Files\\Common Files\\System\\ado\\msado25.tlb" no_namespace rename("EOF","rsEOF")

#define PWD_LEN 16

const char CSFileName[] = "ConnStrs.txt" ;
const size_t connStrLen = 241  ; // max 3 lines
char *	GetIP() ;
bool GetConnStr(int index,char *outcome) ;
//index means in which line of the connStr.txt.
bool ConnectDB(_ConnectionPtr *pConn) ;

void DisconnectDB(_ConnectionPtr *pConn) ;

bool	Password_inquiry(_ConnectionPtr *_pConn,char *user_name , char *pwd_rlt) ;

void	Summery_inquiry(_ConnectionPtr *_pConn,char *user_name,sys_db_login *user_info) ;