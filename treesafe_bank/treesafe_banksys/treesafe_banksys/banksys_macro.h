//������һЩ���׵ĺ�ģ��

//��ָ��__p_nameΪNULL,�򷵻�void
#define ARRSERT_POINTER_NULL(__p_name) \
	if( (__p_name) == NULL)  \
	  return; \

//��������Ϊ__type���ڴ�,�����ָ��__p_malloc��
#define MALLOC_POINTER(__p_malloc , __type) \
	(__p_malloc) = (__type*)malloc( sizeof(__type) ); \

