//网络服务层由ducky完成

//网络服务层是整个计算过程中的首和尾
//网络接收 --> 中转判别 --> 子流程将字符串解析 --> 子流程将结果再转化成字符串 --> 网络发送

//此模块高度独立,要做的就是将一个net_data的结构体发送和接收

//接受的数据是一个类型和一个字符串及这个侧内存块的长度
typedef int COMMAND_TYPE;
typedef char* NET_INFO;
typedef int DATA_LEN;

struct sys_net_data{
	COMMAND_TYPE type;
	DATA_LEN len;//为memcpy准备，否则很容易出错!!
	NET_INFO data;//字符串的形式接受和发送
};

/********************************************************/
//以下这两个函式必须实现

//接收主函式
//将接受的数据转化成一个sys_net_data的结构体
void sys_net_recieve(sys_net_data* _rev);

//发送主函式
//将一个sys_net_data的结构体发送给网页
void sys_net_send(sys_net_data* _send);

//其他的辅助子函式包含在以上两个函式之中
//对于其它代码,只有以上两个主函式可以调用