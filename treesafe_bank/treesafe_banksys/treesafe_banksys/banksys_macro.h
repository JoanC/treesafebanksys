//定义了一些简易的宏模板
#define DEBUG_MID_INFO_TEST true

//若指针__p_name为NULL,则返回void
#define ARRSERT_POINTER_NULL(__p_name) \
	if( (__p_name) == NULL)  \
	  return; \

//申请类型为__type的内存,存放在指针__p_malloc中
//实际是一个长度为n的数组
//n = 1时，就是一个一般的内存申请
//并将内存全部初始化为0
#define MALLOC_POINTER(__p_malloc , _type , _len) \
	(__p_malloc) = (_type*)calloc(_len,sizeof(_type) ); \




