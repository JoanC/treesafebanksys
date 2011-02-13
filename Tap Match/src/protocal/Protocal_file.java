package protocal;

public class Protocal_file {
	public static final String tag = "#";//信息模块间隔标识
	public static final int infoID = 0;//图片标识所在的序号数(以#后的一行算起)
	public static final int resourceRadix = 16;//资源号码进制
	//-------------------------------------------------
	//图片信息模块
	public static final int spriteTag = 1;//图片信息标识
	public static final int spriteResourceNumID = 1;//图片资源号的序号数
	public static final int spritePosX = 2;//图片坐标横坐标的序号
	public static final int spritePosY = 3;//图片坐标纵坐标的序号
	public static final int spriteDisplayZ = 4;//图片显示层
	//------------------------------------------------
	//menu的宏观数据模块
	public static final int menuTag = 2;//menu信息标识
	public static final int menuPosX = 1;//menu横坐标序列号
	public static final int menuPosY = 2;//menu纵坐标序列号
	public static final int menuDisplayZ = 3;//menu的显示层位
	//menuItem数据模块
	public static final int menuItemTag = 3;//menuItem信息标识
	public static final int menuItemInfo = 1;//menuItem所显示的信息
	public static final int menuItemPosX = 2;//menuItem的相对菜单横坐标序列号
	public static final int menuItemPosY = 3;//memuItem的相对菜单纵坐标序列号
	//targetChangeUI数据模块
	public static final int changeUITag = 4;//信息标识
	public static final int changUIDefaultID = 1;//第一个目标的ID号码
	public static final int changeDisplayPosX = 2;//切换目标的显示横坐标
	public static final int changeDisplayPosY = 3;//切换目标的显示纵坐标
	public static final int changeTargetNum = 4;//小目标图片的总个数
	public static final int changeSizeX = 5;//触摸判定区域的大小横方向长度
	public static final int changeSizeY = 6;//触摸判定区域的大小纵方向长度
	//小目标图片的数据
	public static final int smallPicTag = 5;//信息标识
	public static final int smallPicDefaultStatus = 1;//初始的状态
	public static final int smallPicResourceID = 2;//资源检索号码
	public static final int smallPicLuPosX = 3;//相对大图片的左上角横坐标
	public static final int smllPicLuPosY = 4;//相对大图片的左上角纵坐标
	public static final int smallPicDisplayZ = 5;//小图片的显示层数据
}
