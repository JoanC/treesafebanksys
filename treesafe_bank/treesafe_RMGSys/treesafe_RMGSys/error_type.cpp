#include "stdafx.h"
#include "error_type.h"

void err_search_info(int _err_id , err_info* _err_rlt){
	//����err��idȥ����������Ϣ
	//...db��ѯ
#ifdef DEBUG_ERR_INFO
	printf("search the error: %d",_err_id);
#endif
}