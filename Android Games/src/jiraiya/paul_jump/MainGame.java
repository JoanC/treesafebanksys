package jiraiya.paul_jump;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Scene;
import com.wiyun.engine.opengl.WYGLSurfaceView;

import android.app.Activity;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;

public class MainGame extends Activity {
	 private WYGLSurfaceView mGLSurfaceView;//������Ϸ�������View
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
    	 super.onCreate(savedInstanceState);
    	 //����ȫ��ĻЧ��
         requestWindowFeature(Window.FEATURE_NO_TITLE);
         getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                 WindowManager.LayoutParams.FLAG_FULLSCREEN);

         mGLSurfaceView = new WYGLSurfaceView(this);
         setContentView(mGLSurfaceView);
         
         Director.getInstance().setDisplayFPS(true);//��ʾ֡��
         
         this.jumpToMenu();//��ת�����˵�������ȥ
    }
    private void jumpToMenu(){
    	Scene _main_scene = Scene.make();
        _main_scene.addChild(new MainMenu());
        // Make the Scene active
        Director.getInstance().runWithScene(_main_scene);
    }
}




