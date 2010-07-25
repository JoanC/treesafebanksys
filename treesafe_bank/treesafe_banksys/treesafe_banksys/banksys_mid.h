#include "stdafx.h"
//从网络中接受数据
void mid_get_data_from_net(net_recieved_info* _rec);
//从数据库中接受数据
void mid_get_data_from_db(bankDB_result_info* _rlt);
//向数据库中发送数据
void mid_send_data_to_db(bankDB_request_info* _req);
//向网络中发送数据
void mid_send_data_to_net( net_send_info* _send);
//将从网络中接受的数据转化为向数据库的请求
void mid_convert_rec_to_req(net_recieved_info* _rec , bankDB_request_info* _req);
//将从数据库接受的运行结果数据转化为数据
void mid_convert_rlt_to_send(bankDB_result_info* _rlt , net_send_info* _send);