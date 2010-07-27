#ifndef _BANKSYS_NET_H_
#define _BANKSYS_NET_H_


#include"banksys_data_struct.h"



//add connection
void net_add_connection(banksys_net &sServer);

//release connection
void net_release_connection(banksys_net &sServer);

//wait for request
void net_wait_for_request(banksys_net &sServer);

//recieve net data(the size of data is less than 80 bytes)
void net_recieve_data(banksys_net &sServer);

//send net data(the size of data is less than 80 bytes)
void net_send_data(banksys_net &sServer);

//jiraiya's code
//把上面的小函数合并成主函式
//接受主函式
//接受包 --> 整合为接收信息 --> 发送给mid 的过程...
void net_recieve_frame(banksys_mid* _mid,banksys_net* sServer);


//jiraiya's code
//发送主函式
//从mid接受信息 --> 发送信息
void net_send_frame(banksys_mid* _mid,banksys_net* sServer);


#endif
