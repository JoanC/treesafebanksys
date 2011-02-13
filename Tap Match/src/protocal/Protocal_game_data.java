package protocal;

public class Protocal_game_data {
	public static int targetChangeUIData = 0;//目标切换的数据
	public static int bigPicUIData = 1;//大图片的UI数据
	public static int smallPicDataStart = 2;//小图片数据的起始地址,其长度在<targetChangeUI>中定义
    
	public static String getFileName(int _mission){
    	//获取相应关卡的数据
    	return "game_data/mission_"+_mission+".txt";
    }
}
