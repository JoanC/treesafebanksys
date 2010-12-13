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
	private Sprite mBackSprite;//���˵��ı���ͼƬ
	public MainMenu() {
		// TODO Auto-generated constructor stub
		this.setTouchEnabled(true);
		//���뱳��ͼƬ��Դ
		this.LoadBackGround();
		this.generateMenu();
	}
	
	
	private void LoadBackGround(){
		mBackSprite = Sprite.make(R.drawable.background);
		this.addChild(mBackSprite, menu_back_layer);
		this.setPosition(StaticData.GetMiddleData());
	}
	
	private void generateMenu(){
		//�������˵�
		mMenu = Menu.make(this.playMenuItem());
		mMenu.setPosition(WYPoint.make(0, 0));
		mMenu.alignItemsVertically();
		this.addChild(mMenu);
	}
	
	private MenuItemLabel playMenuItem(){
		//����"play"�Ĳ˵�ѡ��
		 MenuItemLabel _item = MenuItemLabel.make("Play New Game", this, "onPlayNewGame");
		 _item.setPosition(StaticData.GetMiddleData());
		 return _item;
	}
	
	//��Ϊ�˵���ť�Ļص�����
	//������Ϊpublic����
	//�����Ϊprivate��������һ��warning,��ʾ���������δ��ʹ��
    public void onPlayNewGame(){
		//���play��ť��
		//�л���һ���µ�layer
		Scene _game = Scene.make();
		_game.addChild(new GameLayer());
		Director.getInstance().pushScene(_game);
	}
}
