//银行数据库服务器端的函数流程
//分为后台数据库的调用和网络传入传输

//数据库模块和网络模块可以剥离出来,中间设计一个通用的数据接口

//request_type : 申请类型,可拓展
struct net_request_info{
	int request_type;//...
	void* _info;
};

//packet结构体,是一个通用结构
struct net_packet{
	void* _data;
	//...
};
//接受的信息
//是网络段处理后的数据,在中间的过渡模块中可以被处理成一个数据库层可用的数据
struct net_recieved_info{
	void* _data;
};

//网络发送的信息
struct net_send_info{
	void* _data;
};

//将请求数据发送给数据库
//数据中包括了请求与请求的相关数据
struct bankDB_request_info{
	int type;
	int index;
};

//结果数据
//输出的数据都存入其中
struct bankDB_result_info{
	void* data;
};
//--------------------------------------------------------------------------
//网络接口处理部分
//建立连接和释放连接
void net_add_connection();
void net_release_connection();
//银行网络模块等待请求
void net_wait_for_request(net_request_info _request);

//网络模块接受数据包
void net_recieve_paket();//从外界接收一个数据包

void net_recieve_data();//从外界接受一段数据,其实是将数据包整合

//发送数据
void net_send_data(net_send_info* _send);

//--------------------------------------------------------------------------
//过度模块处理函数

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
//--------------------------------------------------------------------------
//数据库处理部分

//通过对_data的解析,应该对之进行不同的操作
//但是这些操作都在一个方法中进行
void bankDB_Operate(bankDB_request_info* _req , bankDB_result_info* _rlt, 
	 bankDB_result_info* (*operate_func) (bankDB_request_info* _req));

//...下面是各种数据库的工具函数
//...


