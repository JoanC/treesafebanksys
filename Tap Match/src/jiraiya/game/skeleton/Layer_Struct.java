package jiraiya.game.skeleton;

/*
 * 作者:万君亚
 * 时间:2011.1.22
 * 说明:定义了本软件中一个层的基础结构
 * 
 * 修改:
 * 日期:
 * 说明:
 */

public interface Layer_Struct {
	public Object  readData();//读取布局的数据结构体
	public void generateLayer();//生成一个Layer
}
