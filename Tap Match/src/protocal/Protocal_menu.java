package protocal;

public class Protocal_menu {
	public static final int menu_play_id = 0;
	public static final int menu_select_id = 1;
	public static final int menu_highscore_id = 2;
	public static final int menu_about_id = 3;
	public static final int menu_help_id = 4;
	public static final int menu_quit_id = 5;
	public static final String[] callBackFunc = {"onPlayNewGame","onSelectMission"
			,"onHighScore","onAbout","onHelp","onQuit"};//�ص�����
	//-----------------------------------------------------------
	//�������ļ����ݴ���Э��
	public static final String menuDataFileName = "layer_data/Menu_Layer.txt";//�����ļ���
	public static final int menuGrobalInfo = 0;//�˵����걣�����ļ��ĵ�һ��λ��,��ͬ��
	public static final int menuItemInfoStartID = 1;//�˵������Ϣ�����ڴ�λ��1��ʼ��EndID����Ϣ��
	public static final int menuItemInfoEndID = 6;//�˵�����Ϣ���˽���
}
