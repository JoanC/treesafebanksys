package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

/*
 * ����:�����
 * ʱ��:2011.1.24
 * ˵��:������һ����ť�Ļ�������,�ð�ť����ͼƬ,
 *         �ֱ��������ֲ�ͬ״̬�µ�ͼƬid
 * 
 * �޸�:
 * ����:
 * ˵��:
 */

public class button_data_struct {
	int nomal_resourse_id;//����״̬�µ���Դ����
	int select_resourse_id;//��ѡ��״̬�µ���Դ����
	int disable_resourse_id;//����״̬�µ���Դ����
	int display_z;//��ʾ���
	WYPoint position;//��ť��λ������
	public int getNomal_resourse_id() {
		return nomal_resourse_id;
	}
	public void setNomal_resourse_id(int nomalResourseId) {
		nomal_resourse_id = nomalResourseId;
	}
	public int getSelect_resourse_id() {
		return select_resourse_id;
	}
	public void setSelect_resourse_id(int selectResourseId) {
		select_resourse_id = selectResourseId;
	}
	public int getDisable_resourse_id() {
		return disable_resourse_id;
	}
	public void setDisable_resourse_id(int disableResourseId) {
		disable_resourse_id = disableResourseId;
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
