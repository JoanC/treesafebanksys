package jiraiya.game.tap;


import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;

import jiraiya.game.data.StaticData;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.opengl.WYGLSurfaceView;

import android.app.Activity;
import android.content.Context;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;

public class MainGain extends Activity {
	private WYGLSurfaceView mGLSurfaceView;
    /** Called when the activity is first created. */
	private static AssetManager assetMgr;
	private static FileOutputStream debugFile;
    @Override
    public void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);

        mGLSurfaceView = new WYGLSurfaceView(this);
        setContentView(mGLSurfaceView);
        
        assetMgr = this.getResources().getAssets();
        try {
			debugFile = this.openFileOutput("1.txt", Context.MODE_PRIVATE);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        // show FPS
        Director.getInstance().setDisplayFPS(true);
        StaticData.runApplication();
    }
    
    public static AssetManager getAssetManager(){
    	return assetMgr;
    }
    
    public static FileOutputStream getDebugFile(){
    	return debugFile;
    }
    
}