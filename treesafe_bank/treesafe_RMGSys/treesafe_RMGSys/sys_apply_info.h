//���봦������

/*
//�����˻�����Ϣ
������������
�Ա�
���䣺
֤�����ͣ�
֤�����룺
��ͥסַ��            �������룺
סլȨ���������� ������ ������
��ϵ�绰��
������ϵ�绰��
�ܽ���״������˶ʿ������ ������ ����ר ������ �����м�����

*/

//���¶������û����������еĸ����ַ�������󳤶�

#define APPLY_CUST_ID_LEN 19 //���������֤�ų���
#define APPLY_CUST_NAME_LEN 51//��������
#define APPLY_CARD_NUMBER_LEN 19//֤�����볤��
#define APPLY_CUST_ADDR_LEN 51//��ͥסַ����
#define APPLY_CUST_ZIP_CODE_LEN 7 //�������볤��
#define APPLY_CUST_TEL_LEN 19 //��ϵ�绰����

enum APPLY_GENDER_TYPE {apply_info_male , apply_info_female};//�Ա�ֵ
enum APPLY_CARD_TYPE{id_card/*���֤*/,��ilitary_card/*����֤*/};//֤������
enum APPLY_CUST_HOUSING_TENURE{own/*����*/,lease/*����*/,other/*����*/};//ס��Ȩ��
enum APPLY_CUST_EDUCATION_DEGREE{
	master_and_above,/*˶ʿ������*/
	undergraduate,/*����*/
	college,/*��ר*/
	high_school,/*����*/
	primary_and_below/*Сѧ������*/
};//�ܽ����̶�

//����Ա�������Ϣ�ṹ
struct apply_custmor_info{
	char cust_name[APPLY_CUST_NAME_LEN];//��������Ϣ
	APPLY_GENDER_TYPE cust_gender;//�������Ա�
	int cust_age;//�������Ա�
	APPLY_CARD_TYPE cust_card_type;//֤������
	char cust_id[APPLY_CARD_NUMBER_LEN];//֤��id
	char cust_tel_num[APPLY_CUST_TEL_LEN];//��ϵ�绰
	char cust_other_tel_num[APPLY_CUST_TEL_LEN];//������ϵ�绰
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