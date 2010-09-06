#pragma once
//���ģ��ŵ�����������ϵͳ�еĽṹ������
//����һ������,���������ݱ�ṹ��
//Ŀ���������罫���ݴ����,���Խ�����ȷ������ת��
//�������
//��������ݶ���������
/////////////////////////////////////////////////////////
//���ݿ�ģ��
//���������ݷ��͸����ݿ�
//�����а�����������������������
enum  en_require_type{
	CUST_INFO = 1 ,
	ACCOUNT_INFO = 2 ,
	LOAN_INFO = 3 ,
}  ;
struct bankDB_request_info{
	en_require_type		type ;
	char								id[19] ;
};

//�������
//��������ݶ���������
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
	bool		type ;						// true for ���� �� ��������
	double	balance ;					// balance
	int		month_remain ;		// if ���� ...
};
struct bankDB_result_loan_info{
	char		loan_num[19] ; 			//loan number , length:18 
	char		open_branch[51] ;		//opened in which branch
	char		open_date[11] ;			//when opened
	double	amount ;						//how much
	int		month_remain ;			//how many months remain
	double	monthly_return ;		//how much monthly return
};

struct bankDB_result_info{
	int		nCount ;	//an counter that shows how many results in the array(*pRlt). 
	void		*pRlt ;		//pointer to the result struct , such as bankDB_result_account_info...
};