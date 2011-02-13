package protocal;

public class Protocal_menu {
	public static final int menu_play_id = 0;
	public static final int menu_select_id = 1;
	public static final int menu_highscore_id = 2;
	public static final int menu_about_id = 3;
	public static final int menu_help_id = 4;
	public static final int menu_quit_id = 5;
	public static final String[] callBackFunc = {"onPlayNewGame","onSelectMission"
			,"onHighScore","onAbout","onHelp","onQuit"};//回调函数
	//-----------------------------------------------------------
	//下面是文件数据传输协议
	public static final String menuDataFileName = "layer_data/Menu_Layer.txt";//数据文件名
	public static final int menuGrobalInfo = 0;//菜单坐标保存在文件的第一个位置,下同理
	public static final int menuItemInfoStartID = 1;//菜单项的信息保存在从位置1开始到EndID的信息中
	public static final int menuItemInfoEndID = 6;//菜单项信息到此结束
}
