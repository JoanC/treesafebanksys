const int BUF_SIZE = 80;
typedef int DataType;
//net info
//netType:
//      0:  this just a 80kb package
//      1:  this is total info of net data
struct NetData
{
	DataType netType;
	size_t stNetDataLength;
	char* cNetDataInfo;
};

typedef NetData net_recieved_info;
typedef NetData net_send_info;