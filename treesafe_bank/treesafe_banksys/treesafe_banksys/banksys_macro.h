//定义了一些简易的宏模板

#define ARRSERT_POINTER_NULL(__p_name) \
	if( (__p_name) == NULL)  \
	  return; \


#define MALLOC_POINTER(__p_malloc , __type) \
	(__p_malloc) = (__type*)malloc( sizeof(__type) ); \

