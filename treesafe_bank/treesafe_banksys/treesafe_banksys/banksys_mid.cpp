#include "stdafx.h"
#include "banksys_mid.h"
#include "banksys_macro.h"

//从网络层中获取数据
void mid_get_data_from_net(banksys_mid* _mid ,sys_Server* _net){
	ARRSERT_POINTER_NULL(_mid && _net)//中间转换器无效或_net层为空
		DEBUG_MID_PRINT("get recieved data from net\n")
		_mid->rec.cNetDataInfo = _net->rec.cNetDataInfo;
	if(_net->rec.stNetDataLength == 0){
		DEBUG_MID_PRINT("can't recieve data from net\n");
		return;
	}
	//为接受的字符串开辟一个空间
	//尚未free掉!!!
	_mid->rec.cNetDataInfo = (char*)malloc(PackageSize);
	memset(_mid->rec.cNetDataInfo,'\0',PackageSize);
	//strcpy(_mid->rec.cNetDataInfo,_net->rec.cNetDataInfo,);
	memcpy(_mid->rec.cNetDataInfo,_net->rec.cNetDataInfo
		,PackageSize);
	//_mid->rec = _net->rec;//获得数据
	//#ifdef DEBUG_MID_INFO
	DEBUG_MID_PRINT("recieve done\n")
		//#endif
		//#ifdef DEBUG_MID_INFO
		DEBUG_MID_PRINT("check recieved data , success\n");
	//#endif
}

//从数据库中接受数据
void mid_get_data_from_db(banksys_mid* _mid ,banksys_db* _db){
	ARRSERT_POINTER_NULL(_mid && _db)//中间转换器无效或数据库无效
		DEBUG_MID_PRINT("get reslut data from db\n")
		ARRSERT_POINTER_NULL(_db->rlt.pRlt)
		_mid->rlt.nCount = _db->rlt.nCount;
	//如果使用memcpy则会报错
	//	memcpy(_mid->rlt.pRlt,(char*)_db->rlt.pRlt,strlen((char*)_db->rlt.pRlt));
	int _size = 0;
	DB_INFO_SIZE(_mid->req.type,_size)
	//分配内存!
	//尚未释放!
	_mid->rlt.pRlt = malloc(_size);
	memcpy((char*)_mid->rlt.pRlt,(char*)_db->rlt.pRlt,_size);
	//_mid->rlt = _db->rlt;//获得数据
	DEBUG_MID_PRINT("recieve done\n")
		DEBUG_MID_PRINT("check recieved data , success\n")
}

//向数据库中发送数据
void mid_send_data_to_db(banksys_mid* _mid ,banksys_db* _db){
	ARRSERT_POINTER_NULL(_mid && _db)//中间转换器无效或数据库无效
		DEBUG_MID_PRINT("check send data , success\n")
		DEBUG_MID_PRINT("send request data to db\n")
		//发送/传递
		strcpy_s(_db->req.id,_mid->req.id);
	_db->req.type = _mid->req.type;
	//	_db->req = _mid->req;//发送数据
	DEBUG_MID_PRINT("send done\n")
}

//向网络中发送数据
void mid_send_data_to_net(banksys_mid* _mid ,sys_Server* _net){
	ARRSERT_POINTER_NULL(_mid && _net)//中间转换器无效或_net层为空
		DEBUG_MID_PRINT("check send data , success\n")
		DEBUG_MID_PRINT("send result data to net\n")
		//发送，传递
		//??????
		//不知道 stSendPaketSize怎么传递
		//难道传的是PackageSize??
		
		ARRSERT_POINTER_NULL(_mid->send.cNetDataInfo)
		memcpy(_net->send.cNetDataInfo,_mid->send.cNetDataInfo,strlen(_mid->send.cNetDataInfo));
	DEBUG_MID_PRINT("send done\n")
}

//将从网络中接受的数据转化为向数据库的请求
void mid_convert_rec_to_req(net_recieved_info* _rec , bankDB_request_info* _req){
	ARRSERT_POINTER_NULL(_rec) //接收数据为空
		DEBUG_MID_PRINT("convert from net_recieved_info to bankDB_request_info...\n")
		ARRSERT_POINTER_NULL(_rec->cNetDataInfo);
	memcpy(_req,_rec->cNetDataInfo,PackageSize);//数据复制
}
//将从数据库接受的运行结果数据转化为数据
void mid_convert_rlt_to_send(bankDB_result_info* _rlt , net_send_info* _send){
	ARRSERT_POINTER_NULL(_rlt)//结果数据为空
		DEBUG_MID_PRINT("convert from bankDB_result_info to net_send_info...\n")
		int _size = 0;
	    
		memcpy(_send->cNetDataInfo,_rlt,strlen((char*)_rlt));//数据复制
}

//一次从net中接受数据,并把数据传给db的过程
void mid_recieve_frame(sys_Server* _net, 
	banksys_mid* _mid , banksys_db* _db){
		ARRSERT_POINTER_NULL(_mid && _net && _db)//不可有一者为空
			//开始从net接受一个数据
			mid_get_data_from_net(_mid , _net);
		//转化数据
		mid_convert_rec_to_req(&_mid->rec , &_mid->req);
		//将请求数据发给db
		mid_send_data_to_db(_mid,_db);
}

//一次从db中接受数据,并把数据传给net的过程
void mid_send_frame(sys_Server* _net,
	banksys_mid* _mid ,banksys_db* _db){
		if(!(_mid && _net && _db)) return;
		//开始从数据库中接受一个数据
		mid_get_data_from_db(_mid,_db);
		//转化数据
		mid_convert_rlt_to_send(&_mid->rlt,&_mid->send);
		//将请求发给net
		mid_send_data_to_net(_mid,_net);
}

