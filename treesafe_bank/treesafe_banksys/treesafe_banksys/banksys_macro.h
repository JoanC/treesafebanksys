//������һЩ���׵ĺ�ģ��

//��ָ��__p_nameΪNULL,�򷵻�void
#define ARRSERT_POINTER_NULL(__p_name) \
	if( (__p_name) == NULL)  \
	  return; \

//��������Ϊ__type���ڴ�,�����ָ��__p_malloc��
//�����ڴ�ȫ����ʾ��Ϊ0
#define MALLOC_POINTER(__p_malloc , __type) \
	(__p_malloc) = (__type*)calloc(1,sizeof(__type) ); \
	//memset((char*)__p_malloc + sizeof(__type*),'\0',strlen((char*)__p_malloc)); \


