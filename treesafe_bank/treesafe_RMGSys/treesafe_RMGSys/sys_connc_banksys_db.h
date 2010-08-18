//这个模块放的是在银行子系统中的结构体声明
//包括一个请求,和若干数据表结构体
//目的在于网络将数据传输后,可以进行正确的类型转换
//结果数据
//输出的数据都存入其中
struct bankDB_result_cust_info{
	char		id[19] ;			//id
	char		name[51] ;		//name
	bool		gend ;						// "true" for boy...
	int		age ;						//age
	char		phone_num[12] ;	//...
	char		home_addr[51] ;	//...
} ;
struct	bankDB_result_account_info{
	char		account_num[19] ;	// account number , length:18
	char		open_branch[51] ;	// opened in which branch
	char		open_date[11] ;		// when opened
	bool		type ;						// true for 活期 ， 否则死期
	double	balance ;					// balance
	int		month_remain ;		// if 死期 ...
};
struct bankDB_result_loan_info{
	char		loan_num[19] ; 			//loan number , length:18 
	char		open_branch[51] ;		//opened in which branch
	char		open_date[11] ;			//when opened
	double	amount ;						//how much
	int		month_remain ;			//how many months remain
	double	monthly_return ;		//how much monthly return
};

struct bankDB_result_info
{
	int		nCount ;	//an counter that shows how many results in the array(*pRlt). 
	void		*pRlt ;		//pointer to the result struct , such as bankDB_result_account_info...
};