package other;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Vector;

import protocal.Protocal_UI;
import jiraiya.game.controll.UIManager;
import jiraiya.game.data.StaticData;
import jiraiya.game.data.label_data_struct;
import jiraiya.game.tap.MainGain;

import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.types.WYPoint;


public class Debuger {
	private static Vector<String>info = new Vector<String>();//信息集合
	private static Node pre = null;//前一个节点
	private static Vector<Label> labels = new Vector<Label>();//标签集合
	private static final int vol = 8;//调试信息的容量
	private static final WYPoint startPos = WYPoint.make(240,260);//第一行的初始位置
	private static final int dis = 30;//行距
	private static final int display_z = 10;//显示位置层
	private static final int fontSize = 30;//字体大小
	
	public static void fprinter(String _info){
		OutputStreamWriter _out = new OutputStreamWriter(MainGain.getDebugFile());
		try {
			_out.write(_info);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static void printer(String _info){
		//删除先前的调试信息
		checkNode(StaticData.getCurrentLayer());
		removePreLabel(StaticData.getCurrentLayer());
		checkInfoQueue();
		AddInfo(_info);
		displayLabel(StaticData.getCurrentLayer());
	}
	
	private static void removePreLabel(Node _parent){
		for(int _index = 0 ; _index < labels.size() ; ++_index){
			UIManager.removeUI(labels.elementAt(_index),_parent);
		}
		labels.clear();
	}
	
	private static void checkNode(Node _new){
		if(_new == pre) return;
		else{
			removePreLabel(pre);
			pre = _new;
			info.clear();
		}
	}
	private static void AddInfo(String _newinfo){
		info.add(_newinfo);
	}
	
	private static void checkInfoQueue(){
		if(info.size() >= vol){
			info.remove(0);
		}
	}
	private static void displayLabel(Node _parent){
		for (int _index = 0; _index < info.size(); ++_index) {
			Label tmp = null;
			String _sub = info.elementAt(_index);
			label_data_struct _data = new label_data_struct();
			_data.setDisplay_z(display_z);
			_data.setFontName("DroidSans");
			_data.setInfo(_sub);
			_data.setFontSize(fontSize);
			_data.setPostion(WYPoint.make(startPos.x,startPos.y - dis*_index));
			tmp = (Label) UIManager
					.uiDisplay(_data, _parent, Protocal_UI.label);
			labels.add(tmp);
		}
	}
}
