package jiraiya.game.data;

/*
 * ����:�����
 * ʱ��:2011.1.31
 * ˵��:����������Ϸ��������Ӧ�����������Ϣ	
 * 			
 * 
 * �޸�:
 * ����:
 * ˵��:
 */
public class MainGame_data_struct {
	Picture_big_struct bigPic = new Picture_big_struct();//��ͼƬ���������
	SmallPic_changeUI_data targetChange = new SmallPic_changeUI_data();//Ŀ��СͼƬ���л�����
	public Picture_big_struct getBigPic() {
		return bigPic;
	}
	public void setBigPic(Picture_big_struct bigPic) {
		this.bigPic = bigPic;
	}
	public SmallPic_changeUI_data getTargetChange() {
		return targetChange;
	}
	public void setTargetChange(SmallPic_changeUI_data targetChange) {
		this.targetChange = targetChange;
	}
	
}
