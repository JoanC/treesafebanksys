//定义了一些简易的宏模板

//若指针__p_name为NULL,则返回void
#define ARRSERT_POINTER_NULL(__p_name) \
	if( (__p_name) == NULL)  \
	  return; \

//申请类型为__type的内存,存放在指针__p_malloc中
//并将内存全部出示化为0
#define MALLOC_POINTER(__p_malloc , __type) \
	(__p_malloc) = (__type*)calloc(1,sizeof(__type) ); \
	//memset((char*)__p_malloc + sizeof(__type*),'\0',strlen((char*)__p_malloc)); \


