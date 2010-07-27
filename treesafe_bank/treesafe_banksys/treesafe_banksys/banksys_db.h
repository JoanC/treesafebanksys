#ifndef _BANKSYS_DB_H_
#define _BANKSYS_DB_H_
#include "banksys_data_struct.h"


#endif
#include<stdio.h>
#include<conio.h>

#import "C:\\Program Files\\Common Files\\System\\ado\\msado25.tlb" no_namespace rename("EOF","ENDOFRS")

void ConnectDB(_ConnectionPtr &pConn) ;	   //connect the db

void DisconnectDB(_ConnectionPtr &pConn) ; //disconnect the db