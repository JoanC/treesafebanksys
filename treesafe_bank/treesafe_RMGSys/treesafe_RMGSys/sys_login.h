//��½ϵͳ

//��½Ȩ��
//����Ա,һ���û�...
enum login_competence{
	admin,
	user
	//...other competence
};

struct login_info{
	//��½��Ϣ�洢
	login_competence compe;
	//�û���
	char* user_name;//�û���
	char* user_pwd;//�û�����
	char* verify_code;//��֤��
	//��½��Ϣ

};