//存放了所有数据结构体

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