enum APPLY_GENDER_TYPE {apply_info_male , apply_info_female};

//���봦������
#define APPLY_CUST_ID_LEN 19 //���������֤�ų���
#define APPLY_CUST_NAME_LEN 51//��������

//����Ա�������Ϣ�ṹ
struct apply_custmor_info{
	//������(��Ա)����Ϣ
	//...�д��������ȷ��
	char cust_id[APPLY_CUST_ID_LEN];
	//����
	char cust_name[APPLY_CUST_NAME_LEN];
	//�Ա�
	APPLY_GENDER_TYPE cust_gender;
	//����
	int cust_age;
};

struct apply_loan_info{
	//��������������������Ϣ
	//...�д��������ȷ��
};

struct apply_input_info{
	//���������˵Ļ�����Ϣ
	apply_custmor_info input_basic_info;
	//�������ص�������Ϣ
	apply_loan_info input_loan_info;
};

//���봦���������Ϣ�ṹ
struct apply_info{
	//��Ҫ������������Ϣ
	//������Ϊ:
	//ֻ��Ҫ�ѶԱȻ�����Ϣʱ�Ĵ��󴫸���ǰ��ҳ��
	//���û�д���
	//���ʾ���������ڽ������...
	//�����Ǵ�����Ϣ,���������Ϣ��ʾno_err,��������ɹ�
	sys_err errInfo;//���봦���еĴ�����Ϣ
};

//���봦�������ģ��
struct apply_modle{
	apply_input_info input_info;//������Ϣ
	apply_custmor_info db_cust_info;//�����ݿ��ж������Ϣ
	apply_info rlt_info;//�洢��������е���Ϣ,��Ϊ��������������
};