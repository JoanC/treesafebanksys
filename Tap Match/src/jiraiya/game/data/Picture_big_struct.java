package jiraiya.game.data;

import java.util.Vector;

/*
 * ����:�����
 * ʱ��:2011.1.30
 * ˵��:�����˴�ͼƬ�Ļ�������	
 * 			
 * �޸�:
 * ����:
 * ˵��:
 */

public class Picture_big_struct {
	sprite_data_struct bigPic;// ��ͼƬ��UI����
	Vector<Picture_small_struct> targetsData = new Vector<Picture_small_struct>();// Ŀ��СͼƬ�����ݼ���
	int status;//��ͼ��״̬,����״ֵ̬������Protocal_bigPicStatus����
	public sprite_data_struct getBigPic() {
		return bigPic;
	}
	public void setBigPic(sprite_data_struct bigPic) {
		this.bigPic = bigPic;
	}
	public Vector<Picture_small_struct> getTargetsData() {
		return targetsData;
	}
	public int getStatus() {
		return status;
	}
	public void setStatus(int status) {
		this.status = status;
	}
	public void setTargetsData(Vector<Picture_small_struct> targetsData) {
		this.targetsData = targetsData;
	}
}
