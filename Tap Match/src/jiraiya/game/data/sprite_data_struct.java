package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

/*
 * ����:�����
 * ʱ��:2011.1.24
 * ˵��:������һ��ͼƬ���е�һ������	
 * 			
 * 
 * �޸�:
 * ����:
 * ˵��:
 * 
 */

public class sprite_data_struct {
	private int resoruse_id = 0;//��Դid,����Ŀ�����е���Դ��������ʽ���д洢
	private WYPoint position;//ͼƬ��λ������
	private int display_z;//��ʾʱ��ǰ���ϵ
	
	public int getResoruse_id() {
		return resoruse_id;
	}
	public void setResoruse_id(int resoruseId) {
		resoruse_id = resoruseId;
	}
	public WYPoint getPosition() {
		return position;
	}
	public void setPosition(WYPoint position) {
		this.position = position;
	}
	public int getDisplay_z() {
		return display_z;
	}
	public void setDisplay_z(int displayZ) {
		display_z = displayZ;
	}
}
