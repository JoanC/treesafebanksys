package jiraiya.game.data;

/*
 * 作者:万君亚
 * 时间:2011.1.31
 * 说明:定义了主游戏驱动代码应该填充的相关信息	
 * 			
 * 
 * 修改:
 * 日期:
 * 说明:
 */
public class MainGame_data_struct {
	Picture_big_struct bigPic = new Picture_big_struct();//大图片的相关数据
	SmallPic_changeUI_data targetChange = new SmallPic_changeUI_data();//目标小图片的切换数据
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
