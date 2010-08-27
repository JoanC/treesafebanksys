#include "stdafx.h"
#include "banksys_mid.h"
#include "banksys_macro.h"

//��������л�ȡ����
void mid_get_data_from_net(banksys_mid* _mid ,sys_Server* _net){
	ARRSERT_POINTER_NULL(_mid && _net)//�м�ת������Ч��_net��Ϊ��
		DEBUG_MID_PRINT("get recieved data from net\n")
		_mid->rec.cNetDataInfo = _net->rec.cNetDataInfo;
	if(_net->rec.stNetDataLength == 0){
		DEBUG_MID_PRINT("can't recieve data from net\n");
		return;
	}
	//Ϊ���ܵ��ַ�������һ���ռ�
	//��δfree��!!!
	_mid->rec.cNetDataInfo = (char*)malloc(PackageSize);
	memset(_mid->rec.cNetDataInfo,'\0',PackageSize);
	//strcpy(_mid->rec.cNetDataInfo,_net->rec.cNetDataInfo,);
	memcpy(_mid->rec.cNetDataInfo,_net->rec.cNetDataInfo
		,PackageSize);
	//_mid->rec = _net->rec;//�������
	//#ifdef DEBUG_MID_INFO
	DEBUG_MID_PRINT("recieve done\n")
		//#endif
		//#ifdef DEBUG_MID_INFO
		DEBUG_MID_PRINT("check recieved data , success\n");
	//#endif
}

//�����ݿ��н�������
void mid_get_data_from_db(banksys_mid* _mid ,banksys_db* _db){
	ARRSERT_POINTER_NULL(_mid && _db)//�м�ת������Ч�����ݿ���Ч
		DEBUG_MID_PRINT("get reslut data from db\n")
		ARRSERT_POINTER_NULL(_db->rlt.pRlt)
		_mid->rlt.nCount = _db->rlt.nCount;
	//���ʹ��memcpy��ᱨ��
	//	memcpy(_mid->rlt.pRlt,(char*)_db->rlt.pRlt,strlen((char*)_db->rlt.pRlt));
	int _size = 0;
	DB_INFO_SIZE(_mid->req.type,_size)
	//�����ڴ�!
	//��δ�ͷ�!
	_mid->rlt.pRlt = malloc(_size);
	memcpy((char*)_mid->rlt.pRlt,(char*)_db->rlt.pRlt,_size);
	//_mid->rlt = _db->rlt;//�������
	DEBUG_MID_PRINT("recieve done\n")
		DEBUG_MID_PRINT("check recieved data , success\n")
}

//�����ݿ��з�������
void mid_send_data_to_db(banksys_mid* _mid ,banksys_db* _db){
	ARRSERT_POINTER_NULL(_mid && _db)//�м�ת������Ч�����ݿ���Ч
		DEBUG_MID_PRINT("check send data , success\n")
		DEBUG_MID_PRINT("send request data to db\n")
		//����/����
		strcpy_s(_db->req.id,_mid->req.id);
	_db->req.type = _mid->req.type;
	//	_db->req = _mid->req;//��������
	DEBUG_MID_PRINT("send done\n")
}

//�������з�������
void mid_send_data_to_net(banksys_mid* _mid ,sys_Server* _net){
	ARRSERT_POINTER_NULL(_mid && _net)//�м�ת������Ч��_net��Ϊ��
		DEBUG_MID_PRINT("check send data , success\n")
		DEBUG_MID_PRINT("send result data to net\n")
		//���ͣ�����
		//??????
		//��֪�� stSendPaketSize��ô����
		//�ѵ�������PackageSize??
		
		ARRSERT_POINTER_NULL(_mid->send.cNetDataInfo)
		memcpy(_net->send.cNetDataInfo,_mid->send.cNetDataInfo,strlen(_mid->send.cNetDataInfo));
	DEBUG_MID_PRINT("send done\n")
}

//���������н��ܵ�����ת��Ϊ�����ݿ������
void mid_convert_rec_to_req(net_recieved_info* _rec , bankDB_request_info* _req){
	ARRSERT_POINTER_NULL(_rec) //��������Ϊ��
		DEBUG_MID_PRINT("convert from net_recieved_info to bankDB_request_info...\n")
		ARRSERT_POINTER_NULL(_rec->cNetDataInfo);
	memcpy(_req,_rec->cNetDataInfo,PackageSize);//���ݸ���
}
//�������ݿ���ܵ����н������ת��Ϊ����
void mid_convert_rlt_to_send(bankDB_result_info* _rlt , net_send_info* _send){
	ARRSERT_POINTER_NULL(_rlt)//�������Ϊ��
		DEBUG_MID_PRINT("convert from bankDB_result_info to net_send_info...\n")
		int _size = 0;
	    
		memcpy(_send->cNetDataInfo,_rlt,strlen((char*)_rlt));//���ݸ���
}

//һ�δ�net�н�������,�������ݴ���db�Ĺ���
void mid_recieve_frame(sys_Server* _net, 
	banksys_mid* _mid , banksys_db* _db){
		ARRSERT_POINTER_NULL(_mid && _net && _db)//������һ��Ϊ��
			//��ʼ��net����һ������
			mid_get_data_from_net(_mid , _net);
		//ת������
		mid_convert_rec_to_req(&_mid->rec , &_mid->req);
		//���������ݷ���db
		mid_send_data_to_db(_mid,_db);
}

//һ�δ�db�н�������,�������ݴ���net�Ĺ���
void mid_send_frame(sys_Server* _net,
	banksys_mid* _mid ,banksys_db* _db){
		if(!(_mid && _net && _db)) return;
		//��ʼ�����ݿ��н���һ������
		mid_get_data_from_db(_mid,_db);
		//ת������
		mid_convert_rlt_to_send(&_mid->rlt,&_mid->send);
		//�����󷢸�net
		mid_send_data_to_net(_mid,_net);
}

