package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

/*
 * ����:�����
 * ʱ��:2011.1.26
 * ˵��:������СĿ��ͼƬ�����ݽṹ
 * 			
 * 
 * �޸�:
 * ����:
 * ˵��:
 */

public class Picture_small_struct {
	//UI��ʾ��
	sprite_data_struct small_picUI = new sprite_data_struct();
	//���ݲ�
	//��������ֵ,���ڱ�ʾ���ڴ�ͼƬ�е����λ���Լ�Ϊ�������׼��
	/*ע��,UI��ʾ��posֵ����������Դ�ͼƬ������ֵ�ǲ�ͬ��*/
	WYPoint luPos;//<left_up>���Ͻǵ�����ֵ
	WYPoint smallPicSize; //������СĿ��ͼƬ�ڴ�ͼƬ����ռ�Ĵ�С,ʵ����,�����СӦ�ø�UI������ʾ��ͼƬ����һ��
	int status;//СĿ��ͼƬ��״̬,��ֵ��������Э��Protocal_smallPicStatus��
	float offset = 5.0f;//�������������ж�ʱ,���ܵ�ƫ��ֵ����
	public WYPoint getLuPos() {
		return luPos;
	}
	public void setLuPos(WYPoint luPos) {
		this.luPos = luPos;
	}
	public WYPoint getSmallPicSize() {
		return smallPicSize;
	}
	public void setSmallPicSize(WYPoint size) {
		this.smallPicSize = size;
	}
	public int getStatus() {
		return status;
	}
	public void setStatus(int status) {
		this.status = status;
	}
	public sprite_data_struct getSmall_picUI() {
		return small_picUI;
	}
	public float getOffset() {
		return offset;
	}
	public void setOffset(float offset) {
		this.offset = offset;
	}
}
