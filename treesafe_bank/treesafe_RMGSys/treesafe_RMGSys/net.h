#pragma once
enum DataType {PACKAGE80,NETDATA};
const int PackageSize = 80;
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

#define BANKIP "127.0.0.1"
#define BANKPORT 4999