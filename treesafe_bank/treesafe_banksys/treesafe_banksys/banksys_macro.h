//������һЩ���׵ĺ�ģ��
#define DEBUG_MID_INFO_TEST true

//��ָ��__p_nameΪNULL,�򷵻�void
#define ARRSERT_POINTER_NULL(__p_name) \
	if( (__p_name) == NULL)  \
	  return; \

//��������Ϊ__type���ڴ�,�����ָ��__p_malloc��
//ʵ����һ������Ϊn������
//n = 1ʱ������һ��һ����ڴ�����
//�����ڴ�ȫ����ʼ��Ϊ0
#define MALLOC_POINTER(__p_malloc , _type , _len) \
	(__p_malloc) = (_type*)calloc(_len,sizeof(_type) ); \




