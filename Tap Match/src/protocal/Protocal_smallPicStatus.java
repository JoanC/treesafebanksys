package protocal;

/*
 * 作者:万君亚
 * 时间:2011.1.26
 * 说明:定义了小目标图片的状态协议,定义了三种状态
 * 			
 * 
 * 修改:
 * 日期:
 * 说明:
 */

public class Protocal_smallPicStatus {
	public static final int close = 0;//尚未被选择
	public static final int ready_to_choose = 1;//被选做目标,却未被选中
	public static final int is_chosen = 2;//被选中了
}
