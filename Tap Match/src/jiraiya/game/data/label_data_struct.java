package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

import android.graphics.Typeface;

/*
 * ����:�����
 * ʱ��:2011.1.24
 * ˵��:������һ����ǩ���е�һ������	
 * 			
 * 
 * �޸�:
 * ����:
 * ˵��:
 * 
 */
public class label_data_struct {
	String info;//��ǩ��ʾ����Ϣ
	String fontName;//��ǩ����������
	int fontSize;//�����С
	int type = Typeface.NORMAL;//������
	WYPoint postion;//��ʾ������
	int display_z;//��ʾͼ������
	public String getInfo() {
		return info;
	}
	public void setInfo(String info) {
		this.info = info;
	}
	public String getFontName() {
		return fontName;
	}
	public void setFontName(String fontName) {
		this.fontName = fontName;
	}
	public int getFontSize() {
		return fontSize;
	}
	public void setFontSize(int fontSize) {
		this.fontSize = fontSize;
	}
	public int getType() {
		return type;
	}
	public void setType(int type) {
		this.type = type;
	}
	public WYPoint getPostion() {
		return postion;
	}
	public void setPostion(WYPoint postion) {
		this.postion = postion;
	}
	public int getDisplay_z() {
		return display_z;
	}
	public void setDisplay_z(int displayZ) {
		display_z = displayZ;
	}
}
