package jiraiya.game.skeleton;

import jiraiya.game.data.sprite_data_struct;

import com.wiyun.engine.types.WYPoint;

/*
 * ����:�����
 * ʱ��:2011.1.26
 * ˵��:��������Ϸ��ͼƬ����ؽӿ�,��Щ�ӿڶ���Ӧ�ڴ�ͼƬ��СĿ��ͼƬ
 * 			
 * 
 * 
 * �޸�:�����
 * ����:2011.1.27
 * ˵��:���ƽӿں���
 * 
 * 
 * �޸�:�����
 * ����:2011.2.1
 * ˵��:��ӽӿ�,�Ի�ȡ���Ͻ������size��С
 * 
 * 
 */

public interface Picture {
	/*ȡ�����Ͻ�����
	 * ���Ͻ�������Դ���ͬ,���ڴ�ͼƬ��˵,��������������Ļ���Ͻ�
	 * ����СĿ��ͼƬ��˵,������ڴ�ͼƬ���Ͻ�
	 * ��СĿ������Ͻ�����ת��Ϊ�����Ļ�ϵ����Ͻ���������StaticData�ж���ʵ��
	 */
	public WYPoint getLuPos();
	/*ȡ�ô�С
	 * ��Ϊ��ӦͼƬ����Ӧ��С
	 */
	public WYPoint getSize();
	/*�������������
	 * ���ڴ�ͼƬ��СĿ��ͼƬ,���ߵĴ���ʽ��ͬ
	 * �ڴ�ͼƬ��,Ӧ��ȥ���ö�Ӧ��СͼƬ�����괦��ʽ
	 */
	public int handleInputPosition(WYPoint _input);
	/*����picture��״̬,����int,����СĿ��ͼƬ��״̬Э��
	 * ���ͼƬ�Ĳ�ͬ,�ֱ����ڲ�ͬ��Э��������
	 */
	public void changeStatus(int _new);
	/*ȡ�����е�UI������Ϣ,��ʵ����һ��sprite_data_struct
	 * ÿ��ͼƬ����,�����������д�������,����layer���µõ�����,��ˢ����ʾ
	 */
	abstract sprite_data_struct getUIData();
	/*����״̬�Ĳ�ͬ,UI������Ҳ��һ��
	 * ����һ���µ�״̬(��Э���ж���),�޸���Ӧ��UI����
	 */
}
