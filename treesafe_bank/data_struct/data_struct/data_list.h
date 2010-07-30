#define __LIST_NODE_NAME(_type) _list_node_##_type

#define LIST(_type) __LIST_NODE_NAME(_type)

#define __DATA_LIST_NODE(_type) \
struct __LIST_NODE_NAME(_type){ \
	_type _data; \
    __LIST_NODE_NAME(_type)* _next; \
} ;

#define __LIST_DEC(_type){
   static bool is_dec; 
}

#define _LIST_ADD_NODE(_type,_pos,_new){\
   if(!(_pos&&_new)) return;\
   if(!_pos->_next){\
       _pos->_next = _new; \
       _new->_next = NULL; \
	   return; \
   } \

}

/*
#define _LIST_DEC(_type) \
  __DATA_LIST_NODE(_type)

#define __LIST_ALLOC(__list_head) { \
     __list_head = (list_node*)malloc(sizeof(list_node));\
	 __list_head->_next = NULL; \
  } \


//_type链表类型
//_pos,_new都是__node_type类型,_rlt是bool*
#define __LIST_ADD_NODE(__node_type, _pos , _new , _rlt){ \
	if(_new == NULL || _pos == NULL){ \
	  *_rlt = false; \
      return; \
	}\
	if(_pos->_next == NULL){ \
	   _pos->_next = _new; \
	   _new->_next = NULL; \
	}\
	__node_type* _temp = _pos->_next; \
	_pos->_next = _new; \
	_new->_next = _temp; \
	return; \
} \*/


void test();