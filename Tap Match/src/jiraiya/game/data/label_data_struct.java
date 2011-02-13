package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

import android.graphics.Typeface;

/*
 * 作者:万君亚
 * 时间:2011.1.24
 * 说明:定义了一个标签持有的一般数据	
 * 			
 * 
 * 修改:
 * 日期:
 * 说明:
 * 
 */
public class label_data_struct {
	String info;//标签显示的信息
	String fontName;//标签的字体名称
	int fontSize;//字体大小
	int type = Typeface.NORMAL;//字体风格
	WYPoint postion;//显示的坐标
	int display_z;//显示图层序列
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
