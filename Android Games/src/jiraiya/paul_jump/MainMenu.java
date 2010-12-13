package jiraiya.paul_jump;



import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Menu;
import com.wiyun.engine.nodes.MenuItem;
import com.wiyun.engine.nodes.MenuItemLabel;
import com.wiyun.engine.nodes.Scene;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYPoint;

public class MainMenu extends Layer {
	private final int menu_back_layer = -1;
	private Menu mMenu;
	private Sprite mBackSprite;//主菜单的背景图片
	public MainMenu() {
		// TODO Auto-generated constructor stub
		this.setTouchEnabled(true);
		//载入背景图片资源
		this.LoadBackGround();
		this.generateMenu();
	}
	
	
	private void LoadBackGround(){
		mBackSprite = Sprite.make(R.drawable.background);
		this.addChild(mBackSprite, menu_back_layer);
		this.setPosition(StaticData.GetMiddleData());
	}
	
	private void generateMenu(){
		//生成主菜单
		mMenu = Menu.make(this.playMenuItem());
		mMenu.setPosition(WYPoint.make(0, 0));
		mMenu.alignItemsVertically();
		this.addChild(mMenu);
	}
	
	private MenuItemLabel playMenuItem(){
		//生成"play"的菜单选项
		 MenuItemLabel _item = MenuItemLabel.make("Play New Game", this, "onPlayNewGame");
		 _item.setPosition(StaticData.GetMiddleData());
		 return _item;
	}
	
	//做为菜单按钮的回调函数
	//必须做为public函数
	//如果做为private函数会有一个warning,表示这个函数从未被使用
    public void onPlayNewGame(){
		//点击play按钮后
		//切换到一个新的layer
		Scene _game = Scene.make();
		_game.addChild(new GameLayer());
		Director.getInstance().pushScene(_game);
	}
}
