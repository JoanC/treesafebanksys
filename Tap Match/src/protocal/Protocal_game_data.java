package protocal;

public class Protocal_game_data {
	public static int targetChangeUIData = 0;//Ŀ���л�������
	public static int bigPicUIData = 1;//��ͼƬ��UI����
	public static int smallPicDataStart = 2;//СͼƬ���ݵ���ʼ��ַ,�䳤����<targetChangeUI>�ж���
    
	public static String getFileName(int _mission){
    	//��ȡ��Ӧ�ؿ�������
    	return "game_data/mission_"+_mission+".txt";
    }
}
