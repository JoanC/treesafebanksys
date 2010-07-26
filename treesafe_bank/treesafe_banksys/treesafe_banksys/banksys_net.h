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

#endif
