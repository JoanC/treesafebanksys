package jiraiya.game.data;


/*
 * ����:�����
 * ʱ��:2011.1.22
 * ˵��:������default����Ĳ������ݽṹ,��Ϊ��xmlͨ�ŵ�Э��
 * 
 * �޸�:�����
 * ����:2011.1.24
 * ˵��:�����в����е�ͼƬ���������һ���ṹ��,��֤����������
 *         ����Ϊ�˽��ײ�����ݽṹ��xml���ݽӿڲ��ɼ�,��Ȼ���������л����ӿ�
 */

public class Data_layer_default {
//default�Ĳ����ݽṹ
	sprite_data_struct background = new sprite_data_struct();
	default_layer_text_data text = new default_layer_text_data();
	public sprite_data_struct getBackground() {
		return background;
	}
	public void setBackground(sprite_data_struct background) {
		this.background = background;
	}
	public default_layer_text_data getText() {
		return text;
	}
	public void setText(default_layer_text_data text) {
		this.text = text;
	}
}
